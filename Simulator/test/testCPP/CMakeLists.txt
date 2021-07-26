CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

INCLUDE_DIRECTORIES(
        .
        ./std/utility/
        ./ImageProcess/MIPI_RAWtoRAW/
        )

SET(SRC
        main.cpp
        Test.cpp
        std/utility/std_utility.cpp
        std/utility/std_forward.hpp ImageProcess/MIPI_RAWtoRAW/MipiRaw2Raw.cpp )

ADD_EXECUTABLE(testCpp ${SRC})
