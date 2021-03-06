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

#include "vsf.h"

#if VSF_USE_USB_DEVICE == ENABLED && APP_CFG_USE_USBD_DEMO == ENABLED

#include "../common/usrapp_common.h"

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/

describe_mem_stream(__user_usbd_msc_stream, 1024)
static const vk_virtual_scsi_param_t __usrapp_scsi_param = {
    .block_size             = 512,
    .block_num              = USRAPP_CFG_FAKEFAT32_SIZE / 512,
    .vendor                 = "Simon   ",
    .product                = "VSFDriver       ",
    .revision               = "1.00",
    .type                   = SCSI_PDT_DIRECT_ACCESS_BLOCK,
};
static vk_mal_scsi_t __usrapp_mal_scsi = {
    .drv                = &VK_VIRTUAL_SCSI_DRV,
    .param              = (void *)&__usrapp_scsi_param,
    .virtual_scsi_drv   = &VK_MAL_VIRTUAL_SCSI_DRV,
    .mal                = &usrapp_common.mal.fakefat32.use_as__vk_mal_t,
};

describe_usbd(__user_usbd_msc, APP_CFG_USBD_VID, APP_CFG_USBD_PID, USB_DC_SPEED_HIGH)
    usbd_common_desc(__user_usbd_msc, u"VSF-USBD-Simplest", u"SimonQian", u"1.0.0", 64, USB_DESC_MSCBOT_IAD_LEN, USB_MSCBOT_IFS_NUM, USB_CONFIG_ATT_WAKEUP, 100)
        mscbot_desc(__user_usbd_msc, 0, 0, 1, 1, 512)
    usbd_func_desc(__user_usbd_msc)
        usbd_func_str_desc(__user_usbd_msc, 0, u"VSF-MSC0")
    usbd_std_desc_table(__user_usbd_msc)
        usbd_func_str_desc_table(__user_usbd_msc, 0)
    usbd_func(__user_usbd_msc)
        mscbot_func(__user_usbd_msc, 0, 1, 1, 0,
            &__usrapp_mal_scsi.use_as__vk_scsi_t,
            &__user_usbd_msc_stream.use_as__vsf_stream_t)
    usbd_ifs(__user_usbd_msc)
        mscbot_ifs(__user_usbd_msc, 0)
end_describe_usbd(__user_usbd_msc, VSF_USB_DC0)

/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

#if APP_CFG_USE_LINUX_DEMO == ENABLED
int usbd_msc_main(int argc, char *argv[])
{
#else
int main(void)
{
#   if VSF_USE_TRACE == ENABLED
    vsf_start_trace();
#       if USRAPP_CFG_STDIO_EN == ENABLED
    vsf_stdio_init();
#       endif
#   endif
#endif

    vk_usbd_init(&__user_usbd_msc);
    vk_usbd_connect(&__user_usbd_msc);
    return 0;
}

#endif
