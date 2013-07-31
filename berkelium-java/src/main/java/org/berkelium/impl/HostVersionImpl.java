// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.berkelium.impl;

import org.berkelium.api.HostVersion;
import org.berkelium.api.Runtime;

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

public class HostVersionImpl implements HostVersion {

	@Override
	public native Runtime getRuntime();

	@Override
	public native String getVersionString();

	@Override
	public native int getMajor();

	@Override
	public native int getMinor();

	@Override
	public native int getBuild();

	@Override
	public native int getPatch();

	@Override
	public native boolean isMinVersion(String version);
}
