#include "pch.h"
#include "CppUnitTest.h"
#include "../2024-ADS-repeat-CM/RPNCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RPNCalculatorTest
{


	TEST_CLASS(RPNCalculatorTEST)
	{
	private:

		RPNCalculator<int>* calc;

	public:

		TEST_METHOD_INITIALIZE(settinguptests) {
		
			calc = new RPNCalculator<int>();
		}

		TEST_METHOD_CLEANUP(clearingtestdata) {

			delete calc;

		}
		TEST_METHOD(TestPush)
		{
			
			Assert::AreEqual(0, calc->size());
			calc->push(1);
			Assert::AreEqual(1, calc->size());

		}

		TEST_METHOD(TestAdd)
		{
			
			calc->push(1);
			calc->push(1);
			calc->add();
			Assert::AreEqual(2, *calc->value());

		}

		TEST_METHOD(TestAddNotEqual)
		{

			
			calc->push(1);
			calc->push(2);
			calc->add();
			Assert::AreNotEqual(2, *calc->value());

		}

		TEST_METHOD(Testsubtract)
		{

			
			calc->push(10);
			calc->push(8);
			calc->subtract();
			Assert::AreEqual(2, *calc->value());

		}

		TEST_METHOD(TestsubtractNotEqual)
		{

			
			calc->push(10);
			calc->push(8);
			calc->subtract();
			Assert::AreNotEqual(6, *calc->value());

		}

		TEST_METHOD(Testdivide)
		{

		
			calc->push(500);
			calc->push(5);
			calc->divide();
			Assert::AreEqual(100, *calc->value());

		}

		TEST_METHOD(TestdivideNotEqual)
		{

		
			calc->push(500);
			calc->push(5);
			calc->divide();
			Assert::AreNotEqual(5, *calc->value());

		}

		TEST_METHOD(Testmultiply)
		{

			
			calc->push(10);
			calc->push(2);
			calc->multiply();
			Assert::AreEqual(20, *calc->value());

		}

		TEST_METHOD(TestmultiplyNotEqual)
		{

			
			calc->push(10);
			calc->push(2);
			calc->multiply();
			Assert::AreNotEqual(2, *calc->value());

		}

		TEST_METHOD(Testsquare)
		{

			
			calc->push(8);
			calc->square();
			Assert::AreEqual(64, *calc->value());

		}

		TEST_METHOD(Testsquarebyzero)
		{


			calc->push(0);
			calc->square();
			Assert::AreEqual( 0, *calc->value());

		}

		TEST_METHOD(Testnegate)
		{

			
			calc->push(5);
			calc->negate();
			Assert::AreEqual(-5, *calc->value());

		}

		TEST_METHOD(TestnegateNotEqual)
		{

			
			calc->push(5);
			calc->negate();
			Assert::AreNotEqual(5, *calc->value());

		}
		//TEST_METHOD(TestAddoneNumber)
		//{
		//	RPNCalculator<int> calc;
		//	calc.push(1);
		//	Assert::AreEqual(1, calc.size());
		//	void(*funct)() = []{calc.add();};
		//	Assert::ExpectException<logic_error>(funct);
		//	Assert::AreEqual(1, calc.size());

		//}
		TEST_METHOD(TestHasValuesinStack)
		{
			
			calc->push(7.89);
			Assert::IsFalse(calc->isEmpty());
			

		}
		TEST_METHOD(TestHasNOValuesinStack)
		{
			
			Assert::IsTrue(calc->isEmpty());


		}
		TEST_METHOD(TestDoubles)
		{
		
			calc->push(7.8);
			calc->push(5.5);
			calc->add();
			Assert::AreEqual(13.3, *calc->value(), 0.01);


		}

		TEST_METHOD(TestDoublesNotEqual)
		{
		
			calc->push(7.8);
			calc->push(5.2);
			calc->add();
			Assert::AreNotEqual(13.3, *calc->value(), 0.01);


		}

		TEST_METHOD(TestDoublesandInt)
		{
			
			calc->push(7.8);
			calc->push(5);
			calc->add();
			Assert::AreEqual(12.8, *calc->value(), 0.01);


		}

		TEST_METHOD(TestDoublesandIntNotEqual)
		{
		
			calc->push(7.8);
			calc->push(5);
			calc->add();
			Assert::AreNotEqual(12, *calc->value(), 0.01);


		}

		TEST_METHOD(TestPointerNULL)
		{
			
			Assert::IsNull(calc->value());
		}

		TEST_METHOD(TestPointerNotNULL)
		{
			
			calc->push(5.5);
			Assert::IsNotNull(calc->value());
		}

		TEST_METHOD(TestAreSameInput)
		{
			
			calc->push(5.5);
			int *top = calc->value();
			calc->push(5.5);

			Assert::AreNotSame(top, calc->value());
			Assert::AreEqual(top, calc->value());
			
		}

	};
}
