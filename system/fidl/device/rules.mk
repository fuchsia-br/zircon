# Copyright 2018 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR).display-controller

MODULE_TYPE := fidl

MODULE_SRCS := $(LOCAL_DIR)/display-controller.fidl

MODULE_STATIC_LIBS += system/ulib/fidl

MODULE_FIDL_LIBRARY := display

include make/module.mk