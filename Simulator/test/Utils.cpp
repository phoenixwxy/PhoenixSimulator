//
// Created by mi on 2021/6/29.
//

#include "Utils.h"

Utils::Utils()
{

}

Utils::~Utils() {

}

/*
 * Log an SDL error with some error message to the output stream of our choice
 * @param os The output stream to write the message too
 * @param msg The error message to write, format will be msg error: SDL_GetError()
 */
void Utils::LogSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}
