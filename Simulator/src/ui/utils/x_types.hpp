//
// Created by mi on 2021/7/12.
//

#ifndef SIMULATOR_X_TYPES_HPP
#define SIMULATOR_X_TYPES_HPP

#include <iostream>

// Constant
typedef int XResult;
static const XResult XResultSuccess = 0;
static const XResult XResultFailed = 1;
static const XResult XResultFailedNewObject = 2;

// Structure
typedef struct Rect
{
    int x, y;
    int w, h;
} XRect;

// Function
template<typename T, typename... Types>
void XPrint(std::ostream &os, const T &t) {
    os << t << std::endl;
}

template<typename T, typename... Types>
void XPrint(std::ostream &os, const T &t, const Types &... rest) {
    os << ",";
    XPrint(os, rest...);
}

#endif //SIMULATOR_X_TYPES_HPP
