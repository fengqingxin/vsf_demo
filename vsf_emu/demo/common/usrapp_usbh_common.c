/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

/*============================ INCLUDES ======================================*/

#include "./usrapp_usbh_common.h"

#if VSF_USE_USB_HOST == ENABLED

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/

const usrapp_usbh_common_const_t usrapp_usbh_common_const = {
#if VSF_USE_USB_HOST_HCD_OHCI == ENABLED
    .ohci_param         = {
        .op             = &VSF_USB_HC0_IP,
        .priority       = APP_CFG_USBH_HW_PRIO,
    },
#elif VSF_USE_USB_HOST_HCD_LIBUSB == ENABLED
    .libusb_hcd_param   = {
        .priority       = APP_CFG_USBH_HW_PRIO,
    },
#elif VSF_USE_USB_HOST_HCD_WINUSB == ENABLED
    .winusb_hcd_param   = {
        .priority       = APP_CFG_USBH_HW_PRIO,
    },
#endif
};

usrapp_usbh_common_t usrapp_usbh_common = {
#if VSF_USE_USB_HOST_HCD_OHCI == ENABLED
    .host.drv           = &vk_ohci_drv,
    .host.param         = (void *)&usrapp_usbh_common_const.ohci_param,
#elif VSF_USE_USB_HOST_HCD_LIBUSB == ENABLED
    .host.drv           = &vk_libusb_hcd_drv,
    .host.param         = (void*)&usrapp_usbh_common_const.libusb_hcd_param,
#elif VSF_USE_USB_HOST_HCD_WINUSB == ENABLED
    .host.drv           = &vk_winusb_hcd_drv,
    .host.param         = (void*)&usrapp_usbh_common_const.winusb_hcd_param,
#endif

#if VSF_USE_USB_HOST_HUB == ENABLED
    .hub.drv            = &vk_usbh_hub_drv,
#endif
#if VSF_USE_TCPIP == ENABLED && VSF_USE_USB_HOST_ECM == ENABLED
    .ecm.drv            = &vk_usbh_ecm_drv,
#endif
#   if VSF_USE_USB_HOST_MSC == ENABLED
    .msc.drv            = &vk_usbh_msc_drv,
#   endif
#if VSF_USE_USB_HOST_LIBUSB == ENABLED
    .libusb.drv         = &vk_usbh_libusb_drv,
#endif
#if VSF_USE_USB_HOST_BTHCI == ENABLED
    .bthci.drv          = &vk_usbh_bthci_drv,
#endif
#if VSF_USE_USB_HOST_HID == ENABLED
    .hid.drv            = &vk_usbh_hid_drv,
#endif
#if VSF_USE_USB_HOST_DS4 == ENABLED
    .ds4.drv            = &vk_usbh_ds4_drv,
#endif
#if VSF_USE_USB_HOST_NSPRO == ENABLED
    .nspro.drv          = &vk_usbh_nspro_drv,
#endif
#if VSF_USE_USB_HOST_XB360 == ENABLED
    .xb360.drv          = &vk_usbh_xb360_drv,
#endif
#if VSF_USE_USB_HOST_XB1 == ENABLED
    .xb1.drv            = &vk_usbh_xb1_drv,
#endif
#if VSF_USE_USB_HOST_UAC == ENABLED
    .uac                = &vk_usbh_uac_drv,
#endif
};

/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

vsf_err_t usrapp_usbh_common_init(void)
{
#if VSF_USE_USB_HOST_HCD_OHCI == ENABLED
    vk_ohci_init();
#endif

    vk_usbh_init(&usrapp_usbh_common.host);
#   if VSF_USE_USB_HOST_LIBUSB == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.libusb);
#   endif
#   if VSF_USE_TCPIP == ENABLED && VSF_USE_USB_HOST_ECM == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.ecm);
#   endif
#   if VSF_USE_USB_HOST_MSC == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.msc);
#   endif
#   if VSF_USE_USB_HOST_BTHCI == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.bthci);
#   endif
#   if VSF_USE_USB_HOST_HID == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.hid);
#   endif
#   if VSF_USE_USB_HOST_DS4 == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.ds4);
#   endif
#   if VSF_USE_USB_HOST_NSPRO == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.nspro);
#   endif
#   if VSF_USE_USB_HOST_XB360 == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.xb360);
#   endif
#   if VSF_USE_USB_HOST_XB1 == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.xb1);
#   endif
#   if VSF_USE_USB_HOST_HUB == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.hub);
#   endif
#if VSF_USE_USB_HOST_UAC == ENABLED
    vk_usbh_register_class(&usrapp_usbh_common.host, &usrapp_usbh_common.uac);
#endif

    return VSF_ERR_NONE;
}

#endif      // VSF_USE_USB_HOST
/* EOF */