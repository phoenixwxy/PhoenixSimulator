//
// Created by mi on 2021/6/29.
//

#ifndef SIMULATOR_UTILS_H
#define SIMULATOR_UTILS_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Utils {
public:
    Utils();

    ~Utils();

    /*
     * Log an SDL error with some error message to the output stream of our choice
     * @param os The output stream to write the message too
     * @param msg The error message to write, format will be msg error: SDL_GetError()
     */
    static void LogSDLError(std::ostream &os, const std::string &msg);



};


#endif //SIMULATOR_UTILS_H
