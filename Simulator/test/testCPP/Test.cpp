//
// Created by mi on 2021/6/21.
//

#include "Test.h"

Test::Test() {

}

Test::~Test() {

}

void Test::TestVoid() {    void *test = nullptr;
    auto test_auto = new (void*);
    char *str = "X";
    auto test_piont = new (void*);
    test_piont = &test;

    test = nullptr;

//    test = (void*)str;
    *test_piont = /*(void*)*/str;

    std::cout << "test: " << test << std::endl;
    std::cout << "test: " << (char*)test << std::endl;
    std::cout << "test: " << &test << std::endl;
    std::cout << "test_auto: " << test_auto << std::endl;
    std::cout << "test_auto: " << &test_auto << std::endl;
    std::cout << "str: " << &str << std::endl;

    printf("test: %s\n", (char*)test);

    delete test_auto;
//    delete test_piont;
}

void Test::TestLoadRawAndPrint() {
    auto t1 = new MipiRaw2Raw();
    t1->ReadData("/home/mi/workspace/code/PhoenixSimulator/Simulator/test/testCPP/ImageProcess/res/IMG_20210708_202151-564_b[0]_w[4080]_h[3072]_sw[0]_sh[0].RAWMIPI12");

    delete t1;

}
