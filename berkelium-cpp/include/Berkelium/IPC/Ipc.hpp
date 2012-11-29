// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BERKELIUM_IPC_IPC_HPP_
#define BERKELIUM_IPC_IPC_HPP_
#pragma once

#ifndef BERKELIUM_CPP_IMPL
# error "This file is intended for internal use only!"
#endif

#include <Berkelium/API/Berkelium.hpp>

namespace Berkelium {

namespace Ipc {

class Channel;
typedef std::shared_ptr<Channel> ChannelRef;
typedef std::weak_ptr<Channel> ChannelWRef;

class Message;
typedef std::shared_ptr<Message> MessageRef;
typedef std::weak_ptr<Message> MessageWRef;

class Pipe;
typedef std::shared_ptr<Pipe> PipeRef;
typedef std::weak_ptr<Pipe> PipeWRef;

} // namespace Ipc

} // namespace Berkelium

#endif // BERKELIUM_IPC_IPC_HPP_