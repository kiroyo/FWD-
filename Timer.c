/*
 * Timer.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Kiro Yousri
 */
#include"Timer.h"

/*
 * Service name: Gpt_Init
 * SWS_Item: SWS_Gpt_00280
 * SRS_Item: (SRS_BSW_00404, SRS_BSW_00405, SRS_BSW_00438, SRS_BSW_00101, SRS_BSW_00358, SRS_BSW_00414, SRS_SPAL_12057)
 * Service ID: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Description: Initialises the GPT driver.
 *
 */

void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{

    if(Gpt_State == GPT_INITALIZED)
    {
        /*
         * SWS_Gpt_00309: A re-initialization of the Gpt driver by executing the Gpt_Init function
         *  requires a de-initialization before by executing a Gpt_DeInit.
         */
#if (GPT_DRIVER_CONFIGURATION_GPT_DEV_ERROR_DETECT == STD_ON)

        /* SWS_Gpt_00307 */

        Det_ReportError(MODULE_ID, INSTANCE_ID, GPT_INIT_SERVICE_ID,GPT_E_ALREADY_INITIALIZED);
#endif
    }
    else
    {
        /* Set state of timer module to initialized state */
        Gpt_State = GPT_INITALIZED;

        /* SWS_Gpt_00339: Set the operation mode of the GPT driver to "normal mode" */
        Gpt_Mode = GPT_MODE_NORMAL;

        if (ConfigPtr == NULL_PTR)
        {
            ChannelConfigSet_Index = CHANNEL_CONFIG_SET_DEFAULT_INDEX;
            DriverConfiguration_Index = DRIVER_CONFIGURATION_DEFAULT_INDEX;
        }
        else
        {
            /* To save index of GptChannelConfigSet container passed to Gpt_Init API to use it in other API's*/
            ChannelConfigSet_Index = ConfigPtr->GptChannelConfigSet_startingIndex;

            /* To save index of GptDriverConfiguration container passed to Gpt_Init API to use it in other API's*/
            DriverConfiguration_Index = ConfigPtr->GptDriverConfiguration_startingIndex;
        }


        uint32 Base_Address = VARIABLE_INIT_VALUE; /* To save base address of the channel */



        uint8 iteration = VARIABLE_INIT_VALUE;


        /*
         * Loop on GptChannelConfiguration[iteration].GptChannelId's to save in GptChannelSetting which
         * micro-controller timer channels are configured to operate by the user and save the index of
         * their corresponding configuration
         */

        for (iteration = GptChannelConfigSet[ChannelConfigSet_Index].GptChannelConfiguration_startingIndex;
             iteration < (GptChannelConfigSet[ChannelConfigSet_Index].GptChannelConfiguration_startingIndex
                     +GptChannelConfigSet[ChannelConfigSet_Index].GptChannelConfiguration_numberOfInstances);
             iteration++)
        {
            GptChannelSetting[GptChannelConfiguration[iteration].GptChannelId].Gpt_ChannelConfigState = CHANNEL_CONFIG;
            GptChannelSetting[GptChannelConfiguration[iteration].GptChannelId].Gpt_ChannelConfigIndex = iteration;
        }


        /*
         * Loop on all micro-controller channels and configure only the configured one's
         * in the GptChannelConfiguration sub-container
         */

        for (iteration = VARIABLE_INIT_VALUE; iteration < GPT_CHANNEL_CONFIGURATION_MAX_SIZE; iteration++)
        {

            /* SWS_Gpt_00068 : Gpt_Init initialize the configured resources. Resources that are not configured in the configuration file won't change */

            if (GptChannelSetting[iteration].Gpt_ChannelConfigState == CHANNEL_CONFIG) /* Check if this channel is configured */
            {
                Base_Address = Gpt_ChannelBaseAddress(iteration); /* Get base address of timer channel */
                Gpt_ChannelState[iteration] = CHANNEL_INIT; /* Set state of each configured channel to initialized state */

                /* Copy notification address to Gpt_Notifications array of pointers to functions in order to be called when Notifications are enabled*/
                Gpt_Notifications[iteration] = GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptNotification ;

                if (iteration <= GPT_NORMAL_CHANNELS_MAX_ID) /* Check whether the channel is normal or wide timer channel (32 or 64 bits) */
                {
                    GptChannelSetting[iteration].Gpt_TimerHalfWidth = TIMER_HALF_WIDTH;
                }
                else
                {
                    GptChannelSetting[iteration].Gpt_TimerHalfWidth = WTIMER_HALF_WIDTH;
                }


                /*
                 * Check if the id is for Timer A or Timer B in each timer channel, even id's are
                 * Timer A which can be configured in full width or half width mode, odd id's are
                 * Timer B which can only be configured in half width mode, in case timer A is configured as half width
                 * or not configured at all, if Timer A is configured in Full width mode, Timer B configuration is
                 * discarded and it isn't configured
                 */

                if (iteration % CHECK_TIMER_HALF == TIMER_HALF_A) /* Check if ID is for timer A or timer B, even for timer A and odd for timer B */
                {
                    TimerIntDisable(Base_Address, TIMER_A); /* Disable notification of specified channel */
                    GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelNotificationState = NOTIFICATION_DISABLED; /* Save state of notification of each configured channel */

                    /* Check if Timer A is configured in Full width mode*/
                    if (GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelTickValueMax
                            > GptChannelSetting[iteration].Gpt_TimerHalfWidth)
                    {
                        TimerConfigure( Base_Address, (GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelMode));

                        /*
                         * TimerConfigure Tivaware API automatically sets PWM and Match interrupts bits in TAMR and TBMR timer registers
                         *  , so they must be cleared again using CLEAR_BITS macro
                         */
                        CLEAR_BITS((Base_Address + TIMER_O_TAMR), (TIMER_TAMR_TAPWMIE|TIMER_TAMR_TAMIE));
                        CLEAR_BITS((Base_Address + TIMER_O_TBMR), (TIMER_TBMR_TBPWMIE|TIMER_TBMR_TBMIE));
                        GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigState = CHANNEL_NOT_CONFIG;
                    }
                    else
                    {
                        /*
                         * Check if Timer B is configured and its maximum tick value is suitable for half width timer
                         */
                        if ((GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigState == CHANNEL_CONFIG) &&
                            (GptChannelConfiguration[GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigIndex].GptChannelTickValueMax <= GptChannelSetting[iteration].Gpt_TimerHalfWidth))
                        {
                            TimerIntDisable(Base_Address, TIMER_B); /* Disable notification of specified channel */
                            GptChannelConfiguration[GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigIndex].GptChannelNotificationState = NOTIFICATION_DISABLED; /* Save state of notification of each configured channel */
                            Gpt_ChannelState[iteration + NEXT_ITERATION] = CHANNEL_INIT; /* Set state of each configured channel to initialized state */

                            /* Copy notification address to Gpt_Notifications array of pointers to functions in order to be called when Notifications are enabled*/
                            Gpt_Notifications[iteration + NEXT_ITERATION] = GptChannelConfiguration[GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigIndex].GptNotification ;

                            TimerConfigure( Base_Address, TIMER_CFG_SPLIT_PAIR
                                            | GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelMode
                                            | (GptChannelConfiguration[GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigIndex].GptChannelMode << 8));

                            /*
                             * TimerConfigure Tivaware API automatically sets PWM and Match interrupts bits in TAMR and TBMR timer registers
                             *  , so they must be cleared again using CLEAR_BITS macro
                             */
                            CLEAR_BITS((Base_Address + TIMER_O_TAMR), (TIMER_TAMR_TAPWMIE|TIMER_TAMR_TAMIE));
                            CLEAR_BITS((Base_Address + TIMER_O_TBMR), (TIMER_TBMR_TBPWMIE|TIMER_TBMR_TBMIE));
                            Gpt_ConfigurePrescale(Base_Address, iteration + NEXT_ITERATION,TIMER_B);
                        }
                        else
                        {
                            /* Configure timer A only */
                            Gpt_HalfTimerConfigure( Base_Address, TIMER_CFG_SPLIT_PAIR
                                            | (GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelMode), TIMER_A);
                            GptChannelSetting[iteration + NEXT_ITERATION].Gpt_ChannelConfigState = CHANNEL_NOT_CONFIG;

                        }
                        Gpt_ConfigurePrescale(Base_Address,iteration,TIMER_A);
                    }
                    iteration++; /* Skip next odd iteration as it has been already configured if it's meant to be */
                }
                else
                {
                    /* Configure timer B only */
                    if (GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelTickValueMax
                            <= GptChannelSetting[iteration].Gpt_TimerHalfWidth)
                    {
                        TimerIntDisable( Base_Address, TIMER_B); /* Disable notification of specified channel */
                        GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelNotificationState = NOTIFICATION_DISABLED; /* Save state of notification of each configured channel */
                        Gpt_HalfTimerConfigure( Base_Address, TIMER_CFG_SPLIT_PAIR | ((GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelMode) << TIMER_B_CONFIG_MASK), TIMER_B);
                        Gpt_ConfigurePrescale(Base_Address,iteration,TIMER_B);
                    }

                }
            }
        }


        /*
         * Configure predefined timers, all of them will use wide timer 5, it will be configured in 64 bits mode,
         * in order to make use of the full width and virtually pre-scaling the clock to achieve predefined timers tick
         * frequency, 1 microsecond 32-bit predefined timer is available at full range (32-bit) at any clock,
         * 100 microsecond 32-bit predefined timer is available at full range (32-bit) at clock up to 42.5 MHz,
         * at any higher clock the range equals full range divided by (Clock/42.5 MHz), for example if clock is 80 MHz
         * then range equals to approximately 31-bits which corresponds to 248 Days.
         */

        /* Start of configuring predefined timers */


        /* Check if any of the predefined timers is enabled */
        if ((GptDriverConfiguration[DriverConfiguration_Index].GptPredefTimer1usEnablingGrade != GPT_PREDEF_TIMER_1US_DISABLED)
                || (GptDriverConfiguration[DriverConfiguration_Index].GptPredefTimer100us32bitEnable == TRUE))
        {
            TimerConfigure( WTIMER5_BASE_ADRRESS, TIMER_CFG_PERIODIC_UP);

            /*
             * TimerConfigure Tivaware API automatically sets PWM and Match interrupts bits in TAMR and TBMR timer registers
             *  , so they must be cleared again using CLEAR_BITS macro
             */

            CLEAR_BITS((WTIMER5_BASE_ADRRESS + TIMER_O_TAMR),(TIMER_TAMR_TAPWMIE|TIMER_TAMR_TAMIE));
            CLEAR_BITS((WTIMER5_BASE_ADRRESS + TIMER_O_TBMR),(TIMER_TBMR_TBPWMIE|TIMER_TBMR_TBMIE));

            HWREG(WTIMER5_BASE_ADRRESS + TIMER_O_IMR) = 0; /* Disable all interrupts of this timer */
            TimerLoadSet64(WTIMER5_BASE_ADRRESS, WTIMER_FULL_WIDTH); /* Make timer timeout at maximum value (64-bits) */
            SET_BITS((WTIMER5_BASE_ADRRESS + TIMER_O_CTL), TIMER_CTL_TAEN); /* Start pre-defined timers */
            TimerControlStall(WTIMER5_BASE_ADRRESS, TIMER_A, TRUE); /* To stop timer while debugging */

        }

        /* End of configuring predefined timers */
    }

}


/*
 * Service name: Gpt_DeInit
 * SWS_Item: SWS_Gpt_00281
 * SRS_Item: (SRS_BSW_00336, SRS_SPAL_12163, SRS_Gpt_12116)
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Description: Deinitializes the GPT driver.
 */


/* SWS_Gpt_00194 */
/*The function is pre-compile time configurable On/Off by the configuration parameter: GptDeInitApi */

#if (GPT_CONFIGURATION_OF_OPT_API_SERVICES_GPT_DEINIT_API == STD_ON)

void Gpt_DeInit(void)
{


    if (Gpt_State == GPT_UNINITALIZED)
    {
#if (GPT_DRIVER_CONFIGURATION_GPT_DEV_ERROR_DETECT == STD_ON)

        /* SWS_Gpt_00210 */

        Det_ReportError(MODULE_ID, INSTANCE_ID, GPT_DE_INIT_SERVICE_ID,GPT_E_UNINIT);
#endif
    }
    else
    {
        uint8 iteration = VARIABLE_INIT_VALUE;
        Gpt_ChannelState_e ChannelState_Flag = CHANNEL_INIT; /*Flag to save if any channel is running */

        /*
         * Check if there is any running channel and report runtime error and exit
         * DeInit function if there is any.
         */

        for (iteration = VARIABLE_INIT_VALUE; iteration < GPT_CHANNEL_CONFIGURATION_MAX_SIZE; iteration++)
        {
            if (Gpt_ChannelState[iteration] == CHANNEL_RUNNING)
            {
                /* SWS_Gpt_00234 */
                // Det_ReportRuntimeError(MODULE_ID, INSTANCE_ID, GPT_DE_INIT_SERVICE_ID, GPT_E_BUSY);
                ChannelState_Flag = CHANNEL_RUNNING;
                break;
            }
        }

        if(ChannelState_Flag == CHANNEL_INIT)
        {
            for (iteration = VARIABLE_INIT_VALUE; iteration < GPT_CHANNEL_CONFIGURATION_MAX_SIZE; iteration++)
            {

                if (GptChannelSetting[iteration].Gpt_ChannelConfigState == CHANNEL_CONFIG) /* Check if this channel is configured */
                {

                    /*
                     *  SWS_Gpt_00008, SRS_BSW_00336, SRS_SPAL_12163, SRS_Gpt_12116, SWS_Gpt_00162, SRS_Gpt_12116
                     *   Deinitialize the hardware used by the GPT driver (depending on configuration) to the power on reset state.
                     *   Values of registers which are not writable are excluded.
                     */

                    Gpt_ResetHalfTimer(iteration);
                    GptChannelSetting[iteration].Gpt_ChannelConfigState = CHANNEL_NOT_CONFIG;
                    Gpt_Notifications[iteration] = NULL_PTR;

                    /* Reset notification state of each configured channel */
                    GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelNotificationState = NOTIFICATION_DISABLED;

                    /* Reset wakeup notification state of each configured channel */
                    GptChannelConfiguration[GptChannelSetting[iteration].Gpt_ChannelConfigIndex].GptChannelWakeupState = WAKEUP_DISABLED;

                }
            }

            ChannelConfigSet_Index = VARIABLE_INIT_VALUE;
            DriverConfiguration_Index = VARIABLE_INIT_VALUE;
            CLEAR_BITS((WTIMER5_BASE_ADRRESS + TIMER_O_CTL), TIMER_CTL_TAEN); /* Stop pre-defined timers */
            HWREG(WTIMER5_BASE_ADRRESS + TIMER_O_TAILR) = ILR_RESET_VALUE; /* Reset load register to its reset value */
            HWREG(WTIMER5_BASE_ADRRESS + TIMER_O_TAV) = ILR_RESET_VALUE; /* Reset timer shadow register to its reset value  */
            HWREG(WTIMER5_BASE_ADRRESS + TIMER_O_TBILR) = ILR_RESET_VALUE;
            HWREG(WTIMER5_BASE_ADRRESS + TIMER_O_TBV) = ILR_RESET_VALUE;


            /*SWS_Gpt_00363*/
            Gpt_State = GPT_UNINITALIZED; /* Change state of Gpt driver to GPT_UNINITALIZED */
        }
    }

}

#endif

