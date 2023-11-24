/* File: maxheap.h */

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../list/listdinkicau.h"

#define MAX_HEAP_SIZE 8


typedef struct
{
    Kicauan *elements;
    int size;
} MaxHeap;

/* Inisialisasi heap kosong */
void initMaxHeap(MaxHeap *heap);

/* Cek apakah heap kosong */
int isEmpty(MaxHeap *heap);

/* Cek apakah heap penuh */
int isFull(MaxHeap *heap);

/* Insert elemen ke dalam heap */
void insert(MaxHeap *heap, Kicauan value);

int smallestIndex(MaxHeap heap);

/* Hapus elemen maksimum dari heap */
Kicauan deleteMax(MaxHeap *heap);

/* Cetak isi heap */

#endif
