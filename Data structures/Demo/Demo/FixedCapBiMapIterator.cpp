#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
using namespace std;


FixedCapBiMapIterator::FixedCapBiMapIterator(const FixedCapBiMap& d) : map(d)
{
	//TODO - Implementation
	this->current = 0;
}
//theta(1) 


void FixedCapBiMapIterator::first() {
	//TODO - Implementation
	this->current = 0;
}
//theta(1) 


void FixedCapBiMapIterator::next() {
	//TODO - Implementation
	if (this->current == this->map.nrPairs)
	{
		throw exception();
	}
	else
	{
		this->current++;
	}
}
//theta(1) 

TElem FixedCapBiMapIterator::getCurrent(){
	//TODO - Implementation
	if (this->current == this->map.nrPairs)
	{
		throw exception();
	}
	else
	{
		return this->map.elements[this->current];
	}
}
//theta(1) 


bool FixedCapBiMapIterator::valid() const {
	//TODO - Implementation
	if (this->current < this->map.nrPairs)
	{
		return true;
	}
	else
		return false;
}
//theta(1) 


