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

Node* BST::Search(int key) {
	Node* node = FindLocation(key);
	return node;
}

void BST::Remove(int key) {
	Node* node = FindLocation(key);
	if (!node || node->m_key != key) return;

	Node* parent_node = node->m_parent_node;
	Node* left_node = node->m_left_node;
	Node* right_node = node->m_right_node;

	if (!left_node)
	{
		if (!parent_node)
		{
			m_root = right_node;
			if (m_root) m_root->m_parent_node = nullptr;
		}
		else
		{
			if (parent_node->m_left_node == node) parent_node->m_left_node = right_node;
			if (parent_node->m_right_node == node) parent_node->m_right_node = right_node;
			if (right_node) right_node->m_parent_node = parent_node;
		}
		delete node;
		m_size--;
		return;
	}
	else
	{
		if (!parent_node)
		{
			m_root = left_node;
			m_root->m_parent_node = nullptr;
		}
		else
		{
			if (parent_node->m_left_node == node) parent_node->m_left_node = left_node;
			else parent_node->m_right_node = left_node;
			left_node->m_parent_node = parent_node;
		}
		Node* right_most_node = left_node;
		while (right_most_node->m_right_node) {
			right_most_node = right_most_node->m_right_node;
		}
		right_most_node->m_right_node = right_node;
		if (right_node) right_node->m_parent_node = right_most_node;

		delete node;
		m_size--;
	}
}