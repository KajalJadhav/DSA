#include "bubble_sort.h"
#include <stdlib.h>
#include <memory.h>

void bubbleSort(void* base, int numberOfElements, int typeSize,compare compareFunc) {
    int i, j;
    void* temp = calloc(1, typeSize);
    void* elementToCompare;
    void* nextElement;
    int comparisonResult;
    for (i = 1; i < numberOfElements; i++) {
        for (j = 0; j < numberOfElements - i; j++) {
            elementToCompare = base + j * typeSize;
            nextElement = base + (j + 1) * typeSize;
            comparisonResult = compareFunc(elementToCompare,nextElement);
            if (comparisonResult > 0){
                memcpy(temp, elementToCompare, typeSize);
                memcpy(elementToCompare, nextElement, typeSize);
                memcpy(nextElement, temp, typeSize);
            }
        }
    }
}