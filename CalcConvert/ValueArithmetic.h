#pragma once
#include <string>

namespace VA
{
	float Add(float f1, float f2);
	float Subtract(float f1, float f2);
	float Mult(float f1, float f2);
	float Division(float f1, float f2);

	std::string AND(std::string h1, std::string h2);
	std::string NOT(std::string h1, std::string h2);
	std::string OR(std::string h1, std::string h2);
	std::string NOR(std::string h1, std::string h2);
	std::string XOR(std::string h1, std::string h2);
	std::string SHR(std::string h1, std::string h2);
	std::string SHL(std::string h1, std::string h2);
}