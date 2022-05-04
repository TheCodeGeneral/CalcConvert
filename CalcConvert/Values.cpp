#include "Values.h"

Values::Values(std::string str, bool isHex, bool isBin, bool isSEM)
{
	if ((isHex + isBin + isSEM) > 1)
		throw std::invalid_argument("Only 1 or none of the bool values can be set");

	if (isHex)
		hex = new std::string(str);
	else if (isBin)
		bin = new std::string(str);
	else
		sem = new std::string(str);
	InitOthers();
}
Values::Values(float f) 
{ 
	this->f = new float(f);
	InitOthers();
}
Values::~Values()
{
	delete f;
	delete bin;
	delete hex;
	delete sem;
}

void Values::InitOthers()
{
	if (f != nullptr)
	{
		hex = new std::string(VC::FloatToHex(*f));
		bin = new std::string(VC::FloatToBinary(*f));
		sem = new std::string(VC::BinaryToSEM(*bin));
	}
	else if (hex != nullptr)
	{
		f = new float(VC::hex_to_float(*hex));
		bin = new std::string(VC::FloatToBinary(*f));
		sem = new std::string(VC::BinaryToSEM(*bin));
	}
	else if (bin != nullptr)
	{
		f = new float(VC::BinaryToFloat(std::bitset<32>{*bin}));
		hex = new std::string(VC::FloatToHex(*f));
		sem = new std::string(VC::BinaryToSEM(*bin));
	}
	else if (sem != nullptr)
	{
		bin = new std::string(VC::SEM_to_binary(*sem));
		f = new float(VC::BinaryToFloat(std::bitset<32>{*bin}));
		hex = new std::string(VC::FloatToHex(*f));
	}
}
std::string Values::ToString()
{
	std::stringstream stream;
	stream << "Hex:\t" << *hex
		<< "\nBinary:\t" << *bin
		<< "\nSEM:\t" << *sem
		<< "\nFloat:\t" << *f << std::endl;

	return stream.str();
}
