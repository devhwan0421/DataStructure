#pragma once
#include "IDataStructure.h"

class LinkedList : public IDataStructure {
public:
	void* GetNode();
private:
	int* head;
};