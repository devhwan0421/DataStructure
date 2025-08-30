#pragma once
struct Entry {
	int m_key;	//string���ε� ������ �� ��
	int m_value;
	bool m_isOccupied;

	Entry() : m_key(0), m_value(0), m_isOccupied(false) {}
	Entry(int key, int value, bool isOccupied) : m_key(key), m_value(value), m_isOccupied(isOccupied) {}

	void Set(int key, int value, bool isOccupied) {
		m_key = key;
		m_value = value;
		m_isOccupied = isOccupied;
	}

	void MoveFrom(Entry& src) noexcept {
		if (this == &src) return;
		m_key = src.m_key;
		m_value = src.m_value;
		m_isOccupied = src.m_isOccupied;
	}

	void Clear() noexcept {
		if (!m_isOccupied) return;
		m_key = 0;
		m_value = 0;
		m_isOccupied = false;
	}
};