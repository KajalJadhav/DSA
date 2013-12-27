typedef int (*compare)(void* element1, void* element2);

void bubbleSort(void* base, int numberOfElements, int elementSize,compare compareFunc); 