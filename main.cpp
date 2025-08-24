#include "IDataStructure.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

int main() {
	//IDataStructure* dataStructure = new Stack();
	//IDataStructure* dataStructure = new Queue();
	IDataStructure* dataStructure = new LinkedList();
	dataStructure->RunTestCase();

	return 0;
}