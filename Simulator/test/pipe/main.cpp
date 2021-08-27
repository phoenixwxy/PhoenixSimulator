//
// Created by mi on 2021/8/26.
//
//#include <stdio.h>
//
//int main(void)
//{
//    FILE *fp;
//    if ((fp = popen("wget www.baidu.com -O -", "r")) == NULL) {//用“curl www.baidu.com”也是一样的
//        perror("popen failed");
//        return -1;
//    }
//    char buf[256];
//    while (fgets(buf, 255, fp) != NULL) {
//        printf("%s", buf);
//    }
//    if (pclose(fp) == -1) {
//        perror("pclose failed");
//        return -2;
//    }
//    return 0;
//}
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <regex>

#include <cstdio>

std::string S1()
{
    return "test first frame arrived 123";
}


int main(int argc,char **argv)
{
    std::vector<std::string> parameter_vec;
    FILE* logcat;
    parameter_vec.reserve(argc);
    for (int i = 0; i < argc; i++) {
        parameter_vec.emplace_back(argv[i]);
    }
    if (parameter_vec[1] == "S") {
        std::cout << "Sender" << std::endl;
        char buffer[1024];
        logcat = popen("adb logcat", "r");

        std::smatch results;
        std::string pattern(".*first frame arrived.*");
        std::regex reg(pattern);


        while(fgets(buffer, sizeof buffer, logcat) != nullptr) {
            std::string s(buffer);
            if (std::regex_search(s, results, reg)) {
                std::cout << results.str() << std::endl;
            }
        }
        pclose(logcat);
    } else if (parameter_vec.at(1) == "R") {
        std::cout << "Recipient" << std::endl;
    } else {
        std::cout << "error arg" << std::endl;
    }
}