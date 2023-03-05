#include "../headers/general.hpp"
#include "../headers/TList.h"

template<typename T>
TList<T>::Node::Node(T value)
{
	this->value = value;
	this->pNext = nullptr;
}

template<typename T>
void TList<T>::Add(T value)
{

	if(this->head == nullptr)
	{
		this->head = new Node(value);
		
		++count;
		return;
	}

	Node* buffer = this->head;

	for(int i = 0; i < this->count - 1; ++i)
	{
		buffer = buffer->pNext;
	}

	buffer->pNext = new Node(value);
	++count;
	
	return;
}

template<typename T>
void TList<T>::Remove(int id)
{
	if(this->head == nullptr) { return; }

	if(id == 0)
	{
		Node* removable = this->head;
		this->head = this->head->pNext;

		delete removable;

		--count;

		return;
	}

	if(id == count - 1)
	{
		Node* previous = this->head;

		for(int i = 0; i < id -1; ++i) { previous = previous->pNext; }

		delete previous->pNext;

		previous->pNext = nullptr;

		--count;

		return;
	}

	Node* previous;
	Node* next;

	for(int i = 0; i < id -1; ++i) { previous = previous->pNext; }

	next = previous->pNext->pNext;

	delete previous->pNext;

	previous->pNext = next;

	--count;
}

template<typename T>
T& TList<T>::Get(int id)
{
	return (*this)[id]; // already have operator[] so no point in writing
			    // the code again.
}

template<typename T>
T& TList<T>::operator[](int id)
{
	Node* buffer = this->head;

	for(int i = 0; i < id; ++i) { buffer = buffer->pNext; }

	return buffer->value;
	
}

template <typename T>
TList<T>::TList(T value)
{
	this->head = new Node(value);
	this->count = 1;
}

template<typename T>
TList<T>::TList()
{
	this->head = nullptr;
	this->count = 0;
}

template<typename T>
TList<T>::~TList()
{
	Node* buffer = this->head;

	for(int i = 0; i < this->count; ++i)
	{
		head = head->pNext;
		delete buffer;
		buffer = head;
	}
}

template class TList<int>;
