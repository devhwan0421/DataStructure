#include "IDataStructure.h"
#include "Stack.h"
#include "Queue.h"

int main() {
	//IDataStructure* dataStructure = new Stack();
	IDataStructure* dataStructure = new Queue();
	dataStructure->RunTestCase();

	return 0;
}