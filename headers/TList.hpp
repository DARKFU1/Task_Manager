#ifndef TLIST_H
#define TLIST_H

// Realisation of Forward-list.

template <typename T>
class TList
{
	struct Node
	{
		Node* pNext;
		T value;

		Node(T value);
	};

	Node* head;
	int count;

public:
	void Add(T value);
	void Remove(int id);

	TList(T value);

	T& Get(int id);
	T& operator[](int id);

	TList();
	~TList();
};

#endif
