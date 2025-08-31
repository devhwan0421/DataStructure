#pragma once
#include "IDataStructure.h"
#include "Node.h"
#include <iostream>

class BST : public IDataStructure {
public:
	BST();
	~BST();

	Node* FindLocation(int key);
	Node* Insert(int key);

	void RunTestCase();

private:
	Node* m_root;
	size_t m_size;
};