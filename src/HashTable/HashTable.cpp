#include "HashTable/HashTable.h"

HashTable::HashTable() : m_arr(nullptr), m_size(0), m_capacity(0), m_prob(0) {}

HashTable::~HashTable() {
	delete[] m_arr;
}

void HashTable::ReHash() {
	printf("ReHash!!\n");
	if (m_capacity == 0)
	{
		m_arr = new Entry[1];
		m_capacity = 1;
	}
	else
	{
		Entry* new_arr = new Entry[m_capacity * 2];
		Entry* tmp = m_arr;
		int prev_capacity = m_capacity;

		m_arr = new_arr;
		m_size = 0;
		m_capacity = m_capacity * 2;
		for (int i = 0; i < prev_capacity; i++)
		{
			if (tmp[i].m_isOccupied)
				Insert(tmp[i].m_key, tmp[i].m_value);
		}
		
		delete[] tmp;
	}
	printf("m_capacity : %d\n", m_capacity);
}

int HashTable::HashFunction(int key) {
	int result = key % m_capacity;
	return (result < 0) ? result + m_capacity : result;
}

int HashTable::FindSlot(int key) {
	int idx = HashFunction(key);
	int first_idx = idx;
	while (m_arr[idx].m_isOccupied && m_arr[idx].m_key != key) { // not empty_slot and mismatch key
		idx = (idx + 1) % m_capacity;
		if (idx == first_idx) return -1;	// key not found
	}
	return idx;	// 1.match key : return slot_idx, 2.not found key : return empty_slot_idx
}

void HashTable::Set(int key, int value) {
	if (m_capacity == 0)
		ReHash();
	if ((m_size / m_capacity) >= 0.7)
		ReHash();
	Insert(key, value);
}

void HashTable::Insert(int key, int value) {
	int slot_idx = FindSlot(key);
	if (slot_idx == -1)
		return;	//full. expansion required
	m_arr[slot_idx].Set(key, value, true);
	m_size++;
}

//probe distance를 활용하는 Robin Hood Hashing도 있음. 
//값이 삽입될 때 원래 위치로부터 얼마나 떨어졌는지를 표기 하기 때문에 삭제가 훨씬 간편해 보임
void HashTable::Remove(int key) {
	int remove_slot_idx = FindSlot(key);
	if (remove_slot_idx == -1) return; // key not found

	if (m_arr[remove_slot_idx].m_isOccupied && m_arr[remove_slot_idx].m_key == key) {
		m_arr[remove_slot_idx].Clear();
		m_size--;

		int empty_slot_index = remove_slot_idx;
		int candidate_slot_index = (empty_slot_index + 1) % m_capacity;
		int entry_home_index = 0;

		while (m_arr[candidate_slot_index].m_isOccupied) {
			entry_home_index = HashFunction(m_arr[candidate_slot_index].m_key);
			if (((candidate_slot_index < entry_home_index) && (entry_home_index <= empty_slot_index)) ||
				((entry_home_index <= empty_slot_index) && (empty_slot_index < candidate_slot_index)) ||
				((empty_slot_index < candidate_slot_index) && (candidate_slot_index < entry_home_index)))
			{
				m_arr[empty_slot_index].MoveFrom(m_arr[candidate_slot_index]);
				m_arr[candidate_slot_index].Clear();
				empty_slot_index = candidate_slot_index;
			}
			candidate_slot_index = (candidate_slot_index + 1) % m_capacity;
		}
	}
}

std::optional<Entry*> HashTable::Search(int key) {
	int slot_idx = FindSlot(key);
	if (slot_idx == -1) return std::nullopt;	// key not found and full

	if (m_arr[slot_idx].m_isOccupied && m_arr[slot_idx].m_key == key)
		return &m_arr[slot_idx];
	else
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

	Set(5, 5);
	Set(6, 6);
	Print();

	Set(4, 4);
	Print();

	Set(44, 44);
	Print();

	Set(444, 444);
	Print();

	Set(4444, 4444);
	Set(44444, 44444);
	Set(444444, 444444);
	Set(4444444, 4444444);
	Print();

	if (auto v0 = Search(44); v0.has_value())
		printf("Search(44) key : %d, value : %d\n", (*v0)->m_key, (*v0)->m_value);
	else
		printf("Search(44) key : Not found\n");

	if (auto v1 = Search(7); v1.has_value())
		printf("Search(7) key : %d, value : %d\n", (*v1)->m_key, (*v1)->m_value);
	else
		printf("Search(7) key : Not found\n");

	Remove(4);
	Print();

	Remove(44);
	Print();
}