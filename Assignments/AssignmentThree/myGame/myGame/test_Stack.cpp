#include "Stack.h"
#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Stack<int> myStack(2, 2);

	std::cout << "Testing push() and expand()\nExpected: 10. Result: ";
	for (int i = 1; i <= 10; i++)
	{
		myStack.push(i);
	}
	std::cout << myStack.peek() << std::endl;

	std::cout << std::endl;

	std::cout << "Testing peek() a\nExpected: 10. Result: ";
	std::cout << myStack.peek() << std::endl;

	std::cout << std::endl;

	std::cout << "Testing pop()\nExpected:11987654321. Result: ";
	for (int i = 1; i <= 10; i++)
	{
		std::cout << myStack.pop();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Testing pop() on empty stack\nExpected: Cannot pop on empty stack. Result: ";
	try
	{
		myStack.pop();
	}
	catch (char * e)
	{
		std::cout << e << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing peek() on empty stack\nExpected: Cannot peek on empty stack. Result: ";
	try
	{
		myStack.peek();
	}
	catch (char * e)
	{
		std::cout << e << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing copy constructor\nExpected: 10987654321. Result: ";
	for (int i = 1; i <= 10; i++)
	{
		myStack.push(i);
	}
	Stack<int> cStack(myStack);
	for (int i = 1; i <= 10; i++)
	{
		std::cout << cStack.pop();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Testing assignment operator\nExpected: 10987654321. Result: ";
	Stack<int> aStack;
	aStack = myStack;
	for (int i = 1; i <= 10; i++)
	{
		std::cout << aStack.pop();
	}

	std::cout << std::endl;
	std::cout << std::endl;
	system("Pause");
	return 0;
}