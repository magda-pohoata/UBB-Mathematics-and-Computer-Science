#pragma once

#include "Request.h"

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
	void addLast(Request);
	bool removeLast();
	bool remove(int);
	bool isEmpty();
	bool isFull();
	int search(int);

	int getLength() const { return m_length; }
	int getCapacity() const { return m_capacity; }
	Request* getArray() { return m_arr; }

	Request& operator[](int i);
	DynamicArray& operator+(Request);
	DynamicArray& operator=(const DynamicArray&);
	friend ostream& operator<<(ostream& os, const DynamicArray&);


private:
	int m_length;
	int m_capacity;
	Request* m_arr;

	static int idGenerator;
};