#pragma once
#include "IDataStructure.h"
#include "HashTable/Entry.h"
#include <iostream>
#include <optional>

class HashTable : public IDataStructure {
public:
	HashTable();
	~HashTable();

	void ReHash();

	int HashFunction(int key);
	int FindSlot(int key);

	void Set(int key, int value);
	void Insert(int key, int value);
	void Remove(int key);
	std::optional<Entry*> Search(int key);

	void Print() const;
	void RunTestCase();

private:
	Entry* m_arr;
	int m_size;
	int m_capacity;
	int m_prob;		//collision resolution method
};

// 1. open addressing
//		1) linear probing
//		2) quadratic probing
//		3) double hashing
// 2. chaining