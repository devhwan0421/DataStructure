#include "IDataStructure.h"
#include "Stack.h"

int main() {
	IDataStructure* dataStructure = new Stack();
	dataStructure->RunTestCase();

	return 0;
}