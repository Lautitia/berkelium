// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BERKELIUM_API_HOSTEXECUTABLE_HPP_
#define BERKELIUM_API_HOSTEXECUTABLE_HPP_
#pragma once

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

#include <Berkelium/API/Berkelium.hpp>

namespace Berkelium {

// Represents a reference to the executable file of the berkelium host process.
class HostExecutable {
protected:
	HostExecutable();

public:
	virtual ~HostExecutable() = 0;

	// Returns the full (native) path to the berkelium host executable represented by this object.
	virtual const std::string& getPath() = 0;

	// Returns the version of this berkelium host executable.
	virtual HostVersionRef getVersion() = 0;
};

} // namespace Berkelium

#endif // BERKELIUM_HOSTEXECUTABLE_HPP_
