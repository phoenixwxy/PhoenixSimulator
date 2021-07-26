//
// Created by mi on 2021/7/12.
//

#ifndef SIMULATOR_WINDOW_H
#define SIMULATOR_WINDOW_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "x_types.hpp"

#define DEFAULT_WINDOW_SIZE_WITH 800
#define DEFAULT_WINDOW_SIZE_HIGH 600

class Window {
public:
    Window();
    Window(int with, int high);
    Window(int x, int y, int with, int high);
    explicit Window(XRect winSize);
//    Window(XRect* winSize);

    virtual ~Window();

    XResult Initialize();

    void SetWindowTitle(const std::string& title);

    XResult ApplySurfaceToTexture(int x, int y, SDL_Texture *texture, SDL_Renderer *rend, SDL_Rect *clip = nullptr);

    virtual void Show();

private:
    virtual void Destroy();

private:
    XRect m_WinSize{};
    SDL_Renderer* m_WinRender{};
    SDL_Window* m_Window{};
    std::string m_WindowTitle;
};


#endif //SIMULATOR_WINDOW_H
