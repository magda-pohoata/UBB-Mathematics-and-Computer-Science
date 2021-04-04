#include "MultiMapIterator.h"
#include "MultiMap.h"
#include <exception>


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	//TODO - Implementation
	this->currentNode = col.head;
}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation

	if (currentNode->pair == NULL_TELEM)
		throw exception();

	if (currentNode != nullptr)
		return currentNode->pair;
	else
		throw exception();
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation
	if (this->currentNode == this->col.head)
		if (this->currentNode->pair == NULL_TELEM)
			return false;
	return this->currentNode != nullptr;
}

void MultiMapIterator::next() {
	//TODO - Implementation
	if (this->currentNode != nullptr and this->currentNode->pair != NULL_TELEM)
		this->currentNode = this->currentNode->next;
	else
		throw exception();
}

void MultiMapIterator::first() {
	//TODO - Implementation
	this->currentNode = this->col.head;
}

