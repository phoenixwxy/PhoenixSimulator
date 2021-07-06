CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

MESSAGE("--------------------------------")
MESSAGE("START")
MESSAGE("--------------------------------")

PROJECT(Stock)
MESSAGE("Project Name: " ${PROJECT_NAME})

IF(NOT WIN32)
    STRING(ASCII 27 Esc)
    SET(ColourReset "${Esc}[m")
    SET(ColourBold  "${Esc}[1m")
    SET(Red         "${Esc}[31m")
    SET(Green       "${Esc}[32m")
    SET(Yellow      "${Esc}[33m")
    SET(Blue        "${Esc}[34m")
    SET(MAGENTA     "${Esc}[35m")
    SET(Cyan        "${Esc}[36m")
    SET(White       "${Esc}[37m")
    SET(BoldRed     "${Esc}[1;31m")
    SET(BoldGreen   "${Esc}[1;32m")
    SET(BoldYellow  "${Esc}[1;33m")
    SET(BOLDBLUE    "${Esc}[1;34m")
    SET(BOLDMAGENTA "${Esc}[1;35m")
    SET(BoldCyan    "${Esc}[1;36m")
    SET(BOLDWHITE   "${Esc}[1;37m")
ENDIF()

FUNCTION(message)
    LIST(GET ARGV 0 MessageType)
    IF(MessageType STREQUAL FATAL_ERROR OR MessageType STREQUAL SEND_ERROR)
        LIST(REMOVE_AT ARGV 0)
        _message(${MessageType} "${BoldRed}${ARGV}${ColourReset}")
    ELSEIF(MessageType STREQUAL WARNING)
        LIST(REMOVE_AT ARGV 0)
        _message(${MessageType}
                "${BoldYellow}${ARGV}${ColourReset}")
    ELSEIF(MessageType STREQUAL AUTHOR_WARNING)
        LIST(REMOVE_AT ARGV 0)
        _message(${MessageType} "${BoldCyan}${ARGV}${ColourReset}")
    ELSEIF(MessageType STREQUAL STATUS)
        LIST(REMOVE_AT ARGV 0)
        _message(${MessageType} "${Green}${ARGV}${ColourReset}")
    ELSEIF(MessageType STREQUAL INFO)
        LIST(REMOVE_AT ARGV 0)
        _message("${Blue}${ARGV}${ColourReset}")
    ELSE()
        _message("${ARGV}")
    ENDIF()
ENDFUNCTION()


IF(CMAKE_VERSION VERSION_LESS "3.1")
    IF(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    ENDIF()
ELSE()
    SET(CMAKE_CXX_STANDARD 20)
ENDIF()


IF (NOT CMAKE_CXX_STANDARD)
    SET(CMAKE_CXX_STANDARD 20)
    SET(CMAKE_CXX_STANDARD_REQUIRED ON)
ENDIF()

SET(CMAKE_CXX_EXTENSIONS  OFF)

IF(CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
    SET(CMAKE_CXX_EXTENSIONS ON)
ENDIF()

FUNCTION(set_env_prop)
    SET(ThirdParty "${CMAKE_SOURCE_DIR}/3rdParty" PARENT_SCOPE)
ENDFUNCTION()

set_env_prop()

#set(CMAKE_CXX_STANDARD 20)

# Add you need submodule
ADD_SUBDIRECTORY(src)

# Build tests
MESSAGE("--------------------------------")
OPTION(BUILD_TESTS "Build with tests" ON)
MESSAGE(STATUS "Build Tests: ${BUILD_TESTS}")
MESSAGE("--------------------------------")
IF(BUILD_TESTS)
    ADD_SUBDIRECTORY(test)
ENDIF()


MESSAGE("--------------------------------")
MESSAGE("DONE")
MESSAGE("--------------------------------")