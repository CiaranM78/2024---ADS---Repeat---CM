
#include "App.h"
#include <sstream>


#pragma region void apps

App::App(const string& filePath)
{

	calc = new RPNCalculator<double>(filePath);

	optionsData.menuOption = InvalidInput;

	optionsData.value = 0.0;

	optionsData.valueMessage = "X";

	menuoOptionsMap = {
		{"q",Quit},
		{"c",Clear},
		{"+",Plus},
		{"-",Minus},
		{"/",Divide},
		{"*",Multiply},
		{"s",Square},
		{"^",Power},
		{"n",Negate},
		{"p",Pop},
		{"l",Print}
	};
}

void App:: printMenu() {

	cout << colours.YELB << "Enter c to clear the stack." << endl
		<< "+ to add." << endl
		<< "- to subtract." << endl
		<< "/ to divide." << endl
		<< "* to multiply." << endl
		<< "s to square." << endl
		<< "^ to power." << endl
		<< "n to negate." << endl
		<< "p to pop current value." << endl
		<< "l to print options." << endl
		<< "q to quit." << endl << endl << colours.reset;
	
}

void App:: calculatorOperation() {



	while (optionsData.menuOption != Quit) {

		

		cout << colours.CYNB << optionsData.valueMessage << " > ";
		
		setMenuOption();

		switch (optionsData.menuOption)
		{
			case Quit:
				break;

			case Clear:
				calc->clear();
				break;

			case Plus:
				try 
				{
					calc->add();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Minus:
				try
				{
					calc->subtract();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Divide:
				try
				{
					calc->divide();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Multiply:
				try
				{
					calc->multiply();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Square:
				try
				{
					calc->square();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Power:
				try
				{
					calc->power();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Negate:
				try
				{
					calc->negate();
				}
				catch (const std::exception& e)
				{
					cout << colours.REDB << e.what() << endl << endl;
				}
				break;

			case Pop:
				calc->pop();
				break;

			case Push:
				calc->push(optionsData.value);
				break;

			case InvalidInput:
				break;

			case Print:
				printMenu();
				break;
		}
		
		setValue();
	}

}

void App::welcomeMessage()
{
	cout << colours.GRNB << "Hi my name is Ciaran Murtagh and this is my Calculator that uses Reverse Polish Notation or RPN for short." << endl << endl;
}

void App::setMenuOption()
{
	string input;
	cin >> input;

	if (isNumber(input)) {
		optionsData.menuOption = Push;
		optionsData.value = stoi(input);
		return;
	}
	

	map<string, MenuOptions>::iterator it = menuoOptionsMap.find(input);

	if (it != menuoOptionsMap.end()) {

		optionsData.menuOption = it->second;
	
	}
	else {
		cout << "Invalid input. Please enter a valid command or a number." << endl;
	}

}

bool App::isNumber(const string& s)
{
	stringstream ss(s);
	double d;
	return ss >> d && ss.eof();
}


void App::setValue()
{
	if (calc->isEmpty())
	{
		optionsData.valueMessage = "X";
	}
	else
	{
		optionsData.valueMessage = to_string(calc->value());
	}
}

#pragma endregion 


void App::startUp()
{
	welcomeMessage();
	printMenu();
	calculatorOperation();
}
