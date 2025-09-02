#pragma once
namespace bst {
	struct Node {
		int m_key;
		Node* m_parent_node;
		Node* m_left_node;
		Node* m_right_node;

		Node(int key) : m_key(key), m_parent_node(nullptr), m_left_node(nullptr), m_right_node(nullptr) {}
	};
}