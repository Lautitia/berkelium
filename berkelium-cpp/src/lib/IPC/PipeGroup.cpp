// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <Berkelium/API/Util.hpp>
#include <Berkelium/IPC/PipeGroup.hpp>
#include <Berkelium/IPC/Ipc.hpp>
#include <Berkelium/IPC/Pipe.hpp>
#include <Berkelium/Impl/Impl.hpp>

#include <map>

using Berkelium::impl::getPipeFd;
using Berkelium::impl::bk_error;

#ifdef BERKELIUM_TRACE_IO_SELECT
#define trace 1
#else
#define trace 0
#endif

namespace Berkelium {

namespace Ipc {

PipeCallback::PipeCallback() {
}

PipeCallback::~PipeCallback() {
}

namespace impl {

struct PipeGroupData {
	PipeWRef ref;
	PipeCallbackWRef cb;
	int fd;
	bool highPrio;
};

typedef std::map<Pipe*, PipeGroupData*> PipeMap;

class PipeGroupImpl : public PipeGroup {
private:
	PipeMap map;
	fd_set fds;

public:
	PipeGroupImpl() :
		PipeGroup(),
		map() {
	}

	virtual ~PipeGroupImpl() {
	}

	virtual void registerPipe(PipeRef pipe) {
		//Berkelium::impl::bk_error("register pipe %p %s", channel.get(), channel->getName().c_str());
		PipeGroupData* data = new PipeGroupData();
		data->ref = pipe;
		data->fd = getPipeFd(pipe);
		map.insert(std::pair<Pipe*, PipeGroupData*>(pipe.get(), data));
	}

	virtual void unregisterPipe(Pipe* pipe) {
		//Berkelium::impl::bk_error("unregister pipe %p", channel);
		PipeMap::iterator it(map.find(pipe));
		if(it != map.end()) {
			PipeGroupData* data = it->second;
			delete data;
			map.erase(it);
		}
	}

	virtual void registerCallback(PipeRef pipe, PipeCallbackRef callback, bool highPrio) {
		//Berkelium::impl::bk_error("register callback %p", pipe.get());
		PipeMap::iterator it(map.find(pipe.get()));
		if(it != map.end()) {
			PipeGroupData* data = it->second;
			if(data->fd == -1) {
				Berkelium::impl::bk_error("register callback %p failed: no fd!", pipe.get());
			}
			data->cb = callback;
			data->highPrio = highPrio;
		} else {
			Berkelium::impl::bk_error("register callback %p failed!", pipe.get());
		}
	}

	virtual void registerCallback(ChannelRef channel, PipeCallbackRef callback, bool highPrio) {
		registerCallback(Berkelium::impl::getInputPipe(channel), callback, highPrio);
	}

	virtual void update(int32_t timeout) {
		int64_t end = Util::currentTimeMillis() + timeout;
		while(true) {
			int64_t now = Util::currentTimeMillis();
			int64_t left = end - now;
			if(left < 1) {
				return;
			}
			recv(PipeRef(), left);
		}
	}

	virtual bool recv(PipeRef pipe, MessageRef msg, int32_t timeout) {
		int64_t end = Util::currentTimeMillis() + timeout;
		while(pipe->isEmpty()) {
			if(timeout == -1) {
				recv(pipe, -1);
			} else {
				int64_t now = Util::currentTimeMillis();
				int64_t left = end - now;
				if(left < 1) {
					return false;
				}
				recv(pipe, left);
			}
		}
		pipe->recv(msg);
		return true;
	}

	void recv(PipeRef pipe, int32_t timeout) {
		FD_ZERO(&fds);
		int nfds = 0;
		bool all = !pipe;
		bool included = false;
		if(trace) {
			//bk_error("PipeGroup: selecting...");
		}
		for(PipeMap::iterator it(map.begin()); it != map.end(); it++) {
			PipeGroupData* data = it->second;
			PipeRef ref(data->ref.lock());
			if(ref && (all || data->highPrio || ref == pipe)) {
				included |= ref == pipe;
				int fd = data->fd;
				if(fd == -1) {
					continue;
				}
				nfds = std::max(nfds, fd);
				FD_SET(fd, &fds);
				if(trace) {
					if(ref->getAlias().substr(0, 7) != "process")
					if(ref->getAlias() != "berkelium-host-ipc")
					bk_error("PipeGroup: waiting for %s %d %s", ref->getAlias().c_str(), data->fd, ref->getName().c_str());
				}
			}
		}
		if(pipe && !included) {
			bk_error("PipeGroup: pipe not registered!");
			int fd = getPipeFd(pipe);
			nfds = std::max(nfds, fd);
			FD_SET(fd, &fds);
		}
		static struct timeval tv;
		tv.tv_sec = 0;
		tv.tv_usec = timeout * 1000;
		int r = select(nfds + 1, &fds, NULL, NULL, timeout == -1 ? NULL : &tv);
		if(r == 0) {
			return;
		} else if(r == -1) {
			bk_error("PipeGroup: select error %d", r);
			return;
		}
		for(PipeMap::iterator it(map.begin()); it != map.end(); it++) {
			PipeGroupData* data = it->second;
			if(data->fd == -1) {
				continue;
			}
			if(FD_ISSET(data->fd, &fds)) {
				PipeRef ref(data->ref.lock());
				if(trace) {
					bk_error("PipeGroup: selected %s %d %s", ref->getAlias().c_str(), data->fd, ref->getName().c_str());
				}
				PipeCallbackRef cb(data->cb.lock());
				if(cb) {
					if(ref != pipe) {
						cb->onDataReady(ref);
					}
				} else if(data->highPrio){
					bk_error("PipeGroup: no callback!");
				}
			}
		}
	}
};

} // namespace impl

PipeGroup::PipeGroup() {
}

PipeGroup::~PipeGroup() {
}

PipeGroupRef PipeGroup::create() {
	return PipeGroupRef(new impl::PipeGroupImpl());
}

} // namespace Ipc

} // namespace Berkelium