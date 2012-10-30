// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BERKELIUM_BERKELIUMFACTORY_HPP_
#define BERKELIUM_BERKELIUMFACTORY_HPP_
#pragma once

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

#include "berkelium/Berkelium.hpp"

namespace Berkelium {

class BerkeliumFactory {
public:

	// Creates an HostExecutable Object representing the given executable.
	static HostExecutableRef forExecutable(const std::string& pathTo);

	// Creates an HostExecutable, the exectuable is searched through system path or system configuration (e.g. registry on windows)
	static HostExecutableRef forSystemInstalled();

	// Returns the profile for the given application name.
	static ProfileRef forProfile(const std::string& application);

	// Returns a Profile object representing the Google Chrome profile.
	static ProfileRef getChromeProfile();

	// Returns a Profile object representing the Chromium profile.
	static ProfileRef getChromiumProfile();

	// Returns the profile located inside the given path.
	static ProfileRef forProfilePath(const std::string& path);

	// Creates a temporary profile that gets automatically removed after use.
	static ProfileRef createTemporaryProfile();

	// Creates a HostVersion object representing the given version string.
	static HostVersionRef forVersion(const std::string& version);

	// Creates a HostVersion object representing the given version number.
	static HostVersionRef forVersion(int32_t vMajor, int32_t vMinor, int32_t vBuild, int32_t vPatch);

	// Launches a the given berkelium host process using the given profile.
	static InstanceRef open(HostExecutableRef executable, ProfileRef profile);
};

} // namespace Berkelium

#endif // BERKELIUM_BERKELIUMFACTORY_HPP_