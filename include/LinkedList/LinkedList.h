#pragma once
#include "IDataStructure.h"
#include "LinkedList/Node.h"
#include <iostream>
#include <optional>
#include <string>

namespace linkedlist {
	class LinkedList : public IDataStructure {
	public:
		LinkedList();
		~LinkedList();

		void PushFront(int value);
		void PushBack(int value);
		void Insert(int index, int value);

		void PopFront();
		void PopBack();
		void Erase(int index);
		void Clear();

		Node* FindNode(int value);
		std::optional<int> At(int index);

		bool IsEmpty() const;
		int GetSize() const;
		void Print() const;

		void RunTestCase();

	private:

		Node* m_head;
		Node* m_tail;
		int m_size;
	};
}