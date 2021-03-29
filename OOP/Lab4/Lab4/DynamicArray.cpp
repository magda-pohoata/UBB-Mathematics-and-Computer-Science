#include "DynamicArray.h"
#include "Complex.h"


DynamicArray::DynamicArray()
{
	this->m_length = 0;
	this->m_capacity = 100;
	this->m_arr = new Complex[100];  
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	this->m_length = a.m_length;
	this->m_capacity = a.m_capacity;
	this->m_arr = new Complex[this->m_capacity];
	for (int i = 0; i < this->m_length; i++)
	{
		this->m_arr[i] = a.m_arr[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] this->m_arr;
}

void DynamicArray::resize()
{
	int newCapacity = this->m_capacity * 2;
	Complex* newArr = new Complex[newCapacity];
	for (int i = 0; i < this->m_length; i++)
	{
		newArr[i] = this->m_arr[i];
	}
	delete[] this->m_arr;
	this->m_arr = newArr;
	this->m_capacity = newCapacity;
}

void DynamicArray::addLast(Complex c)
{
	if (this->m_length == this->m_capacity)
	{
		this->resize();
	}
	this->m_arr[this->m_length] = c;
	this->m_length++;
}


void DynamicArray::removeLast()
{
	if (this->m_length != 0)
	{
		//delete (this->m_arr + this->m_length);
		m_length--;
	}
}

Complex& DynamicArray::operator[](int i)
{
	return *(this->m_arr + i);
}

DynamicArray& DynamicArray::operator+(Complex c)
{
	this->addLast(c);
	return *this;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& a)
{
	if (this == &a)
	{
		return *this;
	}
	else
	{
		this->m_capacity = a.m_capacity;
		this->m_length = a.m_length;
		delete[] this->m_arr;
		this->m_arr = new Complex[this->m_capacity];
		for (int i = 0; i < a.m_length; i++)
		{
			this->m_arr[i] = a.m_arr[i];
		}
		return *this;
	}
}

ostream& operator<<(ostream& os, const DynamicArray& d)
{
	for (int i = 0; i < d.m_length; i++)
	{
		os << d.m_arr[i] << " ";
	}
	os << endl;
	return os;
}
