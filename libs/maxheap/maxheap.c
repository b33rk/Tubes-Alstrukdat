/* File: maxheap.c */

#include "maxheap.h"

void initMaxHeap(MaxHeap *heap)
{
    heap->elements = (Kicauan *)malloc(MAX_HEAP_SIZE * sizeof(Kicauan));
    heap->size = 0;
}

int isEmpty(MaxHeap *heap)
{
    return heap->size == 0;
}

int isFull(MaxHeap *heap)
{
    return heap->size == MAX_HEAP_SIZE;
}

void swap(Kicauan *a, Kicauan *b)
{
    Kicauan temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap *heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap->elements[index].like > heap->elements[parent].like)
        {
            swap(&heap->elements[index], &heap->elements[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void insert(MaxHeap *heap, Kicauan value)
{
    if (isFull(heap))
    {
        int index = smallestIndex(*heap);
        heap->elements[index] = value;
        heapifyUp(heap, index);
        return;
    }

    heap->elements[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void heapifyDown(MaxHeap *heap, int index)
{
    while (2 * index + 1 < heap->size)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largerChild = leftChild;

        if (rightChild < heap->size && heap->elements[rightChild].like > heap->elements[leftChild].like)
        {
            largerChild = rightChild;
        }

        if (heap->elements[index].like < heap->elements[largerChild].like)
        {
            swap(&heap->elements[index], &heap->elements[largerChild]);
            index = largerChild;
        }
        else
        {
            break;
        }
    }
}

Kicauan deleteMax(MaxHeap *heap)
{
    Kicauan maxValue;
    if (isEmpty(heap))
    {
        maxValue.id = -1; 
        return maxValue;
    }

    maxValue = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return maxValue;
}


int smallestIndex(MaxHeap heap){
    int i;
    int index = heap.size - 1;
    int min = heap.elements[heap.size - 1].like;
    for (i = heap.size - 2; i >= 4; i--){
        if (heap.elements[i].like < min){
            min = heap.elements[i].like;
            index = i;
        }
    }

    return index;
}

