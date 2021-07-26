//
// Created by mi on 2021/7/8.
//

#include <bitset>
#include <cmath>
#include "MipiRaw2Raw.h"
#include <stdio.h>

MipiRaw2Raw::MipiRaw2Raw() {

}

// TODO Error this function
void MipiRaw2Raw::ReadData(std::string filePath) {
    int width = 4080;
    int height = 3072;
    FILE* fp = fopen(filePath.c_str(), "rb"); //输入MIPI图像流
    FILE* fo = fopen("/home/mi/workspace/code/PhoenixSimulator/Simulator/test/testCPP/ImageProcess/res/test.RAW", "wb"); //输出Raw图像流
    unsigned char buf[1024*8];
    int stride = ceil(width*(10/8)/8)*8; //计算Stride
    int i = 0;
    int j = 0;
    int n = 0;
    while(!feof(fp)) {
        for (n = 0; n < height; n++) { //循环height次
            int ret = fread(buf, 1, stride, fp); // 每次从输入MIPI图像中取出一个Stride到buf，然后读取指针跳到下一个
            if (!ret) {
                break;
            }
            for (j = 0; j < width/4; j++) { //循环width/4次
                unsigned char * p = buf + j*5; //每次从buf中拿出5个
                for (i = 0; i < 4; i++) {  //对这五个Bytes进行移位处理
                    unsigned short d = p[i];
                    d = d << 2; //向左移两位，空出两个位置
                    d = d | ((p[4]>>(i*2))&0x3); //将第5个bytes对应的两位放入后两位
                    fwrite(&d, 2, 1, fo); //输出还原后的10bit像素
                }
            }
        }
    }
//    long long temp;
//    m_MipiRawData.open(filePath, std::ios::in|std::ios::binary);
////    std::cout << m_MipiRawData << std::endl
//    while (m_MipiRawData) {
//        m_MipiRawData.read((char*) (&temp), sizeof(long long));
////        std::cout << std::bitset<12>(temp) << std::endl;
//        std::cout << std::hex << temp << std::endl;
//    }
}

MipiRaw2Raw::~MipiRaw2Raw() {

}
