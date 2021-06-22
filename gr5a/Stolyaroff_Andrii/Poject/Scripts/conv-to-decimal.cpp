#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "binary.h"
#include "data.h"

using namespace std;

union dtype
{
    uint64_t u64;
    uint8_t u8[8];
} type;

int main()
{
    ofstream fout;
    fout.open("frames.csv");
    for (int i = 0; i < IMAGES_1_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_1[i], 8);
        fout << type.u64 << "\n";
    }
    for (int i = 0; i < IMAGES_2_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_2[i], 8);
        fout << type.u64 << "\n";
    }
    for (int i = 0; i < IMAGES_3_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_3[i], 8);

        fout << type.u64 << "\n";
    }
    for (int i = 0; i < IMAGES_4_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_4[i], 8);
        fout << type.u64 << "\n";
    }
    for (int i = 0; i < IMAGES_5_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_5[i], 8);
        fout << type.u64 << "\n";
    }
    for (int i = 0; i < IMAGES_6_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_6[i], 8);
        fout << type.u64 << "\n";
    }
    for (int i = 0; i < IMAGES_7_LEN; i++)
    {
        memcpy(&type.u8, IMAGES_7[i], 8);
        fout << type.u64 << "\n";
    }
    return 0;
}
