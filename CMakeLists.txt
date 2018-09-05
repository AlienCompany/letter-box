cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

set(COMMON_CPPS
        Util.cpp
        FixBug.c
        ArrayAutoSize.cpp
        Sensor.cpp
        Box.cpp
        Led.cpp
        )
set(COMMON_HS
        ArrayAutoSize.h
        Util.h
        Sensor.h
        Box.h
        Led.h
        )

set(PORT COM4)

## ==================== ALL TEST : BEGIN ====================
#FOREACH(TESTNAME "ComB1" "ComB2" "MatriceLed" "Moteur" "UltraSon" "Debug")
#    # -------------------- MarvinTest : BEGIN --------------------
#    set(PROJECT_NAME_TEST MarvinTest${TESTNAME})
#    project(${PROJECT_NAME_TEST})
#
#    print_board_list()
#    #### Uncomment below additional settings as needed.
#    set(${PROJECT_NAME_TEST}_SRCS test${TESTNAME}.cpp ${COMMON_CPPS})
#    set(${PROJECT_NAME_TEST}_HDRS ${COMMON_HS})
#    set(${PROJECT_NAME_TEST}_BOARD ${PROJECT_BOARD})
#    set(${PROJECT_NAME_TEST}_PORT ${PORT})
#    set(${PROJECT_NAME_TEST}_ARDLIBS Servo)
#
#    generate_arduino_firmware(${PROJECT_NAME_TEST})
#    # -------------------- MarvinTest : END --------------------
#ENDFOREACH()
## ==================== ALL TEST : END ====================

# ==================== Marvin : BEGIN ====================
set(PROJECT_NAME LETTER_BOX)
project(${PROJECT_NAME})

#### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_SRCS main.cpp ${COMMON_CPPS})
set(${CMAKE_PROJECT_NAME}_HDRS ${COMMON_HS})
set(${CMAKE_PROJECT_NAME}_BOARD ${PROJECT_BOARD})
set(${CMAKE_PROJECT_NAME}_PORT ${PORT})
set(${CMAKE_PROJECT_NAME}_ARDLIBS Servo)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
# ==================== Marvin : END ====================


