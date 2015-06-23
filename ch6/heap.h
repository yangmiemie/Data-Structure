#include <stdlib.h>
#include <stdio.h>

#define ElementType int

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue CreatePQ(int MaxElements);
void Destory(PriorityQueue PQ);
void MakeEmpty(PriorityQueue PQ);
void Insert(ElementType X, PriorityQueue PQ);
ElementType DeleteMin(PriorityQueue PQ);
ElementType FindMin(PriorityQueue PQ);
int IsEmpty(PriorityQueue PQ);
int IsFull(PriorityQueue PQ);

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};