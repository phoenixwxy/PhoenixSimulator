//
// Created by mi on 2021/6/17.
//
#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "Utils.h"

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;

SDL_Texture *LoadImage(std::string file)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if (texture == nullptr) {
        Utils::LogSDLError(std::cout, "LoadTexture");
    }
    return texture;
}

void RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void RenderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y)
{
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    std::cout << w << "x" << h << std::endl;
    std::cout << x << "x" << y << std::endl;
    RenderTexture(texture, renderer, x, y, w, h);
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

void aplly(SDL_Texture* texture, int x, int y)
{

    SDL_RenderClear(renderer);
//        ApplySurface(x, y, image, renderer);
    RenderTexture(texture, renderer, x, y);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    RenderTexture(texture, renderer, 0, 0);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    RenderTexture(texture, renderer, 100, 100);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    RenderTexture(texture, renderer, 200, 200);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    RenderTexture(texture, renderer, 300, 300);
    SDL_RenderPresent(renderer);
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
        SDL_DestroyWindow(window);
//        SDL_DestroyRenderer(renderer);
        return 3;
    }

    SDL_Texture *image = LoadImage("/home/mi/workspace/code/PhoenixSimulator/Resource/TwinklebearDev-Lessons/res/Lesson4/image.png");
    if (nullptr == image) {
        Utils::LogSDLError(std::cout, "null image pointer");
        SDL_DestroyTexture(image);
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_RenderClear(renderer);

    int iW, iH;
    SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;
//    ApplySurface(x, y, image, renderer);

    SDL_Event sdlEvent;
    bool quit = false;
    while (!quit) {
        if (SDL_PollEvent(&sdlEvent)) {
            if (sdlEvent.type == SDL_QUIT) {
                quit = true;
            }
        } else {
            aplly(image, x, y);
        }
//        SDL_RenderClear(renderer);
////        ApplySurface(x, y, image, renderer);
//        RenderTexture(image, renderer, x, y);
//        SDL_RenderPresent(renderer);
//        aplly(image, x, y);
    }

//    SDL_DestroyTexture(background);
    SDL_DestroyTexture(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}