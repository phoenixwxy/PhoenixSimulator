//
// Created by mi on 2021/6/11.
//

#include <iostream>

#include "Window.h"

int main()
{
    std::cout << "Simulator Begin" << std::endl;

    Window window;
    window.Initialize();
    window.SetWindowTitle("123");

    SDL_Delay(2000);

    std::cout << "Simulator End" << std::endl;


//    SDL_Init(SDL_INIT_TIMER);
//    SDL_Log("ForTest");
//    SDL_Quit();

}