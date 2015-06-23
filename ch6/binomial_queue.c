#include "binomial_queue.h"

BinQueue CreateCollection()
{
	BinQueue Q;
	int i;

	Q = malloc(sizeof(struct Collection));
	Q -> CurrentSize = 0;

	for (i = 0; i < MaxTrees; ++i)
		Q -> TheTrees[i] = NULL;

	return Q;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
	if (T1 -> Element > T2 -> Element)
		return CombineTrees(T2, T1);

	T2 -> NextSibling = T1 -> LeftChild;
	T1 -> LeftChild = T2;

	return T1;
}

void Insert(ElementType X, BinQueue Q)
{
	Position P;
	int i;

	P = malloc(sizeof(struct BinNode));
	P -> Element = X;
	P -> NextSibling = NULL;
	P -> LeftChild = NULL;

	for (i = 0; i < MaxTrees; ++i)
	{
		if (Q -> TheTrees[i] == NULL)
		{
			Q -> TheTrees[i] = P;
			break;
		}
		
		P = CombineTrees(Q -> TheTrees[i], P);
		Q -> TheTrees[i] = NULL;
	}

	Q -> CurrentSize += 1;
}

void MakeEmpty(BinTree T)
{
	if (T)
	{
		MakeEmpty(T -> LeftChild);
		MakeEmpty(T -> NextSibling);

		free(T);
	}
}
void DisposeCollection(BinQueue Q)
{
 	int i;

 	if (Q == NULL)
 		return;

 	for (i = 0; i < MaxTrees; ++i)
 	{
 		if (Q -> TheTrees[i])
 			MakeEmpty(Q -> TheTrees[i]);
 	}

 	free(Q);
}

BinQueue Merge(BinQueue Q1, BinQueue Q2)
{
	BinTree T1, T2, Carry;
	int i, j;

	Q1 -> CurrentSize += Q2 -> CurrentSize;
	Carry = NULL;

	for (i = 0, j = 1; i < MaxTrees, j <= Q1 -> CurrentSize; ++i, j *= 2)
	{
		T1 = Q1 -> TheTrees[i];
		T2 = Q2 -> TheTrees[i];

		switch(!! T1 + !! T2 * 2 + !! Carry * 4)
		{
			case 0:
			case 1:
				break;
			case 2:
				Q1 -> TheTrees[i] = T2;
				break;
			case 3:
				Q1 -> TheTrees[i] = NULL;
				Carry = CombineTrees(T1, T2);
				break;
			case 4:
				Q1 -> TheTrees[i] = Carry;
				Carry = NULL;
				break;
			case 5:
				Q1 -> TheTrees[i] = NULL;
				Carry = CombineTrees(T1, Carry);
				break;
			case 6:
				Carry = CombineTrees(T2, Carry);
				break;
			case 7:
				Carry = CombineTrees(T1, Carry);
				Q1 -> TheTrees[i] = T2;
				break;
		}
	}

	return Q1;
}

ElementType DeleteMin(BinQueue Q)
{
	ElementType MinItem;
	int i;
	int MinTree;
	BinTree DeletedTree;
	Position oldRoot;
	BinQueue DeletedQueue;

	MinItem = 0xfffff;
	for (i = 0; i < MaxTrees; ++i)
	{
		if ((Q -> TheTrees[i] != NULL) && (MinItem > Q -> TheTrees[i] -> Element))
		{
			MinItem = Q -> TheTrees[i] -> Element;
			MinTree = i;
		}	
	}

	DeletedTree = Q -> TheTrees[MinTree] -> LeftChild;
	oldRoot = Q -> TheTrees[MinTree];
	free(oldRoot);

	DeletedQueue = CreateCollection();
	DeletedQueue -> CurrentSize = (1 << MinTree) - 1;
	for (i = MinTree - 1; i >= 0; --i)
	{
		DeletedQueue -> TheTrees[i] = DeletedTree;
		DeletedTree = DeletedTree -> NextSibling;
		DeletedQueue -> TheTrees[i] -> NextSibling = NULL;
	}

	Q -> TheTrees[MinTree] = NULL;
	Q -> CurrentSize -= DeletedQueue -> CurrentSize + 1;
	Merge(Q, DeletedQueue);

	return MinItem;
}