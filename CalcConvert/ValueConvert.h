#pragma once
#include <iostream>
#include <stdio.h>
#include <bitset>
namespace VC
{
    void FloatToBinary(float f);
    void FloatToHex(float f);

    std::string binary_to_float(std::bitset<32> input);
    void binary_to_SEM(std::bitset<32> input);
    std::string binary_to_hex(std::bitset<32> input);
    
    std::string hex_to_binary(std::string input);
    std::string hex_to_float(std::string input);
    void hex_to_SEM(std::string input);
    //void HexToInt();
    //void HexToFloat();

    //void BinaryToInt();
    //void BinaryToFloat();
}
