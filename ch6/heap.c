#include "heap.h"

PriorityQueue CreatePQ(int MaxElements)
{
	PriorityQueue PQ;
	PQ = malloc(sizeof(struct HeapStruct));
	PQ -> Capacity = MaxElements;
	PQ -> Elements = malloc((sizeof(ElementType)) * (PQ -> Capacity + 1));
	PQ -> Size = 0;

	return PQ;
}

void Destory(PriorityQueue PQ)
{
	if (PQ)
	{
		free(PQ -> Elements);
		free(PQ);
	}
}

void MakeEmpty(PriorityQueue PQ)
{
	PQ -> Size = 0;
}

void Swap(ElementType* Elements, int i, int j)
{
	ElementType Temp;
	Temp = Elements[i];
	Elements[i] = Elements[j];
	Elements[j] = Temp;
}

void PercolateDown(int i, int Size, ElementType* Elements)
{
	int k;

	while((k = 2 * i) <= Size)
	{
		if (2 * i < Size && Elements[2*i] > Elements[2*i+1])
			++k;

		if (Elements[i] <= Elements[k])
			break;

		Swap(Elements, i, k);
		i = k;
	}
}

void PercolateUp(int i, ElementType* Elements)
{
	int k;

	while((k = i / 2) >= 1)
	{
		if (Elements[k] <= Elements[i])
			break;

		Swap(Elements, k, i);
		i = k;
	}
}

void Insert(ElementType X, PriorityQueue PQ)
{
	if (PQ == NULL)
		return;

	if (IsFull(PQ))
	{
		fprintf(stderr, "Full PriorityQueue\n");
		exit(1);
	}

	PQ -> Elements[++PQ -> Size] = X;
	PercolateUp(PQ -> Size, PQ -> Elements);
}

ElementType DeleteMin(PriorityQueue PQ)
{
	ElementType MinElement;

	if (IsEmpty(PQ))
	{
		fprintf(stderr, "Empty PriorityQueue\n");
		exit(1);
	}

	MinElement = PQ -> Elements[1];
	Swap(PQ -> Elements, 1, PQ -> Size);
	--PQ -> Size;

	PercolateDown(1, PQ -> Size, PQ -> Elements);

	return MinElement;
}

ElementType FindMin(PriorityQueue PQ);
int IsEmpty(PriorityQueue PQ)
{
	return PQ -> Size == 0;
}

int IsFull(PriorityQueue PQ)
{
	return PQ -> Size >= PQ -> Capacity;
}