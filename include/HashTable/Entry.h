#pragma once
struct Entry {
	int m_key;	//string���ε� ������ �� ��
	int m_value;
	bool m_isOccupied;

	Entry() : m_key(0), m_value(0), m_isOccupied(false) {}
	Entry(int key, int value, bool isOccupied) : m_key(key), m_value(value), m_isOccupied(isOccupied) {}
};