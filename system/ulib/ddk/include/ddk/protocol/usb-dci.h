// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// WARNING: This file is machine generated by fidlc.

#pragma once

#include <ddk/protocol/usb.h>
#include <zircon/compiler.h>
#include <zircon/hw/usb.h>
#include <zircon/types.h>

__BEGIN_CDECLS;

// Forward declarations

typedef struct usb_dci_interface usb_dci_interface_t;
typedef struct usb_dci_protocol usb_dci_protocol_t;

// Declarations

typedef struct usb_dci_interface_ops {
    zx_status_t (*control)(void* ctx, const usb_setup_t* setup, const void* write_buffer,
                           size_t write_size, void* out_read_buffer, size_t read_size,
                           size_t* out_read_actual);
    void (*set_connected)(void* ctx, bool connected);
    void (*set_speed)(void* ctx, usb_speed_t speed);
} usb_dci_interface_ops_t;

// This protocol is used for USB peripheral controller drivers.
// Callbacks implemented by the USB device driver.
struct usb_dci_interface {
    usb_dci_interface_ops_t* ops;
    void* ctx;
};

// callback for handling ep0 control requests
static inline zx_status_t usb_dci_interface_control(const usb_dci_interface_t* proto,
                                                    const usb_setup_t* setup,
                                                    const void* write_buffer, size_t write_size,
                                                    void* out_read_buffer, size_t read_size,
                                                    size_t* out_read_actual) {
    return proto->ops->control(proto->ctx, setup, write_buffer, write_size, out_read_buffer,
                               read_size, out_read_actual);
}
static inline void usb_dci_interface_set_connected(const usb_dci_interface_t* proto,
                                                   bool connected) {
    proto->ops->set_connected(proto->ctx, connected);
}
static inline void usb_dci_interface_set_speed(const usb_dci_interface_t* proto,
                                               usb_speed_t speed) {
    proto->ops->set_speed(proto->ctx, speed);
}

typedef struct usb_dci_protocol_ops {
    void (*request_queue)(void* ctx, usb_request_t* req);
    zx_status_t (*set_interface)(void* ctx, const usb_dci_interface_t* interface);
    zx_status_t (*config_ep)(void* ctx, const usb_endpoint_descriptor_t* ep_desc,
                             const usb_ss_ep_comp_descriptor_t* ss_comp_desc);
    zx_status_t (*disable_ep)(void* ctx, uint8_t ep_address);
    zx_status_t (*ep_set_stall)(void* ctx, uint8_t ep_address);
    zx_status_t (*ep_clear_stall)(void* ctx, uint8_t ep_address);
    zx_status_t (*get_bti)(void* ctx, zx_handle_t* out_bti);
    size_t (*get_request_size)(void* ctx);
} usb_dci_protocol_ops_t;

struct usb_dci_protocol {
    usb_dci_protocol_ops_t* ops;
    void* ctx;
};

static inline void usb_dci_request_queue(const usb_dci_protocol_t* proto, usb_request_t* req) {
    proto->ops->request_queue(proto->ctx, req);
}
// Registers callback interface with the controller driver.
static inline zx_status_t usb_dci_set_interface(const usb_dci_protocol_t* proto,
                                                const usb_dci_interface_t* interface) {
    return proto->ops->set_interface(proto->ctx, interface);
}
static inline zx_status_t usb_dci_config_ep(const usb_dci_protocol_t* proto,
                                            const usb_endpoint_descriptor_t* ep_desc,
                                            const usb_ss_ep_comp_descriptor_t* ss_comp_desc) {
    return proto->ops->config_ep(proto->ctx, ep_desc, ss_comp_desc);
}
static inline zx_status_t usb_dci_disable_ep(const usb_dci_protocol_t* proto, uint8_t ep_address) {
    return proto->ops->disable_ep(proto->ctx, ep_address);
}
static inline zx_status_t usb_dci_ep_set_stall(const usb_dci_protocol_t* proto,
                                               uint8_t ep_address) {
    return proto->ops->ep_set_stall(proto->ctx, ep_address);
}
static inline zx_status_t usb_dci_ep_clear_stall(const usb_dci_protocol_t* proto,
                                                 uint8_t ep_address) {
    return proto->ops->ep_clear_stall(proto->ctx, ep_address);
}
// Shares a copy of the DCI driver's BTI handle.
static inline zx_status_t usb_dci_get_bti(const usb_dci_protocol_t* proto, zx_handle_t* out_bti) {
    return proto->ops->get_bti(proto->ctx, out_bti);
}
// Return request size of parent plus the size of private region per request for
// this layer..
static inline size_t usb_dci_get_request_size(const usb_dci_protocol_t* proto) {
    return proto->ops->get_request_size(proto->ctx);
}


__END_CDECLS;
