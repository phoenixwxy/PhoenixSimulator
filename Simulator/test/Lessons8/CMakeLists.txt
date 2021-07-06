CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(Lessons8)

INCLUDE_DIRECTORIES(.
        ${CMAKE_SOURCE_DIR}/3rdParty/include
        ${CMAKE_SOURCE_DIR}/3rdParty/SDL/include/
        ${CMAKE_SOURCE_DIR}/3rdParty/SDL_Image/include/SDL2/
        ${CMAKE_SOURCE_DIR}/3rdParty/SDL_Mixer/include/SDL2/
        ${CMAKE_SOURCE_DIR}/3rdParty/SDL_ttf/include/SDL2/
        )

AUX_SOURCE_DIRECTORY(. SRC)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ThirdParty}/SDL/lib/libSDL2.so)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ThirdParty}/SDL_Image/lib/libSDL2_image.so)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ThirdParty}/SDL_Mixer/lib/libSDL2_mixer.so)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ThirdParty}/SDL_ttf/lib/libSDL2_ttf.so)