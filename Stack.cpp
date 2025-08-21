#include "Stack.h"
#include <iostream>

Stack::Stack(int initSize) {
	if (initSize <= 0)
	{
		initSize = 1;
	}

	m_arr = (int*)malloc((sizeof(int) * initSize));
	if (!m_arr)
	{
		//���ܿ� �׳� ���ڿ��� �Ѱ��൵ ������ ���� �ڵ忡�� ĳġ�ؼ� ���� ���ؼ��� �� ����� �� �� ���ƺ���
		throw std::bad_alloc();
	}
	m_capacity = initSize;

	//new ������ ���� ���н� �ڵ����� std::bad_alloc ���ܸ� ������.
	//new�� ���� �ʰ� malloc�� ����Ͽ��� ������ ���� ������ �ʿ�
}

Stack::~Stack() {
	free(m_arr);
}

bool Stack::ReSize() {
	if (m_capacity > INT_MAX / 2)
	{
		printf("Stack capacity is Max!\n");
		return false;
	}

	int* tmp = m_arr;
	m_arr = (int*)realloc(m_arr, sizeof(int) * m_capacity * 2);
	if (m_arr == NULL)
	{
		//�޸� �����̳� ��Ÿ ������ ���Ҵ��� ���� �Ͽ��� �� NULL ��ȯ
		//null�� ��ȯ�Ͽ����Ƿ� m_arr�� ���� �ּҸ� �Ҿ����
		//�̸� �����ϱ� ���ؼ��� ������ m_arr �����͸� tmp�� ���� �� ���� ������� ��
		m_arr = tmp;
		return false;
	}
	m_capacity *= 2;
	return true;
}

bool Stack::IsEmpty() {
	if (m_idx != -1)
	{
		return false;
	}
	return true;
}

bool Stack::IsFull() {
	if (m_idx != (m_capacity-1))
	{
		return false;
	}
	return true;
}

int Stack::Size() {
	return m_idx+1;
}

int Stack::Top() {
	if (IsEmpty())
	{
		printf("Stack is Empty!\n");
		return -1;
	}
	return m_arr[m_idx];
}

bool Stack::Push(int value) {
	if (IsFull())
	{
		if (!ReSize())
		{
			printf("ReSize() failed!\n");
			return false;
		}
	}
	m_arr[++m_idx] = value;

	return true;
}

int Stack::Pop() {
	if (IsEmpty())
	{
		printf("Stack is Empty!\n");
		return -1;
	}
	int tmp = m_arr[m_idx--];

	return tmp;
}

void Stack::PrintStack() {
	int idx = m_idx;

	printf("printStack() : ");
	for (int i = idx; i >= 0; i--)
	{
		printf("%d ", m_arr[i]);
	}
	printf("\n");
}

void Stack::RunTestCase() {
	printf("isEmpty() : %s\n", IsEmpty() ? "true" : "false");
	printf("m_idx : %d\n", Size());
	printf("m_capacity : %d\n", m_capacity);
	printf("pop() : %d\n", Pop());
	printf("\n");

	printf("push() : 1\n"); Push(1);
	printf("push() : 2\n"); Push(2);
	printf("push() : 3\n"); Push(3);
	printf("m_idx : %d\n", Size());
	PrintStack();
	printf("\n");

	printf("pop() : %d\n", Pop());
	printf("m_idx : %d\n", Size());
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
	printf("m_idx : %d\n", Size());
	PrintStack();
	printf("\n");

	printf("isFull() : %s\n", IsFull() ? "true" : "false");
	printf("\n");

	printf("push() : 11\n"); Push(11);
	printf("m_idx : %d\n", Size());
	printf("m_capacity : %d\n", m_capacity);
	PrintStack();
	printf("\n");
}