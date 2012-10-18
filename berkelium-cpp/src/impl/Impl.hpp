// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BERKELIUM_IMPL_HPP_
#define BERKELIUM_IMPL_HPP_
#pragma once

#include "berkelium/Berkelium.hpp"

namespace Berkelium {

namespace impl {

HostVersionRef newHostVersion();
HostExecutableRef newHostExecutable();
ProfileRef newProfile();

} // namespace impl

} // namespace Berkelium

#endif // BERKELIUM_IMPL_HPP_
