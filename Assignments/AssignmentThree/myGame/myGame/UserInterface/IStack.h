#ifndef ISTACK_H
#define ISTACK_H
template <typename T>
class IStack
{
public:
	virtual ~IStack() = 0 {};
	virtual void push(const T& element) = 0;
	virtual T& pop() = 0;
	virtual T& peek() const = 0;
	virtual void set(const T& element) = 0;
	virtual bool isEmpty() const = 0;
};


#endif