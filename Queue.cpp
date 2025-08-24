#include "Queue.h"

Queue::Queue() : m_arr(nullptr), m_size(0), m_capacity(0), m_front(0), m_rear(0) {}

Queue::Queue(const Queue& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_front(other.m_front), m_rear(other.m_rear) {
	m_arr = static_cast<int*>(malloc(sizeof(int) * m_capacity));
	if (!m_arr)
		throw std::bad_alloc();
	for (int i = 0; i < m_size; i++)
	{
		int front = (other.m_front + i) % m_capacity;
		m_arr[i] = other.m_arr[front];
		printf(" m_arr[%d] : %d\n", i, other.m_arr[front]);
	}
	printf("\n");
}

Queue::Queue(Queue&& other) noexcept : m_arr(other.m_arr), m_size(other.m_size)
			, m_capacity(other.m_capacity), m_front(other.m_front), m_rear(other.m_rear) {
	other.m_arr = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_front = 0;
	other.m_rear = 0;
}

Queue::~Queue() {
	if (!m_arr)
		free(m_arr);
}

bool Queue::Grow() {
	if (m_capacity == 0)
	{
		m_capacity = 5;
		int* tmp = static_cast<int*>(malloc(sizeof(int) * m_capacity));
		if (!tmp)
			return false;
		m_arr = tmp;
	}
	else
	{
		if (m_capacity > INT_MAX / 2) // int형의 최대에 도달했을 경우 오버플로우 방지
			return false;
		int* tmp = static_cast<int*>(malloc(sizeof(int) * m_capacity * 2));
		if (!tmp)
			return false;

		printf(" --> Grow() : front init 0\n   Queue Data :\n");
		for (int i = 0; i < m_size; i++)	//원형큐이므로 재할당시 이전 데이터를 복사하여 처음부터 재입력 필요
		{
			int front = (m_front + i) % m_capacity;
			tmp[i] = m_arr[front];
			printf("     tmp[%d] : %d\n", i, tmp[i]);
		}
		printf(" -----------Grow and Copy End-----------\n");

		free(m_arr);
		m_arr = tmp;
		m_front = 0;
		m_rear = m_size;
		m_capacity *= 2;
		
	}

	return true;
}

bool Queue::Reserve(int capacity) {
	if (m_capacity == 0)
	{
		m_capacity = capacity;
		int* tmp = static_cast<int*>(malloc(sizeof(int) * m_capacity));
		if (!tmp)
			return false;
		m_arr = tmp;
	}
	else
	{
		if (m_capacity > capacity || capacity > INT_MAX) // int형의 최대에 도달했을 경우 오버플로우 방지
			return false;
		int* tmp = static_cast<int*>(malloc(sizeof(int) * capacity));
		if (!tmp)
			return false;

		printf(" --> Grow() : front init 0\n   Queue Data :\n");
		for (int i = 0; i < m_size; i++)	//원형큐이므로 재할당시 이전 데이터를 복사하여 처음부터 재입력 필요
		{
			int front = (m_front + i) % m_capacity;
			tmp[i] = m_arr[front];
			printf("     tmp[%d] : %d\n", i, tmp[i]);
		}
		printf(" -----------Grow and Copy End-----------\n");

		free(m_arr);
		m_arr = tmp;
		m_front = 0;
		m_rear = m_size;
		m_capacity = capacity;
	}

	return true;
}

bool Queue::isEmpty() {
	return m_size == 0;
}

bool Queue::isFull() {
	return m_size == m_capacity;
}

bool Queue::EnQueue(int value) {
	if (isFull() && !Grow()) return false; //재할당 실패서 false 반환
	
	m_rear = m_rear % m_capacity;
	printf(" EnQueue() : %d, rear : %d\n", value, m_rear);
	m_arr[m_rear++] = value;
	m_size++;
	
	return true;
}

std::optional<int> Queue::DeQueue() {
	if (isEmpty())
		return std::nullopt;
	
	m_front = m_front % m_capacity;
	m_size--;
	printf(" DeQueue() : %d, front : %d\n", m_arr[m_front], m_front);
	return m_arr[m_front++];
}

std::optional<int> Queue::Peek() {
	if (isEmpty()) return std::nullopt;
	return m_arr[m_front % m_capacity];
}

void Queue::RunTestCase() {
	printf("###[this->EnQueue] 1 ~ 5\n");
	EnQueue(1);
	EnQueue(2);
	EnQueue(3);
	EnQueue(4);
	EnQueue(5);
	
	printf("\n###[this->DeQueue] * 3\n");
	DeQueue();
	DeQueue();
	DeQueue();

	printf("\n###[this->EnQueue] 1 ~ 3\n");
	EnQueue(1);
	EnQueue(2);
	EnQueue(3);

	printf("\n###[this->DeQueue] * 5\n");
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();

	printf("\n###[this->EnQueue] 1 ~ 6 \n");
	EnQueue(1);
	EnQueue(2);
	EnQueue(3);
	EnQueue(4);
	EnQueue(5);
	EnQueue(6);

	printf("\n###[this->DeQueue] * 6\n");
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();

	printf("\n###[this->EnQueue] 1 ~ 11 \n");
	EnQueue(1);
	EnQueue(2);
	EnQueue(3);
	EnQueue(4);
	EnQueue(5);
	EnQueue(6);
	EnQueue(7);
	EnQueue(8);
	EnQueue(9);
	EnQueue(10);
	EnQueue(11);

	printf("\n###[Copy constructor] Queue w\n");
	Queue w(*this);
	printf("\n###[w.DeQueue] * 11\n");
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();
	w.DeQueue();

	printf("\n###[Queue c = std::move(*this);]\n");
	Queue c = std::move(*this);

	if (this->m_arr == NULL)
	{
		printf("\n###[this->m_arr]\n nullptr\n");
	}

	printf("\n###[c.DeQueue]\n");
	c.DeQueue();
}