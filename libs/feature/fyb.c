#include "fyb.h"

void FYB(){

    int len = listDinKicauLength(listKicauan);
    int len2 = len;

    if (len > 8){
        len2 = 8;
    }
    printf("banyak kicau %d \n", len2);

    MaxHeap heap;
    initMaxHeap(&heap);
    int i;
    for (i = 0; i < len - 1; i++){
        insert(&heap, listKicauan.buffer[i]);
    }

    printHeap(&heap);
}