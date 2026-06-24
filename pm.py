import ctypes
import time
import csv
from datetime import datetime





NI568X_DLL = r"C:\Program Files\IVI Foundation\IVI\Bin\ni568x_64.dll"

ni568x = ctypes.WinDLL(NI568X_DLL)


# NI / IVI TYPES FROM ni568x.h


ViSession = ctypes.c_uint
ViStatus = ctypes.c_int
ViBoolean = ctypes.c_bool
ViInt32 = ctypes.c_int32
ViReal64 = ctypes.c_double

# FUNCTION DEFINITIONS FROM ni568x.h


# ni568x_init()
ni568x.ni568x_init.argtypes = [
    ctypes.c_char_p,
    ViBoolean,
    ViBoolean,
    ctypes.POINTER(ViSession)
]

ni568x.ni568x_init.restype = ViStatus


# ni568x_close()
ni568x.ni568x_close.argtypes = [
    ViSession
]

ni568x.ni568x_close.restype = ViStatus


# ni568x_ConfigureUnits()
ni568x.ni568x_ConfigureUnits.argtypes = [
    ViSession,
    ViInt32
]

ni568x.ni568x_ConfigureUnits.restype = ViStatus


# ni568x_ConfigureMeasurement()
ni568x.ni568x_ConfigureMeasurement.argtypes = [
    ViSession,
    ViInt32,
    ctypes.c_char_p,
    ctypes.c_char_p
]

ni568x.ni568x_ConfigureMeasurement.restype = ViStatus


# ni568x_Initiate()
ni568x.ni568x_Initiate.argtypes = [
    ViSession
]

ni568x.ni568x_Initiate.restype = ViStatus


# ni568x_Fetch()
ni568x.ni568x_Fetch.argtypes = [
    ViSession,
    ctypes.POINTER(ViReal64)
]

ni568x.ni568x_Fetch.restype = ViStatus

# CONSTANTS FROM ni568x.h


# From header:
# NI568X_VAL_WATTS = IVIPWRMETER_VAL_WATTS
# Usually IVI value is 1, but verify if needed.
POWER_UNITS_WATTS = 1


# Read measurement channel
MATH_NONE = 0


# USER SETTINGS


BPM_DEVICES = [

    # Replace these with your actual NI MAX VISA names

    "USB0::XXXX::XXXX::BPM1::INSTR",
    "USB0::XXXX::XXXX::BPM2::INSTR",
    "USB0::XXXX::XXXX::BPM3::INSTR",
    "USB0::XXXX::XXXX::BPM4::INSTR"

]


CHANNEL = b"Channel1"


RECORD_TIME = 20        # seconds

SAMPLE_PERIOD = 0.25    # seconds

OUTPUT_FILE = "bpm_data.csv"

# HELPER FUNCTIONS



def check_status(status, message):

    if status != 0:
        raise RuntimeError(
            f"{message} failed. Status code = {status}"
        )



def connect_bpm(address):

    session = ViSession()


    status = ni568x.ni568x_init(
        address.encode(),
        True,
        True,
        ctypes.byref(session)
    )


    check_status(
        status,
        f"Connecting {address}"
    )


    return session




def configure_bpm(session):

    # Watts

    status = ni568x.ni568x_ConfigureUnits(
        session,
        POWER_UNITS_WATTS
    )

    check_status(
        status,
        "Setting units"
    )


    # Measurement configuration

    status = ni568x.ni568x_ConfigureMeasurement(
        session,
        MATH_NONE,
        CHANNEL,
        None
    )


    check_status(
        status,
        "Configuring measurement"
    )




def read_power(session):

    value = ViReal64()


    status = ni568x.ni568x_Fetch(
        session,
        ctypes.byref(value)
    )


    check_status(
        status,
        "Reading power"
    )


    return value.value



# MAIN PROGRAM


def main():

    sessions = []


    try:

        print("Connecting BPMs...")


        # Connect all four BPMs
        

        for device in BPM_DEVICES:

            s = connect_bpm(device)

            sessions.append(s)

            print(
                "Connected:",
                device
            )


        # Configure
        

        for s in sessions:

            configure_bpm(s)


        print("Configuration complete")


       
        # Recording
    


        with open(
            OUTPUT_FILE,
            "w",
            newline=""
        ) as file:


            writer = csv.writer(file)


            writer.writerow(
                [
                    "timestamp",
                    "BPM1",
                    "BPM2",
                    "BPM3",
                    "BPM4"
                ]
            )


            start = time.time()


            while time.time() - start < RECORD_TIME:


                # Start measurement on all meters

                for s in sessions:

                    status = ni568x.ni568x_Initiate(s)

                    check_status(
                        status,
                        "Initiate"
                    )


                readings = []


                # Fetch all results

                for s in sessions:

                    readings.append(
                        read_power(s)
                    )


                timestamp = datetime.now()


                writer.writerow(
                    [
                        timestamp,
                        *readings
                    ]
                )


                print(
                    timestamp,
                    readings
                )


                time.sleep(
                    SAMPLE_PERIOD
                )


        print(
            f"Finished. Saved to {OUTPUT_FILE}"
        )


    finally:

     
        # Always close instruments
        

        for s in sessions:

            try:

                ni568x.ni568x_close(s)

            except:

                pass


        print("BPM connections closed")


if __name__ == "__main__":

    main()
