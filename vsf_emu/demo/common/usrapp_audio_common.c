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

#include "./usrapp_audio_common.h"

#if     VSF_USE_AUDIO == ENABLED                                                \
    &&  (VSF_USE_WINSOUND == ENABLED)

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/

usrapp_audio_common_t usrapp_audio_common = {
#if VSF_USE_WINSOUND == ENABLED
    .winsound           = {
        .dev            = {
            .drv        = &vk_winsound_drv,
            .hw_prio    = APP_CFG_WINSOUND_PRIO,
        },
    },
#endif

#if VSF_USE_WINSOUND == ENABLED
    .default_dev        = &usrapp_audio_common.winsound.dev.use_as__vk_audio_dev_t,
#endif
};

/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

#endif      // VSF_USE_AUDIO && (VSF_USE_WINSOUND)
/* EOF */