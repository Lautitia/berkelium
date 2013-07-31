// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.berkelium.impl;

import org.berkelium.api.Logger;

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

public class LoggerImpl implements Logger {

	@Override
	public native void debug(String message);

	@Override
	public native void info(String message);

	@Override
	public native void warn(String message);

	@Override
	public native void error(String message);
}
