//
// Created by mi on 2021/6/11.
//

#include <iostream>

#include "Window.h"

int main()
{
    std::cout << "Simulator Begin" << std::endl;

    Window window;
    window.SetWindowTitle("123");
    window.Initialize();
    window.LoadImage("/home/mi/workspace/code/PhoenixSimulator/Resource/TwinklebearDev-Lessons/res/Lesson1/hello.bmp");

    window.Show();
//    SDL_Delay(2000);

    std::cout << "Simulator End" << std::endl;


//    SDL_Init(SDL_INIT_TIMER);
//    SDL_Log("ForTest");
//    SDL_Quit();

}