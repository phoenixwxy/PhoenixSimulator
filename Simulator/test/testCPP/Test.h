//
// Created by mi on 2021/6/21.
//

#ifndef SIMULATOR_TEST_H
#define SIMULATOR_TEST_H

#include <iostream>
#include <memory>

#include "MipiRaw2Raw.h"

class Test {
public:
    Test();
    ~Test();

    void TestVoid();
    void TestLoadRawAndPrint();

    template<typename T, typename ...Args>
    std::unique_ptr<T> make_unique( Args&& ...args ) {
        return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
    }

private:

};


#endif //SIMULATOR_TEST_H
