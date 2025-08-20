#include "IDataStructure.h"

class Stack : public IDataStructure {
public:
	Stack(int initSize = 10);
	~Stack();
	bool ReSize();
	bool IsEmpty();
	bool IsFull();
	int Size();
	int Top();
	bool Push(int value);
	int Pop();
	void PrintStack();
	void RunTestCase();
	
private:
	int* m_arr;
	int m_count = -1;
	int m_capacity = 0;
};