#pragma once

#include <stack>
#include <math.h>
#include <cmath>

using namespace std;

template<class T> class RPNCalculator
{
private:

	stack<T> stk;

public:

#pragma region 

	RPNCalculator(const string& filePath);

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

#pragma endregion 

};


template <class T>
RPNCalculator<T>::RPNCalculator(const string& filePath)
{

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
	


}

template <class T>
void RPNCalculator<T>::subtract()
{
	checkSize("subtract");

	
		T op1 = stk.top();
		stk.pop();
		T op2 = stk.top();
		stk.pop();
		stk.push(op2 - op1);
	
}

template <class T>
void RPNCalculator<T>::divide()
{

	checkSize("divide");

	
		T op1 = stk.top();
		stk.pop();
		T op2 = stk.top();
		stk.pop();
		stk.push(op2 / op1);

}

template <class T>
void RPNCalculator<T>::multiply()
{

	checkSize("multiply");

	
		T op1 = stk.top();
		stk.pop();
		T op2 = stk.top();
		stk.pop();
		stk.push(op2 * op1);
	
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

}

template <class T>
void RPNCalculator<T>::negate()
{
	if (isEmpty())
	{
		throw logic_error("Invalid operation on a empty stack.");
	}

	if (stk.top() > 0)
	{
		T op = stk.top();
		stk.pop();
		stk.push(op - op - op);
	}
}

#pragma  endregion 

#pragma region stack options


template <class T>
void RPNCalculator<T>::checkSize(const string& calculatorNotation)
{
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



#pragma endregion 



