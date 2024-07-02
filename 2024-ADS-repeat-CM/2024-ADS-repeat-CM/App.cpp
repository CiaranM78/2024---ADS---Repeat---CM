


#include <iostream>
#include "RPNCalculator.h"
#include "RPNLogPrint.h"
#include "sstream"
using namespace std;


using namespace std;

void CalculatorOperation() {


	//welcomemessage();
	RPNCalculator<int> calc;

	
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

				calc.clear();
				cout << "calculator history is now cleared" << endl;
			}


			//add
			else if (input == 't') {

				cout << "+" << endl;
				calc.add();
	
			}

			//subtract
			else if (input == 'y') {

				cout << "-" << endl;
				calc.subtract();
			}

			//divide
			else if (input == 'y') {

				cout << "%" << endl;
				calc.divide();
			}

			//multiply
			else if (input == 'i') {

				cout << "X" << endl;
				calc.multiply();
			
			}

			//to the power of
			else if (input == 's') {

				cout << "power of" << endl;
				calc.square();
			
			}

			//turn into negetive number
			else if (input == 'n') {

				cout << "turned last number negetive" << endl;
				calc.negate();
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