// 2024-ADS-repeat-CM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RPNCalculator.h"
#include "RPNLogPrint.h"
#include "sstream"


using namespace std;

void welcomemessage() {
	
cout << "Hi my name is Ciaran Murtagh and this is my Calculator that uses Reverse Polish Notation or RPN for short." << endl;
 cout << "Enter c to clear the stack." << endl;
 cout << "t to add." << endl;
 cout << "y to subtract." << endl;
 cout << "u to divide." << endl;
 cout << "i to multiply." << endl;
 cout << "s to square." << endl;
 cout << "n to negate." << endl;
 cout << "p to pop current value." << endl;
 cout << "q to quit." << endl;
}

void CalculatorOperation() {

	stack<int>  calc;
	string input;


	while (true) {

		cout << "enter calculater value";
		cin >> input;






		// if statements for whatever letter input has been entered


		   //quit
		if (input == "q") {

//shuts down calculator


		}

		//clear
		else if (input == "c") {

			while (calc.size() != 0) {
				calc.pop();
			}

			cout << "calculator history is now cleared" <<

		}

		//add
		else if (input == "t") {

			if (size() < 2)
			{
				throw logic_error("Not enough Numbers to add together");

			}

			if (calc.size() != 0) {
				calc.push();
				calc.push();
				calc.add();
			}

		}

		//subtract
		else if (input == "y") {

			if (size() < 2)
			{
				throw logic_error("Not enough Numbers to subtract together");

			}

			if (calc.size() != 0) {
				calc.push();
				calc.push();
				calc.subtract();
			}
		}

		//divide
		else if (input == "u") {

			if (size() < 2)
			{
				throw logic_error("Not enough Numbers to divide together");

			}

			if (calc.size() != 0) {
				calc.push();
				calc.push();
				calc.divide();
			}
		}

		//multiply
		else if (input == "i") {

			if (size() < 2)
			{
				throw logic_error("Not enough Numbers to multiply together");

			}

			if (calc.size() != 0) {
				calc.push();
				calc.push();
				calc.multiply();
			}
		}

		//to the power of
		else if (input == "s") {


			if (calc.size() != 0) {
				calc.push();
				calc.push();
				calc.square();
			}
		}

		//turn into negetive number
		else if (input == "n") {

			if (calc.size() != 0) {
				calc.push();
				calc.negate();
			}
		}

		//pop value out of stack
		else if (input == "p") {

			if (calc.size() != 0) {
				calc.pop();
				cout << "pop worked";
			}
		}

		else
			cout << "invalid input";
	}
}




int main()
{
	welcomemessage();
	CalculatorOperation();


	return 0;
}


