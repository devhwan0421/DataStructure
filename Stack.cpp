#include "Stack.h"
#include <iostream>

Stack::Stack(int initSize) {
	m_arr = (int*)malloc((sizeof(int) * initSize));
	if (!m_arr)
	{
		//예외에 그냥 문자열을 넘겨줘도 되지만 상위 코드에서 캐치해서 쓰기 위해서는 이 방법이 좀 더 좋아보임
		throw std::bad_alloc();
	}
	m_capacity = initSize;

	//new 연산을 쓰면 실패시 자동으로 std::bad_alloc 예외를 던진다.
	//new를 쓰지 않고 malloc을 사용하였기 때문에 직접 구현이 필요
}

Stack::~Stack() {
	free(m_arr);
}

bool Stack::ReSize() {
	int* tmp = m_arr;
	m_arr = (int*)realloc(m_arr, sizeof(int) * m_capacity * 2);
	if (m_arr == NULL)
	{
		//메모리 부족이나 기타 이유로 재할당을 실패 하였을 때 NULL 반환
		//null을 반환하였으므롤 m_arr은 기존 주소를 잃어버림
		//이를 방지하기 위해서는 기존의 m_arr 포인터를 tmp에 저장 후 복구 시켜줘야 함
		m_arr = tmp;
		return false;
	}
	m_capacity *= 2;
	return true;
}

bool Stack::IsEmpty() {
	if (m_count != -1)
	{
		return false;
	}
	return true;
}

bool Stack::IsFull() {
	if (m_count != (m_capacity-1))
	{
		return false;
	}
	return true;
}

int Stack::Size() {
	return m_count+1;
}

int Stack::Top() {
	return m_arr[m_count];
}

bool Stack::Push(int value) {
	if (IsFull())
	{
		ReSize();
	}
	m_arr[++m_count] = value;

	return true;
}

int Stack::Pop() {
	if (IsEmpty())
	{
		printf("Stack is Empty!\n");
		return -1;
	}
	int tmp = m_arr[m_count--];

	return tmp;
}

void Stack::PrintStack() {
	int idx = m_count;

	printf("printStack() : ");
	for (int i = idx; i >= 0; i--)
	{
		printf("%d ", m_arr[i]);
	}
	printf("\n");
}

void Stack::RunTestCase() {
	printf("isEmpty() : %s\n", IsEmpty() ? "true" : "false");
	printf("m_count : %d\n", Size());
	printf("m_capacity : %d\n", m_capacity);
	printf("pop() : %d\n", Pop());
	printf("\n");

	printf("push() : 1\n"); Push(1);
	printf("push() : 2\n"); Push(2);
	printf("push() : 3\n"); Push(3);
	printf("m_count : %d\n", Size());
	PrintStack();
	printf("\n");

	printf("pop() : %d\n", Pop());
	printf("m_count : %d\n", Size());
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
	printf("m_count : %d\n", Size());
	PrintStack();
	printf("\n");

	printf("isFull() : %s\n", IsFull() ? "true" : "false");
	printf("\n");

	printf("push() : 11\n"); Push(11);
	printf("m_count : %d\n", Size());
	printf("m_capacity : %d\n", m_capacity);
	PrintStack();
	printf("\n");
}