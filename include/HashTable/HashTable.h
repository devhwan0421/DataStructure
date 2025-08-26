#pragma once
#include "IDataStructure.h"
#include "HashTable/Entry.h"
#include <iostream>
#include <optional>

class HashTable : public IDataStructure {
public:
	HashTable();
	~HashTable();

	int HashFunction(int key);

	bool Insert(int key, int value, int prob = 0);
	void LinearProbing(int key, int value);

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