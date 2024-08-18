#pragma once

#include <stack>
#include <math.h>
#include <cmath>
#include <fstream>

//printing code references https://cplusplus.com/reference/fstream/ofstream/ofstream/#google_vignette
// https://bytes.com/topic/c/63964-file-creation-problem-windows-using-fstream


using namespace std;

template<class T> class RPNCalculator
{
private:

	stack<T> stk;
	ofstream logFile;

public:

#pragma region 

	RPNCalculator(const string& filePath);

	//empty constructor for test
	RPNCalculator();

	// pushes a new operand onto the stack
	void push(T item);

	// checks overall size of the stack
	int size();

	// binary operators:
	void add();

	void subtract();

	void multiply();

	void divide();

	// squares the current value
	void square();

	// squares to a certain value
	void power();

	// negates, i.e. 3 becomes -3
	void negate();

	// tests to see if there are elements on the stack
	bool isEmpty();

	// clears out the stack
	void clear();

	// returns the topmost value
	T value();

	// returns the topmost value and pops it off the top
	T pop();

	//checks the size of the stack to see if the query is possible
	void checkSize(const string&);

	//handles the printing function into a text file
	void logOperation(const string& operation);

#pragma endregion 

};


template <class T>
RPNCalculator<T>::RPNCalculator(const string& filePath)
{
	//opens file so it can catalog calculator history
	logFile.open(filePath, ofstream::out | ofstream::trunc);
}

template <class T>
RPNCalculator<T>::RPNCalculator()
{

}

#pragma region functions

template <class T>
void RPNCalculator<T>::add()
{
	checkSize("add");

	T op1 = stk.top();
	stk.pop();
	T op2 = stk.top();
	stk.pop();
	stk.push(op1 + op2);

	//prints the output of method into txt file
	logOperation(to_string(op1) + " + " + to_string(op2) + " = " + to_string(op1 + op2));

}

template <class T>
void RPNCalculator<T>::subtract()
{
	checkSize("subtract");

	
		T op1 = stk.top();
		stk.pop();
		T op2 = stk.top();
		stk.pop();
		stk.push(op1 - op2);

		//prints the output of method into txt file
		logOperation(to_string(op1) + " - " + to_string(op2) + " = " + to_string(op1 - op2));
	
}

template <class T>
void RPNCalculator<T>::divide()
{

	checkSize("divide");

	
		T op1 = stk.top();
		stk.pop();
		T op2 = stk.top();
		stk.pop();

		
		if (op2 == T{})
		{
			throw logic_error("Error in division.");
		}

		stk.push(op1 / op2);

		//prints the output of method into txt file
		logOperation(to_string(op1) + " / " + to_string(op2) + " = " + to_string(op1 / op2));
}

template <class T>
void RPNCalculator<T>::multiply()
{

	checkSize("multiply");

	
		T op1 = stk.top();
		stk.pop();
		T op2 = stk.top();
		stk.pop();
		stk.push(op1 * op2);
	
		//prints the output of method into txt file
		logOperation(to_string(op1) + " * " + to_string(op2) + " = " + to_string(op1 * op2));
}


template <class T>
void RPNCalculator<T>::square()
{
	if (isEmpty())
	{
		throw logic_error("Invalid operation on a empty stack.");
	}

	T op = stk.top();
	stk.pop();
	int newop = pow(op, 2);
	stk.push(newop);

	//prints the output of method into txt file
	logOperation(to_string(op) + "^" + to_string(2) + " = " + to_string(newop));
	
}

template <class T>
void RPNCalculator<T>::power()
{
	checkSize("power");

	T op = stk.top();
	stk.pop();
	T op1 = stk.top();
	int newop = pow(op, op1);
	stk.push(newop);

	//prints the output of method into txt file
	logOperation(to_string(op) + "^" + to_string(op1) + " = " + to_string(newop));

}

template <class T>
void RPNCalculator<T>::negate()
{
	if (isEmpty())
	{
		throw logic_error("Invalid operation on a empty stack.");
	}


	T op = stk.top();
	stk.pop();
	stk.push(-op);

	//prints the output of method into txt file
	logOperation("negate(" + to_string(op) + ") = " + to_string(-op));
	

	
}

#pragma  endregion 

#pragma region stack options


template <class T>
void RPNCalculator<T>::checkSize(const string& calculatorNotation)
{

	//checks size of stack and throws logic error if it isnt big enough
	if (size() < 2)
	{
		clear();
		throw logic_error("Not enough numbers to " + calculatorNotation + " together.");
	}
}



template <class T>
void RPNCalculator<T>::push(T item)
{
	
		stk.push(item);
	
	
}

template <class T>
int RPNCalculator<T>::size()
{
	return stk.size();
}


template <class T>
bool RPNCalculator<T>::isEmpty()
{

	if (stk.size() == 0)
	{
		return true;
	}
		return false;

}

template <class T>
void RPNCalculator<T>::clear()
{
	while (stk.size() > 0)
	{
		stk.pop();
	}
	//prints the output of method into txt file
	logOperation("History Cleared.");
}

template <class T>
T RPNCalculator<T>::value()
{
	if (isEmpty())
	{
		return 0;
	}

	T value = stk.top();
	return value;
}

template <class T>
T RPNCalculator<T>::pop()
{
	if (isEmpty())
	{
		return T{};
	}

	T value = stk.top();
	stk.pop();
	return value;
}

template <class T>
void RPNCalculator<T>::logOperation(const string& operation)
{
	if (logFile.is_open())
	{
		logFile << operation << endl;
	}
}

#pragma endregion 



