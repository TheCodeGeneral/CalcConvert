#include "ValueArithmetic.h"
namespace VA
{
	float Add(float f1, float f2)
	{
		return f1 + f2;
	}
	float Subtract(float f1, float f2)
	{
		return f1 - f2;
	}
	float Mult(float f1, float f2)
	{
		return f1 * f2;
	}
	float Division(float f1, float f2)
	{
		return f1 / f2;
	}

	std::string AND(std::string op1, std::string op2)
	{
		return "Not Implemented";
	}
	std::string NOT(std::string input)
	{
		// Check if hex or binary
		std::string result{};
		bool isHex = false;
		if (input[1] == 'x')
		{
			// convert to binary to make it easier
			input = VC::hex_to_binary(input);
			isHex = true;
		}

		for(int i = 0; i < input.size(); ++i)
		{
			result.push_back(input[i] == '0' ? '1' : '0');
		}

		if (isHex)
			return VC::binary_to_hex((std::bitset<32>{result}));
		return result;
	}
	std::string OR(std::string op1, std::string op2)
	{
		return "Not Implemented";
	}
	std::string NOR(std::string op1, std::string op2)
	{
		return NOT(OR(op1, op2));
	}
	std::string XOR(std::string op1, std::string op2)
	{
		return "Not Implemented";
	}
	std::string SHR(std::string op1, std::string op2)
	{
		return "Not Implemented";
	}
	std::string SHL(std::string op1, std::string op2)
	{
		return "Not Implemented";
	}
}