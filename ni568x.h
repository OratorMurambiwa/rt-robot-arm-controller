// Copyright (c) 2015-2015, National Instruments Corporation. All rights reserved.

#ifndef __NI568X_HEADER
#define __NI568X_HEADER

#include <ivi.h>
#include <ivipwrmeter.h>

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

#define NI568X_MAJOR_VERSION 15 /* Instrument driver major version */
#define NI568X_MINOR_VERSION 0  /* Instrument driver minor version */

    /*- IVI Inherent Instrument Attributes ---------------------------------*/

        /* User Options */
#define NI568X_ATTR_RANGE_CHECK                      IVI_ATTR_RANGE_CHECK                            /* ViBoolean */
#define NI568X_ATTR_QUERY_INSTRUMENT_STATUS          IVI_ATTR_QUERY_INSTRUMENT_STATUS                /* ViBoolean */
#define NI568X_ATTR_CACHE                            IVI_ATTR_CACHE                                  /* ViBoolean */
#define NI568X_ATTR_SIMULATE                         IVI_ATTR_SIMULATE                               /* ViBoolean */
#define NI568X_ATTR_RECORD_COERCIONS                 IVI_ATTR_RECORD_COERCIONS                       /* ViBoolean */
#define NI568X_ATTR_INTERCHANGE_CHECK                IVI_ATTR_INTERCHANGE_CHECK                      /* ViBoolean */

        /* Driver Information  */
#define NI568X_ATTR_SPECIFIC_DRIVER_PREFIX           IVI_ATTR_SPECIFIC_DRIVER_PREFIX                 /* ViString,  read-only  */
#define NI568X_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS            /* ViString,  read-only  */
#define NI568X_ATTR_GROUP_CAPABILITIES               IVI_ATTR_GROUP_CAPABILITIES                     /* ViString,  read-only  */
#define NI568X_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER                /* ViString,  read-only  */
#define NI568X_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL                       /* ViString,  read-only  */
#define NI568X_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION           /* ViString,  read-only  */
#define NI568X_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION               /* ViString,  read-only  */
#define NI568X_ATTR_SPECIFIC_DRIVER_VENDOR           IVI_ATTR_SPECIFIC_DRIVER_VENDOR                 /* ViString,  read-only  */
#define NI568X_ATTR_SPECIFIC_DRIVER_DESCRIPTION      IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION            /* ViString,  read-only  */
#define NI568X_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, read-only    */
#define NI568X_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, read-only    */

        /* Advanced Session Information */
#define NI568X_ATTR_LOGICAL_NAME                     IVI_ATTR_LOGICAL_NAME                           /* ViString,  read-only             */
#define NI568X_ATTR_IO_RESOURCE_DESCRIPTOR           IVI_ATTR_IO_RESOURCE_DESCRIPTOR                 /* ViString,  read-only             */
#define NI568X_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                           /* ViString,  read-only             */

    /*- Instrument-Specific Attributes -------------------------------------*/
    /*- IviPwrMeter Fundamental Attributes -*/
#define NI568X_ATTR_CHANNEL_COUNT                    IVI_ATTR_CHANNEL_COUNT                          /* ViInt32,   read-only             */
#define NI568X_ATTR_UNITS                            IVIPWRMETER_ATTR_UNITS                          /* ViInt32                          */
#define NI568X_ATTR_RANGE_AUTO_ENABLED               IVIPWRMETER_ATTR_RANGE_AUTO_ENABLED             /* ViBoolean, multi-channel         */
#define NI568X_ATTR_AVERAGING_AUTO_ENABLED           IVIPWRMETER_ATTR_AVERAGING_AUTO_ENABLED         /* ViBoolean, multi-channel         */
#define NI568X_ATTR_CORRECTION_FREQUENCY             IVIPWRMETER_ATTR_CORRECTION_FREQUENCY           /* ViReal64,  multi-channel, hertz  */
#define NI568X_ATTR_OFFSET                           IVIPWRMETER_ATTR_OFFSET                         /* ViReal64,  multi-channel, dB     */

    /*- IviPwrMeterAveragingCount Attribute -*/
#define NI568X_ATTR_AVERAGING_COUNT                  IVIPWRMETER_ATTR_AVERAGING_COUNT                /* ViInt32, multi-channel           */

    /*- IviPwrMeterManualRange Attributes -*/
#define NI568X_ATTR_RANGE_LOWER                      IVIPWRMETER_ATTR_RANGE_LOWER                    /* ViReal64, multi-channel, units attribute */
#define NI568X_ATTR_RANGE_UPPER                      IVIPWRMETER_ATTR_RANGE_UPPER                    /* ViReal64, multi-channel, units attribute */

    /*- IviPwrMeterDutyCycleCorrection Attributes -*/
#define NI568X_ATTR_DUTY_CYCLE_CORRECTION            IVIPWRMETER_ATTR_DUTY_CYCLE_CORRECTION          /* ViReal64, multi-channel, percentage */
#define NI568X_ATTR_DUTY_CYCLE_CORRECTION_ENABLED    IVIPWRMETER_ATTR_DUTY_CYCLE_CORRECTION_ENABLED  /* ViBoolean, multi-channel         */

    /*- IviPwrMeterTriggerSource Attributes -*/
#define NI568X_ATTR_TRIGGER_SOURCE                   IVIPWRMETER_ATTR_TRIGGER_SOURCE                 /* ViInt32 */

    /*- IviPwrMeterInternalTrigger Attributes -*/
#define NI568X_ATTR_INTERNAL_TRIGGER_EVENT_SOURCE    IVIPWRMETER_ATTR_INTERNAL_TRIGGER_EVENT_SOURCE  /* ViString                  */
#define NI568X_ATTR_INTERNAL_TRIGGER_LEVEL           IVIPWRMETER_ATTR_INTERNAL_TRIGGER_LEVEL         /* ViReal64, units attribute */
#define NI568X_ATTR_INTERNAL_TRIGGER_SLOPE           IVIPWRMETER_ATTR_INTERNAL_TRIGGER_SLOPE         /* ViInt32, enum             */

    /*- IVI Specific Driver Instrument Attributes --------------------------*/
#define NI568X_ATTR_INSTRUMENT_SERIAL_NUMBER         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)            /* ViString, read-only              */
#define NI568X_ATTR_APERTURE_TIME_MODE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)            /* ViInt32, multi-channel           */
#define NI568X_ATTR_APERTURE_TIME                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)            /* ViReal64, multi-channel          */
#define NI568X_ATTR_EXTERNAL_CALIBRATION_DATE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)            /* ViString, read-only              */
#define NI568X_ATTR_AVERAGING_AUTO_RESOLUTION        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)            /* ViReal64, multi-channel, dBm     */
#define NI568X_ATTR_AVERAGING_AUTO_SOURCE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)            /* ViInt32, multi-channel           */
#define NI568X_ATTR_ENHANCED_MODULATION_MODE_ENABLED (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)            /* ViBoolean                        */
#define NI568X_ATTR_BUFFER_SIZE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 10L)           /* ViInt32, muti-channel            */

#define NI568X_ATTR_EXTERNAL_TRIGGER_EVENT_SOURCE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106L)          /* ViString                         */
#define NI568X_ATTR_EXTERNAL_TRIGGER_SLOPE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L)          /* ViInt32, enum                    */

#define NI568X_ATTR_TRIGGER_DELAY                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 120L)          /* ViReal64, seconds                */
#define NI568X_ATTR_TRIGGER_DELAY_ENABLED            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 121L)          /* ViBoolean                        */
#define NI568X_ATTR_TRIGGER_NOISE_IMMUNITY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 122L)          /* ViInt32, data points             */
#define NI568X_ATTR_TRIGGER_NOISE_IMMUNITY_ENABLED   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 123L)          /* ViBoolean                        */
#define NI568X_ATTR_TRIGGER_HYSTERESIS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 124L)          /* ViReal64, dB */
#define NI568X_ATTR_TRIGGER_HYSTERESIS_ENABLED       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 125L)          /* ViBoolean */

#define NI568X_ATTR_TIME_SLOT_COUNT                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 200L)          /* ViInt32                          */
#define NI568X_ATTR_TIME_SLOT_WIDTH                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 201L)          /* ViReal64, seconds                */
#define NI568X_ATTR_TIME_SLOT_EXCLUSION_START        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 202L)          /* ViReal64, seconds                */
#define NI568X_ATTR_TIME_SLOT_EXCLUSION_END          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 203L)          /* ViReal64, seconds                */
#define NI568X_ATTR_TIME_SLOT_EXCLUSION_ENABLED      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 204L)          /* ViBoolean                        */

#define NI568X_ATTR_SCOPE_RECORD_LENGTH              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 300L)          /* ViReal64, seconds */
#define NI568X_ATTR_SCOPE_RECORD_POINTS              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 301L)          /* ViInt32 */
#define NI568X_ATTR_SCOPE_GATE_START                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 302L)          /* ViReal64, seconds */
#define NI568X_ATTR_SCOPE_GATE_END                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 303L)          /* ViReal64, seconds */
#define NI568X_ATTR_SCOPE_GATE_ENABLED               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 304L)          /* ViBoolean */
#define NI568X_ATTR_SCOPE_FENCE_START                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 305L)          /* ViReal64, seconds */
#define NI568X_ATTR_SCOPE_FENCE_END                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 306L)          /* ViReal64, seconds */
#define NI568X_ATTR_SCOPE_FENCE_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 307L)          /* ViBoolean */
#define NI568X_ATTR_SCOPE_GATE_AVERAGE_POWER         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 320L)          /* ViReal64, dBm, multi-channel */
#define NI568X_ATTR_SCOPE_GATE_PEAK_POWER            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L)          /* ViReal64, dBm, multi-channel */
#define NI568X_ATTR_SCOPE_GATE_MINIMUM_POWER         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L)          /* ViReal64, dBm, multi-channel */
#define NI568X_ATTR_SCOPE_GATE_CREST_FACTOR          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 323L)          /* ViReal64, dB,  multi-channel */

/****************************************************************************
 *---------- IviPwrMeter Class Function Parameter Value Defines ------------*
 ****************************************************************************/

    /*- Defined values for function: Read, Fetch   -*/
    /*-                   parameter: maxTime       -*/
#define NI568X_VAL_MAX_TIME_INFINITE                 IVI_VAL_MAX_TIME_INFINITE                       /* Immediate Timeout               */
#define NI568X_VAL_MAX_TIME_IMMEDIATE                IVI_VAL_MAX_TIME_IMMEDIATE                      /* Infinite Timeout                */

    /*- Defined values for function: ConfigureMeasurement  -*/
    /*-                   parameter: Operator              -*/
#define NI568X_VAL_NONE                                IVIPWRMETER_VAL_NONE                            /* Read Channel                    */
//#define NI568X_VAL_DIFFERENCE                        IVIPWRMETER_VAL_DIFFERENCE                      /* Difference                      */
//#define NI568X_VAL_SUM                               IVIPWRMETER_VAL_SUM                             /* Sum                             */
//#define NI568X_VAL_QUOTIENT                          IVIPWRMETER_VAL_QUOTIENT                        /* Quotient                        */

#define NI568X_VAL_OPERATOR_CLASS_EXT_BASE           IVIPWRMETER_VAL_OPERATOR_CLASS_EXT_BASE
#define NI568X_VAL_OPERATOR_SPECIFIC_EXT_BASE        IVIPWRMETER_VAL_OPERATOR_SPECIFIC_EXT_BASE

    /*- Defined values for function: IsMeasurementComplete  -*/
    /*-                   parameter: status                 -*/
#define NI568X_VAL_MEAS_COMPLETE                     IVIPWRMETER_VAL_MEAS_COMPLETE                   /* Measurement Complete            */
#define NI568X_VAL_MEAS_IN_PROGRESS                  IVIPWRMETER_VAL_MEAS_IN_PROGRESS                /* Measurement In Progress         */
#define NI568X_VAL_MEAS_STATUS_UNKNOWN               IVIPWRMETER_VAL_MEAS_STATUS_UNKNOWN             /* Measurement Status Unknow       */

    /*- Defined values for function: QueryResultRangeType  -*/
    /*-                   parameter: rangeType             -*/
#define NI568X_VAL_IN_RANGE                          IVIPWRMETER_VAL_IN_RANGE                        /* Within the current range limits */
#define NI568X_VAL_UNDER_RANGE                       IVIPWRMETER_VAL_UNDER_RANGE                     /* Below the current range limits  */
#define NI568X_VAL_OVER_RANGE                        IVIPWRMETER_VAL_OVER_RANGE                      /* Above the current range limits  */

    /*- Defined values for function: IsZeroComplete         -*/
    /*-                   parameter: status                 -*/
#define NI568X_VAL_ZERO_COMPLETE                     IVIPWRMETER_VAL_ZERO_COMPLETE                   /* Zero Correction Complete        */
#define NI568X_VAL_ZERO_IN_PROGRESS                  IVIPWRMETER_VAL_ZERO_IN_PROGRESS                /* Zero Correction In Progress     */
#define NI568X_VAL_ZERO_STATUS_UNKNOWN               IVIPWRMETER_VAL_ZERO_STATUS_UNKNOWN             /* Zero Correction Status Unknown  */

    /*- Defined values for function: ConfigureTriggerSource -*/
    /*-                   parameter: TriggerSource -*/
#define NI568X_VAL_IMMEDIATE                         IVIPWRMETER_VAL_IMMEDIATE                       /* Trigger immediately                 */
#define NI568X_VAL_EXTERNAL                          IVIPWRMETER_VAL_EXTERNAL                        /* Trigger on external trigger input   */
#define NI568X_VAL_INTERNAL                          IVIPWRMETER_VAL_INTERNAL                        /* Trigger on measurement signal       */
#define NI568X_VAL_SOFTWARE_TRIG                     IVIPWRMETER_VAL_SOFTWARE_TRIG                   /* Trigger on software trigger command */

    /*- Defined values for function: ConfigureInternalTrigger -*/
    /*-                   parameter: slope -*/
#define NI568X_VAL_POSITIVE                          IVIPWRMETER_VAL_POSITIVE                        /* Positive slope */
#define NI568X_VAL_NEGATIVE                          IVIPWRMETER_VAL_NEGATIVE                        /* Negative slope */

/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/

    /*- Defined values for attribute NI568X_ATTR_MEASUREMENT_UNITS -*/
#define NI568X_VAL_DBM                               IVIPWRMETER_VAL_DBM
//#define NI568X_VAL_DBMV                              IVIPWRMETER_VAL_DBMV
//#define NI568X_VAL_DBUV                              IVIPWRMETER_VAL_DBUV
#define NI568X_VAL_WATTS                             IVIPWRMETER_VAL_WATTS
#define NI568X_VAL_MWATTS                            (IVIPWRMETER_VAL_UNITS_SPECIFIC_EXT_BASE + 1L)
#define NI568X_VAL_UWATTS                            (IVIPWRMETER_VAL_UNITS_SPECIFIC_EXT_BASE + 2L)

        /* Instrument specific attribute value definitions */

    /*- Defined values for attribute NI568X_ATTR_APERTURE_TIME_MODE -*/
#define NI568X_VAL_LOW                               (0)
#define NI568X_VAL_HIGH                              (1)
#define NI568X_VAL_OTHER                             (-1)

    /*- Defined values for function: ni568x_ConfigureAcquisitionMode() -*/
#define NI568X_VAL_CONTINUOUS_MODE                   (10000)
#define NI568X_VAL_TIME_SLOT_MODE                    (20000)
#define NI568X_VAL_SCOPE_MODE                        (30000)

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close Functions -*/
ViStatus _VI_FUNC ni568x_init(ViRsrc resourceName, ViBoolean IDQuery, ViBoolean resetDevice, ViSession* vi);
ViStatus _VI_FUNC ni568x_InitWithOptions(ViRsrc resourceName, ViBoolean IDQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* newVi);
ViStatus _VI_FUNC ni568x_close(ViSession vi);

/*- Locking Functions -*/
ViStatus _VI_FUNC ni568x_LockSession(ViSession vi, ViBoolean* callerHasLock);
ViStatus _VI_FUNC  ni568x_UnlockSession(ViSession vi, ViBoolean* callerHasLock);

/*- Channel Info Functions -*/
ViStatus _VI_FUNC ni568x_GetChannelName(ViSession vi, ViInt32 index, ViInt32 bufferSize, ViChar name[]);

/*- IviPwrMeterBase Configuration Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureMeasurement(ViSession vi, ViInt32 mathOperator, ViConstString channelNameOne, ViConstString channelNameTwo);
ViStatus _VI_FUNC ni568x_ConfigureUnits(ViSession vi, ViInt32 units);
ViStatus _VI_FUNC ni568x_ConfigureRangeAutoEnabled(ViSession vi, ViConstString channelName, ViBoolean rangeAutoEnabled);
ViStatus _VI_FUNC ni568x_ConfigureAveragingAutoEnabled(ViSession vi, ViConstString channelName, ViBoolean autoAveragingEnabled);
ViStatus _VI_FUNC ni568x_ConfigureCorrectionFrequency(ViSession vi, ViConstString channelName, ViReal64 frequency);
ViStatus _VI_FUNC ni568x_ConfigureOffset(ViSession vi, ViConstString channelName, ViReal64 offset);

/*- IviPwrMeterAveragingCount Function -*/
ViStatus _VI_FUNC ni568x_ConfigureAveragingCount(ViSession vi, ViConstString channelName, ViInt32 averagingCount);

/*- IviPwrMeterZeroCorrection Functions -*/
ViStatus _VI_FUNC ni568x_IsZeroComplete(ViSession vi, ViInt32* zeroStatus);
ViStatus _VI_FUNC ni568x_Zero(ViSession vi, ViConstString channelName);
ViStatus _VI_FUNC ni568x_ZeroAllChannels(ViSession vi);

/*- IviPwrMeterManualRange Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureRange(ViSession vi, ViConstString channelName, ViReal64 rangeLower, ViReal64 rangeUpper);

/*- IviPwrMeterDutyCycleCorrection Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureDutyCycleCorrection(ViSession vi, ViConstString channelName, ViBoolean correctionEnabled, ViReal64 correction);

/*- IviPwrMeterTriggerSource Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureTriggerSource(ViSession vi, ViInt32 triggerSource);

/*- IviPwrMeterInternalTrigger Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureInternalTrigger(ViSession vi, ViConstString sourceChannelName, ViInt32 slope);
ViStatus _VI_FUNC ni568x_ConfigureInternalTriggerLevel(ViSession vi, ViReal64 triggerLevel);

/*- IviPwrMeterSoftwareTrigger Functions -*/
ViStatus _VI_FUNC ni568x_SendSoftwareTrigger(ViSession vi);

/*- Instrument Specific Trigger Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureExternalTrigger(ViSession vi, ViConstString sourceChannelName, ViInt32 slope);
ViStatus _VI_FUNC ni568x_ConfigureTriggerDelay(ViSession vi, ViBoolean triggerDelayEnabled, ViReal64 triggerDelayTime);
ViStatus _VI_FUNC ni568x_ConfigureTriggerNoiseImmunity(ViSession vi, ViBoolean triggerImmunityEnabled, ViInt32 triggerImmunityFactor);
ViStatus _VI_FUNC ni568x_ConfigureTriggerHysteresis(ViSession vi, ViBoolean triggerHysteresisEnabled, ViReal64 triggerHysteresis);

/*- IviPwrMeter Measurement Functions -*/
ViStatus _VI_FUNC ni568x_Read(ViSession vi, ViInt32 maxTimeMillisecond, ViReal64* power);
ViStatus _VI_FUNC ni568x_ReadArray(ViSession vi, ViInt32* bufferSize, ViInt32 maxTimeMilliSecond, ViReal64* power);

/*- Low-Level Measurement Functions -*/
ViStatus _VI_FUNC ni568x_Fetch(ViSession vi, ViReal64* reading);
ViStatus _VI_FUNC ni568x_FetchArray(ViSession vi, ViInt32* bufferSize, ViReal64* power);
ViStatus _VI_FUNC ni568x_Initiate(ViSession vi);
ViStatus _VI_FUNC ni568x_IsMeasurementComplete(ViSession vi, ViInt32* measurementStatus);
ViStatus _VI_FUNC ni568x_Abort(ViSession vi);
ViStatus _VI_FUNC ni568x_QueryResultRangeType(ViSession vi, ViReal64 measurementValue, ViInt32* rangeType);

/*- Error Functions -*/
ViStatus _VI_FUNC ni568x_error_query(ViSession vi, ViInt32* errorCode, ViChar errorMessage[]);
ViStatus _VI_FUNC ni568x_GetError(ViSession vi, ViStatus* code, ViInt32 bufferSize, ViChar description[]);
ViStatus _VI_FUNC ni568x_ClearError(ViSession vi);
ViStatus _VI_FUNC  ni568x_error_message(ViSession vi, ViStatus errorCode, ViChar errorMessage[256]);

    /*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC ni568x_InvalidateAllAttributes(ViSession vi);
ViStatus _VI_FUNC ni568x_reset(ViSession vi);
ViStatus _VI_FUNC ni568x_ResetWithDefaults(ViSession vi);
ViStatus _VI_FUNC ni568x_self_test(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[]);
ViStatus _VI_FUNC ni568x_revision_query(ViSession vi, ViChar instrumentDriverRevision[], ViChar firmwareRevision[]);
ViStatus _VI_FUNC ni568x_Disable(ViSession vi);

    /*- Set, Get, and Check Attribute Functions ----------------------------*/
ViStatus _VI_FUNC ni568x_GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 *value);
ViStatus _VI_FUNC ni568x_GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 *value);
ViStatus _VI_FUNC ni568x_GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 bufSize, ViChar value[]);
ViStatus _VI_FUNC ni568x_GetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession *value);
ViStatus _VI_FUNC ni568x_GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean *value);
ViStatus _VI_FUNC ni568x_SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC ni568x_SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC ni568x_SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value);
ViStatus _VI_FUNC ni568x_SetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC ni568x_SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);
ViStatus _VI_FUNC ni568x_CheckAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC ni568x_CheckAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC ni568x_CheckAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value);
ViStatus _VI_FUNC ni568x_CheckAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC ni568x_CheckAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

   /*- Time Slot and Scope Mode Functions -*/
ViStatus _VI_FUNC ni568x_ConfigureAcquisitionMode(ViSession vi, ViConstString channelName, ViInt32 mode);
ViStatus _VI_FUNC ni568x_ConfigureTimeSlot(ViSession vi, ViConstString channelName, ViInt32 slotCount, ViReal64 slotWidth);
ViStatus _VI_FUNC ni568x_ConfigureTimeSlotExclusion(ViSession vi, ViConstString channelName, ViBoolean exclusionEnabled, ViReal64 exclusionTimeForSlotStart, ViReal64 exclusionTimeForSlotEnd);
ViStatus _VI_FUNC ni568x_ReadTimeSlotData(ViSession vi, ViConstString channelName, ViInt32 slotDataSize, ViInt32 maxTimeMillisecond, ViReal64 power[], ViInt32 * actualPoints);
ViStatus _VI_FUNC ni568x_FetchTimeSlotData(ViSession vi, ViConstString channelName, ViInt32 slotDataSize, ViReal64 power[], ViInt32 * actualPoints);
ViStatus _VI_FUNC ni568x_ConfigureScope(ViSession vi, ViConstString channelName, ViReal64 scopeRecordLength, ViInt32 pointsPerRecord);
ViStatus _VI_FUNC ni568x_ConfigureScopeGate(ViSession vi, ViConstString channelName, ViBoolean gateEnabled, ViReal64 gateStartTime, ViReal64 gateEndTime);
ViStatus _VI_FUNC ni568x_ConfigureScopeFence(ViSession vi, ViConstString channelName, ViBoolean fenceEnabled, ViReal64 fenceStartTime, ViReal64 fenceEndTime);
ViStatus _VI_FUNC ni568x_ReadScopeData(ViSession vi, ViConstString channelName, ViInt32 recordBufferSize, ViInt32 maxTimeMillisecond, ViReal64 power[], ViInt32 * actualPoints);
ViStatus _VI_FUNC ni568x_FetchScopeData(ViSession vi, ViConstString channelName, ViInt32 recordBufferSize, ViReal64 power[], ViInt32 * actualPoints);

   /*- Obsolete Functions -*/
ViStatus _VI_FUNC ni568x_GetNextInterchangeWarning(ViSession vi, ViInt32 bufferSize, ViChar interchangeWarning[]);
ViStatus _VI_FUNC ni568x_ResetInterchangeCheck(ViSession vi);
ViStatus _VI_FUNC ni568x_ClearInterchangeWarnings(ViSession vi);
ViStatus _VI_FUNC ni568x_GetNextCoercionRecord(ViSession vi, ViInt32 bufferSize, ViChar record[]);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/

#define NI568X_WARN_UNDER_RANGE                      IVIPWRMETER_WARN_UNDER_RANGE
#define NI568X_WARN_OVER_RANGE                       IVIPWRMETER_WARN_OVER_RANGE

#define NI568X_ERROR_MAX_TIME_EXCEEDED               IVIPWRMETER_ERROR_MAX_TIME_EXCEEDED

#define NI568X_WARNMSG_UNDER_RANGE                   IVIPWRMETER_WARNMSG_UNDER_RANGE
#define NI568X_WARNMSG_OVER_RANGE                    IVIPWRMETER_WARNMSG_OVER_RANGE

#define NI568X_ERRMSG_MAX_TIME_EXCEEDED              IVIPWRMETER_ERRMSG_MAX_TIME_EXCEEDED

    /* Instrument-specific error codes -------------------------------------*/
#define NI568X_ERROR_ZERO_TEMP_ERROR                 (IVI_SPECIFIC_ERROR_BASE + 1L)
#define NI568X_ERROR_TEMP_OVERRANGE                  (IVI_SPECIFIC_ERROR_BASE + 2L)
#define NI568X_ERROR_DETECTOR_A_OVERRANGE            (IVI_SPECIFIC_ERROR_BASE + 3L)
#define NI568X_ERROR_ZERO_ERROR_DET_A                (IVI_SPECIFIC_ERROR_BASE + 4L)
#define NI568X_ERROR_ZERO_ERROR_DET_B                (IVI_SPECIFIC_ERROR_BASE + 5L)
#define NI568X_ERROR_TEMP_ERROR                      (IVI_SPECIFIC_ERROR_BASE + 6L)
#define NI568X_ERROR_INVALID_RESPONSE                (IVI_SPECIFIC_ERROR_BASE + 7L)
#define NI568X_ERROR_STOP_ERROR                      (IVI_SPECIFIC_ERROR_BASE + 8L)
#define NI568X_ERROR_READ_PWR_ERROR                  (IVI_SPECIFIC_ERROR_BASE + 9L)
#define NI568X_ERROR_SET_FREQ_ERROR                  (IVI_SPECIFIC_ERROR_BASE + 10L)
#define NI568X_ERROR_ZERO_ERROR                      (IVI_SPECIFIC_ERROR_BASE + 11L)
#define NI568X_ERROR_APERTURE_ERROR                  (IVI_SPECIFIC_ERROR_BASE + 12L)
#define NI568X_ERROR_MEAS_NOT_INIT                   (IVI_SPECIFIC_ERROR_BASE + 13L)
#define NI568X_ERROR_MEAS_NOT_COMPLETE               (IVI_SPECIFIC_ERROR_BASE + 14L)
#define NI568X_ERROR_ZERO_NOT_COMPLETE               (IVI_SPECIFIC_ERROR_BASE + 15L)
#define NI568X_ERROR_WRONG_ACQUISITION_MODE          (IVI_SPECIFIC_ERROR_BASE + 16L)
#define NI568X_ERROR_BAD_TRIGGER_LEVEL               (IVI_SPECIFIC_ERROR_BASE + 17L)
#define NI568X_ERROR_BAD_MANUAL_RANGE                (IVI_SPECIFIC_ERROR_BASE + 18L)
#define NI568X_ERROR_UNSUPPORTED_TRIGGER_SOURCE      (IVI_SPECIFIC_ERROR_BASE + 19L)
#define NI568X_ERROR_ALREADY_INITIATED               (IVI_SPECIFIC_ERROR_BASE + 20L)
#define NI568X_ERROR_FAILED_OPEN_VISA_SESSION        (IVI_SPECIFIC_ERROR_BASE + 21L)
#define NI568X_ERROR_DEVICE_BUSY                     (IVI_SPECIFIC_ERROR_BASE + 22L)
// TODO: replace the following two errors with an error for trying to change state between initiate and fetch
#define NI568X_ERROR_FETCH_TOO_MANY_MEASUREMENTS     (IVI_SPECIFIC_ERROR_BASE + 23L)
#define NI568X_ERROR_FETCH_TOO_FEW_MEASUREMENTS      (IVI_SPECIFIC_ERROR_BASE + 24L)
#define NI568X_ERROR_READ_WITH_SW_TRIG               (IVI_SPECIFIC_ERROR_BASE + 25L)
#define NI568X_ERROR_READ_SINGLE_EXPECT_ARRAY        (IVI_SPECIFIC_ERROR_BASE + 26L)
#define NI568X_ERROR_INVALID_SCOPE_PARAMS            (IVI_SPECIFIC_ERROR_BASE + 27L)
#define NI568X_ERROR_INVALID_TIME_SLOT_PARAMS        (IVI_SPECIFIC_ERROR_BASE + 28L)
#define NI568X_ERROR_BUFFER_MODE_AVERAGING           (IVI_SPECIFIC_ERROR_BASE + 29L)

#define NI568X_WARN_AVG_COUNT_NOT_REACHED            (IVI_SPECIFIC_WARN_BASE + 1L)

#define NI568X_ERRMSG_ZERO_TEMP_ERROR                "Temperature changed more than allowable limit after zeroing sensor."
#define NI568X_ERRMSG_TEMP_OVERRANGE                 "Temperature over range."
#define NI568X_ERRMSG_DETECTOR_A_OVERRANGE           "Detector A over ranged."
#define NI568X_ERRMSG_ZERO_ERROR_DET_A               "Detector A failed to zero."
#define NI568X_ERRMSG_ZERO_ERROR_DET_B               "Detector B failed to zero."
#define NI568X_ERRMSG_TEMP_ERROR                     "Temperature beyond operating range."
#define NI568X_ERRMSG_INVALID_RESPONSE               "The device sent an invalid response."
#define NI568X_ERRMSG_STOP_ERROR                     "The device encountered an error while returning to idle mode."
#define NI568X_ERRMSG_READ_PWR_ERROR                 "The device encountered an error while obtaining a power reading.\n\nCall ni568x_error_query for more information."
#define NI568X_ERRMSG_SET_FREQ_ERROR                 "The device encountered an error while setting the calibration factor frequency."
#define NI568X_ERRMSG_ZERO_ERROR                     "The device encountered an error while zeroing.\nThe reason could be the presence of RF power at the input of the sensor. Turn off the RF input to the sensor or disconnect the sensor from the RF source and try the zero operation again."
#define NI568X_ERRMSG_APERTURE_ERROR                 "The device encountered an error while changing aperture time mode."
#define NI568X_ERRMSG_MEAS_NOT_INIT                  "The measurement has not been initiated.\n\nCall ni568x_Initiate prior to making this call."
#define NI568X_ERRMSG_MEAS_NOT_COMPLETE              "The measurement has not been completed.\n\nSet a longer waitTime if calling ni568x_Read, or wait for ni568x_IsMeasurementComplete to be true prior to making this call."
#define NI568X_ERRMSG_ZERO_NOT_COMPLETE              "The zero operation has not been completed.\n\nWait for ni568x_IsZeroComplete to be true prior to making this call."
#define NI568X_ERRMSG_WRONG_ACQUISITION_MODE         "The requested function is not valid for the current acquisition mode.\n\nRefer to the NI RF Power Meter's Help for more information about which functions are applicable for particular acquisition modes."
#define NI568X_ERRMSG_BAD_TRIGGER_LEVEL              "The requested trigger level exceeds device capabilities.\n\nRefer to the device specifications for more information about the maximum and minimum trigger levels."
#define NI568X_ERRMSG_BAD_MANUAL_RANGE               "The requested manual range is invalid or does not map to a supported device measurement range.\n\nRefer to the device specifications for more information about the available ranges."
#define NI568X_ERRMSG_UNSUPPORTED_TRIGGER_SOURCE     "The requested trigger source is not supported in the current acquisition mode.\n\nRefer to the NI RF Power Meters Help for more information about supported trigger sources."
#define NI568X_ERRMSG_ALREADY_INITIATED              "The device cannot be initiated because it has already been initiated. You must abort or complete the previous measurements before initiating new ones."
#define NI568X_ERRMSG_FAILED_OPEN_VISA_SESSION       "Cannot access the device. Unplug the sensor's usb cable from the computer and plug it back in."
#define NI568X_ERRMSG_DEVICE_BUSY                    "Cannot access the device. It may be in use by another application. Close any open session in other applications."
// TODO: replace the following two errors with an error for trying to change state between initiate and fetch
#define NI568X_ERRMSG_FETCH_TOO_MANY_MEASUREMENTS    "The requested number of measurements fetched is greater than the number of measurements initiated."
#define NI568X_ERRMSG_FETCH_TOO_FEW_MEASUREMENTS     "The requested number of measurements fetched is fewer than the number of measurements initiated."
#define NI568X_ERRMSG_READ_WITH_SW_TRIG              "The software trigger cannot be used with read. Use initiate and fetch instead."
#define NI568X_ERRMSG_READ_SINGLE_EXPECT_ARRAY       "The acquisition is configured to return an array of measurements. Use Read Array or Fetch Array."
#define NI568X_ERRMSG_INVALID_SCOPE_PARAMS           "The combined scope parameters are invalid. Increase the scope record length or decrease the points per record."
#define NI568X_ERRMSG_INVALID_TIME_SLOT_PARAMS       "The combined time slot parameters are invalid. Decrease total capture time."
#define NI568X_ERRMSG_BUFFER_MODE_AVERAGING          "The averaging count must be 1 with a buffer size greater than 1."

#define NI568X_WARNMSG_AVG_COUNT_NOT_REACHED         "The measurement was aborted before the averaging count was reached."

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NI568X_HEADER */
