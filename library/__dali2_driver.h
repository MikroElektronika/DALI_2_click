/*
    __dali2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __dali2_driver.h
@brief    DALI_2 Driver
@mainpage DALI_2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DALI2
@brief      DALI_2 Click Driver
@{

| Global Library Prefix | **DALI2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DALI2_H_
#define _DALI2_H_

/** 
 * @macro T_DALI2_P
 * @brief Driver Abstract type 
 */
#define T_DALI2_P    const uint8_t*

/** @defgroup DALI2_COMPILE Compilation Config */                      /** @{ */

//  #define   __DALI2_DRV_SPI__                            /**<     @macro __DALI2_DRV_SPI__  @brief SPI driver selector */
//  #define   __DALI2_DRV_I2C__                            /**<     @macro __DALI2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DALI2_DRV_UART__                           /**<     @macro __DALI2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DALI2_VAR Variables */                                   /** @{ */

extern const uint8_t _DALI2_BACKWARD_FRAME_SENT             ;
extern const uint8_t _DALI2_FORWARD_FRAME_RECEIVED          ;
extern const uint8_t _DALI2_EXTENDED_COMMAND                ;
extern const uint8_t _DALI2_COMMAND                         ;
extern const uint8_t _DALI2_BACKCHANNEL                     ;
extern const uint8_t _DALI2_SHORT_ADDRESS                   ;
extern const uint8_t _DALI2_GROUP_ADDRESS                   ;
extern const uint8_t _DALI2_BROADCAST_DIRECT                ;
extern const uint8_t _DALI2_BROADCAST_CMD                   ;
extern const uint8_t _DALI2_FOLLOWING_DIRECT_ARC_POWER_LVL  ;
extern const uint8_t _DALI2_FOLLOWING_COMMAND               ;
                                                                       /** @} */
/** @defgroup DALI2_BALMEM Ballast Memory Offsets */                   /** @{ */

extern const uint8_t _DALI2_BALLAST_SHORT_ADDRESS            ;
extern const uint8_t _DALI2_BALLAST_ACTUAL_DIM_LEVEL         ;
extern const uint8_t _DALI2_BALLAST_POWER_ON_LEVEL           ;
extern const uint8_t _DALI2_BALLAST_SYSTEM_FAILURE_LEVEL     ;
extern const uint8_t _DALI2_BALLAST_MIN_LEVEL                ;
extern const uint8_t _DALI2_BALLAST_MAX_LEVEL                ;
extern const uint8_t _DALI2_BALLAST_FADE_RATE                ;
extern const uint8_t _DALI2_BALLAST_FADE_TIME                ;
extern const uint8_t _DALI2_BALLAST_SEARCH_ADDRESS_H         ;
extern const uint8_t _DALI2_BALLAST_SEARCH_ADDRESS_M         ;
extern const uint8_t _DALI2_BALLAST_SEARCH_ADDRESS_L         ;
extern const uint8_t _DALI2_BALLAST_RANDOM_ADDRESS_H         ;
extern const uint8_t _DALI2_BALLAST_RANDOM_ADDRESS_M         ;
extern const uint8_t _DALI2_BALLAST_RANDOM_ADDRESS_L         ;
extern const uint8_t _DALI2_BALLAST_GROUP_0_7                ;
extern const uint8_t _DALI2_BALLAST_GROUP_8_15               ;
extern const uint8_t _DALI2_BALLAST_SCENE_01                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_02                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_03                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_04                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_05                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_06                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_07                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_08                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_09                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_10                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_11                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_12                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_13                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_14                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_15                 ;
extern const uint8_t _DALI2_BALLAST_SCENE_16                 ;
extern const uint8_t _DALI2_BALLAST_STATUS_INFORMATION       ;
extern const uint8_t _DALI2_BALLAST_VERSION_NUMBER           ;
extern const uint8_t _DALI2_BALLAST_PHYSICAL_MIN_LEVEL       ;
extern const uint8_t _DALI2_BALLAST_SLAVE_OFFSET             ;
                                                                       /** @} */
/** @defgroup DALI2_ERR DALI Errors */                                 /** @{ */

extern const uint8_t _DALI2_NO_ERROR                    ;
extern const uint8_t _DALI2_INTERFACE_FAILURE_ERROR     ;
                                                                       /** @} */
/** @defgroup DALI2_STATE DALI 2 States */                             /** @{ */

extern const uint8_t _DALI2_NO_ACTION                        ;
extern const uint8_t _DALI2_SENDING_DATA                     ;
extern const uint8_t _DALI2_RECEIVING_DATA                   ;
extern const uint8_t _DALI2_ERR                              ;
extern const uint8_t _DALI2_SETTLING_FF_TO_BF                ;
extern const uint8_t _DALI2_SETTLING_FF_TO_FF                ;
extern const uint8_t _DALI2_BACKWARD_FRAME_RECEIVED          ;
extern const uint8_t _DALI2_FORWARD_FRAME_SENT               ;
extern const uint8_t _DALI2_SETTLING_FF_TO_BF_FINISHED       ;
extern const uint8_t _DALI2_SETTLING_FF_TO_FF_FINISHED       ;
extern const uint8_t _DALI2_WAIT_FOR_BACKCHANNEL_TO_RECEIVE  ;
                                                                       /** @} */
/** @defgroup DALI2_RXSTAT RX Statuses */                              /** @{ */

extern const uint8_t _DALI2_READY_TO_RECEIVE            ;
extern const uint8_t _DALI2_NEW_FRAME_RECEIVED          ;
extern const uint8_t _DALI2_RECEIVE_OVERFLOW            ;
                                                                       /** @} */
/** @defgroup DALI2_TXSTAT TX Statuses */                              /** @{ */

extern const uint8_t _DALI2_IDLE                        ;  
extern const uint8_t _DALI2_SEND_START                  ;  
extern const uint8_t _DALI2_SEND_ADDRESS                ;  
extern const uint8_t _DALI2_SEND_DATA                   ;  
extern const uint8_t _DALI2_SEND_STOP                   ;  
extern const uint8_t _DALI2_SEND_SETTLING               ;  
extern const uint8_t _DALI2_SEND_WAIT                   ;  
                                                                       /** @} */
/** @defgroup DALI2_GRADDR Group addresses */                          /** @{ */

extern const uint8_t _DALI2_GROUP01_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP02_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP03_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP04_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP05_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP06_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP07_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP08_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP09_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP10_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP11_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP12_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP13_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP14_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP15_DIRECT_ADDR             ;
extern const uint8_t _DALI2_GROUP16_DIRECT_ADDR             ;
                                                                       /** @} */
/** @defgroup DALI2_ADDR Available addresses 0-63 */                   /** @{ */

extern const uint8_t _DALI2_ADDRESS01                       ;
extern const uint8_t _DALI2_ADDRESS02                       ;
extern const uint8_t _DALI2_ADDRESS03                       ;
extern const uint8_t _DALI2_ADDRESS04                       ;
extern const uint8_t _DALI2_ADDRESS05                       ;
extern const uint8_t _DALI2_ADDRESS06                       ;
extern const uint8_t _DALI2_ADDRESS07                       ;
extern const uint8_t _DALI2_ADDRESS08                       ;
extern const uint8_t _DALI2_ADDRESS09                       ;
extern const uint8_t _DALI2_ADDRESS10                       ;
extern const uint8_t _DALI2_ADDRESS11                       ;
extern const uint8_t _DALI2_ADDRESS12                       ;
extern const uint8_t _DALI2_ADDRESS13                       ;
extern const uint8_t _DALI2_ADDRESS14                       ;
extern const uint8_t _DALI2_ADDRESS15                       ;
extern const uint8_t _DALI2_ADDRESS16                       ;
extern const uint8_t _DALI2_ADDRESS17                       ;
extern const uint8_t _DALI2_ADDRESS18                       ;
extern const uint8_t _DALI2_ADDRESS19                       ;
extern const uint8_t _DALI2_ADDRESS20                       ;
extern const uint8_t _DALI2_ADDRESS21                       ;
extern const uint8_t _DALI2_ADDRESS22                       ;
extern const uint8_t _DALI2_ADDRESS23                       ;
extern const uint8_t _DALI2_ADDRESS24                       ;
extern const uint8_t _DALI2_ADDRESS25                       ;
extern const uint8_t _DALI2_ADDRESS26                       ;
extern const uint8_t _DALI2_ADDRESS27                       ;
extern const uint8_t _DALI2_ADDRESS28                       ;
extern const uint8_t _DALI2_ADDRESS29                       ;
extern const uint8_t _DALI2_ADDRESS30                       ;
extern const uint8_t _DALI2_ADDRESS31                       ;
extern const uint8_t _DALI2_ADDRESS32                       ;
extern const uint8_t _DALI2_ADDRESS33                       ;
extern const uint8_t _DALI2_ADDRESS34                       ;
extern const uint8_t _DALI2_ADDRESS35                       ;
extern const uint8_t _DALI2_ADDRESS36                       ;
extern const uint8_t _DALI2_ADDRESS37                       ;
extern const uint8_t _DALI2_ADDRESS38                       ;
extern const uint8_t _DALI2_ADDRESS39                       ;
extern const uint8_t _DALI2_ADDRESS40                       ;
extern const uint8_t _DALI2_ADDRESS41                       ;
extern const uint8_t _DALI2_ADDRESS42                       ;
extern const uint8_t _DALI2_ADDRESS43                       ;
extern const uint8_t _DALI2_ADDRESS44                       ;
extern const uint8_t _DALI2_ADDRESS45                       ;
extern const uint8_t _DALI2_ADDRESS46                       ;
extern const uint8_t _DALI2_ADDRESS47                       ;
extern const uint8_t _DALI2_ADDRESS48                       ;
extern const uint8_t _DALI2_ADDRESS49                       ;
extern const uint8_t _DALI2_ADDRESS50                       ;
extern const uint8_t _DALI2_ADDRESS51                       ;
extern const uint8_t _DALI2_ADDRESS52                       ;
extern const uint8_t _DALI2_ADDRESS53                       ;
extern const uint8_t _DALI2_ADDRESS54                       ;
extern const uint8_t _DALI2_ADDRESS55                       ;
extern const uint8_t _DALI2_ADDRESS56                       ;
extern const uint8_t _DALI2_ADDRESS57                       ;
extern const uint8_t _DALI2_ADDRESS58                       ;
extern const uint8_t _DALI2_ADDRESS59                       ;
extern const uint8_t _DALI2_ADDRESS60                       ;
extern const uint8_t _DALI2_ADDRESS61                       ;
extern const uint8_t _DALI2_ADDRESS62                       ;
extern const uint8_t _DALI2_ADDRESS63                       ;
extern const uint8_t _DALI2_ADDRESS64                       ;
                                                                       /** @} */
/** @defgroup DALI2_INDARC Indirect Arc Power Commands */              /** @{ */

extern const uint8_t _DALI2_OFF                             ;
extern const uint8_t _DALI2_UP                              ;
extern const uint8_t _DALI2_DOWN                            ;
extern const uint8_t _DALI2_STEP_UP                         ;
extern const uint8_t _DALI2_STEP_DOWN                       ;
extern const uint8_t _DALI2_RECALL_MAX_LEVEL                ;
extern const uint8_t _DALI2_RECALL_MIN_LEVEL                ;
extern const uint8_t _DALI2_STEP_DOWN_AND_OFF               ;
extern const uint8_t _DALI2_ON_AND_STEP_UP                  ;

extern const uint8_t _DALI2_GO_TO_SCENE01                   ;
extern const uint8_t _DALI2_GO_TO_SCENE02                   ;
extern const uint8_t _DALI2_GO_TO_SCENE03                   ;
extern const uint8_t _DALI2_GO_TO_SCENE04                   ;
extern const uint8_t _DALI2_GO_TO_SCENE05                   ;
extern const uint8_t _DALI2_GO_TO_SCENE06                   ;
extern const uint8_t _DALI2_GO_TO_SCENE07                   ;
extern const uint8_t _DALI2_GO_TO_SCENE08                   ;
extern const uint8_t _DALI2_GO_TO_SCENE09                   ;
extern const uint8_t _DALI2_GO_TO_SCENE10                   ;
extern const uint8_t _DALI2_GO_TO_SCENE11                   ;
extern const uint8_t _DALI2_GO_TO_SCENE12                   ;
extern const uint8_t _DALI2_GO_TO_SCENE13                   ;
extern const uint8_t _DALI2_GO_TO_SCENE14                   ;
extern const uint8_t _DALI2_GO_TO_SCENE15                   ;
extern const uint8_t _DALI2_GO_TO_SCENE16                   ;
                                                                       /** @} */
/** @defgroup DALI2_GENCFG General Configuration Commands */           /** @{ */

extern const uint8_t _DALI2_RESET                           ;
extern const uint8_t _DALI2_STORE_ACTUAL_LEVEL_IN_THE_DTR   ;
                                                                       /** @} */
/** @defgroup DALI2_ARCP Arc Power Parameter Settings */               /** @{ */

extern const uint8_t _DALI2_STORE_THE_DTR_AS_MAX_LEVEL                 ;
extern const uint8_t _DALI2_STORE_THE_DTR_AS_MIN_LEVEL                 ;
extern const uint8_t _DALI2_STORE_THE_DTR_AS_SYSTEM_FAILURE_LEVEL      ;
extern const uint8_t _DALI2_STORE_THE_DTR_AS_POWER_ON_LEVEL            ;
extern const uint8_t _DALI2_STORE_THE_DTR_AS_FADE_TIME                 ;
extern const uint8_t _DALI2_STORE_THE_DTR_AS_FADE_RATE                 ;

extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE01                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE02                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE03                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE04                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE05                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE06                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE07                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE08                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE09                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE10                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE11                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE12                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE13                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE14                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE15                    ;
extern const uint8_t _DALI2_STORE_THE_DTRAS_SCENE16                    ;
                                                                       /** @} */
/** @defgroup DALI2_SYSPARAM System Parameters Settings */             /** @{ */

extern const uint8_t _DALI2_REMOVE_FROM_SCENE01                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE02                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE03                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE04                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE05                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE06                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE07                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE08                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE09                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE10                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE11                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE12                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE13                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE14                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE15                        ;
extern const uint8_t _DALI2_REMOVE_FROM_SCENE16                        ;

extern const uint8_t _DALI2_ADD_TO_GROUP01                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP02                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP03                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP04                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP05                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP06                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP07                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP08                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP09                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP10                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP11                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP12                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP13                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP14                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP15                             ;
extern const uint8_t _DALI2_ADD_TO_GROUP16                             ;

extern const uint8_t _DALI2_REMOVE_FROM_GROUP01                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP02                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP03                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP04                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP05                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP06                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP07                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP08                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP09                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP10                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP11                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP12                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP13                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP14                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP15                        ;
extern const uint8_t _DALI2_REMOVE_FROM_GROUP16                        ;
extern const uint8_t _DALI2_STORE_DTR_AS_SHORT_ADDRESS                 ;
                                                                       /** @} */
/** @defgroup DALI2_STATINFO Status Information Commands */            /** @{ */

extern const uint8_t _DALI2_QUERY_STATUS                               ;
extern const uint8_t _DALI2_QUERY_BALLAST                              ;
extern const uint8_t _DALI2_QUERY_LAMP_FAILURE                         ;
extern const uint8_t _DALI2_QUERY_LAMP_POWER_ON                        ;
extern const uint8_t _DALI2_QUERY_LIMIT_ERROR                          ;
extern const uint8_t _DALI2_QUERY_RESET_STATE                          ;
extern const uint8_t _DALI2_QUERY_MISSING_SHORT_ADDRESS                ;
extern const uint8_t _DALI2_QUERY_VERSION_NUMBER                       ;
extern const uint8_t _DALI2_QUERY_CONTENT_DTR                          ;
extern const uint8_t _DALI2_QUERY_DEVICE_TYPE                          ;
extern const uint8_t _DALI2_QUERY_PHYSICAL_MINIMUM_LEVEL               ;
extern const uint8_t _DALI2_QUERY_POWER_FAILURE                        ;
                                                                       /** @} */
/** @defgroup DALI2_ARC Arc Power Parameter Settings */                /** @{ */

extern const uint8_t _DALI2_UERY_ACTUAL_LEVEL                         ;
extern const uint8_t _DALI2_UERY_MAX_LEVEL                            ;
extern const uint8_t _DALI2_UERY_MIN_LEVEL                            ;
extern const uint8_t _DALI2_UERY_POWER_ON_LEVEL                       ;
extern const uint8_t _DALI2_UERY_SYSTEM_FAILURE_LEVEL                 ;
extern const uint8_t _DALI2_UERY_FADE_TIME_FADE_RATE                  ;
                                                                       /** @} */
/** @defgroup DALI2_Q Queries Related To The System Settings */        /** @{ */

extern const uint8_t _DALI2_QUERY_SCENE_LEVEL01                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL02                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL03                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL04                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL05                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL06                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL07                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL08                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL09                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL10                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL11                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL12                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL13                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL14                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL15                        ;
extern const uint8_t _DALI2_QUERY_SCENE_LEVEL16                        ;
extern const uint8_t _DALI2_QUERY_GROUPS_0_7                           ;
extern const uint8_t _DALI2_QUERY_GROUPS_8_15                          ;
extern const uint8_t _DALI2_QUERY_RANDOM_ADDRESS_H                     ;
extern const uint8_t _DALI2_QUERY_RANDOM_ADDERSS_M                     ;
extern const uint8_t _DALI2_QUERY_RANDOM_ADDRESS_L                     ;
                                                                       /** @} */
/** @defgroup DALI2_SPEC Special Commands */                           /** @{ */

extern const uint8_t _DALI2_TERMINATE_H_BITS                           ;    
extern const uint8_t _DALI2_TERMINATE_L_BITS                           ;    
extern const uint8_t _DALI2_DTR                                        ;    
extern const uint8_t _DALI2_INITIALISE                                 ;    
extern const uint8_t _DALI2_INITIALISE_ALL_BALLAST_H                   ;
extern const uint8_t _DALI2_INITIALISE_ALL_BALLAST_L                   ;
extern const uint8_t _DALI2_INITIALISE_BALLAST_WITHOUT_SHORT_ADDR_H    ;
extern const uint8_t _DALI2_INITIALISE_BALLAST_WITHOUT_SHORT_ADDR_L    ;
extern const uint8_t _DALI2_RANDOMISE_H                                ;
extern const uint8_t _DALI2_RANDOMISE_L                                ;
extern const uint8_t _DALI2_COMPARE_H                                  ;
extern const uint8_t _DALI2_COMPARE_L                                  ;
extern const uint8_t _DALI2_WITHDRAW_H                                 ;
extern const uint8_t _DALI2_WITHDRAW_L                                 ;
extern const uint8_t _DALI2_SEARCHADDRH                                ;    
extern const uint8_t _DALI2_SEARCHADDRM                                ;    
extern const uint8_t _DALI2_SEARCHADDRL                                ;    
extern const uint8_t _DALI2_PROGRAM_SHORT_ADDRESS                      ;    
extern const uint8_t _DALI2_VERIFY_SHORT_ADDRESS                       ;    
extern const uint8_t _DALI2_QUERY_SHORT_ADDRESS_H                      ;    
extern const uint8_t _DALI2_QUERY_SHORT_ADDRESS_L                      ;
extern const uint8_t _DALI2_PHYSICAL_SELECTION_H                       ;    
extern const uint8_t _DALI2_PHYSICAL_SELECTION_L                       ;
extern const uint8_t _DALI2_ENABLE_STANDARD_DEVICE_H                   ;    
extern const uint8_t _DALI2_ENABLE_STANDARD_DEVICE_L                   ;
extern const uint8_t _DALI2_ENABLE_EMERGENCY_LIGHTS_H                  ;    
extern const uint8_t _DALI2_ENABLE_EMERGENCY_LIGHTS_L                  ;
extern const uint8_t _DALI2_ENABLE_HID_LAMPS_H                         ;    
extern const uint8_t _DALI2_ENABLE_HID_LAMPS_L                         ;
extern const uint8_t _DALI2_ENABLE_LOW_V_HALOGEN_LAMPS_H               ;    
extern const uint8_t _DALI2_ENABLE_LOW_V_HALOGEN_LAMPS_L               ;
extern const uint8_t _DALI2_ENABLE_DIM_INCANDESCENT_LAMPS_H            ;    
extern const uint8_t _DALI2_ENABLE_DIM_INCANDESCENT_LAMPS_L            ;
extern const uint8_t _DALI2_ENABLE_LED_MODULES_H                       ;    
extern const uint8_t _DALI2_ENABLE_LED_MODULES_L                       ;
                                                                       /** @} */
/** @defgroup DALI2_TYPES Types */                                     /** @{ */

typedef struct
{
  	uint8_t address;
  	uint8_t on;
  	uint8_t arcLevel;
  	uint8_t group0_7;
  	uint8_t group8_15;
  	uint8_t to_fade;

}T_dali2_lightObjectType;

typedef struct LightCommandStruct
{
  	uint8_t ballastAddress;
  	uint8_t command;
  	uint8_t typeOfCommand;
  	uint8_t followingType;

}T_dali2_lightCommandType;

                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DALI2_INIT Driver Initialization */                      /** @{ */

#ifdef   __DALI2_DRV_SPI__
void dali2_spiDriverInit(T_DALI2_P gpioObj, T_DALI2_P spiObj);
#endif
#ifdef   __DALI2_DRV_I2C__
void dali2_i2cDriverInit(T_DALI2_P gpioObj, T_DALI2_P i2cObj, uint8_t slave);
#endif
#ifdef   __DALI2_DRV_UART__
void dali2_uartDriverInit(T_DALI2_P gpioObj, T_DALI2_P uartObj);
#endif

void dali2_gpioDriverInit(T_DALI2_P gpioObj);
                                                                       /** @} */
/** @defgroup DALI2_FUNC Driver Functions */                           /** @{ */

/**
 * @brief DALI Inerrupt Service Routine
 *
 * @note
 * This function must be placed inside timer ISR whihc occurs every 104 us.
 */
void dali2_isr();

/**
 * @brief DALI master device initialization
 *
 * @note 
 * This function must be called after driver initialization and before any 
 * functions.
 */
void dali2_masterInit();

/**
 * @brief DALI master device status
 * 
 * @retval DALI state
 */
uint8_t dali2_masterStatus();

/**
 * @brief Send DALI command over DALI protocol
 * 
 * @param[in] balAddress - Address of the ballast (dimmer)
 * @param[in] cmd        - Command which is going to be sent
 * @param[in] cmdType    - Type of address ( BROADCAST_DIRECT / BROADCAST_CMD / SHORT_ADDRESS / GROUP_ADDRESS )
 * @param[in] folType    - Status of the last bit in address byte (FOLLOWING_DIRECT_ARC_POWER_LVL / FOLLOWING_COMMAND)
 */
void dali2_sendCmd(const uint8_t balAddress, const uint8_t cmd, const uint8_t cmdType, const uint8_t folType);

/*
 * @brief Encode and write received data. 
 * 
 * @retval Ballast answer
 *
 * YES  : 1111 1111
 * NO   : 0
 * 8bit : XXXX XXXX - 8bit value
 *
 * Check in _rxBuffer.
 */
uint8_t dali2_getBallastResponse();
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_DALI_2_STM.c
    @example Click_DALI_2_TIVA.c
    @example Click_DALI_2_CEC.c
    @example Click_DALI_2_KINETIS.c
    @example Click_DALI_2_MSP.c
    @example Click_DALI_2_PIC.c
    @example Click_DALI_2_PIC32.c
    @example Click_DALI_2_DSPIC.c
    @example Click_DALI_2_AVR.c
    @example Click_DALI_2_FT90x.c
    @example Click_DALI_2_STM.mbas
    @example Click_DALI_2_TIVA.mbas
    @example Click_DALI_2_CEC.mbas
    @example Click_DALI_2_KINETIS.mbas
    @example Click_DALI_2_MSP.mbas
    @example Click_DALI_2_PIC.mbas
    @example Click_DALI_2_PIC32.mbas
    @example Click_DALI_2_DSPIC.mbas
    @example Click_DALI_2_AVR.mbas
    @example Click_DALI_2_FT90x.mbas
    @example Click_DALI_2_STM.mpas
    @example Click_DALI_2_TIVA.mpas
    @example Click_DALI_2_CEC.mpas
    @example Click_DALI_2_KINETIS.mpas
    @example Click_DALI_2_MSP.mpas
    @example Click_DALI_2_PIC.mpas
    @example Click_DALI_2_PIC32.mpas
    @example Click_DALI_2_DSPIC.mpas
    @example Click_DALI_2_AVR.mpas
    @example Click_DALI_2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __dali2_driver.h

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