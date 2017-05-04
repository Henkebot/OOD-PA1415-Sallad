#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector
{
public:
	Vector(int capacity = 10, int increment = 10);
	Vector(const Vector<T> &other);
	virtual ~Vector();

	void addLast(const T &element);
	void addFirst(const T &element);
	void addAt(int index, const T &element) throw(...);

	T getFirst() const throw(...);
	T getLast() const throw(...);
	T getAt(int index) throw(...);

	T removeFirst() throw(...);
	T removeLast() throw(...);
	T removeAt(int index) throw(...);
	void removeBetween(int start, int end) throw(...);

	void clear();
	Vector<T>& operator=(const Vector<T> &other);
	Vector<T> operator+(const Vector<T> &other) const throw(...);
	T operator[](int index) const throw(...);

private:
	int nrOfElements;
	int cap;
	int increment;

	T* elements;

private:
	void expand();
	void copy(const Vector &other);
};

template<typename T>
Vector<T>::Vector(int capacity, int increment)
{
	if (capacity > 0)
	{
		this->cap = capacity;
	}
	else
	{
		this->cap = 10;
	}
	if (increment > 0)
	{
		this->increment = increment;
	}
	else
	{
		this->increment = 10;
	}
	this->nrOfElements = 0;
	this->elements = new T[this->cap];
}

template<typename T>
Vector<T>::Vector(const Vector & other)
{
	this->copy(other);
}

template<typename T>
Vector<T>::~Vector()
{
	this->clear();
}

template<typename T>
void Vector<T>::addLast(const T & element)
{
	if (this->nrOfElements == this->cap)
	{
		this->expand();
	}
	this->elements[this->nrOfElements++] = element;
}

template<typename T>
void Vector<T>::addFirst(const T & element)
{
	if (this->nrOfElements == this->cap)
	{
		this->expand();
	}
	if (this->nrOfElements != 0)
	{
		T temp = this->elements[0];
		this->elements[this->nrOfElements++] = temp;
	}
	else
	{
		this->nrOfElements++;
	}
	this->elements[0] = element;
	
}

template<typename T>
void Vector<T>::addAt(int index, const T & element) throw(...)
{
	if (index < 0 || index > this->nrOfElements - 1)
	{
		throw "Out of bounce!";
	}
	if (this->nrOfElements == this->cap)
	{
		this->expand();
	}
	T temp = this->elements[index];
	this->elements[index] = element;
	this->elements[nrOfElements++] = temp;
}

template<typename T>
T Vector<T>::getFirst() const throw(...)
{
	if (nrOfElements == 0)
	{
		throw "No elements in vector!";
	}

	return this->elements[0];
}

template<typename T>
T Vector<T>::getLast() const throw(...)
{
	if (nrOfElements == 0)
	{
		throw "No elements in vector!";
	}

	return this->elements[this->nrOfElements-1];
}

template<typename T>
T Vector<T>::getAt(int index) throw(...)
{
	if (nrOfElements == 0 || index < 0 || index >= this->nrOfElements)
	{
		throw "No elements in vector or out of range!";
	}

	return this->elements[index];
}

template<typename T>
T Vector<T>::removeFirst() throw(...)
{
	if (nrOfElements == 0)
	{
		throw "No elements in vector!";
	}
	T temp = this->elements[0];

	this->elements[0] = this->elements[--this->nrOfElements];

	return temp;
}

template<typename T>
T Vector<T>::removeLast() throw(...)
{
	if (nrOfElements == 0)
	{
		throw "No elements in vector!";
	}
	T temp = this->elements[--this->nrOfElements];
	return temp;
}

template<typename T>
T Vector<T>::removeAt(int index) throw(...)
{
	if (nrOfElements == 0 || index < 0 || index >= this->nrOfElements)
	{
		throw "No elements in vector or out of range!";
	}

	T temp = this->elements[index];
	this->elements[index] == this->elements[--this->nrOfElements];

	return temp;
}

template<typename T>
void Vector<T>::removeBetween(int start, int end) throw(...)
{
	if (nrOfElements == 0 || start < 0 || end >= this->nrOfElements || start > end || start == end)
	{
		throw "No elements in vector or out of range or start index is greater or equal to end index!";
	}
	int counter = start;
	for (int i = this->nrOfElements - 1; i >= end ; i--)
	{
		this->elements[counter++] = this->elements[i];
	}
	this->nrOfElements -= (end + 1) - start;
}

template<typename T>
void Vector<T>::clear()           
{
	delete[]this->elements;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector & other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector & other) const throw(...)
{
	Vector<T> temp(*this);
	if (typeid(this->elements[0]) == typeid(other.elements[0]))
	{
		for (int i = 0; i < other.nrOfElements; i++)
		{
			temp.addLast(other.elements[i]);
		}
	}
	else
	{
		throw "Different objects in vectors!";
	}
	return temp;
}

template<typename T>
T Vector<T>::operator[](int index) const throw(...)
{
	if (index < 0 || index > this->nrOfElements - 1)
	{
		throw "Out of range!";
	}
	return this->elements[index];
}

template<typename T>
void Vector<T>::expand()
{
	this->cap += this->increment;
	T* temp = new T[this->cap];
	for (int i = 0; i < this->nrOfElements; i++)
	{
		temp[i] = this->elements[i];
	}
	delete[]this->elements;
	this->elements = temp;
	temp = nullptr;
}

template<typename T>
void Vector<T>::copy(const Vector & other)
{
	this->nrOfElements = other.nrOfElements;
	this->cap = other.cap;
	this->increment = other.increment;
	this->elements = new T[this->cap];
	for (int i = 0; i < this->nrOfElements; i++)
	{
		this->elements[i] = other.elements[i];
	}
}
#endif // !VECTOR_HPP

