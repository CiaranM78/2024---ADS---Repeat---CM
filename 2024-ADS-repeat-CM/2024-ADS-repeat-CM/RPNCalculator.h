#pragma once


#include <stack>

using namespace std;



template<class T> class RPNCalculator
{
private:

	stack<T> stk;

public:

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
};

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
	if (size() < 2)
{
		throw logic_error("Not enough Numbers to add together");

}


	T op1 = stk.top();
	stk.pop();
	T op2 = stk.top();
	stk.pop();
	stk.push(op1 + op2);

}

template <class T>
void RPNCalculator<T>::subtract()
{
	if (size() < 2)
	{
		throw logic_error("Not enough Numbers to add together");

	}


	T op1 = stk.top();
	stk.pop();
	T op2 = stk.top();
	stk.pop();
	stk.push(op1 - op2);

}

template <class T>
void RPNCalculator<T>::divide()
{

	if (size() < 2)
	{
		throw logic_error("Not enough Numbers to add together");

	}


	T op1 = stk.top();
	stk.pop();
	T op2 = stk.top();
	stk.pop();
	stk.push(op1 / op2);

}

template <class T>
void RPNCalculator<T>::multiply()
{

	if (size() < 2)
	{
		throw logic_error("Not enough Numbers to add together");

	}


	T op1 = stk.top();
	stk.pop();
	T op2 = stk.top();
	stk.pop();
	stk.push(op1 * op2);

}

template <class T>
void RPNCalculator<T>::square()
{

	if (size() < 2)
	{
		throw logic_error("Not enough Numbers to add together");

	}


	T op1 = stk.top();
	stk.pop();
	T op2 = stk.top();
	stk.pop();
	stk.push(op1 ** op2);

}

template <class T>
void RPNCalculator<T>::negate()
{
	if (stk.top() > 0)
	{
		T op = stk.top();
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
	else
		return false;

	//return stk.size()==0;

}

template <class T>
void RPNCalculator<T>::clear()
{
	while (stk.size() > 0)
	{
		size--;
	}

}

template <class T>
T* RPNCalculator<T>::value()
{
	if (stk.size() == 0) {
		return nullptr;
	}

	else	
	return &stk.top();

}

template <class T>
T RPNCalculator<T>::pop()
{

	if (stk.top != nullptr)
	{
		size--;


	}



}




