#include "Stack.h"

Stack::Stack() : m_arr(nullptr), m_size(-1), m_capacity(0) { } //�����ڴ� �⺻ �ʱ�ȭ�� ��Ű�� �� ���ڴ� �����Ͽ� �޸� �Ҵ� �κ� ������.

Stack::Stack(const Stack& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
	void* tmp = malloc((sizeof(int) * m_capacity));
	m_arr = static_cast<int*>(tmp);
	if (!m_arr)	//�޸� �������� �Ҵ� ���н� ���� �߻�
		throw std::bad_alloc();

	for (int i = 0; i <= m_size; i++)
	{
		m_arr[i] = other.m_arr[i];
	}
}

Stack::Stack(Stack&& other) noexcept : m_arr(other.m_arr), m_size(other.m_size), m_capacity(other.m_capacity) {
	other.m_arr = nullptr;
	other.m_size = -1;
	other.m_capacity = 0;
}

Stack::~Stack() {
	if (m_arr)	//m_arr�� �Ҵ�� �޸𸮰� ���� ��쿡�� �޸� ����
		free(m_arr);
}

bool Stack::Reserve(int capacity) {
	if (m_capacity > capacity || capacity > INT_MAX)	//��ȿ�� üũ
		return false;

	void* tmp = realloc(m_arr, sizeof(int) * capacity);
	if (!tmp)
		return false;
	m_arr = static_cast<int*>(tmp);	//���� ����ȯ�� �ƴ� �� �� �������� ���
	m_capacity = capacity;

	return true;
}

bool Stack::Grow() {
	void* tmp = nullptr;

	if (m_capacity == 0) {
		tmp = malloc(sizeof(int));
		m_arr = static_cast<int*>(tmp);
		m_capacity = 1;
	}
	else
	{
		if (m_capacity > INT_MAX / 2)
		{
			printf("Stack capacity is Max!\n");
			return false;
		}

		tmp = realloc(m_arr, sizeof(int) * m_capacity * 2);
		if (tmp == NULL) //�޸� �����̳� ��Ÿ ������ ���Ҵ��� ���� �Ͽ��� �� NULL ��ȯ��
			return false;

		m_arr = static_cast<int*>(tmp);
		m_capacity *= 2;
	}
	return true;
}

bool Stack::IsEmpty() {
	if (m_size != -1)
	{
		return false;
	}
	return true;
}

bool Stack::IsFull() {
	if (m_size != (m_capacity-1))	//Empty�� ��쿡�� full�� ǥ�� ��
	{
		return false;
	}
	return true;
}

int Stack::Size() {
	return m_size+1;
}

std::optional<int> Stack::Top() {	//c++ 17�� �߰��� ����̶� ��.
	if (IsEmpty())
	{
		printf("Stack is Empty!\n");
		return std::nullopt;
	}
	return m_arr[m_size];
}

bool Stack::Push(int value) {
	if (IsFull() || m_capacity == 0)
	{
		if (!Grow())
		{
			printf("ReSize() failed!\n");
			return false;
		}
	}
	m_arr[++m_size] = value;

	return true;
}

int Stack::Pop() {
	if (IsEmpty())
	{
		printf("Stack is Empty!\n");
		return -1;
	}
	int tmp = m_arr[m_size--];

	return tmp;
}

void Stack::PrintStack() {
	int idx = m_size;

	printf("printStack() : ");
	for (int i = idx; i >= 0; i--)
	{
		printf("%d ", m_arr[i]);
	}
	printf("\n");
}

void Stack::RunTestCase() {
	printf("isEmpty() : %s\n", IsEmpty() ? "true" : "false");
	printf("m_size : %d\n", Size());
	printf("m_capacity : %d\n", m_capacity);
	printf("pop() : %d\n", Pop());
	printf("\n");

	printf("push() : 1\n"); Push(1);
	printf("push() : 2\n"); Push(2);
	printf("push() : 3\n"); Push(3);
	printf("m_size : %d\n", Size());
	PrintStack();
	printf("\n");

	printf("pop() : %d\n", Pop());
	printf("m_size : %d\n", Size());
	PrintStack();
	printf("\n");
	
	printf("print top : %d\n", Top());
	printf("\n");

	printf("push() : 3\n"); Push(3);
	printf("push() : 4\n"); Push(4);
	printf("push() : 5\n"); Push(5);
	printf("push() : 6\n"); Push(6);
	printf("push() : 7\n"); Push(7);
	printf("push() : 8\n"); Push(8);
	printf("push() : 9\n"); Push(9);
	printf("push() : 10\n"); Push(10);
	printf("m_size : %d\n", Size());
	PrintStack();
	printf("\n");

	printf("isFull() : %s\n", IsFull() ? "true" : "false");
	printf("\n");

	printf("push() : 11\n"); Push(11);
	printf("m_size : %d\n", Size());
	printf("m_capacity : %d\n", m_capacity);
	PrintStack();
	printf("\n");

	Stack b = *this;
	Stack c = std::move(*this);
	b.PrintStack();
	PrintStack();
	printf("\n");
}