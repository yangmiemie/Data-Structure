#include "queue.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Queue Q;
	int i;

	Q = CreateQueue(8);

	for (i = 0; i < 5; ++i)
		Enqueue(i, Q);

	for (i = 0; i < 3; ++i)
		Dequeue(Q);

	for (i = 5; i < 10; ++i)
		Enqueue(i, Q);

	for (i = 0; i < 3; ++i)
		Dequeue(Q);

	for (i = 10; i < 13; ++i)
		Enqueue(i, Q);

	for (i = 0; i < 6; ++i)
		Dequeue(Q);

	while(!IsEmpty(Q))
	{
		printf("index %d: ", Q->Front);
		printf("%d\n", FrontAndDequeue(Q));
	}

	printf("\n");

	DisposeQueue(Q);
}