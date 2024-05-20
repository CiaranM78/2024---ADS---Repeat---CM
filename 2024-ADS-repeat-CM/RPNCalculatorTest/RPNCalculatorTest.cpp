#include "pch.h"
#include "CppUnitTest.h"
#include "../2024-ADS-repeat-CM/RPNCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RPNCalculatorTest
{
	RPNCalculator<int> calc;

	TEST_CLASS(RPNCalculatorTEST)
	{

	//	TEST_CLASS_INITIALIZE (settinguptests){

	//		calc = new RPNCalculator<int>();
	//	}

	//	TEST_CLASS_CLEANUP(clearingtestdata) {


	//		delete calc;

	//	}



	public:
		
		TEST_METHOD(TestPush)
		{

			RPNCalculator<int> calc;
			Assert::AreEqual(0, calc.size());
			calc.push(1);
			Assert::AreEqual(1, calc.size());

		}

		TEST_METHOD(TestAdd)
		{

			RPNCalculator<int> calc;
			calc.push(1);
			calc.push(1);
			calc.add();
			Assert::AreEqual(2, *calc.value());

		}

		TEST_METHOD(Test)
		{

			RPNCalculator<int> calc;
			calc.push(8);
			calc.push(10);
			calc.subtract();
			Assert::AreEqual(2, *calc.value());

		}

		TEST_METHOD(Testdivide)
		{

			RPNCalculator<int> calc;
			calc.push(5);
			calc.push(500);
			calc.divide();
			Assert::AreEqual(100, *calc.value());

		}

		TEST_METHOD(Testnegate)
		{

			RPNCalculator<int> calc;
			calc.push(5);
			calc.negate();
			Assert::AreEqual(-5, *calc.value());

		}
		TEST_METHOD(TestAddoneNumber)
		{

			calc.push(1);
			Assert::AreEqual(1, calc.size());
			void(*funct)() = []{calc.add();};
			Assert::ExpectException<logic_error>(funct);
			Assert::AreEqual(1, calc.size());

		}
		TEST_METHOD(TestHasValuesinStack)
		{
			RPNCalculator<int> calc;
			calc.push(7.89);
			Assert::IsFalse(calc.isEmpty());
			

		}
		TEST_METHOD(TestHasNOValuesinStack)
		{
			RPNCalculator<int> calc;
			Assert::IsTrue(calc.isEmpty());


		}
		TEST_METHOD(TestDoubles)
		{
			RPNCalculator<double> calc;
			calc.push(7.8);
			calc.push(5.5);
			calc.add();
			Assert::AreEqual(13.3, *calc.value(), 0.01);


		}

		TEST_METHOD(TestPointerNULL)
		{
			RPNCalculator<double> calc;
			Assert::IsNull(calc.value());
		}

		TEST_METHOD(TestPointerNotNULL)
		{
			RPNCalculator<double> calc;
			calc.push(5.5);
			Assert::IsNotNull(calc.value());
		}

		TEST_METHOD(TestAreSameInput)
		{
			RPNCalculator<double> calc;
			calc.push(5.5);
			double* top = calc.value();
			calc.push(5.5);

			Assert::AreNotSame(top, calc.value());
			Assert::AreEqual(*top, *calc.value());
			
		}

	};
}
