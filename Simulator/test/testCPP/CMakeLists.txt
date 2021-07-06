CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

INCLUDE_DIRECTORIES(
        .
        ./std/utility/
        )

SET(SRC
        main.cpp
        Test.cpp
        std/utility/std_utility.cpp
        std/utility/std_forward.hpp)

ADD_EXECUTABLE(testCpp ${SRC})
