#pragma once
#include "IDataStructure.h"
#include <iostream>
#include <vector>

class Heap : public IDataStructure {
public:
	Heap();
	~Heap();

	void MakeHeap();
	void HeapifyDown(size_t parent_idx);
	void HeapifyUp(size_t current_idx);
	
	void Insert(int value);
	int FindMax();
	void DeleteMax();

	void Print();
	void RunTestCase();

private:
	std::vector<int> m_arr;	//stack, queue, linkedlist, hashtable 에서 이미 구현해 보았으므로
								//여기부터 연속적인 메모리 구조를 사용할 경우 vector를 사용했음 
};