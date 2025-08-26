#include "IDataStructure.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "LinkedList/LinkedList.h"
#include "HashTable/HashTable.h"

int main() {
	//IDataStructure* dataStructure = new Stack();
	//IDataStructure* dataStructure = new Queue();
	//IDataStructure* dataStructure = new LinkedList();
	IDataStructure* dataStructure = new HashTable();
	dataStructure->RunTestCase();

	return 0;
}