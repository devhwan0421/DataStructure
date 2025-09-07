#include "Tree/BST/BinarySearchTree.h"
#include <cassert>
using namespace bst;

//장
BST::BST() : m_root(nullptr), m_size(0) {}

BST::~BST() {
	//재귀와 반복으로 구현해 볼 것
	ClearByPostOrder();
}

void BST::ClearByPostOrder() {
	Node* current_node = m_root;
	if (!current_node) return;

	while (current_node != nullptr) {
		if (current_node->m_left_node) { current_node = current_node->m_left_node; continue; }
		if (current_node->m_right_node) { current_node = current_node->m_right_node; continue; }

		Node* parent_node = current_node->m_parent_node;
		if (parent_node) {
			if (parent_node->m_left_node == current_node)	parent_node->m_left_node = nullptr;
			else											parent_node->m_right_node = nullptr;
		}

		delete current_node;
		--m_size;
		current_node = parent_node;
	}
	m_root = nullptr;
	assert(m_size == 0);
	m_size = 0;
}

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
	//DeleteByMerging(key);
	DeleteByCopying(key);
}

void BST::DeleteByMerging(int key) {
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
	}
	m_size--;
}

void BST::DeleteByCopying(int key) {
	Node* node = FindLocation(key);
	if (!node || node->m_key != key) return;

	Node* left_node = node->m_left_node;
	Node* right_node = node->m_right_node;

	if (left_node && right_node)
	{
		Node* pred = left_node;
		while (pred->m_right_node) pred = pred->m_right_node;

		node->m_key = pred->m_key;

		Node* pred_parent = pred->m_parent_node;	//이렇게 선언하니 코드가 간결해짐
		Node* pred_left = pred->m_left_node;

		if (pred_parent == node)	pred_parent->m_left_node = pred_left;
		else						pred_parent->m_right_node = pred_left;
		if (pred_left) pred_left->m_parent_node = pred_parent;
		delete pred;
	}
	else
	{
		Node* parent_node = node->m_parent_node;
		Node* child = left_node ? left_node : right_node;
		if (m_root != node)
		{
			if (node == parent_node->m_left_node)	parent_node->m_left_node = child;
			else									parent_node->m_right_node = child;
			if (child) child->m_parent_node = parent_node;
		}
		else
		{
			m_root = child;
			if(child) child->m_parent_node = nullptr;
		}
		delete node;
	}
	m_size--;
}

void BST::RunTestCase() {
	Insert(15);
	Insert(4);
	Insert(20);
	Insert(2);
	//     15
	//   4    20
	// 2

	Remove(15);
	//     4
	//   2   20
}