CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

INCLUDE_DIRECTORIES(.)

AUX_SOURCE_DIRECTORY(. SRC)

ADD_EXECUTABLE(Stock ${SRC})

#TARGET_LINK_LIBRARIES(Simulator ${ThirdParty}/SDL/lib/libSDL2.so)