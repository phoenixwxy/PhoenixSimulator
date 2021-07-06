//
// Created by mi on 2021/6/30.
//

#include "std_utility.h"

#include "std_forward.hpp"

std_utility::std_utility() {
    std::cout << __func__ << "Begin" << std::endl;
}

std_utility::~std_utility() {
    std::cout << __func__ << "End" << std::endl;
}

void std_utility::forward() {
    test_forward();
}
