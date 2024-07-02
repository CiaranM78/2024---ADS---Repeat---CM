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


	RPNCalculator();

	void welcomemessage();

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

	// negates, i.e. 3 becomes -3
	void negate();

	// tests to see if there are elements on the stack
	bool isEmpty();

	// clears out the stack
	void clear();

	// returns the topmost value
	T* value();

	// returns the topmost value and pops it off the top
	T pop();

	T top();


	//checks the size of the stack to see if the query is possible
	void checkSize(const string&);
};

template <class T>
void RPNCalculator<T>::welcomemessage() {

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

template <class T>
void RPNCalculator<T>::checkSize(const string& calculatorNotation)
{
	if (size() < 2)
	{
		throw logic_error("Not enough Numbers to" + calculatorNotation + "together");
	}
}

template <class T>
RPNCalculator<T>::RPNCalculator()
{

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

	T op = stk.top();
	stk.pop();
	T op1 = stk.top();

	if (op != 1) {

	int newop = pow(op, op1);
	stk.push(newop);

	}

	if (op == 1) {
		stk.pop();
		op = 1;
		stk.push(op);
	}

	if (op == 0 )
	{
		throw logic_error("0 to the power of will always be 0");
	}
}

template <class T>
void RPNCalculator<T>::negate()
{
	if (stk.top() > 0)
	{
		T op = stk.top();
		stk.pop();
		stk.push(op - op - op);
	}
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
T* RPNCalculator<T>::value()
{
	if (stk.size() == 0) {
		return nullptr;
	}

		
	return &stk.top();

}

template <class T>
T RPNCalculator<T>::pop()
{

	if (isEmpty())
	{
		return 0;	
	}

	T value = stk.top();
	stk.pop();
	return value;
}

template <class T>
T RPNCalculator<T>::top()
{

	if (isEmpty())
	{
		return 0;
	}

	T value = stk.top();
	return value;
}






