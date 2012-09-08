// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IPCCONSTANTS_HPP_
#define IPCCONSTANTS_HPP_
#pragma once

namespace Berkelium {

namespace IpcConstants {

namespace Delegate {

enum {
	onPaintDone = 0, //
	onAddressBarChanged = 1, //
	onStartLoading = 2, //
	onLoad = 3, //
	onCrashedWorker = 4, //
	onCrashedPlugin = 5, //
	onProvisionalLoadError = 6, //
	onConsoleMessage = 7, //
	onScriptAlert = 8, //
	freeLastScriptAlert = 9, //
	onNavigationRequested = 10, //
	onLoadingStateChanged = 11, //
	onTitleChanged = 12, //
	onTooltipChanged = 13, //
	onCrashed = 14, //
	onUnresponsive = 15, //
	onResponsive = 16, //
	onExternalHost = 17, //
	onCreatedWindow = 18, //
	onPaint = 19, //
	onJavascriptCallback = 20, //
	onRunFileChooser = 21, //
};

} // namespace Delegate

} // namespace IpcConstants

} // namespace Berkelium


#endif // IPCCONSTANTS_HPP_
