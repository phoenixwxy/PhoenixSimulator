//
// Created by mi on 2021/7/12.
//

#include "Window.h"

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
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Window::SetWindowTitle(const std::string& title) {
    if (!title.empty()) {
        m_WindowTitle = title;
    }
}

XResult Window::ApplySurfaceToTexture(int x, int y, SDL_Texture *texture, SDL_Renderer *render) {
    return 0;
}


