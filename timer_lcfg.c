#include "Gpt_LCfg.h"



/******************************************************************************************
*****************************GptDriverConfiguration Container*****************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_GptDriverConfiguration_size = GPT_DRIVER_CONFIGURATION_SIZE;

/* Array Of Structures Linking Configurations*/
GptDriverConfiguration_s GptDriverConfiguration[GPT_DRIVER_CONFIGURATION_SIZE] =
{
	{	/*Instance_0*/
		.GptPredefTimer100us32bitEnable = FALSE,
		.GptPredefTimer1usEnablingGrade = GPT_PREDEF_TIMER_1US_DISABLED,
		.GptReportWakeupSource = FALSE,
		.GptClockReferencePoint_startingIndex = GPT_CLOCK_REFERENCE_POINT_0_STARTING_INDEX,
		.GptClockReferencePoint_numberOfInstances = GPT_CLOCK_REFERENCE_POINT_0_NUMBER_INSTANCES
	}
};

/******************************************************************************************
*****************************GptClockReferencePoint Container*****************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_GptClockReferencePoint_size = GPT_CLOCK_REFERENCE_POINT_SIZE;

/* Array Of Structures Linking Configurations*/
GptClockReferencePoint_s GptClockReferencePoint[GPT_CLOCK_REFERENCE_POINT_SIZE] =
{
	{	/*Instance_0*/
		.McuClockReferencePointFrequency = 16000000
	}
};


/******************************************************************************************
*******************************GptChannelConfigSet Container*******************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_GptChannelConfigSet_size = GPT_CHANNEL_CONFIG_SET_SIZE;

/* Array Of Structures Linking Configurations*/
GptChannelConfigSet_s GptChannelConfigSet[GPT_CHANNEL_CONFIG_SET_SIZE] =
{
	{	/*Instance_0*/
		.GptChannelConfiguration_startingIndex = GPT_CHANNEL_CONFIGURATION_0_STARTING_INDEX,
		.GptChannelConfiguration_numberOfInstances = GPT_CHANNEL_CONFIGURATION_0_NUMBER_INSTANCES
	}
};


/******************************************************************************************
*****************************GptChannelConfiguration Container*****************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_GptChannelConfiguration_size = GPT_CHANNEL_CONFIGURATION_SIZE;

/* Array Of Structures Linking Configurations*/
GptChannelConfiguration_s GptChannelConfiguration[GPT_CHANNEL_CONFIGURATION_SIZE] =
{
	{	/*Instance_0*/
		.GptChannelId = 1,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
		.GptChannelTickFrequency = 8000000,
		.GptChannelTickValueMax = 65535,
		.GptEnableWakeup = FALSE,
		.GptNotification = TIMER0B_Handler,
		.GptChannelClkSrcRef_type = GPT_CLOCK_REFERENCE_POINT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = &GptChannelClkSrcRef_GptClockReferencePoint[0],
		.GptChannelClkSrcRef_numberOfElements = 1
	},
	{	/*Instance_1*/
		.GptChannelId = 0,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
		.GptChannelTickFrequency = 8000000,
		.GptChannelTickValueMax = 65535,
		.GptEnableWakeup = FALSE,
		.GptNotification = TIMER0A_Handler,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_2*/
		.GptChannelId = 2,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 4294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = TIMER1A_Handler,
		.GptChannelClkSrcRef_type = GPT_CLOCK_REFERENCE_POINT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = &GptChannelClkSrcRef_GptClockReferencePoint[1],
		.GptChannelClkSrcRef_numberOfElements = 1
	},
	{	/*Instance_3*/
		.GptChannelId = 5,
		.GptChannelMode = GPT_CH_MODE_ONESHOT,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 65535,
		.GptEnableWakeup = FALSE,
		.GptNotification = DEFAULT_PARAMETER_FUNCTION_NAME_VALUE,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_4*/
		.GptChannelId = 4,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 4294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = DEFAULT_PARAMETER_FUNCTION_NAME_VALUE,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_5*/
		.GptChannelId = 7,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 4294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = DEFAULT_PARAMETER_FUNCTION_NAME_VALUE,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_6*/
		.GptChannelId = 13,
		.GptChannelMode = GPT_CH_MODE_ONESHOT,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 4294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = WTIMER0B_Handler,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_7*/
		.GptChannelId = 12,
		.GptChannelMode = GPT_CH_MODE_ONESHOT,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 4294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = WTIMER0A_Handler,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_8*/
		.GptChannelId = 14,
		.GptChannelMode = GPT_CH_MODE_ONESHOT,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 40294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = WTIMER1A_Handler,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_9*/
		.GptChannelId = 17,
		.GptChannelMode = GPT_CH_MODE_ONESHOT,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 4294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = DEFAULT_PARAMETER_FUNCTION_NAME_VALUE,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	},
	{	/*Instance_10*/
		.GptChannelId = 19,
		.GptChannelMode = GPT_CH_MODE_ONESHOT,
		.GptChannelTickFrequency = 16000000,
		.GptChannelTickValueMax = 40294967295,
		.GptEnableWakeup = FALSE,
		.GptNotification = DEFAULT_PARAMETER_FUNCTION_NAME_VALUE,
		.GptChannelClkSrcRef_type = DEFAULT_REFERENCE_TYPE,
		.GptChannelClkSrcRef_ptr = DEFAULT_REFERENCE_VALUE,
		.GptChannelClkSrcRef_numberOfElements = DEFAULT_REFERENCE_NUMBER_INSTANCES
	}
};



/*
* GptChannelConfiguration Container
*	GptChannelClkSrcRef Reference 
*		To GptClockReferencePoint Container
*			Ids Map Array
*/
uint8 GptChannelClkSrcRef_GptClockReferencePoint[GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_SIZE]=
{
	GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_VALUE_0,
	GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_VALUE_1
};
