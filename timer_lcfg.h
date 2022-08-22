#ifndef GPT_LCFG_H
#define GPT_LCFG_H



/******************************************************************************************
****************************************Gpt Module****************************************
*********************************Link-Time Configurations*********************************
******************************************************************************************/


/*
* Gpt_LCfg_H
* 	File's Includes
*/
#include <Gpt_Types.h>
#include "Gpt_NotificationsCbk.h"


/******************************************************************************************
***************************************Gpt Module's***************************************
****************************************Structures****************************************
******************************************************************************************/


/*
* GptDriverConfiguration Container
*  Macro Configurations
*/
#define GPT_DRIVER_CONFIGURATION_SIZE                         (1U)

/* Container Instance 0*/
#define GPT_DRIVER_CONFIGURATION_ID_0                         (0U)
#define GPT_CLOCK_REFERENCE_POINT_0_STARTING_INDEX            (0U)
#define GPT_CLOCK_REFERENCE_POINT_0_NUMBER_INSTANCES          (1U)


/*
* GptClockReferencePoint Container
*  Macro Configurations
*/
#define GPT_CLOCK_REFERENCE_POINT_SIZE                        (1U)

/* Container Instance 0*/
#define GPT_CLOCK_REFERENCE_POINT_ID_0                        (0U)


/*
* GptChannelConfigSet Container
*  Macro Configurations
*/
#define GPT_CHANNEL_CONFIG_SET_SIZE                           (1U)

/* Container Instance 0*/
#define GPT_CHANNEL_CONFIG_SET_ID_0                           (0U)
#define GPT_CHANNEL_CONFIGURATION_0_STARTING_INDEX            (0U)
#define GPT_CHANNEL_CONFIGURATION_0_NUMBER_INSTANCES          (11U)


/*
* GptChannelConfiguration Container
*  Macro Configurations
*/
#define GPT_CHANNEL_CONFIGURATION_SIZE                        (11U)

/* Container Instance 0*/
#define GPT_CHANNEL_CONFIGURATION_ID_0                        (0U)
/* Container Instance 1*/
#define GPT_CHANNEL_CONFIGURATION_ID_1                        (1U)
/* Container Instance 2*/
#define GPT_CHANNEL_CONFIGURATION_ID_2                        (2U)
/* Container Instance 3*/
#define GPT_CHANNEL_CONFIGURATION_ID_3                        (3U)
/* Container Instance 4*/
#define GPT_CHANNEL_CONFIGURATION_ID_4                        (4U)
/* Container Instance 5*/
#define GPT_CHANNEL_CONFIGURATION_ID_5                        (5U)
/* Container Instance 6*/
#define GPT_CHANNEL_CONFIGURATION_ID_6                        (6U)
/* Container Instance 7*/
#define GPT_CHANNEL_CONFIGURATION_ID_7                        (7U)
/* Container Instance 8*/
#define GPT_CHANNEL_CONFIGURATION_ID_8                        (8U)
/* Container Instance 9*/
#define GPT_CHANNEL_CONFIGURATION_ID_9                        (9U)
/* Container Instance 10*/
#define GPT_CHANNEL_CONFIGURATION_ID_10                       (10U)




/******************************************************************************************
***************************************Gpt Module's***************************************
**************************************Ids Map Arrays**************************************
***********************************Macro Configurations***********************************
******************************************************************************************/


/*
* GptChannelConfiguration Container
*	GptChannelClkSrcRef Reference 
*		To GptClockReferencePoint Container
*			Ids Map Array
*/
#define GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_SIZE             (2U)
#define GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_VALUE_0          (0U)
#define GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_VALUE_1          (0U)





/******************************************************************************************
***************************************Gpt Module's***************************************
*************************************Structures Arrays*************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* GptDriverConfiguration Container
* 	Extern Array Of Structures
*/
extern GptDriverConfiguration_s GptDriverConfiguration[GPT_DRIVER_CONFIGURATION_SIZE];

/*
* GptClockReferencePoint Container
* 	Extern Array Of Structures
*/
extern GptClockReferencePoint_s GptClockReferencePoint[GPT_CLOCK_REFERENCE_POINT_SIZE];

/*
* GptChannelConfigSet Container
* 	Extern Array Of Structures
*/
extern GptChannelConfigSet_s GptChannelConfigSet[GPT_CHANNEL_CONFIG_SET_SIZE];

/*
* GptChannelConfiguration Container
* 	Extern Array Of Structures
*/
extern GptChannelConfiguration_s GptChannelConfiguration[GPT_CHANNEL_CONFIGURATION_SIZE];




/******************************************************************************************
***************************************Gpt Module's***************************************
*************************************Structures Sizes*************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* GptDriverConfiguration Container
* 	Extern Size Variable
*/
extern uint8 lcfg_GptDriverConfiguration_size;

/*
* GptClockReferencePoint Container
* 	Extern Size Variable
*/
extern uint8 lcfg_GptClockReferencePoint_size;

/*
* GptChannelConfigSet Container
* 	Extern Size Variable
*/
extern uint8 lcfg_GptChannelConfigSet_size;

/*
* GptChannelConfiguration Container
* 	Extern Size Variable
*/
extern uint8 lcfg_GptChannelConfiguration_size;




/******************************************************************************************
***************************************Gpt Module's***************************************
**************************************Ids Map Arrays**************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* GptChannelConfiguration Container
*	GptChannelClkSrcRef Reference 
*		To GptClockReferencePoint Container
*			Ids Map Array
*/
extern uint8 GptChannelClkSrcRef_GptClockReferencePoint[GPT_CHANNEL_CLK_SRC_REF_GPT_CLOCK_REFERENCE_POINT_SIZE];




/******************************************************************************************
***************************************Gpt Module's***************************************
**************************************Reference Types**************************************
******************************************************************************************/

		/* Any re-defined reference type will be automatically commented*/



/*
* Reference: GptWakeupSourceRef
* 	Possible Types
*/
#define ECU_M_WAKEUP_SOURCE_REFERENCE_TYPE                (1U)

/*
* Reference: GptChannelClkSrcRef
* 	Possible Types
*/
#define GPT_CLOCK_REFERENCE_POINT_REFERENCE_TYPE          (2U)

/*
* Reference: GptClockReference
* 	Possible Types
*/
#define MCU_CLOCK_REFERENCE_POINT_REFERENCE_TYPE          (3U)




/******************************************************************************************
***************************************Gpt Module's***************************************
***************************************Enumerations***************************************
******************************************************************************************/
#if 0



/*
* Type Definition
* 	Enumeration: GptChannelMode
*/
typedef enum
{

	GPT_CH_MODE_CONTINUOUS,
	GPT_CH_MODE_ONESHOT

}GptChannelMode_e;


/*
* Type Definition
* 	Enumeration: GptPredefTimer1usEnablingGrade
*/
typedef enum
{

	GPT_PREDEF_TIMER_1US_16BIT_ENABLED,
	GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED,
	GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED,
	GPT_PREDEF_TIMER_1US_DISABLED

}GptPredefTimer1usEnablingGrade_e;


#endif


/******************************************************************************************
***************************************Gpt Module's***************************************
**************************************Default Values**************************************
******************************************************************************************/

#define DEFAULT_PARAMETER_8BIT_VALUE            (255U)
#define DEFAULT_PARAMETER_16BIT_VALUE           (65535U)
#define DEFAULT_PARAMETER_32BIT_VALUE           (4294967295U)
#define DEFAULT_PARAMETER_64BIT_VALUE           (18446744073709551615U)
#define DEFAULT_PARAMETER_BOOLEAN_VALUE         (0U)
#define DEFAULT_PARAMETER_ENUM_VALUE            (4U)
#define DEFAULT_PARAMETER_STRING_VALUE          ("\0")
#define DEFAULT_REFERENCE_TYPE                  (0U)
#define DEFAULT_REFERENCE_NUMBER_INSTANCES      (0U)
#define DEFAULT_REFERENCE_VALUE                 ((void *)0)
#define DEFAULT_PARAMETER_FUNCTION_NAME_VALUE   ((void *)0)
#define DEFAULT_CONTAINER_TYPE                  (0U)
#define DEFAULT_CONTAINER_STARTING_VALUE        (0U)
#define DEFAULT_CONTAINER_NUMBER_INSTANCES      (0U)
#define FALSE                                   (0U)
#define TRUE                                    (1U)




#endif
