#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QueueRecord
{
	int Rear;
	int Front;
	int Capacity;
	QueueElementType* Array;
};

int IsEmpty(Queue Q)
{
	return Q -> Rear == Q -> Front;
}

int Succ(int Value, Queue Q)
{
	if (++Value == Q -> Capacity)
		Value = 0;

	return Value;
}

int IsFull(Queue Q)
{
	return Succ(Q -> Rear, Q) == Q -> Front;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	Q -> Rear = 0;
	Q -> Front = 0;
	Q -> Capacity = MaxElements;
	Q -> Array = malloc((sizeof(QueueElementType) * MaxElements));

	return Q;
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
	Q -> Front = Q -> Rear;
}

void Enqueue(QueueElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		fprintf(stderr, "Queue Full\n");
		exit(1);
	}

	Q -> Array[Q -> Rear] = X;
	Q -> Rear = Succ(Q -> Rear, Q);
}

QueueElementType Front(Queue Q)
{
	if (IsEmpty(Q))
	{
		fprintf(stderr, "Queue Empty\n");
		exit(1);		
	}

	return Q -> Array[Q -> Front];
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		fprintf(stderr, "Queue Empty\n");
		exit(1);		
	}

	Q -> Front = Succ(Q -> Front, Q);
}

QueueElementType FrontAndDequeue(Queue Q)
{
	QueueElementType Temp;

	if (IsEmpty(Q))
	{
		fprintf(stderr, "Queue Empty\n");
		exit(1);		
	}

	Temp = Q -> Array[Q -> Front]; 
	Q -> Front = Succ(Q -> Front, Q);

	return Temp;
}

