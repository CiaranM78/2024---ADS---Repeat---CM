#include "pch.h"
#include "CppUnitTest.h"
#include "../2024-ADS-repeat-CM/RPNCalculator.h"
#include "Vector3.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework
		{

			template<>static std::wstring ToString<Vector3>(const Vector3& v)
			{
				std::wostringstream oss;
				oss << L"(" << v.x << L", " << v.y << L", " << v.z << L")";
				return oss.str();
			}


		}
	}
}



namespace RPNCalculatorTest
{


	TEST_CLASS(RPNCalculatorTEST)
	{
	private:

		RPNCalculator<double>* calc;

	public:

#pragma region testsetup/cleanup


		TEST_METHOD_INITIALIZE(settinguptests) {
		
			calc = new RPNCalculator<double>();
		}

		TEST_METHOD_CLEANUP(clearingtestdata) {

			delete calc;

		}

#pragma endregion 

#pragma region function tests

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
			Assert::AreEqual(2.0, calc->value());

		}

		TEST_METHOD(TestAddNotEqual)
		{

			
			calc->push(1);
			calc->push(2);
			calc->add();
			Assert::AreNotEqual(2.0, calc->value());

		}

		TEST_METHOD(Testsubtract)
		{

			
			calc->push(10);
			calc->push(8);
			calc->subtract();
			Assert::AreEqual(2.0, calc->value());

		}

		TEST_METHOD(TestsubtractNotEqual)
		{

			
			calc->push(10);
			calc->push(8);
			calc->subtract();
			Assert::AreNotEqual(6.0, calc->value());

		}

		TEST_METHOD(Testdivide)
		{

		
			calc->push(500);
			calc->push(5);
			calc->divide();
			Assert::AreEqual(100.0, calc->value());

		}

		TEST_METHOD(TestdivideNotEqual)
		{

		
			calc->push(500);
			calc->push(5);
			calc->divide();
			Assert::AreNotEqual(5.0, calc->value());

		}

		TEST_METHOD(Testmultiply)
		{

			
			calc->push(10);
			calc->push(2);
			calc->multiply();
			Assert::AreEqual(20.0, calc->value());

		}

		TEST_METHOD(TestmultiplyNotEqual)
		{

			
			calc->push(10);
			calc->push(2);
			calc->multiply();
			Assert::AreNotEqual(2.0, calc->value());

		}

		TEST_METHOD(Testsquare)
		{

			
			calc->push(2);
			calc->push(8);
			calc->square();
			Assert::AreEqual(64.0, calc->value());

		}

		TEST_METHOD(Testsquarebyzero)
		{


			calc->push(3);
			calc->push(0);
			calc->square();
			Assert::AreEqual( 0.0, calc->value());

		}


		TEST_METHOD(Testplusbynegetive)
		{


			calc->push(-3);
			calc->push(10);
			calc->add();
			Assert::AreEqual(7.0, calc->value());

		}

		/*TEST_METHOD(Testplusbynegetive)
		{


			calc->push(-3);
			calc->push(10);
			calc->add();
			Assert::AreEqual(7.0, calc->value());

		}*/

		TEST_METHOD(Testplusmultiplybynegetiveposistive)
		{


			calc->push(-3);
			calc->push(10);
			calc->multiply();
			Assert::AreEqual(-30.0, calc->value());

		}

		TEST_METHOD(Testplusmultiplybynegetive)
		{


			calc->push(-3);
			calc->push(-10);
			calc->multiply();
			Assert::AreEqual(30.0, calc->value());

		}

		TEST_METHOD(Testpluspowerbynegetive)
		{


			calc->push(-3);
			calc->push(10);
			calc->power();
			Assert::AreEqual(30.0, calc->value());

		}

		TEST_METHOD(Testdividebyzero)
		{


			calc->push(0);
			calc->push(0);
			calc->divide();
			Assert::AreEqual(0.0, calc->value());

		}

		TEST_METHOD(Testnegate)
		{

			
			calc->push(5);
			calc->negate();
			Assert::AreEqual(-5.0, calc->value());

		}

		TEST_METHOD(TestnegateNotEqual)
		{

			
			calc->push(5);
			calc->negate();
			Assert::AreNotEqual(5.0, calc->value());

		}
	
		TEST_METHOD(TestHasValuesinStack)
		{
			
			calc->push(7.89);
			Assert::IsFalse(calc->isEmpty());
			

		}
		TEST_METHOD(TestHasNOValuesinStack)
		{
			
			Assert::IsTrue(calc->isEmpty());


		}
#pragma endregion 

#pragma region doubles test
		TEST_METHOD(TestDoubles)
		{
		
			calc->push(7.8);
			calc->push(5.5);
			calc->add();
			Assert::AreEqual(13.3, calc->value(), 0.01);


		}

		TEST_METHOD(TestDoublesNotEqual)
		{
		
			calc->push(7.8);
			calc->push(5.2);
			calc->add();
			Assert::AreNotEqual(13.3, calc->value(), 0.01);


		}

		TEST_METHOD(TestDoublesandInt)
		{
			
			calc->push(7.8);
			calc->push(5);
			calc->add();
			Assert::AreEqual(12.8, calc->value(), 0.01);


		}

		TEST_METHOD(TestDoublesandIntNotEqual)
		{
		
			calc->push(7.8);
			calc->push(5);
			calc->add();
			Assert::AreNotEqual(12, calc->value(), 0.01);


		}
#pragma endregion 

#pragma region pointers tests
	

		TEST_METHOD(TestAddEmptyStack)
		{
			calc->push(12);
			auto fnc = [this] { calc->add(); };
			Assert::ExpectException<std::logic_error>(fnc, L"Not enough Numbers to add together");
			Assert::AreEqual(0, calc->size());
		}

		TEST_METHOD(TestAreSameInput)
		{
			
			calc->push(5.5);
			double top = calc->value();
			calc->push(5.5);

			Assert::AreNotSame(top, calc->value());
			Assert::AreEqual(top, calc->value());
			
		}
	

		TEST_METHOD(PopDoubleEmptyTest)
		{
			RPNCalculator<double>* calc = new RPNCalculator<double>();

			Assert::AreEqual(0.0, calc->pop());

		}

		TEST_METHOD(PopIntEmptyTest)
		{
			RPNCalculator<int>* calc = new RPNCalculator<int>();

			Assert::AreEqual(0, calc->pop());

		}

		TEST_METHOD(PopVector3EmptyTest)
		{
			RPNCalculator<Vector3>* calc = new RPNCalculator<Vector3>();
			
			Vector3* vector3 = new Vector3();
			Assert::AreEqual(*vector3, calc->pop());

		}

#pragma endregion 

#pragma region LogicTests

		TEST_METHOD(TestaddLogic)
		{
		
			auto fnc = [this] { calc->add(); };
			Assert::ExpectException<std::logic_error>(fnc, L"Not enough Numbers to add together");
		}

		TEST_METHOD(TestSubtractLogic)
		{
			auto fnc = [this] { calc->subtract(); };
			Assert::ExpectException<std::logic_error>(fnc, L"Not enough Numbers to subtract together");
		}

		TEST_METHOD(TestmultiplyLogic)
		{
			auto fnc = [this] { calc->multiply(); }; 
			Assert::ExpectException<std::logic_error>(fnc, L"Not enough Numbers to multiply together");
		}

		TEST_METHOD(TestdivideLogic)
		{
			auto fnc = [this] { calc->divide(); };  
			Assert::ExpectException<std::logic_error>(fnc, L"Not enough Numbers to divide together");
		}

		TEST_METHOD(TestsquareLogic)
		{
			auto fnc = [this] { calc->square(); };
			Assert::ExpectException<std::logic_error>(fnc, L"Cannot access top element from an empty stack.");
		}

		TEST_METHOD(TestnegateLogic)
		{
			auto fnc = [this] { calc->negate(); };
			Assert::ExpectException<std::logic_error>(fnc, L"Cannot access top element from an empty stack.");
		}

		

#pragma endregion 
	};
}
