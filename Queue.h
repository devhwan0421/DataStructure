#pragma once
#include "IDataStructure.h"
#include <iostream>
#include <optional>

//고정크기의 원형 큐로 설계
class Queue : public IDataStructure {
public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other) noexcept;
	~Queue();

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
	int m_front;	//맨 앞 원소의 위치
	int m_rear;		//마지막으로 삽입된 원소의 위치
	int m_size;
	int m_capacity;
};