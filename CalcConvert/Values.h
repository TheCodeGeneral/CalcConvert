#pragma once
#include <string>
#include <stdexcept>
#include "ValueConvert.h"
class Values
{
	std::string* bin = nullptr;
	std::string* hex = nullptr;
	std::string* sem = nullptr;
	float* f = nullptr;

	void InitOthers();
	public:
		Values(std::string str, bool isHex, bool isBin, bool isSEM);
		Values(float f);
		virtual ~Values();

		std::string ToString();
	
};

