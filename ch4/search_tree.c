#include "queue.h"
#include "binary_search_tree.h"

#include <stdio.h>
#include <stdlib.h>

void PrintTree(SearchTree T)
{
	if (T != NULL)
	{
		PrintTree(T -> Left);
		printf("%d ", T -> Element);
		PrintTree(T -> Right);
	}
}

void PreOrderTraverse(SearchTree T)
{
	if (T != NULL)
	{
		printf("%d ", T -> Element);
		PreOrderTraverse(T -> Left);
		PreOrderTraverse(T -> Right);
	}
}

void MidOrderTraverse(SearchTree T)
{
	if (T != NULL)
	{
		MidOrderTraverse(T -> Left);
		printf("%d ", T -> Element);
		MidOrderTraverse(T -> Right);
	}
}

void PostOrderTraverse(SearchTree T)
{
	if (T != NULL)
	{
		PostOrderTraverse(T -> Left);
		PostOrderTraverse(T -> Right);
		printf("%d ", T -> Element);
	}
}

void LevelTraverse(SearchTree T)
{
	Queue Q;
	Position P;
	int MaxElement = 32;

	if (T == NULL)
		return;

	Q = CreateQueue(MaxElement);
	Enqueue(T, Q);

	while(!IsEmpty(Q))
	{
		P = FrontAndDequeue(Q);
		printf("%d ", P -> Element);
		if (P -> Left)
			Enqueue(P -> Left, Q);
		if (P -> Right)
			Enqueue(P -> Right, Q);
	}

	DisposeQueue(Q);
}

int main(int argc, char const *argv[])
{
	SearchTree T;
	int Array[8] = {3, 1, 4, 6, 9, 2, 5, 7};
	int i;

	T = NULL;
	for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
	{
		T = Insert(Array[i], T);
	}

	PreOrderTraverse(T);
	printf("\n");

	MidOrderTraverse(T);
	printf("\n");

	PostOrderTraverse(T);
	printf("\n");

	LevelTraverse(T);
	printf("\n");

	for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
	{
		T = Delete(Array[i], T);
		LevelTraverse(T);
		printf("\n");
	}
	return 0;
}