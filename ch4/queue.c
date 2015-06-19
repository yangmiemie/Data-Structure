#include "queue.h"
#include <stdio.h>

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	QueueElementType *Array;
};

int IsEmpty(Queue Q)
{
	return Q -> Size == 0;
}

int IsFull(Queue Q)
{
	return Q -> Size == Q -> Capacity;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	Q -> Capacity = MaxElements;
	Q -> Front = 1;
	Q -> Rear = 0;
	Q -> Array = malloc(sizeof(QueueElementType) * MaxElements);
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q -> Array);
		free(Q);
	}
}

void MakeEmpty(Queue Q)
{
	Q -> Size = 0;
	Q -> Front = 1;
	Q -> Rear = 0;
}

int Succ(int Value, Queue Q)
{
	if (++Value == Q -> Capacity)
		Value = 0;

	return Value;
}

void Enqueue(QueueElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		fprintf(stderr, "Queue Full\n");
		exit(1);
	}

	++Q -> Size;
	Q -> Rear = Succ(Q -> Rear, Q);
	Q -> Array[Q -> Rear] = X;
}

QueueElementType Front(Queue Q)
{
	if (IsEmpty(Q))
	{
		fprintf(stderr, "Empty Queue\n");
		exit(1);
	}

	return Q -> Array[Succ(Q -> Front, Q)];
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		fprintf(stderr, "Empty Queue\n");
		exit(1);
	}

	--Q -> Size;
	Q -> Front = Succ(Q -> Front, Q);
}

QueueElementType FrontAndDequeue(Queue Q)
{
	QueueElementType Temp;

	if (IsEmpty(Q))
	{
		fprintf(stderr, "Empty Queue\n");
		exit(1);
	} 

	--Q -> Size;
	Temp = Q -> Array[Q -> Front];
	Q -> Front = Succ(Q -> Front, Q);
	return Temp;
}
