/*
 * Copyright © 2017 Keith Packard
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef WSI_COMMON_DISPLAY_H
#define WSI_COMMON_DISPLAY_H

#include "wsi_common.h"
#include <xf86drm.h>
#include <xf86drmMode.h>

#define typed_memcpy(dest, src, count) ({ \
   STATIC_ASSERT(sizeof(*src) == sizeof(*dest)); \
   memcpy((dest), (src), (count) * sizeof(*(src))); \
})

VkResult
wsi_display_get_physical_device_display_properties(
   VkPhysicalDevice physical_device,
   struct wsi_device *wsi_device,
   uint32_t *property_count,
   VkDisplayPropertiesKHR *properties);

VkResult
wsi_display_get_physical_device_display_plane_properties(
   VkPhysicalDevice physical_device,
   struct wsi_device *wsi_device,
   uint32_t *property_count,
   VkDisplayPlanePropertiesKHR *properties);

VkResult
wsi_display_get_display_plane_supported_displays(
   VkPhysicalDevice physical_device,
   struct wsi_device *wsi_device,
   uint32_t plane_index,
   uint32_t *display_count,
   VkDisplayKHR *displays);

VkResult
wsi_display_get_display_mode_properties(VkPhysicalDevice physical_device,
                                        struct wsi_device *wsi_device,
                                        VkDisplayKHR display,
                                        uint32_t *property_count,
                                        VkDisplayModePropertiesKHR *properties);

VkResult
wsi_display_create_display_mode(VkPhysicalDevice physical_device,
                                struct wsi_device *wsi_device,
                                VkDisplayKHR display,
                                const VkDisplayModeCreateInfoKHR *create_info,
                                const VkAllocationCallbacks *allocator,
                                VkDisplayModeKHR *mode);

VkResult
wsi_get_display_plane_capabilities(VkPhysicalDevice physical_device,
                                   struct wsi_device *wsi_device,
                                   VkDisplayModeKHR mode_khr,
                                   uint32_t plane_index,
                                   VkDisplayPlaneCapabilitiesKHR *capabilities);

VkResult
wsi_create_display_surface(VkInstance instance,
                           const VkAllocationCallbacks *pAllocator,
                           const VkDisplaySurfaceCreateInfoKHR *pCreateInfo,
                           VkSurfaceKHR *pSurface);

#endif