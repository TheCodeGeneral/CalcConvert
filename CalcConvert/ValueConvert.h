#pragma once
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <algorithm>
#include <cctype>
#include <complex>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>
#include <cmath>
#include <map>
#include <utility>
//#include <bits/stdc++.h>
#include <valarray>
namespace VC
{
    std::string FloatToBinary(float f);
    void FloatToHex(float f);

    std::string binary_to_float(std::bitset<32> input);
    void binary_to_SEM(std::bitset<32> input);
    std::string binary_to_hex(std::bitset<32> input);
    
    std::string hex_to_binary(std::string input);
    std::string hex_to_float(std::string input);
    void hex_to_SEM(std::string input);
    float cast_to_float(std::string f_test);
    //void HexToInt();
    //void HexToFloat();

    //void BinaryToInt();
    //void BinaryToFloat();
}
