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

public enum LogType {

	// Represents the stdout stream of the berkelium host process.
	HostOut,

	// Represents the stderr stream of the berkelium host process.
	HostErr,

	// Represents debug messages of the berkelium library.
	Debug,

	// Represents error messages of the berkelium library.
	Error,
}