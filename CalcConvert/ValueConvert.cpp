#include "ValueConvert.h"
namespace VC
{
    void FloatToBinary(float f)
    {
        std::cout << std::bitset<sizeof f * 8>(*(long unsigned int*)(&f)) << std::endl;
    }

    void FloatToHex(float f)
    {
        union float_bytes {
            float f;
            char  b[sizeof(float)];
        };
        union float_bytes fb = { 1.1 };
        for (int i = sizeof(float) - 1; i >= 0; --i)
            printf("%hhx ", fb.b[i]);
    }

}