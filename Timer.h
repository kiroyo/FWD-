/*
 * Timer.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Kiro Yousri
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Std_Types.h"

/*******************************************************************************
 *                         Needed macro definitions                            *
 *******************************************************************************/

/* Configurations default index in case of null pointer */

#define CHANNEL_CONFIG_SET_DEFAULT_INDEX        (0U)
#define DRIVER_CONFIGURATION_DEFAULT_INDEX      (0U)


/* Define channel width */

#define TIMER_HALF_WIDTH                        (65535UL)                 /* Normal timer channel (32-bits) half width */
#define WTIMER_HALF_WIDTH                       (4294967295UL)            /* Wide timer channel (64-bits) half width */
#define WTIMER_FULL_WIDTH                       (18446744073709551615ULL)  /* Wide timer channel (64-bits) full width */


/* Channel base addresses */
#define  TIMER0_BASE_ADDRESS                    (0x40030000U)
#define  WTIMER2_BASE_ADRRESS                   (0x4004C000U)
#define  WTIMER5_BASE_ADRRESS                   (0x4004F000U)

/* Maximum number of channels */
#define GPT_CHANNEL_CONFIGURATION_MAX_SIZE      (22U)

/* Number of 16/32-bits timer channel ID's */
#define GPT_NORMAL_CHANNELS_MAX_ID              (11U)

/* Normal channel maximum pre-scaler value*/
#define GPT_NORMAL_CHANNEL_MAX_PRE_SCALER       (255U)

/* Number of 32/64-bits timer channel ID's */
#define GPT_WIDE_CHANNELS_MAX_ID                (21U)

/* Wide channel maximum pre-scaler value*/
#define GPT_WIDE_CHANNEL_MAX_PRE_SCALER         (65535U)

#define MASK_16_BITS                            (0XFFFFU)
#define MASK_24_BITS                            (0XFFFFFFU)
#define MASK_32_BITS                            (0XFFFFFFFFU)

#define US_FREQ                                 (1000000U)
#define US_TO_100_US                            (100U)

#define NEXT_ITERATION                          (1U)

#define VARIABLE_INIT_VALUE                     (0U)

#define CHECK_TIMER_HALF                        (2U)
#define TIMER_HALF_A                            (0U)

#define TIMER_B_CONFIG_MASK                     (8U)

#define ILR_RESET_VALUE                         (0xFFFFFFFFU)

#define EXPIRED_CHANNEL_TIMER_VALUE             (0U)

#define TIMER_TICKS_0                           (0U)

#define PREDEFINED_TIMER_RESET_VALUE            (0U)



/*
 * Service name: Gpt_Init
 * SWS_Item: SWS_Gpt_00280
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Description: Initialises the GPT driver.
 */
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);

/*
 * Service name: Gpt_DeInit
 * SWS_Item: SWS_Gpt_00281
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Description: Deinitializes the GPT driver.
 */

#if (GPT_CONFIGURATION_OF_OPT_API_SERVICES_GPT_DEINIT_API == 1)
void Gpt_DeInit(void);
#endif

/*
 * Service name: Gpt_StartTimer
 * SWS_Item: SWS_Gpt_00284
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant (but not for the same timer channel)
 * Description: Starts a timer channel.
 */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/*
 * Service name: Gpt_StopTimer
 * SWS_Item: SWS_Gpt_00285
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant (but not for the same timer channel)
 * Description: Stops a timer channel.
 */
void Gpt_StopTimer(Gpt_ChannelType Channel);


#endif /* TIMER_H_ */
