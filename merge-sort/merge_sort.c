#include "merge_sort.h"
#include <memory.h>
#include "stdlib.h"

void mergeSort(void* array,int min,int max,int typesize, Comparator* compare){
    void* temp =  calloc(min + max, typesize);
    int mid;
    if(min < max){
        mid = (min + max) / 2;
        mergeSort(array,min,mid,typesize,compare);
        mergeSort(array,mid+1,max,typesize,compare);
        merge(array,min,mid,max,temp,typesize,compare);
    }
}

void merge(void* array,int min,int mid,int max,void* temp,int typeSize, Comparator* compare){
    int i,j,k,m;
    j = min;
    m = mid+1;
    for(i = min; j <= mid && m <= max ; i++){
        if(compare(array + j * typeSize,array + m * typeSize)){
            memcpy(temp + i * typeSize,array + j * typeSize,typeSize);
            j++;
        }
        else{
            memcpy(temp + i * typeSize,array + m * typeSize,typeSize);
            m++;        
        }
    }
    if(j > mid){
        for(k = m; k <= max; k++){
            memcpy(temp + i * typeSize,array + k * typeSize,typeSize);
            i++;
        }
    }
    else{
        for(k = j; k <= mid; k++){
            memcpy(temp + i * typeSize,array + k * typeSize,typeSize);
            i++;
        }
    }
    for(k = min; k <= max; k++)
        memcpy(array + k * typeSize,temp + k * typeSize,typeSize);
}