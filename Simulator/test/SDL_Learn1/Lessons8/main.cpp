//
// Created by mi on 2021/6/17.
//
#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

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
//void ApplySurface(int x, int y, SDL_Texture *texture, SDL_Renderer *rend)
//{
//    SDL_Rect pos;
//    pos.x = x;
//    pos.y = y;
//    SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);
//
//    SDL_RenderCopy(rend, texture, nullptr, &pos);
//}

// apply a surface to draw a renderer in anywhere
void ApplySurface(int x, int y, SDL_Texture *texture, SDL_Renderer *rend, SDL_Rect *clip = nullptr)
{
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    if (nullptr != clip) {
        pos.w = clip->w;
        pos.h = clip->h;
    } else {
        SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);
    }

    SDL_RenderCopy(rend, texture, clip, &pos);
}

SDL_Texture *RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize)
{
    TTF_Font *font = nullptr;
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr) {
        throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
    }

    SDL_Surface *surface = TTF_RenderText_Blended(font, message.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    if (TTF_Init() == -1) {
        std::cout << TTF_GetError() << std::endl;
        return 2;
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
        SDL_Color color = {255, 0, 255};
        image = RenderText("TTF Fonts are cool", "/home/mi/workspace/code/PhoenixSimulator/Resource/font/FiraCode/distr/ttf/FiraCode-Bold.ttf",
                                color, 16);
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 4;
    }
//    try {
////        background = LoadImage("/home/mi/workspace/code/PhoenixSimulator/Resource/TwinklebearDev-Lessons/res/Lesson3/background.png");
//        image = LoadImage("/home/mi/workspace/code/PhoenixSimulator/Resource/TwinklebearDev-Lessons/res/Lesson5/image.png");
//    } catch (const std::runtime_error &e) {
//        std::cout << e.what() << std::endl;
//        return 4;
//    }
//    if (background == nullptr || image == nullptr)
//        return 4;

//    for (uint i = 0; i < 3; ++i)
//    {
//        // clear Renderer
//        SDL_RenderClear(renderer);
//
////        int bW, bH;
////        SDL_QueryTexture(background, nullptr, nullptr, &bW, &bH);
////        ApplySurface(0, 0, background, renderer);
////        ApplySurface(bW, 0, background, renderer);
////        ApplySurface(0, bH, background, renderer);
////        ApplySurface(bW, bH, background, renderer);
//
//        int iW, iH;
//        SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
//        int x = SCREEN_WIDTH / 2 - iW / 2;
//        int y = SCREEN_HEIGHT / 2 - iH / 2;
//        ApplySurface(x, y, image, renderer);
//
//        // display renderer
//        SDL_RenderPresent(renderer);
//
//        SDL_Delay(1000);
//    }

//    int iW = 100, iH = 100;
//    SDL_Rect clips[4];
//
//    int x = SCREEN_WIDTH / 2 - iW / 2;
//    int y = SCREEN_HEIGHT / 2 - iH / 2;
//
//    int column = 0;
//
//    for (int i = 0; i < 4; ++i) {
//        if (i !=0 && i % 2 == 0)
//            ++column;
//
//        clips[i].x = column * iW;
//        clips[i].y = i % 2 * iH;
//        clips[i].w = iW;
//        clips[i].h = iH;
//    }
//
//    int useClip = 0;

    SDL_Event sdlEvent;
    bool quit = false;
    while (!quit) {
        if (SDL_PollEvent(&sdlEvent)) {
            if (sdlEvent.type == SDL_QUIT) {
                quit = true;
//            } else if (sdlEvent.type == SDL_KEYDOWN) {
//                switch (sdlEvent.key.keysym.sym) {
//                    case SDLK_1:
//                        useClip = 0;
//                        std::cout << "useClip= " << useClip <<std::endl;
//                        break;
//                    case SDLK_2:
//                        useClip = 1;
//                        break;
//                    case SDLK_3:
//                        useClip = 2;
//                        break;
//                    case SDLK_4:
//                        useClip = 3;
//                        break;
//                    case SDLK_ESCAPE:
//                        quit = true;
//                        break;
//                    default:
//                        break;
//                }
        }
        }
        SDL_RenderClear(renderer);
        ApplySurface(0, 0, image, renderer);
        SDL_RenderPresent(renderer);
    }

//    SDL_DestroyTexture(background);
    SDL_DestroyTexture(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}