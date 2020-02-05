/***************************************************************************
*    <:copyright-BRCM:2000:proprietary:standard
*    
*       Copyright (c) 2000 Broadcom 
*       All Rights Reserved
*    
*     This program is the proprietary software of Broadcom and/or its
*     licensors, and may only be used, duplicated, modified or distributed pursuant
*     to the terms and conditions of a separate, written license agreement executed
*     between you and Broadcom (an "Authorized License").  Except as set forth in
*     an Authorized License, Broadcom grants no license (express or implied), right
*     to use, or waiver of any kind with respect to the Software, and Broadcom
*     expressly reserves all rights in and to the Software and all intellectual
*     property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
*     NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
*     BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
*    
*     Except as expressly set forth in the Authorized License,
*    
*     1. This program, including its structure, sequence and organization,
*        constitutes the valuable trade secrets of Broadcom, and you shall use
*        all reasonable efforts to protect the confidentiality thereof, and to
*        use this information only in connection with your use of Broadcom
*        integrated circuit products.
*    
*     2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
*        AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
*        WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
*        RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
*        ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
*        FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
*        COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
*        TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
*        PERFORMANCE OF THE SOFTWARE.
*    
*     3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
*        ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
*        INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
*        WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
*        IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
*        OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
*        SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
*        SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
*        LIMITED REMEDY.
*    :>
****************************************************************************
*
*    Filename: hdspToneProfile.h
*
****************************************************************************
*    Description:
*
*     This file contains the public declarations for tone generation profiles
*
****************************************************************************/

#ifndef HDSP_TONE_PROFILE_H
#define HDSP_TONE_PROFILE_H

/* ---- Include Files ---------------------------------------------------- */

#include <env.h>
#include <bcm_country.h>
#include <hdspCfg.h>
#include <hapi_pte.h>
#include <hdspTone.h>


/* ---- Constants and Types ---------------------------------------------- */

#define HDSP_TONE_PROFILE_PLACE_HOLDER             \
{ "PLACE-HOLDER", 0,                               \
   {                                               \
      /* Frequency control */                      \
      HAPI_PTE_MKFREQCTRL(0, HAPI_PTE_SINEWAVE),   \
      /* 4 FREQUENCIES */                          \
      {0, 0, 0, 0},/* nr. of AMPLITUDES */         \
      {0, 0, 0, 0},                                \
      /* No Loop Counter used */                   \
      0,                                           \
      /* timeout - not used */                     \
      0,                                           \
      /* number of states used */                  \
      0,                                           \
                                                   \
      /* 16 STATES */                              \
      {                                            \
         /* State 0 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 1 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 2 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 3 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 4 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 5 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 6 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 7 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 8 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 9 - Not Used */                  \
         {0,0,0,0},                                \
         /* State 10 - Not Used */                 \
         {0,0,0,0},                                \
         /* State 11 - Not Used */                 \
         {0,0,0,0},                                \
         /* State 12 - Not Used */                 \
         {0,0,0,0},                                \
         /* State 13 - Not Used */                 \
         {0,0,0,0},                                \
         /* State 14 - Not Used */                 \
         {0,0,0,0},                                \
         /* State 15 - Not Used */                 \
         {0,0,0,0}                                 \
      }                                            \
   }                                               \
}

#define HDSP_FREQGROUP_UNUSED    \
{                                \
   0,                            \
   {0, 0, 0, 0},                 \
   {0, 0, 0, 0},                 \
   0,                            \
   0,                            \
   {                             \
      {0,0,0,0},                 \
      {0,0,0,0}                  \
   }                             \
}

/* Used as a placeholder pulse time in the tone profile to be
** replaced by a provisioned call waiting delay value */
#define HDSP_DELAY_PLACEHOLDER (0xFFFE)

/* Default time to wait in milliseconds for DTMFD ack signal
** from the customers telephone/handset */
#define HDSP_DTMF_ACK_DELAY 200


/* Used for SAS tone loops that are required to continuously repeat. */
#define HDSP_LARGE_LOOP       65534

/* Custom tone structure */
typedef struct
{
   const char    *name;
   HAPI_PTE_CP_PROFILE  profile;
} HDSP_CUSTOM_TONE;


/* ---- Variable Externs ------------------------------------------------- */

extern const HDSP_CUSTOM_TONE gCASTones[];


#if VRG_COUNTRY_CFG_CYPRUS
   extern const HDSP_CUSTOM_TONE gHdspToneProfile_CYPRUS[];
#else
   #define gHdspToneProfile_CYPRUS ((const HDSP_CUSTOM_TONE*) NULL)
#endif


/* ---- Function Prototypes ---------------------------------------------- */


#endif  /* HDSP_TONE_PROFILE_H  */
