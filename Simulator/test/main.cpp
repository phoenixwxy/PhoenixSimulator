//
// Created by mi on 2021/6/15.
//
#include <iostream>

#include "SDL2/SDL.h"

#include "Utils.h"

static const int SUCCEED = 0;
static const int FAILED = 1;

#define INIT_EVERYTHING ( \
                SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | \
                SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR \
            )

int main()
{
    int result = SUCCEED;
    Utils::LogSDLError(std::cout, "test");
    return result;
}