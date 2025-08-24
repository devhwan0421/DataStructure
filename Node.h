#pragma once
struct Node {
	int m_data;
	Node* m_next;

	Node(int value) : m_data(value), m_next(nullptr) {}
};