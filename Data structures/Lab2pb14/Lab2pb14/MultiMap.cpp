#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	//TODO - Implementation

	head = new Node;
	(*head).pair = NULL_TELEM;
	(*head).next = nullptr;
	(*head).prev = nullptr;
	
}


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation

	if (isEmpty())
	{
		TElem pair;
		pair.first = c;
		pair.second = v;
		if (head == nullptr)
			head = new Node;
		head->next = nullptr;
		head->prev = nullptr;
		head->pair = pair;
	}
	else
	{
		Node* newNode = new Node;
		Node* currentNode;
		newNode->pair.first = c;
		newNode->pair.second = v;

		currentNode = head;

		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		newNode->prev = currentNode;
		newNode->next = nullptr;
		currentNode->next = newNode;
	}
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	Node* newNode = new Node;
	TElem pair;
	pair.first = c;
	pair.second = v;

	Node* currentNode = head;
	while (currentNode != nullptr && currentNode->pair != pair )
		currentNode = currentNode->next;
	if (currentNode == nullptr)
		return  false;
	else
		if (currentNode == head)
		{
			if (currentNode->next != nullptr)
			{
				Node* toDelete;
				toDelete = currentNode;
				head = currentNode->next;
				head->prev = nullptr;
				delete toDelete;
				return true;
			}
			else
			{
				Node* toDelete;
				toDelete = currentNode;
				head=nullptr;
				delete toDelete;
				return true;
			}
		}
		else
			if (currentNode->next == nullptr)
			{
				Node* toDelete;
				toDelete = currentNode;
				currentNode = currentNode->prev;
				currentNode->next = nullptr;
				delete toDelete;
				return true;
			}
			else
			{
				Node* nextNode;
				Node* toDelete;
				nextNode = currentNode -> next;
				toDelete = currentNode;
				currentNode = currentNode->prev;
				
				currentNode->next = nextNode;
				nextNode->prev = currentNode;
				delete toDelete;
				return true;
			}
}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector <TValue> valueVector;

	Node* currentNode = head;
	while (currentNode!=nullptr)
	{
		if (currentNode->pair.first == c)
		{
			valueVector.push_back(currentNode->pair.second);
		}
		currentNode = currentNode->next;
	}

	return valueVector;
}


int MultiMap::size() const {
	//TODO - Implementation
	
	int l = 0;

	if (isEmpty() == false)
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			l++;
			currentNode = currentNode->next;
		}
	}
	return l;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation
	if (this->head == nullptr)
		return true;
	else
		return this->head->pair == NULL_TELEM;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation
	
	Node* currentNode = head;

	if (currentNode != nullptr)
	{
		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
			delete currentNode->prev;
		}

		delete currentNode;
	}
}

