#pragma once
#include <string>
#include "ValueConvert.h"

namespace VA
{
	float Add(float f1, float f2);
	float Subtract(float f1, float f2);
	float Mult(float f1, float f2);
	float Division(float f1, float f2);

	std::string AND(std::string op1, std::string op2);
	std::string NOT(std::string input);
	std::string OR(std::string op1, std::string op2);
	std::string NOR(std::string op1, std::string op2);
	std::string XOR(std::string op1, std::string op2);
	std::string SHR(std::string op1, std::string op2);
	std::string SHL(std::string op1, std::string op2);
}