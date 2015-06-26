#include "randomize_bst.h"

#include <stdio.h>
#include <stdlib.h>

struct BSTNode
{
	ElementType Element;
	BSTree Left;
	BSTree Right;
	int Height;
	int Number;
};

void ResetHeight(BSTree T)
{
	T -> Height = Max(Height(T -> Left), Height(T -> Right)) + 1;
}

void ResetNumber(BSTree T)
{
	T -> Number = Count(T -> Left) + Count(T -> Right) + 1;
}

BSTree RotateLeft(BSTree T)
{
	BSTree P;

	P = T -> Left;
	T -> Left = P -> Right;
	ResetHeight(T);
	ResetNumber(T);
	P -> Right = T;
	ResetHeight(P);
	ResetNumber(P);
	return P;
}

BSTree RotateRight(BSTree T)
{
	BSTree P;

	P = T -> Right;
	T -> Right = P -> Left;
	ResetHeight(T);
	ResetNumber(T);
	P -> Left = T;
	ResetHeight(P);
	ResetNumber(P);
	return P;
}

int Height(BSTree T)
{
	if (T == NULL)
		return 0;

	return T -> Height;
}

int Count(BSTree T)
{
	if (T == NULL)
		return 0;

	return T -> Number;
}

ElementType Value(Position P)
{
	if (P == NULL)
	{
		fprintf(stderr, "No Such Node\n");
		exit(1);
	}

	return P -> Element;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

BSTree Insert(ElementType X, BSTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct BSTNode));
		T -> Left = T -> Right = NULL;
		T -> Height = 1;
		T -> Element = X;
		T -> Number = 1;
		return T;
	}

	if (T -> Element > X)
	{
		T -> Left = Insert(X, T -> Left);
		T = RotateLeft(T);
	}
	else if (T -> Element < X)
	{
		T -> Right = Insert(X, T -> Right);
		T = RotateRight(T);
	}

	ResetHeight(T);
	ResetNumber(T);
	return T;
}

void PreOrderTraverse(BSTree T)
{
	if (T == NULL)
		return;

	printf("%c(%d) ", T -> Element, Count(T));
	PreOrderTraverse(T -> Left);
	PreOrderTraverse(T -> Right);
}

BSTree Select(int k, BSTree T)
{
	int t;
	t = (T == NULL) ? 0 : Count(T -> Left);

	if (t > k)
		return Select(k, T -> Left);
	else if (t < k)
		return Select(k - t - 1, T -> Right);

	return T;
}

BSTree Partition(int k, BSTree T)
{
	int t;

	t = (T == NULL) ? 0 : Count(T -> Left);

	if (t > k)
	{
		T -> Left = Partition(k, T -> Left);
		T = RotateLeft(T);
	}
	else if (t < k)
	{
		T -> Right = Partition(k - t - 1, T -> Right);
		T = RotateRight(T);
	}

	return T;
}

BSTree Balance(BSTree T)
{
	if (Count(T) < 2)
		return T;

	T = Partition(Count(T) / 2, T);
	T -> Left = Balance(T -> Left);
	T -> Right = Balance(T -> Right);

	return T;
}

BSTree InsertStandard(ElementType X, BSTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct BSTNode));
		T -> Left = T -> Right = NULL;
		T -> Height = 1;
		T -> Element = X;
		T -> Number = 1;
		return T;
	}

	if (T -> Element > X)
	{
		T -> Left = Insert(X, T -> Left);
	}
	else if (T -> Element < X)
	{
		T -> Right = Insert(X, T -> Right);
	}

	ResetHeight(T);
	ResetNumber(T);
	return T;
}

BSTree InsertRandomize(ElementType X, BSTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct BSTNode));
		T -> Left = T -> Right = NULL;
		T -> Height = 1;
		T -> Element = X;
		T -> Number = 1;
		return T;
	}

	if (rand() < RAND_MAX / (Height(T) + 1))
	 	return Insert(X, T);

	if (T -> Element > X)
		T -> Left = InsertRandomize(X, T -> Left);
	else if (T -> Element < X)
		T -> Right = InsertRandomize(X, T -> Right);

	ResetNumber(T);
	ResetHeight(T);
	return T;
}
