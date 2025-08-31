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
	std::vector<int> m_arr;	//stack, queue, linkedlist, hashtable ���� �̹� ������ �������Ƿ�
								//������� �������� �޸� ������ ����� ��� vector�� ������� 
};