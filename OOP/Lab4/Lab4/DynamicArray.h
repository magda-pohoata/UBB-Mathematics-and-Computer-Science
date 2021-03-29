#pragma once

#include "Complex.h"

class DynamicArray
{
public:
	//DynamicArray& operator=(const DynamicArray& a);   //assignment operator
	//copy constructor
	//deconstructor
	//rule of 3 ^^


	DynamicArray();
	DynamicArray(const DynamicArray& a);
	~DynamicArray();
	void resize();
	void addLast(Complex);
	void removeLast();
	int getLength() const { return m_length; }
	int getCapacity() const { return m_capacity; }

	Complex& operator[](int i);
	DynamicArray& operator+(Complex);
	DynamicArray& operator=(const DynamicArray&);
	friend ostream& operator<<(ostream& os, const DynamicArray&);


private:
	int m_length;
	int m_capacity;
	Complex* m_arr;
};

