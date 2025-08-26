#include "HashTable/HashTable.h"

HashTable::HashTable() : m_arr(nullptr), m_size(0), m_capacity(0), m_prob(0) {
	m_arr = new Entry[10];
	m_size = 0;
	m_capacity = 10;
	m_prob = 0;
}

HashTable::~HashTable() {
	delete m_arr;
}

int HashTable::HashFunction(int key) {
	return key % m_capacity;
}

bool HashTable::Insert(int key, int value, int prob) {
	if (prob == 0)
	{
		LinearProbing(key, value);
	}
	return true;
}

void HashTable::LinearProbing(int key, int value) {
	int idx = HashFunction(key);

	while (true) {
		if (m_arr[idx].m_isOccupied == false)
		{
			m_arr[idx].m_key = key;
			m_arr[idx].m_value = value;
			m_arr[idx].m_isOccupied = true;
			break;
		}
		idx = (idx + 1) % m_capacity;
	}
}

std::optional<Entry*> HashTable::Search(int key) {
	int idx = HashFunction(key);
	while (m_arr[idx].m_isOccupied) {
		if (m_arr[idx].m_key == key)
		{
			return &m_arr[idx];
		}
		else
		{
			printf("no match : %d\n", m_arr[idx].m_key);
		}
		idx = (idx + 1) % m_capacity;
	}
	return std::nullopt;
}

void HashTable::Print() const {
	for (int i = 0; i < m_capacity; i++)
	{
		printf("%02d ", m_arr[i].m_value);
	}
	printf("\n");
}

void HashTable::RunTestCase() {
	Print();

	Insert(5, 5);
	Insert(55, 55);
	Print();

	Insert(4, 4);
	Print();

	Insert(44, 44);
	Print();

	if (auto v0 = Search(44); v0.has_value())
		printf("Search() key : %d, value : %d\n", (*v0)->m_key, (*v0)->m_value);
	else
		printf("Not found\n");

	if (auto v1 = Search(7); v1.has_value())
		printf("Search() key : %d, value : %d\n", (*v1)->m_key, (*v1)->m_value);
	else
		printf("Not found\n");
}