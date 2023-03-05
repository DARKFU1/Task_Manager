#ifndef TLIST_H
#define TLIST_H

// Realisation of Forward-list.

class TList
{
	struct Node
	{
		Node* pNext;
		Node* pPrev;

		T value;

		Node(T value);
		Node(T value, Node* pPrev, Node* pNext);
	};

	Node* head;

public:
	void Add(T value);
	void Remove(int id);
	T& Get(int id);
	T& operator[](int id);

	TList();
	~TList();
};

#endif
