// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.berkelium.api;

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

public interface HostVersion {

	// Returns the associated Runtime.
	Runtime getRuntime();

	// Returns the berkelium host version e.g. “22.0.1229.94”
	String getVersionString();

	// Returns the Major Version, e.g. “22”
	int getMajor();

	// Returns the Minor Version, always zero?
	int getMinor();

	// Returns the Build Version, e.g. “1229”
	int getBuild();

	// Returns the Patch Version, e.g. “94”
	int getPatch();

	// Returns true if the given Version is less or equal to the version of the executable represented by this executable object.
	boolean isMinVersion(String version);
}
