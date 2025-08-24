#pragma once
#include "IDataStructure.h"
#include "Node.h"

class LinkedList : public IDataStructure {
public:
	LinkedList();
	~LinkedList();

	Node* GetNode();

	void PushFront(int value);
	void PushBack(int value);
	void Insert(int index, int value);

	void PopFront();
	void PopBack();
	void Erase(int index);
	void Clear();

	Node* Search(int value);
	int At(int index);

	bool IsEmpty() const;
	int GetSize() const;
	void Print() const;

private:
	int* m_head;
	int* m_tail;
	int m_size;
};