#pragma once
struct Node {
	int m_data;
	Node* m_next_left;
	Node* m_next_right;

	Node(int value) : m_data(value), m_next_left(nullptr), m_next_right(nullptr) {}
};