#pragma once
#include "IDataStructure.h"
#include "Tree/BST/Node.h"
#include <iostream>
using Node = bst::Node;

class BST : public IDataStructure {
public:
	BST();
	~BST();

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