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
		}
	};

	TEST_CLASS(ValueAritmetic)
	{
	public:
		TEST_METHOD(And)
		{
			Assert::AreEqual(static_cast<std::string>("00000000000000000000000000000000"), VA::AND("00000000000000000000000000000000", "1"));
		}
	};
}
