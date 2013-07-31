// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.berkelium.impl;

import org.berkelium.api.Runtime;
import org.berkelium.api.Tab;
import org.berkelium.api.TabDelegate;
import org.berkelium.api.Window;

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

public class TabImpl implements Tab {

	@Override
	public native Runtime getRuntime();

	@Override
	public native void internalUpdate();

	@Override
	public native void close();

	@Override
	public native void sync();

	@Override
	public native TabDelegate getTabDelegate();

	@Override
	public native void addTabDelegate(TabDelegate delegate);

	@Override
	public native void removeTabDelegate(TabDelegate delegate);

	@Override
	public native Window getWindow();

	@Override
	public native void resize(int width, int height);

	@Override
	public native void navigateTo(String url);
}
