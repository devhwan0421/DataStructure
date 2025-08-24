#include "LinkedList.h"

LinkedList::LinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0){}

LinkedList::~LinkedList() {
	//if (m_head) free(m_head);
	//순회를 돌며 모두 동적할당 해제 해야할 듯.
	Clear();
}

bool LinkedList::IsEmpty() const {
	return m_size == 0;
}

void LinkedList::PushFront(int value) {
	Node* newNode = new Node(value);

	if (IsEmpty())
	{
		m_head = newNode;
		m_tail = newNode;
		m_size++;
	}
	else {
		newNode->m_next_left = nullptr;
		newNode->m_next_right = m_head;
		m_head->m_next_left = newNode;
		m_head = newNode;
		m_size++;
	}
}

void LinkedList::PushBack(int value) {
	Node* newNode = new Node(value);

	if (IsEmpty())
	{
		m_head = newNode;
		m_tail = newNode;
		m_size++;
	}
	else {
		newNode->m_next_left = m_tail;
		newNode->m_next_right = nullptr;
		m_tail->m_next_right = newNode;
		m_tail = newNode;
		m_size++;
	}
}

void LinkedList::Insert(int index, int value) {
	if (index <= 0) { PushFront(value); return; }
	if (index >= m_size) { PushBack(value); return; }

	Node* newNode = new Node(value);
	Node* tmp = m_head;
	for (int i = 0; i < index; i++) tmp = tmp->m_next_right;

	newNode->m_next_left = tmp->m_next_left;
	newNode->m_next_right = tmp;

	tmp->m_next_left->m_next_right = newNode;
	tmp->m_next_left = newNode;
	m_size++;
}

void LinkedList::PopFront() {
	if (IsEmpty()) return ;
	if (m_size == 1) {
		delete m_head;
		m_head = m_tail = nullptr;
		m_size--;
	}
	else {
		Node* tmp = m_head;
		m_head->m_next_right->m_next_left = nullptr;
		m_head = m_head->m_next_right;
		delete tmp;
		m_size--;
	}
}

void LinkedList::PopBack() {
	if (IsEmpty()) return;
	if (m_size == 1) {
		delete m_head;
		m_size--;
		m_head = m_tail = nullptr;
	}
	else
	{
		Node* tmp = m_tail;
		tmp->m_next_left->m_next_right = nullptr;
		m_tail = tmp->m_next_left;
		delete tmp;
		m_size--;
	}
}

void LinkedList::Erase(int index) {
	if (index > m_size - 1 || IsEmpty() || index < 0) return;

	if (index == 0) { PopFront(); return; }
	if (index == m_size - 1) { PopBack(); return; }

	Node* tmp = m_head;
	for (int i = 0; i < index; i++)	tmp = tmp->m_next_right;

	tmp->m_next_left->m_next_right = tmp->m_next_right;
	tmp->m_next_right->m_next_left = tmp->m_next_left;

	delete tmp;
	m_size--;
}

void LinkedList::Clear() {
	if (IsEmpty()) return;
	Node* tmp = nullptr;
	while(m_head){
		tmp = m_head->m_next_right;
		delete m_head;
		m_head = tmp;
	}

	m_head = m_tail = nullptr;
	m_size = 0;
}

std::optional<Node*> LinkedList::FindNode(int value) {
	if (IsEmpty()) return std::nullopt;
	Node* tmp = m_head;
	while (tmp) {
		if (tmp->m_data == value)
		{
			return tmp;
		}
		tmp = tmp->m_next_right;
	}
	return std::nullopt;
}

std::optional<int> LinkedList::At(int index) {
	if (IsEmpty() || index > m_size - 1 || index < 0) return std::nullopt;

	Node* tmp = m_head;
	for (int i = 0; i < index; i++) tmp = tmp->m_next_right;
	return tmp->m_data;
}

int LinkedList::GetSize() const {
	return m_size;
}

void LinkedList::Print() const {
	Node* tmp = m_head;
	while (tmp) {
		printf("%d ", tmp->m_data);
		tmp = tmp->m_next_right;
	}
	printf("\n");
}

void LinkedList::RunTestCase() {
	PushFront(1);
	PopFront();
	PushFront(1);
	PopBack();
	PushFront(1);
	PushBack(2);
	PushFront(0);
	PushBack(3);
	Insert(100, 4);

	Print();

	PopFront();
	
	Print();

	PopBack();

	Print();

	Erase(0);

	Print();

	PushBack(4);
	Print();

	Erase(2);
	Print();

	PushBack(7);
	PushBack(8);
	PushBack(9);
	Print();

	std::optional<Node*> data = FindNode(8);
	if (auto opt = FindNode(8); opt.has_value())
	{
		printf("data : %d\n", opt.value()->m_data);
	}
	else
	{
		printf("data not found\n");
	}

	if (auto v0 = At(0); v0.has_value())	//c++ 17에서 추가된 if문의 활용법. if(초기화; 조건 검사)
		printf("At(0) : %d\n", *v0);
	else
		printf("At(0) : none\n");

	if (auto v3 = At(3); v3.has_value())
		printf("At(3) : %d\n", *v3);
	else
		printf("At(3) : none\n");

	if (auto v5 = At(5); v5.has_value())
		printf("At(5) : %d\n", *v5);
	else
		printf("At(5) : none\n");

	if (auto v6 = At(6); v6.has_value())
		printf("At(6) : %d\n", *v6);
	else
		printf("At(6) : none\n");

	Clear();
	Print();
}