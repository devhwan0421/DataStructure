#pragma once
#include "IDataStructure.h"
#include <iostream>
#include <optional>

//����ũ���� ���� ť�� ����
class Queue : public IDataStructure {
public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other) noexcept;
	~Queue();

	Queue& operator=(const Queue& other);
	Queue& operator=(Queue&& other) noexcept;


	bool EnQueue(int value);
	std::optional<int> DeQueue();
	std::optional<int> Peek();
	bool isEmpty();
	bool isFull();
	bool Reserve(int capacity);

	void RunTestCase();

private:
	bool Grow();

	int* m_arr;
	int m_front;	//�� �� ������ ��ġ
	int m_rear;		//���������� ���Ե� ������ ��ġ
	int m_size;
	int m_capacity;
};