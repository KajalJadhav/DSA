typedef int Comparator(void* first, void* second);
void mergeSort(void* array,int min,int max,int typesize, Comparator* compare);
void merge(void* array,int min,int mid,int max, void* tmp,int typeSize, Comparator* compare);