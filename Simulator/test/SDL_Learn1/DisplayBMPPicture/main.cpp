//
// Created by mi on 2021/6/15.
//
#include <iostream>

#include "SDL2/SDL.h"

static const int SUCCEED = 0;
static const int FAILED = 1;

int main()
{
    int result = SUCCEED;

    std::cout << "Beginning of TEST" << std::endl;
    // Some error in Init Audio
    // To apt install libasound2-dev libpulse-dev
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
//    if (SDL_Init(SDL_INIT_AUDIO) == -1) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        result = FAILED;
        return result;
    }

    // Create a new Window
    SDL_Window *win = nullptr;
    win = SDL_CreateWindow("Test SDL", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return result = FAILED;
    }

    // Create a new Renderer
    SDL_Renderer *ren = nullptr;
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return result = FAILED;
    }

    // Create a surface to display picture, Load BMP picture
    SDL_Surface *bmp = nullptr;
    bmp = SDL_LoadBMP("/home/mi/workspace/code/PhoenixSimulator/Simulator/test/resource/hello.bmp");
    if (bmp == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return result = FAILED;
    }

    // create new texture for surface
    SDL_Texture *tex = nullptr;
    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    // will be run 2000ms
    SDL_Delay(2000);

    // clean and destroy res
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    // destroy SDL
    SDL_Quit();

    std::cout << "End of TEST" << std::endl;
    return result;
}