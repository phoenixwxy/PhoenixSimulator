//
// Created by mi on 2021/7/12.
//

#include "Window.h"

#include <utility>

Window::Window() {
    m_WinSize.w = DEFAULT_WINDOW_SIZE_WITH;
    m_WinSize.h = DEFAULT_WINDOW_SIZE_HIGH;
}

Window::~Window() {

}

Window::Window(int with, int high) {
    m_WinSize.w = with;
    m_WinSize.h = high;
}

Window::Window(int x, int y, int with, int high) {
    m_WinSize.w = with;
    m_WinSize.h = high;
}

Window::Window(XRect winSize) {
    m_WinSize = winSize;
}

XResult Window::Initialize() {
    XResult result = XResultSuccess;

    if (0 != SDL_Init(SDL_INIT_EVERYTHING)) {
        result = XResultFailed;
//        XPrint(std::cerr, __func__, "SDL_Init Failed, result: ", result);
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init Failed, result: %d", result);
        return result;
    }
    if (0 != TTF_Init()) {
        result = XResultFailed;
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_Init Failed, result: %d", result);
//        XPrint(std::cerr, __func__, "TTF_Init Failed, result: ", result);
    }
    if (0 != IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP)) {
        result = XResultFailed;
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "IMG_Init Failed, result: %d", result);
//        XPrint(std::cerr, __func__, "IMG_Init Failed, result: ", result);
    }

    m_WinRender = nullptr;
    m_Window = nullptr;

    m_WinSize.x = SDL_WINDOWPOS_CENTERED;
    m_WinSize.y = SDL_WINDOWPOS_CENTERED;

    if (m_WindowTitle.empty()) {
        m_WindowTitle = "Default";
    }

    m_Window = SDL_CreateWindow(m_WindowTitle.c_str(), m_WinSize.x, m_WinSize.y, m_WinSize.w, m_WinSize.h,
                              SDL_WINDOW_SHOWN);

    if (nullptr == m_Window) {
        result = XResultFailedNewObject;
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed create window object");
        return result;
    }

    // index is render device, like Direct3D，OpenGL，Software, use -1 will auto selected best one
    // flags will use this default selected
    m_WinRender = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (nullptr == m_WinRender) {
        result = XResultFailedNewObject;
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed create renderer object");
        return result;
    }

    XPrint(std::cout, "Window Initialize Success");
    return result;
}

void Window::Destroy() {
//    SDL_DestroyTexture();
    SDL_DestroyRenderer(m_WinRender);
    SDL_DestroyWindow(m_Window);


    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Window::SetWindowTitle(const std::string& title) {
    if (!title.empty()) {
        m_WindowTitle = title;
    }
}

void Window::ApplySurfaceToTexture(int x, int y, SDL_Texture *texture, SDL_Renderer *rend, SDL_Rect *clip)
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

void Window::Show() {
    SDL_Event sdlEvent;
    bool quit = false;

    while (!quit) {
        if (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
//            if (sdlEvent.type == SDL_QUIT) {
//                quit = true;
//            }
        }

//        SDL_RenderClear(m_WinRender);
//        SDL_RenderPresent(m_WinRender);
    }

    Destroy();
}

SDL_Texture *Window::LoadImageFromFile(std::string file)
{
    SDL_Texture *tex = nullptr;
    tex = IMG_LoadTexture(m_WinRender, file.c_str());
    if (tex == nullptr) {
        throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
    }
    return tex;
}

void Window::LoadImage(std::string file, int x, int y) {
    // TODO tex could be Member variables
    SDL_Texture *tex = nullptr;
    tex = LoadImageFromFile(std::move(file));

    // TODO For test func
    int iW, iH;
    SDL_QueryTexture(tex, NULL, NULL, &iW, &iH);
    x = m_WinSize.w / 2 - iW / 2;
    y = m_WinSize.h / 2 - iH / 2;

    SDL_RenderClear(m_WinRender);
    ApplySurfaceToTexture(x, y, tex, m_WinRender);
    SDL_RenderPresent(m_WinRender);

    SDL_DestroyTexture(tex);
}


