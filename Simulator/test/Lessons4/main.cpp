//
// Created by mi on 2021/6/17.
//
#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;

SDL_Texture *LoadImage(std::string file)
{
    SDL_Texture *tex = nullptr;
    tex = IMG_LoadTexture(renderer, file.c_str());
    if (tex == nullptr) {
        throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
    }
    return tex;
}

// apply a surface to draw a renderer in anywhere
void ApplySurface(int x, int y, SDL_Texture *texture, SDL_Renderer *rend)
{
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);

    SDL_RenderCopy(rend, texture, nullptr, &pos);
}

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Pic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return 2;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return 3;
    }

//    SDL_Texture *background = nullptr;
    SDL_Texture *image = nullptr;
    try {
//        background = LoadImage("/home/mi/workspace/code/PhoenixSimulator/Resource/TwinklebearDev-Lessons/res/Lesson3/background.png");
        image = LoadImage("/home/mi/workspace/code/PhoenixSimulator/Resource/TwinklebearDev-Lessons/res/Lesson4/image.png");
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 4;
    }
//    if (background == nullptr || image == nullptr)
//        return 4;

    for (uint i = 0; i < 3; ++i)
    {
        // clear Renderer
        SDL_RenderClear(renderer);

//        int bW, bH;
//        SDL_QueryTexture(background, nullptr, nullptr, &bW, &bH);
//        ApplySurface(0, 0, background, renderer);
//        ApplySurface(bW, 0, background, renderer);
//        ApplySurface(0, bH, background, renderer);
//        ApplySurface(bW, bH, background, renderer);

        int iW, iH;
        SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
        int x = SCREEN_WIDTH / 2 - iW / 2;
        int y = SCREEN_HEIGHT / 2 - iH / 2;
        ApplySurface(x, y, image, renderer);

        // display renderer
        SDL_RenderPresent(renderer);

        SDL_Delay(1000);
    }

//    SDL_DestroyTexture(background);
    SDL_DestroyTexture(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}