#include "DynamicArray.h"
#include "Request.h"

int DynamicArray::idGenerator = 0;

DynamicArray::DynamicArray()
{
	this->m_length = 0;
	this->m_capacity = 100;
	this->m_arr = new Request[100];  
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	this->m_length = a.m_length;
	this->m_capacity = a.m_capacity;
	this->m_arr = new Request[this->m_capacity];
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
	Request* newArr = new Request[newCapacity];
	for (int i = 0; i < this->m_length; i++)
	{
		newArr[i] = this->m_arr[i];
	}
	delete[] this->m_arr;
	this->m_arr = newArr;
	this->m_capacity = newCapacity;
}

void DynamicArray::addLast(Request c)
{
	idGenerator++;
	c.setId(idGenerator);
	if (isFull())
	{
		this->resize();
	}
	this->m_arr[this->m_length] = c;
	this->m_length++;
}


bool DynamicArray::removeLast()
{
	if (isEmpty() == true)
	{
		//delete (this->m_arr + this->m_length);
		m_length--;
		return true;
	}
	else
		return false;
}

bool DynamicArray::remove(int position)
{
	if (isEmpty() == false)
	{
		for (int j = position + 1; j < this->m_length; j++)
			this->m_arr[j - 1] = this->m_arr[j];
		this->m_length--;
		return true;
	}
	else
		return false;
}

bool DynamicArray::isEmpty()
{
	return this->getLength() == 0;
}

bool DynamicArray::isFull()
{
	return this->getLength() == this->getCapacity();
}

int DynamicArray::search(int id)
{
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->getArray()[i].getId() == id)
			return i;
	}
	return -1;
}

Request& DynamicArray::operator[](int i)
{
	return *(this->m_arr + i);
}

DynamicArray& DynamicArray::operator+(Request c)
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
		this->m_arr = new Request[this->m_capacity];
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
		os << d.m_arr[i];
	}
	os << endl;
	return os;
}