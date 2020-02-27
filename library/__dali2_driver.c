/*
    __dali2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__dali2_driver.h"
#include "__dali2_hal.c"

/* ------------------------------------------------------------------- MACROS */

#define TRUE                             1
#define FALSE                            0

#define DALI_LOW_POWER_TIMEOUT           2000 
#define DALI_START_BIT_PULSE             0
#define DALI_END_BIT_PULSE               1

/* ---------------------------------------------------------------- VARIABLES */

/** @defgroup DALI2_VAR Variables */                                   /** @{ */

const uint8_t _DALI2_BACKWARD_FRAME_SENT            =   11;
const uint8_t _DALI2_FORWARD_FRAME_RECEIVED         =   12;
const uint8_t _DALI2_EXTENDED_COMMAND               =  0x03;
const uint8_t _DALI2_COMMAND                        =  0x02;
const uint8_t _DALI2_BACKCHANNEL                    =  0x01;
const uint8_t _DALI2_SHORT_ADDRESS                  =  0x00;
const uint8_t _DALI2_GROUP_ADDRESS                  =  0x80;
const uint8_t _DALI2_BROADCAST_DIRECT               =  0xFE;
const uint8_t _DALI2_BROADCAST_CMD                  =  0xFF;
const uint8_t _DALI2_FOLLOWING_DIRECT_ARC_POWER_LVL =  0x00;
const uint8_t _DALI2_FOLLOWING_COMMAND              =  0x01;
                                                                       /** @} */
/** @defgroup DALI2_BALMEM Ballast Memory Offsets */                   /** @{ */

const uint8_t _DALI2_BALLAST_SHORT_ADDRESS            = 0x00;
const uint8_t _DALI2_BALLAST_ACTUAL_DIM_LEVEL         = 0x01;
const uint8_t _DALI2_BALLAST_POWER_ON_LEVEL           = 0x02;
const uint8_t _DALI2_BALLAST_SYSTEM_FAILURE_LEVEL     = 0x03;
const uint8_t _DALI2_BALLAST_MIN_LEVEL                = 0x04;
const uint8_t _DALI2_BALLAST_MAX_LEVEL                = 0x05;
const uint8_t _DALI2_BALLAST_FADE_RATE                = 0x06;
const uint8_t _DALI2_BALLAST_FADE_TIME                = 0x07;
const uint8_t _DALI2_BALLAST_SEARCH_ADDRESS_H         = 0x08;
const uint8_t _DALI2_BALLAST_SEARCH_ADDRESS_M         = 0x09;
const uint8_t _DALI2_BALLAST_SEARCH_ADDRESS_L         = 0x0A;
const uint8_t _DALI2_BALLAST_RANDOM_ADDRESS_H         = 0x0B;
const uint8_t _DALI2_BALLAST_RANDOM_ADDRESS_M         = 0x0C;
const uint8_t _DALI2_BALLAST_RANDOM_ADDRESS_L         = 0x0D;
const uint8_t _DALI2_BALLAST_GROUP_0_7                = 0x0E;
const uint8_t _DALI2_BALLAST_GROUP_8_15               = 0x0F;
const uint8_t _DALI2_BALLAST_SCENE_01                 = 0x10;
const uint8_t _DALI2_BALLAST_SCENE_02                 = 0x11;
const uint8_t _DALI2_BALLAST_SCENE_03                 = 0x12;
const uint8_t _DALI2_BALLAST_SCENE_04                 = 0x13;
const uint8_t _DALI2_BALLAST_SCENE_05                 = 0x14;
const uint8_t _DALI2_BALLAST_SCENE_06                 = 0x15;
const uint8_t _DALI2_BALLAST_SCENE_07                 = 0x16;
const uint8_t _DALI2_BALLAST_SCENE_08                 = 0x17;
const uint8_t _DALI2_BALLAST_SCENE_09                 = 0x18;
const uint8_t _DALI2_BALLAST_SCENE_10                 = 0x19;
const uint8_t _DALI2_BALLAST_SCENE_11                 = 0x1A;
const uint8_t _DALI2_BALLAST_SCENE_12                 = 0x1B;
const uint8_t _DALI2_BALLAST_SCENE_13                 = 0x1C;
const uint8_t _DALI2_BALLAST_SCENE_14                 = 0x1D;
const uint8_t _DALI2_BALLAST_SCENE_15                 = 0x1E;
const uint8_t _DALI2_BALLAST_SCENE_16                 = 0x1F;
const uint8_t _DALI2_BALLAST_STATUS_INFORMATION       = 0x20;
const uint8_t _DALI2_BALLAST_VERSION_NUMBER           = 0x21;
const uint8_t _DALI2_BALLAST_PHYSICAL_MIN_LEVEL       = 0x22;
const uint8_t _DALI2_BALLAST_SLAVE_OFFSET             = 0x23; 
                                                                       /** @} */
/** @defgroup DALI2_ERR DALI Errors */                                 /** @{ */

const uint8_t _DALI2_NO_ERROR                    = 0;
const uint8_t _DALI2_INTERFACE_FAILURE_ERROR     = 1;
                                                                       /** @} */
/** @defgroup DALI2_STATE DALI 2 States */                             /** @{ */

const uint8_t _DALI2_NO_ACTION                        = 0;
const uint8_t _DALI2_SENDING_DATA                     = 1;
const uint8_t _DALI2_RECEIVING_DATA                   = 2;
const uint8_t _DALI2_ERR                              = 3;
const uint8_t _DALI2_SETTLING_FF_TO_BF                = 4;
const uint8_t _DALI2_SETTLING_FF_TO_FF                = 5;
const uint8_t _DALI2_BACKWARD_FRAME_RECEIVED          = 6;
const uint8_t _DALI2_FORWARD_FRAME_SENT               = 7;
const uint8_t _DALI2_SETTLING_FF_TO_BF_FINISHED       = 8;
const uint8_t _DALI2_SETTLING_FF_TO_FF_FINISHED       = 9;
const uint8_t _DALI2_WAIT_FOR_BACKCHANNEL_TO_RECEIVE  = 10;
                                                                       /** @} */
/** @defgroup DALI2_RXSTAT RX Statuses */                              /** @{ */

const uint8_t _DALI2_READY_TO_RECEIVE            = 0;
const uint8_t _DALI2_NEW_FRAME_RECEIVED          = 1;
const uint8_t _DALI2_RECEIVE_OVERFLOW            = 2;
                                                                       /** @} */
/** @defgroup DALI2_TXSTAT TX Statuses */                              /** @{ */

const uint8_t _DALI2_IDLE                        = 0;  
const uint8_t _DALI2_SEND_START                  = 1;  
const uint8_t _DALI2_SEND_ADDRESS                = 2;  
const uint8_t _DALI2_SEND_DATA                   = 3;  
const uint8_t _DALI2_SEND_STOP                   = 4;  
const uint8_t _DALI2_SEND_SETTLING               = 5;  
const uint8_t _DALI2_SEND_WAIT                   = 6;  
                                                                       /** @} */
/** @defgroup DALI2_GRADDR Group addresses */                          /** @{ */

const uint8_t _DALI2_GROUP01_DIRECT_ADDR             = 0x81;
const uint8_t _DALI2_GROUP02_DIRECT_ADDR             = 0x83;
const uint8_t _DALI2_GROUP03_DIRECT_ADDR             = 0x85;
const uint8_t _DALI2_GROUP04_DIRECT_ADDR             = 0x87;
const uint8_t _DALI2_GROUP05_DIRECT_ADDR             = 0x89;
const uint8_t _DALI2_GROUP06_DIRECT_ADDR             = 0x8B;
const uint8_t _DALI2_GROUP07_DIRECT_ADDR             = 0x8D;
const uint8_t _DALI2_GROUP08_DIRECT_ADDR             = 0x8F;
const uint8_t _DALI2_GROUP09_DIRECT_ADDR             = 0x91;
const uint8_t _DALI2_GROUP10_DIRECT_ADDR             = 0x93;
const uint8_t _DALI2_GROUP11_DIRECT_ADDR             = 0x95;
const uint8_t _DALI2_GROUP12_DIRECT_ADDR             = 0x97;
const uint8_t _DALI2_GROUP13_DIRECT_ADDR             = 0x99;
const uint8_t _DALI2_GROUP14_DIRECT_ADDR             = 0x9B;
const uint8_t _DALI2_GROUP15_DIRECT_ADDR             = 0x9D;
const uint8_t _DALI2_GROUP16_DIRECT_ADDR             = 0x9F;
                                                                       /** @} */
/** @defgroup DALI2_ADDR Available addresses 0-63 */                   /** @{ */

const uint8_t _DALI2_ADDRESS01                       = 0x00;
const uint8_t _DALI2_ADDRESS02                       = 0x01;
const uint8_t _DALI2_ADDRESS03                       = 0x02;
const uint8_t _DALI2_ADDRESS04                       = 0x03;
const uint8_t _DALI2_ADDRESS05                       = 0x04;
const uint8_t _DALI2_ADDRESS06                       = 0x05;
const uint8_t _DALI2_ADDRESS07                       = 0x06;
const uint8_t _DALI2_ADDRESS08                       = 0x07;
const uint8_t _DALI2_ADDRESS09                       = 0x08;
const uint8_t _DALI2_ADDRESS10                       = 0x09;
const uint8_t _DALI2_ADDRESS11                       = 0x0A;
const uint8_t _DALI2_ADDRESS12                       = 0x0B;
const uint8_t _DALI2_ADDRESS13                       = 0x0C;
const uint8_t _DALI2_ADDRESS14                       = 0x0D;
const uint8_t _DALI2_ADDRESS15                       = 0x0E;
const uint8_t _DALI2_ADDRESS16                       = 0x0F;
const uint8_t _DALI2_ADDRESS17                       = 0x10;
const uint8_t _DALI2_ADDRESS18                       = 0x11;
const uint8_t _DALI2_ADDRESS19                       = 0x12;
const uint8_t _DALI2_ADDRESS20                       = 0x13;
const uint8_t _DALI2_ADDRESS21                       = 0x14;
const uint8_t _DALI2_ADDRESS22                       = 0x15;
const uint8_t _DALI2_ADDRESS23                       = 0x16;
const uint8_t _DALI2_ADDRESS24                       = 0x17;
const uint8_t _DALI2_ADDRESS25                       = 0x18;
const uint8_t _DALI2_ADDRESS26                       = 0x19;
const uint8_t _DALI2_ADDRESS27                       = 0x1A;
const uint8_t _DALI2_ADDRESS28                       = 0x1B;
const uint8_t _DALI2_ADDRESS29                       = 0x1C;
const uint8_t _DALI2_ADDRESS30                       = 0x1D;
const uint8_t _DALI2_ADDRESS31                       = 0x1E;
const uint8_t _DALI2_ADDRESS32                       = 0x1F;
const uint8_t _DALI2_ADDRESS33                       = 0x20;
const uint8_t _DALI2_ADDRESS34                       = 0x21;
const uint8_t _DALI2_ADDRESS35                       = 0x22;
const uint8_t _DALI2_ADDRESS36                       = 0x23;
const uint8_t _DALI2_ADDRESS37                       = 0x24;
const uint8_t _DALI2_ADDRESS38                       = 0x25;
const uint8_t _DALI2_ADDRESS39                       = 0x26;
const uint8_t _DALI2_ADDRESS40                       = 0x27;
const uint8_t _DALI2_ADDRESS41                       = 0x28;
const uint8_t _DALI2_ADDRESS42                       = 0x29;
const uint8_t _DALI2_ADDRESS43                       = 0x2A;
const uint8_t _DALI2_ADDRESS44                       = 0x2B;
const uint8_t _DALI2_ADDRESS45                       = 0x2C;
const uint8_t _DALI2_ADDRESS46                       = 0x2D;
const uint8_t _DALI2_ADDRESS47                       = 0x2E;
const uint8_t _DALI2_ADDRESS48                       = 0x2F;
const uint8_t _DALI2_ADDRESS49                       = 0x30;
const uint8_t _DALI2_ADDRESS50                       = 0x31;
const uint8_t _DALI2_ADDRESS51                       = 0x32;
const uint8_t _DALI2_ADDRESS52                       = 0x33;
const uint8_t _DALI2_ADDRESS53                       = 0x34;
const uint8_t _DALI2_ADDRESS54                       = 0x35;
const uint8_t _DALI2_ADDRESS55                       = 0x36;
const uint8_t _DALI2_ADDRESS56                       = 0x37;
const uint8_t _DALI2_ADDRESS57                       = 0x38;
const uint8_t _DALI2_ADDRESS58                       = 0x39;
const uint8_t _DALI2_ADDRESS59                       = 0x3A;
const uint8_t _DALI2_ADDRESS60                       = 0x3B;
const uint8_t _DALI2_ADDRESS61                       = 0x3C;
const uint8_t _DALI2_ADDRESS62                       = 0x3D;
const uint8_t _DALI2_ADDRESS63                       = 0x3E;
const uint8_t _DALI2_ADDRESS64                       = 0x3F;
                                                                       /** @} */
/** @defgroup DALI2_INDARC Indirect Arc Power Commands */              /** @{ */

const uint8_t _DALI2_OFF                             = 0x00;
const uint8_t _DALI2_UP                              = 0x01;
const uint8_t _DALI2_DOWN                            = 0x02;
const uint8_t _DALI2_STEP_UP                         = 0x03;
const uint8_t _DALI2_STEP_DOWN                       = 0x04;
const uint8_t _DALI2_RECALL_MAX_LEVEL                = 0x05;
const uint8_t _DALI2_RECALL_MIN_LEVEL                = 0x06;
const uint8_t _DALI2_STEP_DOWN_AND_OFF               = 0x07;
const uint8_t _DALI2_ON_AND_STEP_UP                  = 0x08;

const uint8_t _DALI2_GO_TO_SCENE01                   = 0x10;
const uint8_t _DALI2_GO_TO_SCENE02                   = 0x11;
const uint8_t _DALI2_GO_TO_SCENE03                   = 0x12;
const uint8_t _DALI2_GO_TO_SCENE04                   = 0x13;
const uint8_t _DALI2_GO_TO_SCENE05                   = 0x14;
const uint8_t _DALI2_GO_TO_SCENE06                   = 0x15;
const uint8_t _DALI2_GO_TO_SCENE07                   = 0x16;
const uint8_t _DALI2_GO_TO_SCENE08                   = 0x17;
const uint8_t _DALI2_GO_TO_SCENE09                   = 0x18;
const uint8_t _DALI2_GO_TO_SCENE10                   = 0x19;
const uint8_t _DALI2_GO_TO_SCENE11                   = 0x1A;
const uint8_t _DALI2_GO_TO_SCENE12                   = 0x1B;
const uint8_t _DALI2_GO_TO_SCENE13                   = 0x1C;
const uint8_t _DALI2_GO_TO_SCENE14                   = 0x1D;
const uint8_t _DALI2_GO_TO_SCENE15                   = 0x1E;
const uint8_t _DALI2_GO_TO_SCENE16                   = 0x1F;
                                                                       /** @} */
/** @defgroup DALI2_GENCFG General Configuration Commands */           /** @{ */

const uint8_t _DALI2_RESET                           = 0x20;
const uint8_t _DALI2_STORE_ACTUAL_LEVEL_IN_THE_DTR   = 0x21;
                                                                       /** @} */
/** @defgroup DALI2_ARCP Arc Power Parameter Settings */               /** @{ */

const uint8_t _DALI2_STORE_THE_DTR_AS_MAX_LEVEL                 = 0x22;
const uint8_t _DALI2_STORE_THE_DTR_AS_MIN_LEVEL                 = 0x23;
const uint8_t _DALI2_STORE_THE_DTR_AS_SYSTEM_FAILURE_LEVEL      = 0x2C;
const uint8_t _DALI2_STORE_THE_DTR_AS_POWER_ON_LEVEL            = 0x2D;
const uint8_t _DALI2_STORE_THE_DTR_AS_FADE_TIME                 = 0x2E;
const uint8_t _DALI2_STORE_THE_DTR_AS_FADE_RATE                 = 0x2F;

const uint8_t _DALI2_STORE_THE_DTRAS_SCENE01                    = 0x40;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE02                    = 0x41;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE03                    = 0x42;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE04                    = 0x43;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE05                    = 0x44;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE06                    = 0x45;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE07                    = 0x46;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE08                    = 0x47;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE09                    = 0x48;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE10                    = 0x49;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE11                    = 0x4A;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE12                    = 0x4B;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE13                    = 0x4C;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE14                    = 0x4D;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE15                    = 0x4E;
const uint8_t _DALI2_STORE_THE_DTRAS_SCENE16                    = 0x4F;
                                                                       /** @} */
/** @defgroup DALI2_SYSPARAM System Parameters Settings */             /** @{ */

const uint8_t _DALI2_REMOVE_FROM_SCENE01                        = 0x50;
const uint8_t _DALI2_REMOVE_FROM_SCENE02                        = 0x51;
const uint8_t _DALI2_REMOVE_FROM_SCENE03                        = 0x52;
const uint8_t _DALI2_REMOVE_FROM_SCENE04                        = 0x53;
const uint8_t _DALI2_REMOVE_FROM_SCENE05                        = 0x54;
const uint8_t _DALI2_REMOVE_FROM_SCENE06                        = 0x55;
const uint8_t _DALI2_REMOVE_FROM_SCENE07                        = 0x56;
const uint8_t _DALI2_REMOVE_FROM_SCENE08                        = 0x57;
const uint8_t _DALI2_REMOVE_FROM_SCENE09                        = 0x58;
const uint8_t _DALI2_REMOVE_FROM_SCENE10                        = 0x59;
const uint8_t _DALI2_REMOVE_FROM_SCENE11                        = 0x5A;
const uint8_t _DALI2_REMOVE_FROM_SCENE12                        = 0x5B;
const uint8_t _DALI2_REMOVE_FROM_SCENE13                        = 0x5C;
const uint8_t _DALI2_REMOVE_FROM_SCENE14                        = 0x5D;
const uint8_t _DALI2_REMOVE_FROM_SCENE15                        = 0x5E;
const uint8_t _DALI2_REMOVE_FROM_SCENE16                        = 0x5F;

const uint8_t _DALI2_ADD_TO_GROUP01                             = 0x60;
const uint8_t _DALI2_ADD_TO_GROUP02                             = 0x61;
const uint8_t _DALI2_ADD_TO_GROUP03                             = 0x62;
const uint8_t _DALI2_ADD_TO_GROUP04                             = 0x63;
const uint8_t _DALI2_ADD_TO_GROUP05                             = 0x64;
const uint8_t _DALI2_ADD_TO_GROUP06                             = 0x65;
const uint8_t _DALI2_ADD_TO_GROUP07                             = 0x66;
const uint8_t _DALI2_ADD_TO_GROUP08                             = 0x67;
const uint8_t _DALI2_ADD_TO_GROUP09                             = 0x68;
const uint8_t _DALI2_ADD_TO_GROUP10                             = 0x69;
const uint8_t _DALI2_ADD_TO_GROUP11                             = 0x6A;
const uint8_t _DALI2_ADD_TO_GROUP12                             = 0x6B;
const uint8_t _DALI2_ADD_TO_GROUP13                             = 0x6C;
const uint8_t _DALI2_ADD_TO_GROUP14                             = 0x6D;
const uint8_t _DALI2_ADD_TO_GROUP15                             = 0x6E;
const uint8_t _DALI2_ADD_TO_GROUP16                             = 0x6F;

const uint8_t _DALI2_REMOVE_FROM_GROUP01                        = 0x70;
const uint8_t _DALI2_REMOVE_FROM_GROUP02                        = 0x71;
const uint8_t _DALI2_REMOVE_FROM_GROUP03                        = 0x72;
const uint8_t _DALI2_REMOVE_FROM_GROUP04                        = 0x73;
const uint8_t _DALI2_REMOVE_FROM_GROUP05                        = 0x74;
const uint8_t _DALI2_REMOVE_FROM_GROUP06                        = 0x75;
const uint8_t _DALI2_REMOVE_FROM_GROUP07                        = 0x76;
const uint8_t _DALI2_REMOVE_FROM_GROUP08                        = 0x77;
const uint8_t _DALI2_REMOVE_FROM_GROUP09                        = 0x78;
const uint8_t _DALI2_REMOVE_FROM_GROUP10                        = 0x79;
const uint8_t _DALI2_REMOVE_FROM_GROUP11                        = 0x7A;
const uint8_t _DALI2_REMOVE_FROM_GROUP12                        = 0x7B;
const uint8_t _DALI2_REMOVE_FROM_GROUP13                        = 0x7C;
const uint8_t _DALI2_REMOVE_FROM_GROUP14                        = 0x7D;
const uint8_t _DALI2_REMOVE_FROM_GROUP15                        = 0x7E;
const uint8_t _DALI2_REMOVE_FROM_GROUP16                        = 0x7F;
const uint8_t _DALI2_STORE_DTR_AS_SHORT_ADDRESS                 = 0x80;
                                                                       /** @} */
/** @defgroup DALI2_STATINFO Status Information Commands */            /** @{ */

const uint8_t _DALI2_QUERY_STATUS                              = 0x90;
const uint8_t _DALI2_QUERY_BALLAST                             = 0x91;
const uint8_t _DALI2_QUERY_LAMP_FAILURE                        = 0x92;
const uint8_t _DALI2_QUERY_LAMP_POWER_ON                       = 0x93;
const uint8_t _DALI2_QUERY_LIMIT_ERROR                         = 0x94;
const uint8_t _DALI2_QUERY_RESET_STATE                         = 0x95;
const uint8_t _DALI2_QUERY_MISSING_SHORT_ADDRESS               = 0x96;
const uint8_t _DALI2_QUERY_VERSION_NUMBER                      = 0x97;
const uint8_t _DALI2_QUERY_CONTENT_DTR                         = 0x98;
const uint8_t _DALI2_QUERY_DEVICE_TYPE                         = 0x99;
const uint8_t _DALI2_QUERY_PHYSICAL_MINIMUM_LEVEL              = 0x9A;
const uint8_t _DALI2_QUERY_POWER_FAILURE                       = 0x9B;
                                                                       /** @} */
/** @defgroup DALI2_ARC Arc Power Parameter Settings */                /** @{ */

const uint8_t _DALI2_UERY_ACTUAL_LEVEL                         = 0xA0;
const uint8_t _DALI2_UERY_MAX_LEVEL                            = 0xA1;
const uint8_t _DALI2_UERY_MIN_LEVEL                            = 0xA2;
const uint8_t _DALI2_UERY_POWER_ON_LEVEL                       = 0xA3;
const uint8_t _DALI2_UERY_SYSTEM_FAILURE_LEVEL                 = 0xA4;
const uint8_t _DALI2_UERY_FADE_TIME_FADE_RATE                  = 0xA5;
                                                                       /** @} */
/** @defgroup DALI2_Q Queries Related To The System Settings */        /** @{ */

const uint8_t _DALI2_QUERY_SCENE_LEVEL01                        = 0xB0;
const uint8_t _DALI2_QUERY_SCENE_LEVEL02                        = 0xB1;
const uint8_t _DALI2_QUERY_SCENE_LEVEL03                        = 0xB2;
const uint8_t _DALI2_QUERY_SCENE_LEVEL04                        = 0xB3;
const uint8_t _DALI2_QUERY_SCENE_LEVEL05                        = 0xB4;
const uint8_t _DALI2_QUERY_SCENE_LEVEL06                        = 0xB5;
const uint8_t _DALI2_QUERY_SCENE_LEVEL07                        = 0xB6;
const uint8_t _DALI2_QUERY_SCENE_LEVEL08                        = 0xB7;
const uint8_t _DALI2_QUERY_SCENE_LEVEL09                        = 0xB8;
const uint8_t _DALI2_QUERY_SCENE_LEVEL10                        = 0xB9;
const uint8_t _DALI2_QUERY_SCENE_LEVEL11                        = 0xBA;
const uint8_t _DALI2_QUERY_SCENE_LEVEL12                        = 0xBB;
const uint8_t _DALI2_QUERY_SCENE_LEVEL13                        = 0xBC;
const uint8_t _DALI2_QUERY_SCENE_LEVEL14                        = 0xBD;
const uint8_t _DALI2_QUERY_SCENE_LEVEL15                        = 0xBE;
const uint8_t _DALI2_QUERY_SCENE_LEVEL16                        = 0xBF;
const uint8_t _DALI2_QUERY_GROUPS_0_7                           = 0xC0;
const uint8_t _DALI2_QUERY_GROUPS_8_15                          = 0xC1;
const uint8_t _DALI2_QUERY_RANDOM_ADDRESS_H                     = 0xC2;
const uint8_t _DALI2_QUERY_RANDOM_ADDERSS_M                     = 0xC3;
const uint8_t _DALI2_QUERY_RANDOM_ADDRESS_L                     = 0xC4;
                                                                       /** @} */
/** @defgroup DALI2_SPEC Special Commands */                           /** @{ */

const uint8_t _DALI2_TERMINATE_H_BITS                           = 0xA1;    
const uint8_t _DALI2_TERMINATE_L_BITS                           = 0x00;    
const uint8_t _DALI2_DTR                                        = 0xA3;    
const uint8_t _DALI2_INITIALISE                                 = 0xA5;    
const uint8_t _DALI2_INITIALISE_ALL_BALLAST_H                   = 0xA5;
const uint8_t _DALI2_INITIALISE_ALL_BALLAST_L                   = 0x00;
const uint8_t _DALI2_INITIALISE_BALLAST_WITHOUT_SHORT_ADDR_H    = 0xA5;
const uint8_t _DALI2_INITIALISE_BALLAST_WITHOUT_SHORT_ADDR_L    = 0xFF;
const uint8_t _DALI2_RANDOMISE_H                                = 0xA7;
const uint8_t _DALI2_RANDOMISE_L                                = 0x00;
const uint8_t _DALI2_COMPARE_H                                  = 0xA9;
const uint8_t _DALI2_COMPARE_L                                  = 0x00;
const uint8_t _DALI2_WITHDRAW_H                                 = 0xAB;
const uint8_t _DALI2_WITHDRAW_L                                 = 0x00;
const uint8_t _DALI2_SEARCHADDRH                                = 0xB1;    
const uint8_t _DALI2_SEARCHADDRM                                = 0xB3;    
const uint8_t _DALI2_SEARCHADDRL                                = 0xB5;    
const uint8_t _DALI2_PROGRAM_SHORT_ADDRESS                      = 0xB7;    
const uint8_t _DALI2_VERIFY_SHORT_ADDRESS                       = 0xB9;    
const uint8_t _DALI2_QUERY_SHORT_ADDRESS_H                      = 0xBB;    
const uint8_t _DALI2_QUERY_SHORT_ADDRESS_L                      = 0x00;
const uint8_t _DALI2_PHYSICAL_SELECTION_H                       = 0xBD;    
const uint8_t _DALI2_PHYSICAL_SELECTION_L                       = 0x00;
const uint8_t _DALI2_ENABLE_STANDARD_DEVICE_H                   = 0xC1;    
const uint8_t _DALI2_ENABLE_STANDARD_DEVICE_L                   = 0x00;
const uint8_t _DALI2_ENABLE_EMERGENCY_LIGHTS_H                  = 0xC1;    
const uint8_t _DALI2_ENABLE_EMERGENCY_LIGHTS_L                  = 0x01;
const uint8_t _DALI2_ENABLE_HID_LAMPS_H                         = 0xC1;    
const uint8_t _DALI2_ENABLE_HID_LAMPS_L                         = 0x02;
const uint8_t _DALI2_ENABLE_LOW_V_HALOGEN_LAMPS_H               = 0xC1;    
const uint8_t _DALI2_ENABLE_LOW_V_HALOGEN_LAMPS_L               = 0x03;
const uint8_t _DALI2_ENABLE_DIM_INCANDESCENT_LAMPS_H            = 0xC1;    
const uint8_t _DALI2_ENABLE_DIM_INCANDESCENT_LAMPS_L            = 0x04;
const uint8_t _DALI2_ENABLE_LED_MODULES_H                       = 0xC1;    
const uint8_t _DALI2_ENABLE_LED_MODULES_L                       = 0x00;
                                                                       /** @} */

#ifdef   __DALI2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t _ballast[ 160 ];

static volatile uint16_t _tickCounter;
static volatile uint8_t  _bitCounter;

static volatile uint8_t _daliState;
static volatile uint8_t _currentVal;
static volatile uint8_t _formerVal;
static volatile uint8_t _expectBackCh;

static volatile uint8_t _txBuffer[ 17 ];
static volatile uint8_t _rxBuffer[ 9 ];

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

/*
 * Check status of IN line and write to array
 */
static void _receivingData();

/*
 * Check status of IN line and write to array
 */
static void _sendingData();

/*
 * Read DALI data from memory
 */
static uint8_t _readData(uint8_t addrToRead);

/*
 * Write DALI data to memory
 */
static void _writeData(uint8_t addrToWrite, uint8_t dataToWrite);

/*
 * Prepare command array to be encoded and create new array where every element is a bit.
 */
static void _prepareData(uint8_t *commandArray, uint8_t *tx_array, uint8_t bytesInCmd);

/*
 * Description:    Prepare address byte.
 */
static void _prepareAddress(uint8_t *commandArray, uint8_t addressType, uint8_t byteAddressPosition, uint8_t followingType);

static uint8_t _checkSpecCmd(uint8_t addrByte);

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

static void _receivingData()
{
    uint8_t pulsePosition;

    if (_tickCounter == (_bitCounter * 8 + 2))
    {
        if (hal_gpio_intGet())
        {
            _rxBuffer[_bitCounter] = 0;
        }
        else
        {
            _rxBuffer[_bitCounter] = 1;
        }
    }

    _tickCounter++;

    if ((_tickCounter + 1) % 8 == 0)
    {
        _bitCounter++;
    }

    if (_bitCounter > 8)
    {
        _daliState = _DALI2_BACKWARD_FRAME_RECEIVED;
    }
}

static void _sendingData()
{
    uint8_t pulsePosition;
  
    if (_bitCounter < 17)
    {
        if (_tickCounter % 4 == 0)
        {
            pulsePosition = _tickCounter / 4;
      
            if (pulsePosition % 2 == 0)
            {
                if (_txBuffer[_bitCounter] == DALI_START_BIT_PULSE)
                {
                    hal_gpio_rstSet( 0 );
                }
                else
                {
                    hal_gpio_rstSet( 1 );
                }
            }
            else
            {
                if (_txBuffer[_bitCounter] == DALI_START_BIT_PULSE)
                {
                    hal_gpio_rstSet( 1 );
                }
                else
                {
                    hal_gpio_rstSet( 0 );
                }
            }
        }
    }
  
    _tickCounter++;
  
    if (_tickCounter % 8 == 0)
    {
        _bitCounter++;
    }
    
    if (_bitCounter > 16)
    {
        _daliState = _DALI2_FORWARD_FRAME_SENT;
        hal_gpio_rstSet( 0 );
    }
}

static uint8_t _readData(uint8_t addrToRead)
{
    uint8_t loc;
    uint8_t val;

    loc = addrToRead * 2 + 1;
    val = _ballast[ loc ];
  
    return val;
}

static void _writeData(uint8_t addrToWrite, uint8_t dataToWrite)
{
    uint8_t loc;

    loc = addrToWrite * 2 + 1;
    _ballast[ loc ] = dataToWrite;
}

static uint8_t _checkSpecCmd(uint8_t addrByte)
{
    uint8_t addrToCheck;
    
    addrToCheck = addrByte;

    if ((addrToCheck >= 0x90) || (addrToCheck <= 0xA0))
    {
        if (addrToCheck & 0x01)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        return FALSE;
    }
}

static void _prepareData(uint8_t *commandArray, uint8_t *tx_array, uint8_t bytesInCmd)
{
    uint8_t mask = 0x80;
    uint8_t dummy;
    uint8_t bytes_counter;
    uint8_t i;
    uint8_t bitCounter;


    bitCounter = 0;
    
    for (i = 0; i < 9; i++)
    {
        tx_array[i] = 0;
    }
    
    for (bytes_counter = 0; bytes_counter < bytesInCmd; bytes_counter++)
    {
        dummy = commandArray[bytes_counter];
        mask = 0x80;
        bitCounter++;

        if (bitCounter == 1)
        {
            tx_array[0] = DALI_END_BIT_PULSE;
        }

        for (i = 1; i < 9; i++)
        {
            if (dummy & mask)
            {
                tx_array[i + (8 * bytes_counter)] = DALI_END_BIT_PULSE;
            }
            else
            {
                tx_array[i + (8 * bytes_counter)] = DALI_START_BIT_PULSE;
            }

            if (mask == 0x01)
            {
                mask <<= 7;
            }
            else
            {
                mask >>= 1;
            }
        }
    }
}

static void _prepareAddress(uint8_t *commandArray, uint8_t addressType, uint8_t byteAddressPosition, uint8_t followingType)
{
    uint8_t addr_tmp;

	if(_checkSpecCmd(commandArray[byteAddressPosition]))
	{
		return;
	}
    
    if (addressType == _DALI2_BROADCAST_CMD)
    {
        commandArray[byteAddressPosition] = _DALI2_BROADCAST_CMD;
    }
    else
    {
        addr_tmp = commandArray[byteAddressPosition];

        if (addressType == _DALI2_BROADCAST_DIRECT)
        {
            commandArray[byteAddressPosition] = _DALI2_BROADCAST_DIRECT;
        }
        else
        {
            addr_tmp <<= 1;
        
            if (followingType == _DALI2_FOLLOWING_COMMAND)
            {
                addr_tmp |= 0x01;
            }

            if (addressType == _DALI2_GROUP_ADDRESS)
            {
                addr_tmp |= _DALI2_GROUP_ADDRESS;
                commandArray[byteAddressPosition] = addr_tmp;
            }
        }
    }
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __DALI2_DRV_SPI__

void dali2_spiDriverInit(T_DALI2_P gpioObj, T_DALI2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __DALI2_DRV_I2C__

void dali2_i2cDriverInit(T_DALI2_P gpioObj, T_DALI2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __DALI2_DRV_UART__

void dali2_uartDriverInit(T_DALI2_P gpioObj, T_DALI2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

void dali2_gpioDriverInit(T_DALI2_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void dali2_masterInit()
{
    uint8_t i;
    uint8_t tmp;

    _daliState = _DALI2_NO_ACTION;
  
    _tickCounter = 0;
    _bitCounter = 0;
  
    hal_gpio_rstSet( 1 );
    
    for (i = 1; i < 65; i++)
    {
        tmp = 0;
        tmp = i << 1;
        
        _ballast[ (i * 2) - 2 ] = tmp;
        _ballast[ (i * 2) - 1 ] = 0;
    }

    for (i = 1; i < 17; i++)
    {

        tmp = 0;
        tmp = i << 1;
        tmp = _DALI2_GROUP_ADDRESS + tmp;
    
        _ballast[ _DALI2_GROUP_ADDRESS + ( i * 2 ) - 2 ] = tmp;
        _ballast[ _DALI2_GROUP_ADDRESS + ( i * 2 ) - 1 ] = 0;
    }
}

void dali2_sendCmd(const uint8_t balAddress, const uint8_t cmd, const uint8_t cmdType, const uint8_t folType)
{
    uint8_t tmp[2];
    uint8_t i;

    hal_gpio_rstSet( 0 );
    
    _tickCounter = 0;
    _bitCounter  = 0;
   

    tmp[0] = balAddress;
    tmp[1] = cmd;
    
    for (i = 0; i < 17; i++)
    {
        _txBuffer[i] = 0;
    }
    
    _prepareAddress(tmp, cmdType, 0, folType);
    _prepareData(tmp, _txBuffer, 2);

    _writeData(balAddress, tmp[1]);

    if ((cmd >= 0x00) && (cmd <= 0x1F))
    {
        _expectBackCh   = FALSE;
    }

    if ((cmd >= 20) && (cmd <= 0x80))
    {
        _expectBackCh = FALSE;
    }

    if (cmd >= 0x90)
    {
        _expectBackCh = TRUE;
    }

    if (_checkSpecCmd(tmp[0]))
    {
        _expectBackCh = TRUE;

        if ((tmp[0] == _DALI2_TERMINATE_H_BITS) || (tmp[0] == _DALI2_DTR))
        {
            _expectBackCh = FALSE;
        }
        else if ((tmp[0] == _DALI2_VERIFY_SHORT_ADDRESS) || (tmp[0] == _DALI2_QUERY_SHORT_ADDRESS_H))
        {
            _expectBackCh = TRUE;
        }
        else
        {
            _expectBackCh = FALSE;
        }
    }
  
    _daliState = _DALI2_SENDING_DATA;
    _tickCounter = 0;
    _bitCounter = 0;
}

uint8_t dali2_masterStatus()
{
    uint8_t i;

    if (_daliState == _DALI2_NO_ACTION)
    {
        _tickCounter = 0;
        _bitCounter  = 0;
    }

    if (_daliState == _DALI2_SENDING_DATA)
    {
    
        // ...
    }

    if (_daliState == _DALI2_RECEIVING_DATA)
    {
        //backchannel
        //check for backchannel timeout; used for NO answer

    }
    
    if (_daliState == _DALI2_FORWARD_FRAME_SENT)
    {
        _tickCounter = 0;
        _bitCounter  = 0;

        hal_gpio_rstSet( 0 );
      
        if (_expectBackCh)
        {
            _daliState = _DALI2_SETTLING_FF_TO_BF;
        }
        else
        {
            _daliState = _DALI2_SETTLING_FF_TO_FF;
        }
    }

    if (_daliState == _DALI2_BACKWARD_FRAME_RECEIVED)
    {
        _daliState = _DALI2_NO_ACTION;
        _expectBackCh = 0;
    }

    if ((_daliState == _DALI2_SETTLING_FF_TO_FF_FINISHED) || (_daliState == _DALI2_SETTLING_FF_TO_BF_FINISHED))
    {
        _daliState = _DALI2_NO_ACTION;

        if (_expectBackCh)
        {
            _daliState = _DALI2_WAIT_FOR_BACKCHANNEL_TO_RECEIVE;
        
            _formerVal = 1;
            _currentVal = 1;
        }
    }

    if (_daliState == _DALI2_WAIT_FOR_BACKCHANNEL_TO_RECEIVE)
    {
        _formerVal = _currentVal;
        _currentVal = hal_gpio_intGet();
      
        if (_formerVal != _currentVal)
        {
            _tickCounter = 0;
            _bitCounter  = 0;
            _daliState = _DALI2_RECEIVING_DATA;
        }
    }
    
    if (_daliState == _DALI2_ERR)
    {
        hal_gpio_rstSet( 0 );
    }
    
    return _daliState;
}

void dali2_isr()
{

    uint8_t i;
    uint8_t pulsePosition;

    if (_daliState != _DALI2_NO_ACTION)
    {
        if (_daliState == _DALI2_SENDING_DATA)
        {
            _sendingData();
        }

        if (_daliState == _DALI2_RECEIVING_DATA)
        {
            _receivingData();
        }
    }
    else
    {
        // ...
    }

    if (_daliState == _DALI2_WAIT_FOR_BACKCHANNEL_TO_RECEIVE)
    {
        _formerVal = _currentVal;
        _currentVal = hal_gpio_intGet();
    
        if (_tickCounter > 200)
        {
            _daliState = _DALI2_NO_ACTION;

            for (i = 0; i < 8; i++)
            {
                _rxBuffer[i] = 0;
            }
        }
        else
        {
            if(_formerVal != _currentVal)
            {
                _daliState = _DALI2_RECEIVING_DATA;
                _tickCounter = 0;
                _bitCounter  = 0;
            }
        }
    
        _tickCounter++;
    }
    
    if ((_daliState == _DALI2_SETTLING_FF_TO_BF) || (_daliState == _DALI2_SETTLING_FF_TO_FF))
    {
        if (_daliState == _DALI2_SETTLING_FF_TO_FF)
        {
            if(_tickCounter > 104)
            {
                _daliState = _DALI2_SETTLING_FF_TO_FF_FINISHED;
            }
        }

        if(_daliState == _DALI2_SETTLING_FF_TO_BF)
        {
            if(_tickCounter > 28)
            {
                _daliState = _DALI2_SETTLING_FF_TO_BF_FINISHED;
            }
        }
    
        _tickCounter++;
    }
}

uint8_t dali2_getBallastResponse()
{
    uint8_t i;
    uint8_t receivedData;
    
    for (i = 0; i < 8; i++)
    {
        _rxBuffer[i] <<= i;
        receivedData |= _rxBuffer[i];
    }

    return receivedData;
}

/* -------------------------------------------------------------------------- */
/*
  __dali2_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */
