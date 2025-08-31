#include "Tree/BST/BinarySearchTree.h"

Node* BST::FindLocation(int key) {
	if (m_size == 0) return nullptr;
	Node* parent_node = nullptr;
	Node* visit_node = m_root;
	while (visit_node != nullptr) {
		if (visit_node->m_key == key) return visit_node;
		if (visit_node->m_key > key)
		{
			parent_node = visit_node;
			visit_node = visit_node->m_left_node;
		}
		else
		{
			parent_node = visit_node;
			visit_node = visit_node->m_right_node;
		}
	}
	return parent_node;
}

Node* BST::Insert(int key) {
	Node* parent = FindLocation(key);

	if (parent == nullptr || parent->m_key != key) {
		Node* newNode = new Node(key);
		if (parent == nullptr) {
			m_root = newNode;
		}
		else
		{
			newNode->m_parent_node = parent;
			if (parent->m_key > key)
			{
				parent->m_left_node = newNode;
			}
			else
			{
				parent->m_right_node = newNode;
			}
		}
		m_size++;
		return newNode;
	}
	else
	{
		printf("Key is alreay in tree");
		return nullptr;
	}
}