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
        printf("Heap is full. Cannot insert Kicauan.\n");
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
        printf("Heap is empty. Cannot delete.\n");
        maxValue.id = -1; // Menandakan bahwa heap kosong
        return maxValue;
    }

    maxValue = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return maxValue;
}

void printHeap(MaxHeap *heap)
{
    printf("Heap:\n");
    for (int i = 0; i < heap->size; i++)
    {
        printf("Kicauan ID: %d, Like: %d\n", heap->elements[i].id, heap->elements[i].like);
    }
    printf("\n");
}
