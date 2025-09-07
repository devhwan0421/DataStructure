#pragma once
#include "IDataStructure.h"
#include "Tree/BST/Node.h"
#include <iostream>
namespace bst {
	class BST : public IDataStructure {
	public:
		BST();
		~BST();

		void ClearByPostOrder();

		Node* FindLocation(int key);
		Node* Insert(int key);

		Node* Search(int key);
		void Remove(int key);

		void DeleteByMerging(int key);
		void DeleteByCopying(int key);

		void RunTestCase();

	private:
		Node* m_root;
		size_t m_size;
	};
}