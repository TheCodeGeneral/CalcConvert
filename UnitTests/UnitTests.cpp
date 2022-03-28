#include <math.h>
#include "pch.h"
#include "CppUnitTest.h"
#include "ValueConvert.h"
#include "ValueArithmetic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	/*
	* To view and run tests, at the top of visual studio
	* Click view, then Test Explorer.
	* Or use the key combo Ctrl+E then press T
	* 
	* To Write tests, use the Assert class methods to test methods
	* Some useful methods from the Assert class
	* Assert::AreEqual(ExpectedValue, ActualValue)
	* Assert::AreNotEqual(ExpectedValue, ActualValue)
	* 
	* Use the website https://www.h-schmidt.net/FloatConverter/IEEE754.html to get test values
	*/
	TEST_CLASS(ValueConvert)
	{
	public:
		TEST_METHOD(FloatToBinary)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000000"), VC::FloatToBinary(0));
			Assert::AreEqual(static_cast<std::string>("01000010100010101101011100001010"), VC::FloatToBinary(69.420));
			Assert::AreEqual(static_cast<std::string>("01111111110000000000000000000000"), VC::FloatToBinary(nanf("")), L"Not a number");
			Assert::AreEqual(static_cast<std::string>("01111111100000000000000000000000"), VC::FloatToBinary(INFINITY), L"+inf");
			Assert::AreEqual(static_cast<std::string>("11111111100000000000000000000000"), VC::FloatToBinary(-INFINITY), L"-inf");
		}

		TEST_METHOD(FloatToHex)
		{
			Assert::AreEqual(static_cast<std::string>("0x00000000"), VC::FloatToHex(0));
			Assert::AreEqual(static_cast<std::string>("0x428ad70a"), VC::FloatToHex(69.420));
			Assert::AreEqual(static_cast<std::string>("0x7fc00000"), VC::FloatToHex(nanf("")), L"Not a number");
			Assert::AreEqual(static_cast<std::string>("0x7f800000"), VC::FloatToHex(INFINITY), L"+inf");
			Assert::AreEqual(static_cast<std::string>("0xff800000"), VC::FloatToHex(-INFINITY), L"-inf");
		}
	};

	TEST_CLASS(ValueAritmetic)
	{
	public:
		TEST_METHOD(And)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000000"), VA::AND("00000000000000000000000000000000", "1"));
		}
		TEST_METHOD(Or)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000001"), VA::OR("00000000000000000000000000000000", "1"));
		}
		TEST_METHOD(Not)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000000"), VA::NOT("11111111111111111111111111111111"));
			Assert::AreEqual(static_cast<std::string>("0x00000000"), VA::NOT("0x11111111"));
		}
		TEST_METHOD(Xor)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000001"), VA::XOR("00000000000000000000000000000000", "1"));
		}
		TEST_METHOD(Nor)
		{
			Assert::AreEqual(static_cast<std::string>("11111111111111111111111111111110"), VA::NOR("00000000000000000000000000000000", "1"));
		}
		TEST_METHOD(Shr)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000000"), VA::SHR("00000000000000000000000000000001", "1"));
		}
		TEST_METHOD(Shl)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000010"), VA::SHL("00000000000000000000000000000001", "1"));
		}
	};
}
