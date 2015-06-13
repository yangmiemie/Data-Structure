#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue CreateQueue(int MaxElements)
{
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	Q->Array = malloc(sizeof(QueueElementType) * MaxElements);
	Q->Capacity = MaxElements;
	Q->Size = 0;
	Q->Front = 0;
	Q->Rear = 0;

	return Q;
}

int IsEmptyQueue(Queue Q)
{
	return Q->Rear == Q->Front;
}

int IsFull(Queue Q)
{
	return (Q->Rear + 1) == (Q->Front);
}

void MakeEmptyQueue(Queue Q)
{
	Q->Rear = Q->Front;
}

int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;

	return Value;
}

void Enqueue(QueueElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		fprintf(stderr, "Full Queue\n");
		exit(1);
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

int Prev(int Value, Queue Q)
{
	if (--Value == -1)
		Value = Q->Capacity - 1;

	return Value;
}

void Dequeue(Queue Q)
{
	if (IsEmptyQueue(Q))
	{
		fprintf(stderr, "Empty Queue\n");
		exit(1);
	}
	else
	{
		Q->Size--;
		Q->Front =  Succ(Q->Front, Q);
	}
}

QueueElementType FrontAndDequeue(Queue Q)
{
	QueueElementType X;
	if (IsEmptyQueue(Q))
	{
		fprintf(stderr, "Empty Queue\n");
		exit(1);
	}
	else
	{
		Q->Size--;
		Q->Front =  Succ(Q->Front, Q);
		return Q->Array[Q->Front];
	}
}

void DisposeQueue(Queue Q)
{
	if (Q)
	{
		free(Q->Array);
		free(Q);
	}
}