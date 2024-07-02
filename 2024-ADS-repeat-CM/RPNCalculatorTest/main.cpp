// 2024-ADS-repeat-CM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "RPNCalculator.h"
#include "RPNLogPrint.h"
#include "sstream"


using namespace std;

void CalculatorOperation() {


	welcomemessage();
	RPNCalculator<int> calc;

	stack<int>  calc;
	char input;


	while (true) {

		cout << "enter calculater value";
		cin >> input;



		// if statements for whatever letter input has been entered


		if (isdigit(input)) {

			calc.push(input);
		}
		else {



			//quit
			if (input == 'q') {

				//shuts down calculator

				break;


			}

			//clear
			else if (input == 'c') {

				while (calc.size() != 0) {
					calc.pop();

					cout << "calculator history is now cleared" << endl;
				}



			}


			//add
			else if (input == 't') {

				if (calc.size() < 2)
				{
					throw logic_error("Not enough Numbers to add together");

				}

				if (calc.size() != 0) {

					int numberinputone = calc.top();

					int	numberinputtwo = calc.top();

					calc.push(numberinputone);
					calc.push(numberinputtwo);
					calc.add(numberinputone, numberinputtwo);
				}

			}

			//subtract
			else if (input == 'y') {

				if (calc.size() < 2)
				{
					throw logic_error("Not enough Numbers to subtract together");

				}

				if (calc.size() != 0) {

					int numberinputone = calc.top();

					int	numberinputtwo = calc.top();

					calc.push(numberinputone);
					calc.push(numberinputtwo);
					calc.subtract(numberinputone, numberinputtwo);
				}
			}

			//divide
			else if (input == 'y') {

				if (calc.size() < 2)
				{
					throw logic_error("Not enough Numbers to divide together");

				}

				if (calc.size() != 0) {

					int numberinputone = calc.top();

					int	numberinputtwo = calc.top();

					calc.push(numberinputone);
					calc.push(numberinputtwo);
					calc.divide(numberinputone, numberinputtwo);
				}
			}

			//multiply
			else if (input == 'i') {

				if (calc.size() < 2)
				{
					throw logic_error("Not enough Numbers to multiply together");

				}

				if (calc.size() != 0) {

					int numberinputone = calc.top();

					int	numberinputtwo = calc.top();

					calc.push(numberinputone);
					calc.push(numberinputtwo);
					calc.multiply(numberinputone, numberinputtwo);
				}
			}

			//to the power of
			else if (input == 's') {


				if (calc.size() != 0) {

					int numberinputone = calc.top();

					int	numberinputtwo = calc.top();

					calc.push(numberinputone);
					calc.push(numberinputtwo);
					calc.square(numberinputone, numberinputtwo);
				}
			}

			//turn into negetive number
			else if (input == 'n') {

				if (calc.size() != 0) {

					int negatenumber = calc.top();

					calc.push(negatenumber);
					calc.negate(negatenumber);
				}
			}

			//pop value out of stack
			else if (input == 'p') {

				if (calc.size() != 0) {
					calc.pop();
					cout << "pop worked";
				}
			}
			else
				cout << "invalid input";

		}

	}

}




int main()
{
	CalculatorOperation();


	return 0;
}


