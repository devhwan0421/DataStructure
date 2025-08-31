#include "Tree/Heap.h"

Heap::Heap() {}

Heap::~Heap() {
	delete &m_arr;
}

void Heap::MakeHeap() {
	const size_t size = m_arr.size();

	for (size_t idx = size / 2; idx-- > 0;) HeapifyDown(idx);
}

void Heap::HeapifyDown(size_t parent_idx) {
	const size_t size = m_arr.size();
	if (parent_idx >= size) return;

	while (true) {
		size_t left_child_idx = (parent_idx * 2) + 1;
		size_t right_child_idx = (parent_idx * 2) + 2;
		size_t big_child_idx = parent_idx;

		if (left_child_idx < size && m_arr[left_child_idx] > m_arr[big_child_idx])
			big_child_idx = left_child_idx;
		if (right_child_idx < size && m_arr[right_child_idx] > m_arr[big_child_idx])
			big_child_idx = right_child_idx;

		if (big_child_idx == parent_idx) break;
		std::swap(m_arr[parent_idx], m_arr[big_child_idx]);
		parent_idx = big_child_idx;
	}
}

void Heap::Insert(int value) {
	m_arr.push_back(value);
	HeapifyUp(m_arr.size() - 1);
}

void Heap::HeapifyUp(size_t current_idx) {
	size_t parent_idx;

	while (current_idx > 0) {
		parent_idx = (current_idx - 1) / 2;
		if (m_arr[current_idx] <= m_arr[parent_idx]) break;
		
		std::swap(m_arr[current_idx], m_arr[parent_idx]);
		current_idx = parent_idx;
	}
}

int Heap::FindMax() {
	return m_arr[0];
}

void Heap::DeleteMax() {
	if (m_arr.size() == 0) return;
	m_arr[0] = m_arr[m_arr.size() - 1];
	m_arr.pop_back();
	if (m_arr.size() != 0)
		HeapifyDown(0);
}

void Heap::Print() {
	if (m_arr.size() == 0) {
		printf("Empty!\n");
		return;
	}
	for (auto& i : m_arr)
		std::cout << i << ' ';
	std::cout << '\n';
}

void Heap::RunTestCase() {
	DeleteMax();
	Insert(0);
	Print();
	DeleteMax();
	Print();

	Insert(0);
	Insert(1);
	Print();
	DeleteMax();
	Print();
	m_arr.clear();

	Insert(0);
	Insert(1);
	Insert(2);
	Print();
	DeleteMax();
	Print();
	/*Insert(0);
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Insert(6);
	Insert(7);
	Insert(8);
	Insert(9);
	Insert(10);
	Insert(11);
	Insert(12);
	Insert(13);
	Insert(14);

	Print();
	MakeHeap();
	Print();*/
}