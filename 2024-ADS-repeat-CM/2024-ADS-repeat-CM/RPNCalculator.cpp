// 2024-ADS-repeat-CM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RPNCalculator.h"

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

	 
	int currentinput;

	cout << "enter calculater value" << endl;
	cin >> currentinput;



}




int main()
{
	welcomemessage();
	CalculatorOperation();


	return 0;
}


