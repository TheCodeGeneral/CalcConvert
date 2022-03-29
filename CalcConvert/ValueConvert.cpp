#include "ValueConvert.h"

namespace VC
{
    std::string FloatToBinary(float f)
    {
        return std::bitset<sizeof f * 8>(*(long unsigned int*)(&f)).to_string();
    }

    std::string FloatToHex(float f)
    {
        union float_bytes {
            float f;
            char  b[sizeof(float)];
        };
        union float_bytes fb = { f };
        std::stringstream stream;
        stream << std::hex << std::setfill('0') << "0x";


        for (int i = sizeof(float) - 1; i >= 0; --i)
            stream << std::setw(2) << (fb.b[i] & 0xFF);

        return stream.str();
    }

    float BinaryToFloat(std::bitset<32> input)
    {
        union long_float
        {
            unsigned long in;
            float out;
        };
        return long_float { input.to_ulong() }.out;
    }

    std::string binary_to_float(std::bitset<32> input)
    {
        float sign = (input[31] == 1) ? 1 : 0;
        float exponent = 0;
        float mantissa = 0.0;
        float bias = 127.0;
        float result;
        if(input.any())
        {
            for(std::size_t i = 23; i <= 30; i++)
            {
                exponent = exponent + input[i]*std::pow(2.0, i - 23.0);
            }
        }
        if(input.any())
        {
            for(std::size_t i = 0; i <= 22; i++)
            {
                mantissa = mantissa + input[i]*std::pow(2.0, i - 23.0);
            }
        }
        result = std::pow(-1.0, sign) * (1.0 + mantissa) * std::pow(2.0, exponent - bias);
        return std::to_string(result);
    }

    void binary_to_SEM(std:: bitset<32> input)
    {
        float sign = (input[31] == 1) ? 1 : 0;
        float exponent = 0;
        float mantissa = 0.0;
        if(input.any())
        {
            for(std::size_t i = 23; i <= 30; i++)
            {
                exponent = exponent + input[i]*std::pow(2.0, i - 23.0);
            }
        }
        if(input.any())
        {
            for(std::size_t i = 0; i <= 22; i++)
            {
                mantissa = mantissa + input[i]*std::pow(2.0, i - 23.0);
            }
        }
        std::cout << "\nsign: " << sign << "\texponent: " << exponent << "\tmantissa: " << mantissa << std::endl;
        for(std::size_t i = 31; i > 0; i--)
        {
            if(i == 30 || i == 22){std::cout << "\t";}
            std::cout << input[i];
        }
        std::cout << input[0] << std::endl;
    }

    std::string binary_to_hex(std::bitset<32> input)
    {
        std::string output;
        std::string temp = "";
        std::map<std::string, std::string> hex_value;
        hex_value.insert(std::pair<std::string, std::string>("0000", "0"));
        hex_value.insert(std::pair<std::string, std::string>("0001", "1"));
        hex_value.insert(std::pair<std::string, std::string>("0010", "2"));
        hex_value.insert(std::pair<std::string, std::string>("0011", "3"));
        hex_value.insert(std::pair<std::string, std::string>("0100", "4"));
        hex_value.insert(std::pair<std::string, std::string>("0101", "5"));
        hex_value.insert(std::pair<std::string, std::string>("0110", "6"));
        hex_value.insert(std::pair<std::string, std::string>("0111", "7"));
        hex_value.insert(std::pair<std::string, std::string>("1000", "8"));
        hex_value.insert(std::pair<std::string, std::string>("1001", "9"));
        hex_value.insert(std::pair<std::string, std::string>("1010", "A"));
        hex_value.insert(std::pair<std::string, std::string>("1011", "B"));
        hex_value.insert(std::pair<std::string, std::string>("1100", "C"));
        hex_value.insert(std::pair<std::string, std::string>("1101", "D"));
        hex_value.insert(std::pair<std::string, std::string>("1110", "E"));
        hex_value.insert(std::pair<std::string, std::string>("1111", "F"));
        std::map<std::string, std::string>::iterator it;

        for(std::size_t i = 31; i > 0; i--)
        {
            temp.append(std::to_string(input[i]));
            //std::cout << std::to_string(input[i]);
            if(i % 4 == 0 || i ==0)
            {
                it = hex_value.find(temp);
                output.append(it->second);
                temp = "";
            }
        }
        temp.append(std::to_string(input[0]));
        it = hex_value.find(temp);
        output.append(it->second);
        hex_value.clear();
        return output;
    }

    std::string hex_to_binary(std::string input)
    {
        std::string output = "";
        std::map<std::string, std::string> binary_value;
        binary_value.insert(std::pair<std::string, std::string>("0", "0000"));
        binary_value.insert(std::pair<std::string, std::string>("1", "0001"));
        binary_value.insert(std::pair<std::string, std::string>("2", "0010"));
        binary_value.insert(std::pair<std::string, std::string>("3", "0011"));
        binary_value.insert(std::pair<std::string, std::string>("4", "0100"));
        binary_value.insert(std::pair<std::string, std::string>("5", "0101"));
        binary_value.insert(std::pair<std::string, std::string>("6", "0110"));
        binary_value.insert(std::pair<std::string, std::string>("7", "0111"));
        binary_value.insert(std::pair<std::string, std::string>("8", "1000"));
        binary_value.insert(std::pair<std::string, std::string>("9", "1001"));
        binary_value.insert(std::pair<std::string, std::string>("A", "1010"));
        binary_value.insert(std::pair<std::string, std::string>("B", "1011"));
        binary_value.insert(std::pair<std::string, std::string>("C", "1100"));
        binary_value.insert(std::pair<std::string, std::string>("D", "1101"));
        binary_value.insert(std::pair<std::string, std::string>("E", "1110"));
        binary_value.insert(std::pair<std::string, std::string>("F", "1111"));
        std::map<std::string, std::string>::iterator it;

        for(char &c: input)
        {
            /*TODO: Implement try catch for value not in map.*/
            c = std::toupper(c, std::locale());
            std::string temp(1, c);
            //std::string temp = s;
            //temp = std::toupper(s, std::locale());
            it = binary_value.find(temp);
            output.append(it->second);
        }
        binary_value.clear();
        return output;
    }

    std::string hex_to_float(std::string input)
    {
        std::string output;
        std::bitset<32> temp(hex_to_binary(input));
        output = binary_to_float(temp);
        return output;
    }

    void hex_to_SEM(std::string input)
    {
        std::bitset<32> temp(hex_to_binary(input));
        binary_to_SEM(temp);
    }

    std::string float_to_binary(std::string input)
    {
        std::string output;
        float in = cast_to_float(input);
        std::bitset<32> result;
        int decimal_moves = -1;
        float exponent;
        std::string power;
        long long int integer_part;
        float decimal_part;
        std::string fraction = "";


        (in < 0) ? result[31] = 1 : result[31] = 0;
        in = std::abs(in);
        if(in > 0 && in < 1)
        {
            //Move decimal to right
        }
        //Else move decimal to left to normalize the manitissa
        integer_part = in;
        while(integer_part > 0)
        {
            if(integer_part % 2 == 0){fraction.append("0");}
            else if (integer_part % 2 != 0){fraction.append("1");}
            integer_part = integer_part / 2;
            decimal_moves += 1;
        }
        std::reverse(fraction.begin(), fraction.end());

        fraction.erase(fraction.begin());
        std::cout << "fraction:\t" << fraction << "\n" << "Decimal_Moves:\t" << decimal_moves << std::endl;
        exponent = 127.0 + (float)decimal_moves;
        if(std::abs(exponent) > 255.0){ std::cout << "NaN"; return "NaN";}
        exponent = std::abs(exponent);
        std::cout << exponent << "\t";
        integer_part = exponent;
        while(integer_part > 0)
        {
            if(integer_part % 2 == 0){power.append("0");}
            else if (integer_part % 2 != 0){power.append("1");}
            integer_part = integer_part / 2;
        }

        //Put Exponent in order and place in the bitset
        std::reverse(power.begin(), power.end());
        int string_pointer = power.size() - 1;
        for(std::size_t i = 23; i < 31; i++)
        {
            if(string_pointer < 0)
            {
                result[i] = 0;
            }
            else
            {
                //Cast char to string then int
                std::string temp(1, power[string_pointer]);
                result[i] = std::stoi(temp);
            }
            string_pointer--;
        }

        //calculate the decimal portion of the fraction

        int the_rest = 23 - fraction.size() - 1;
        std::string decimal = "";
        //just the decimal fraction portion of the number
        integer_part = in;
        decimal_part = in - integer_part;
        std::cout << "in: \t" << in << "-integer_part: \n" << integer_part << "=Decimal_part: \t" << decimal_part<<std::endl;
        if(the_rest > 0)
        {
            for(std::size_t i = 0; i <= the_rest; i++)
            {
                int temp;
                std::cout << "Decimal portion: "<< decimal_part << std::endl;
                decimal_part *= 2;
                temp = decimal_part;
                temp = std::abs(temp);
                decimal_part = std::abs(temp - decimal_part);
                fraction.append(std::to_string(temp));
            }
        }
        std::cout << "\n" << fraction << std::endl;
        std::reverse(fraction.begin(), fraction.end());
        //put the fraction string in the bitset fraction portion
        for(std::size_t i = 0; i < 23; i++)
        {
            //Cast char to string then int
            std::string temp(1, fraction[i]);
            //temp = std::stoi(temp);
            result[i] = std::stoi(temp);
        }
        //Test prints
        for(std::size_t i = 0; i <= 31; i++)
        {
            std::cout << result[i];
        }
        return output;
    }

    float cast_to_float(std::string f_test)
    {

        float f;
        try {
        f = std::stof(f_test);
        return f;
        } catch (...) {
            std::cout << "Please enter a valid floating point number:" << std::endl;
            std::string try_again;
            std::cin >> try_again;
            return cast_to_float(try_again);
        }
        return f;
    }
}