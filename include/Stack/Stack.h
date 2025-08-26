#include "IDataStructure.h"
#include <iostream>
#include <optional>

class Stack : public IDataStructure {
public:
	Stack();
	Stack(const Stack& other);
	Stack(Stack&& other) noexcept;
	~Stack();
	
	bool Reserve(int capacity);
	bool IsEmpty();
	bool IsFull();
	int Size();
	std::optional<int> Top();
	bool Push(int value);
	int Pop();
	void PrintStack();
	void RunTestCase();
	
private:
	bool Grow();

	int* m_arr;
	int m_size;
	int m_capacity;
};