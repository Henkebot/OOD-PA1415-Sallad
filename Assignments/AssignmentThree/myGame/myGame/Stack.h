#ifndef STACK_H
#define STACK_H
#include "IStack.h"

template <typename T>
class Stack : public IStack<T>
{
public:
	Stack(int cap = 10, int expandRate = 2);
	Stack(const Stack &other);
	virtual ~Stack();
	void push(const T& element);
	T& pop();
	T& peek() const;
	void set(const T& element); //This will first pop than push
	bool isEmpty() const;
	Stack& operator=(const Stack &other);

private:
	void initiateVars(int cap, int expandRate); //This sets all the variables
	void expand();
	void copy(const Stack &other);
	void cleanup();

private:
	T* stack;
	int cap;
	int top;
	int expandRate;
};

template<typename T>
inline Stack<T>::Stack(int cap, int expandRate)
{
	this->initiateVars(cap, expandRate);
}

template<typename T>
inline Stack<T>::Stack(const Stack<T> & other)
{
	this->copy(other);
}

template<typename T>
inline Stack<T>::~Stack()
{
	this->cleanup();
}

template<typename T>
inline void Stack<T>::push(const T & element)
{
	if (this->top == cap)
	{
		this->expand();
	}

	this->stack[this->top++] = element;
}

template<typename T>
inline T& Stack<T>::pop()
{
	if (this->isEmpty()) throw "Cannot pop on empty stack";
	return this->stack[--this->top];
}

template<typename T>
inline T & Stack<T>::peek() const
{
	if (this->isEmpty()) throw "Cannot peek on empty stack";
	return this->stack[this->top - 1];
}

template<typename T>
inline void Stack<T>::set(const T & element)
{
	if (!this->isEmpty())
	{
		this->pop();
	}
	this->push(element);
}

template<typename T>
inline Stack<T> & Stack<T>::operator=(const Stack<T> & other)
{
	if (this != &other)
	{
		this->cleanup();
		this->copy(other);
	}
	return *this;
}

template<typename T>
inline void Stack<T>::initiateVars(int cap, int expandRate)
{
	if (cap <= 0)
	{
		cap = 5;
	}
	if (expandRate <= 1)
	{
		expandRate = 2;
	}

	this->cap = cap;
	this->expandRate = expandRate;
	this->stack = new T[this->cap];

	this->top = 0;
}

template<typename T>
inline void Stack<T>::expand()
{
	this->cap *= this->expandRate;
	T* temp = new T[this->cap];
	for (int i = 0; i < this->top; i++)
	{
		temp[i] = this->stack[i];
	}
	delete[] this->stack;
	this->stack = temp;
}

template<typename T>
inline void Stack<T>::copy(const Stack<T> & other)
{
	this->cap = other.cap;
	this->expandRate = other.expandRate;
	this->top = other.top;
	this->stack = new T[this->cap];
	for (int i = 0; i < this->top; i++)
	{
		this->stack[i] = other.stack[i];
	}
}

template<typename T>
inline void Stack<T>::cleanup()
{
	delete[]this->stack;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return this->top == 0;
}
#endif


