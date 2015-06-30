#include "bst.h"

#include <stdlib.h>
#include <stdio.h>

struct BSTNode
{
	ElementType Element;
	int Number;
	BSTree Left;
	BSTree Right;
};

BSTree Insert(ElementType X, BSTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct BSTNode));
		T -> Left = T -> Right = NULL;
		T -> Element = X;
		T -> Number = 1;
		return T; 
	}

	if (T -> Element > X)
		T -> Left = Insert(X, T -> Left);
	else if (T -> Element < X)
		T -> Right = Insert(X, T -> Right);


	T -> Number++;
	return T;
}

BSTree Insert2(ElementType X, BSTree T)
{
	Position P1, P2;

	P1 = P2 = T;

	while(P2 != NULL)
	{
		P1 = P2;

		if (P2 -> Element > X) 
			P2 = P2 -> Left;
		else
			P2 = P2 -> Right;
	}

	P2 = malloc(sizeof(struct BSTNode));
	P2 -> Element = X;
	P2 -> Left = P2 -> Right = NULL;

	if (!T)
		T = P2;
	else
		if (P1 -> Element > X)
			P1 -> Left = P2;
		else
			P1 -> Right = P2;

	T -> Number++;
	return T;
}

Position RotateR(Position P)
{
	Position P1;

	P1 = P -> Left;
	P -> Number = Count(P -> Right) + Count(P1 -> Right) + 1;
	P -> Left = P1 -> Right;
	P1 -> Right = P;
	P1 -> Number = Count(P1 -> Left) + Count(P1 -> Right) + 1; 
	return P1;
}

Position RotateL(Position P)
{
	Position P1;

	P1 = P -> Right;
	P -> Number = Count(P -> Left) + Count(P1 -> Left) + 1;
	P -> Right = P1 -> Left;
	P1 -> Left = P;
	P1 -> Number = Count(P1 -> Left) + Count(P1 -> Right) + 1; 
	return P1;
}

BSTree Insert3(ElementType X, BSTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct BSTNode));
		T -> Element = X;
		T -> Left = T -> Right = NULL;
		T -> Number = 1;
		return T;
	}

	if (T -> Element > X)
	{
		T -> Left = Insert3(X, T -> Left);
		T = RotateR(T);
	}
	else if (T -> Element < X)
	{
		T -> Right = Insert3(X, T -> Right);
		T = RotateL(T);
	}

	return T;
}

int Count(BSTree T)
{
	if (T == NULL)
		return 0;

	return T -> Number;
}

int Value(Position P)
{
	if (P == NULL)
	{
		fprintf(stderr, "No such Node\n");
		exit(1);
	}

	return P -> Element;
}

Position Search(ElementType X, BSTree T)
{
	if (T == NULL)
		return NULL;

	if (T -> Element == X)
		return T;
	else if (T -> Element > X)
		return Search(X, T -> Left);
	else
		return Search(X, T -> Right);
}

void SortTree(BSTree T)
{
	if (T == NULL)
		return;

	SortTree(T -> Left);
	printf("%c ", T -> Element);
	SortTree(T -> Right);
}

void PreOrderTraverse(BSTree T)
{
	if (T == NULL)
		return;

	printf("%c(%d) ", T -> Element, Count(T));
	PreOrderTraverse(T -> Left);
	PreOrderTraverse(T -> Right);
}

void InOrderTraverse(BSTree T)
{
	if (T == NULL)
		return;

	InOrderTraverse(T -> Left);
	printf("%c ", T -> Element);
	InOrderTraverse(T -> Right);
}

Position Select(int k, BSTree T)
{
	int t;

	if (T == NULL)
		return NULL;

	t = (T -> Left == NULL) ? 0 : T -> Left -> Number;

	if (t < k)
		return Select(k - t - 1, T -> Right);
	else if (t > k)
		return Select(k, T -> Left);

	return T;
}

BSTree Partition(int k, BSTree T)
{
	int t;

	t = (T -> Left == NULL) ? 0 : T -> Left -> Number;

	if (t < k)
	{
		T -> Right = Partition(k - t - 1, T -> Right);
		T = RotateL(T);
	}
	else if (t > k)
	{
		T -> Left = Partition(k, T -> Left);
		T = RotateR(T);
	}
	
	return T;
}

BSTree JoinLR(BSTree T1, BSTree T2)
{
	if (T2 == NULL)
		return T1;

	T2 = Partition(0, T2);
	T2 -> Left = T1;

	T2 -> Number = T2 -> Left -> Number + T2 -> Right -> Number + 1;
	return T2;
}

BSTree Delete(ElementType X, BSTree T)
{
	Position P;

	if (T == NULL)
		return NULL;

	if (T -> Element > X)
		T -> Left = Delete(X, T -> Left);
	else if (T -> Element < X)
		T -> Right = Delete(X, T -> Right);
	else
	{
		P = T;
		T = JoinLR(T -> Left, T -> Right);
		free(P);
	}

	return T;
}

BSTree Join(BSTree T1, BSTree T2)
{
	if (T1 == NULL)
		return T2;

	if (T2 == NULL)
		return T1;

	T2 = Insert3(T1 -> Element, T2);
	T2 -> Left = Join(T1 -> Left, T2 -> Left);
	T2 -> Right = Join(T1 -> Right, T2 -> Right);
	free(T1);

	return T2;
}