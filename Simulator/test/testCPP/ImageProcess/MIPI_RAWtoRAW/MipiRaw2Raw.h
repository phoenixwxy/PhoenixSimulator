//
// Created by mi on 2021/7/8.
//

#ifndef SIMULATOR_MIPIRAW2RAW_H
#define SIMULATOR_MIPIRAW2RAW_H

#include <iostream>
#include <string>
#include <fstream>

class MipiRaw2Raw {
public:
    MipiRaw2Raw();

    virtual ~MipiRaw2Raw();

    // TODO Error this function
    void ReadData(std::string filePath);

private:
    std::ifstream m_MipiRawData;
};


#endif //SIMULATOR_MIPIRAW2RAW_H
