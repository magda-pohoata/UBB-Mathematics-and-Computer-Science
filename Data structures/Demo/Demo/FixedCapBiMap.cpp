#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
	//TODO - Implementation
	if (capacity <= 0)
	{
		throw exception();
	}
	this->capacity = capacity;
	this->nrPairs = 0;
	this->elements = new TElem[capacity];
}
// theta(1)/theta(cap)

FixedCapBiMap::~FixedCapBiMap() {
	//TODO - Implementation
	delete[] this->elements;
}
// theta(1)

bool FixedCapBiMap::add(TKey c, TValue v){
	//TODO - Implementation

	if (this->capacity == this->nrPairs)
	{
		throw exception();
	}
	int index = 0;
	int count = 0;
	while (count != 2 && index != nrPairs)
	{
		if (this->elements[index].first == c)
		{
			count++;
		}
		index++;
	}
	if (count == 2)
	{
		return false;
	}
	else
	{
		this->elements[this->nrPairs].first = c;
		this->elements[this->nrPairs].second = v;
		this->nrPairs++;
		return true;
	}
}
// best case: theta(1)    worst case: theta(nrPairs) => total complexity: O(nrPairs)

ValuePair FixedCapBiMap::search(TKey c) const{
	//TODO - Implementation

	ValuePair returnedValue;
	returnedValue.first = NULL_TVALUE;
	returnedValue.second = NULL_TVALUE;
	int count = 0;
	int index = 0;
	while (count != 2 && index != this->nrPairs)
	{
		if (this->elements[index].first == c)
		{
			if (count == 0)
			{
				returnedValue.first = this->elements[index].second;
			}
			else
			{
				returnedValue.second = this->elements[index].second;
			}
			count++;
		}
		index++;
	}

	return returnedValue;
}
// best case: theta(1)    worst case: theta(nrPairs) => total complexity: O(nrPairs)


bool FixedCapBiMap::remove(TKey c, TValue v){
	//TODO - Implementation

	int index = 0;
	bool found = false;
	while (index < this->nrPairs && found == false)
	{
		if (this->elements[index].first == c && this->elements[index].second == v)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}
	if (found == false)
	{
		return false;
	}
	else
	{
		this->elements[index] = this->elements[this->nrPairs - 1];
		this->nrPairs--;
		return true;
	}
}
// best case: theta(1)    worst case: theta(nrPairs) => total complexity: O(nrPairs)


int FixedCapBiMap::size() const {
	//TODO - Implementation
	return this->nrPairs;
}
//theta(1) 

bool FixedCapBiMap::isEmpty() const{
	//TODO - Implementation
	if (this->nrPairs == 0)
		return true;
	else
		return false;
}
//theta(1) 

bool FixedCapBiMap::isFull() const {
	//TODO - Implementation
	if (this->capacity == this->nrPairs)
		return true;
	else
		return false;
}
// theta(1)

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}
//theta(1) 

ValuePair FixedCapBiMap::removeKey(TKey k) {

	ValuePair searchedKey;
	searchedKey = search(k);
	if (searchedKey.first != NULL_TVALUE)
	{
		if (remove(k, searchedKey.first) == true)
		{
			if (searchedKey.second != NULL_TVALUE)
			{
				if (remove(k, searchedKey.second) == true)
				{
					return searchedKey;
				}
			}
		}
	}
	return searchedKey;
}
