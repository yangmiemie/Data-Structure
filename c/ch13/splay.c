#include "splay.h"

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	ELementType Element;
	SplayTree Left;
	SplayTree Right;
};

SplayTree RotateLeft(SplayTree T)
{
	SplayTree P;

	P = T -> Left;
	T -> Left = P -> Right;
	P -> Right = T;
	return P;
}

SplayTree RotateRight(SplayTree T)
{
	SplayTree P;

	P = T -> Right;
	T -> Right = P -> Left;
	P -> Left = T;

	return P;
}

SplayTree NewNode(ELementType X)
{
	SplayTree T;
	T = malloc(sizeof(struct TreeNode));
	T -> Left = T -> Right = NULL;
	T -> Element = X;
	return T;
}

SplayTree Insert(ELementType X, SplayTree T)
{
	if (T == NULL)
		return NewNode(X);

	if (T -> Element > X)
	{
		if (T -> Left == NULL)
			T -> Left = NewNode(X);
		else
		{
			if (T -> Left -> Element > X)
			{
				T -> Left -> Left = Insert(X, T -> Left -> Left);
				T = RotateLeft(T);
			}
			else if (T -> Left -> Element < X)
			{
				T -> Left -> Right = Insert(X, T -> Left -> Right);
				T -> Left = RotateRight(T -> Left);
			}
		}
		return RotateLeft(T);
	}
	else if (T -> Element < X)
	{
		if (T -> Right == NULL)
			T -> Right = NewNode(X);
		else
		{
			if (T -> Right -> Element > X)
			{
				T -> Right -> Left = Insert(X, T -> Right -> Left);
				T -> Right = RotateLeft(T -> Right);
			}
			else if (T -> Right -> Element < X)
			{
				T -> Right -> Right = Insert(X, T -> Right -> Right);
				T = RotateRight(T);
			}
		}
		return RotateRight(T);
	}
}

SplayTree InsertRotate(ELementType X, SplayTree T)
{
	if (T == NULL)
		return NewNode(X);

	if (T -> Element > X)
	{
		T -> Left = InsertRotate(X, T -> Left);
		T = RotateLeft(T);
	}
	else if (T -> Element < X)
	{
		T -> Right = InsertRotate(X, T -> Right);
		T = RotateRight(T);
	}

	return T;
}

void PreOrderTraverse(SplayTree T)
{
	if (T == NULL)
		return;

	printf("%d ", T -> Element);
	PreOrderTraverse(T -> Left);
	PreOrderTraverse(T -> Right);
}

void InOrderTraverse(SplayTree T)
{
	if (T == NULL)
		return;

	InOrderTraverse(T -> Left);
	printf("%d ", T -> Element);
	InOrderTraverse(T -> Right);
}


void PostOrderTraverse(SplayTree T)
{
	if (T == NULL)
		return;

	PostOrderTraverse(T -> Left);
	PostOrderTraverse(T -> Right);
	printf("%d ", T -> Element);
}