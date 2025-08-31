#include "IDataStructure.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "LinkedList/LinkedList.h"
#include "HashTable/HashTable.h"
#include "Tree/Heap.h"

int main() {
	//IDataStructure* dataStructure = new Stack();
	//IDataStructure* dataStructure = new Queue();
	//IDataStructure* dataStructure = new LinkedList();
	//IDataStructure* dataStructure = new HashTable();
	IDataStructure* dataStructure = new Heap();
	dataStructure->RunTestCase();

	return 0;
}