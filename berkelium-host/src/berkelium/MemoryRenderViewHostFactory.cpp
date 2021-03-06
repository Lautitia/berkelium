// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "BerkeliumHost.hpp"
#include "MemoryRenderViewHostFactory.hpp"

#include "base/command_line.h"
#include "base/utf_string_conversions.h"
#include "content/common/view_messages.h"
#include "content/browser/renderer_host/render_view_host_impl.h"

#include <Berkelium/IPC/Channel.hpp>
#include <Berkelium/IPC/Message.hpp>

#include "googleurl/src/gurl.h"

#include <stdio.h>

namespace Berkelium {

using Ipc::Channel;
using Ipc::ChannelRef;
using Ipc::Message;
using Ipc::MessageRef;

class MemoryRenderViewHost : public content::RenderViewHostImpl {
private:
	content::SiteInstance* instance;
	content::RenderViewHostDelegate* delegate;
	content::RenderWidgetHostDelegate* widget_delegate;
	int routing_id;
	bool swapped_out;
	content::SessionStorageNamespace* session_storage_namespace;
	bool started;
	ChannelRef ipc;
	MessageRef msg;

public:
	MemoryRenderViewHost(
		content::SiteInstance* instance,
		content::RenderViewHostDelegate* delegate,
		content::RenderWidgetHostDelegate* widget_delegate,
		int routing_id,
		bool swapped_out,
		content::SessionStorageNamespace* session_storage_namespace)
	: content::RenderViewHostImpl(instance, delegate, widget_delegate, routing_id, swapped_out, session_storage_namespace),
	instance(instance),
	delegate(delegate),
	widget_delegate(widget_delegate),
	routing_id(routing_id),
	swapped_out(swapped_out),
	session_storage_namespace(session_storage_namespace),
	started(false),
	ipc(BerkeliumHost::addTab(this)),
	msg(/*ipc->getMessage()*/)
	{
		printf("new MemoryRenderViewHost!\n");
	}

	virtual ~MemoryRenderViewHost() {
		printf("delete MemoryRenderViewHost!\n");
		BerkeliumHost::removeTab(this);
	}

	virtual bool OnMessageReceived(const IPC::Message& msg) {
		// pass all events to berkelium
		uint32 type = msg.type();

		/*
		Debug Code...

#define CHECK_EVENT(X) case X::ID: fprintf(stderr, "Event: " #X "\n"); break

		switch(type) {
			//CHECK_EVENT(ViewHostMsg_DocumentOnLoadCompletedInMainFrame);
			CHECK_EVENT(ViewHostMsg_UpdateEncoding);
			CHECK_EVENT(ViewHostMsg_DocumentLoadedInFrame);
			CHECK_EVENT(ViewHostMsg_FrameNavigate);
			CHECK_EVENT(ViewHostMsg_UpdateZoomLimits);
			CHECK_EVENT(ViewHostMsg_DidStartProvisionalLoadForFrame);
			//CHECK_EVENT(ViewHostMsg_DidStartLoading);
			//CHECK_EVENT(ViewHostMsg_DidStopLoading);
			CHECK_EVENT(ViewHostMsg_DidFinishLoad);
			CHECK_EVENT(ViewHostMsg_DidZoomURL);
			CHECK_EVENT(ViewHostMsg_HasTouchEventHandlers);
			//CHECK_EVENT(ViewHostMsg_RenderViewReady);
			CHECK_EVENT(ViewHostMsg_DidChangeNumWheelEvents);

		default:
			fprintf(stderr, "WindowSender::OnMessageReceived: %d\n", msg.type() - (1 << 16));
		}
		*/

		if(!started) {
			if(type == ViewHostMsg_DidStopLoading::ID) {
				started = true;
				OnReady();
			}
		} else {
			IPC_BEGIN_MESSAGE_MAP(MemoryRenderViewHost, msg)
			IPC_MESSAGE_HANDLER_GENERIC(ViewHostMsg_DidStartLoading, OnLoading(true))
			IPC_MESSAGE_HANDLER_GENERIC(ViewHostMsg_DidStopLoading, OnLoading(false))
			IPC_END_MESSAGE_MAP()
		}

		// after processing them with berkelium,
		// just pass them to chrome
		return content::RenderViewHostImpl::OnMessageReceived(msg);
	}

private: // BerkeliumTab impl
	virtual void CloseTab() {
		content::RenderViewHostImpl::ClosePage();
	}

	virtual void NavigateTo(const std::string& url) {
		NavigateToURL(GURL(url));
	}

	virtual void Update() {
		/*
		if(!ipc->isEmpty()) {
			ipc->recv(msg);
			std::string str = msg->get_str();

			if(str.compare("Navigate") == 0) {
				NavigateTo(msg->get_str());
			} else {
				fprintf(stderr, "*** Update(%s)\n", str.c_str());
			}
		}
		*/
		fprintf(stderr, "*** Update\n");
	}

	virtual void OnReady() {
		/*
		msg->reset();
		msg->add_str("OnReady");
		ipc->send(msg);
		*/
		fprintf(stderr, "*** OnReady()\n");
	}

	virtual void OnLoading(bool start) {
		/*
		msg->reset();
		msg->add_str("OnLoading");
		msg->add_8(start);
		ipc->send(msg);
		*/
		fprintf(stderr, "*** OnLoading(%s)\n", start ? "true" : "false");
	}
};

std::vector<std::string> split(std::string l, char delim) {
    std::replace(l.begin(), l.end(), delim, ' ');
    std::istringstream stm(l);
    std::vector<std::string> tokens;
    for (;;) {
        std::string word;
        if (!(stm >> word)) break;
        tokens.push_back(word);
    }
    return tokens;
}

bool doRegister() {
	const std::string debug("berkelium-debug");
	const std::string bs("berkelium");
	const std::string ds("user-data-dir");

	if(CommandLine::ForCurrentProcess()->HasSwitch(debug)) {
		return !!BerkeliumHost::initDebug(CommandLine::ForCurrentProcess()->GetSwitchValueASCII(debug));
	}

	if(!CommandLine::ForCurrentProcess()->HasSwitch(bs)) return false;
	if(!CommandLine::ForCurrentProcess()->HasSwitch(ds)) return false;
	std::string id = CommandLine::ForCurrentProcess()->GetSwitchValueASCII(bs);
	std::string dir = CommandLine::ForCurrentProcess()->GetSwitchValueASCII(ds);
	if(id.empty() || dir.empty()) {
		return false;
	}
	return !!BerkeliumHost::init(dir, id);
}

MemoryRenderViewHostFactory::MemoryRenderViewHostFactory()
: registered(doRegister())
{
	if(registered) {
		RenderViewHostFactory::RegisterFactory(this);
	}
}

MemoryRenderViewHostFactory::~MemoryRenderViewHostFactory() {
	if(registered) {
		RenderViewHostFactory::UnregisterFactory();
	}
}

content::RenderViewHost* MemoryRenderViewHostFactory::CreateRenderViewHost(
	content::SiteInstance* instance,
	content::RenderViewHostDelegate* delegate,
	content::RenderWidgetHostDelegate* widget_delegate,
	int routing_id,
	bool swapped_out,
	content::SessionStorageNamespace* session_storage) {

	BerkeliumHost::lasyInit();

	return new MemoryRenderViewHost(instance, delegate, widget_delegate, routing_id,
			swapped_out, session_storage);
}

} // namespace Berkelium
