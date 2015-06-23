#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>


void MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T -> Left);
		MakeEmpty(T -> Right);
		free(T);
	}
}

Position Find(ElementType X, AvlTree T)
{
	if (T != NULL)
	{
		if (T -> Element > X)
			return Find(X, T -> Right);
		else if (T -> Element < X)
			return Find(X, T -> Left);
		else
			return T;
	}

	return NULL;
}

Position FindMin(AvlTree T)
{
	if (T -> Left)
		return FindMin(T -> Left);

	return T;
}

Position FindMax(AvlTree T)
{
	if (T -> Right)
		return FindMax(T -> Right);

	return T;
}

Position SingleRotateWithLeft(Position P)
{
	Position Temp;
	Temp = P -> Left;
	P -> Left = Temp -> Right;
	Temp -> Right = P;

	P -> Height = Max(Height(P -> Left), Height(P -> Right)) + 1; 
	Temp -> Height = Max(Height(Temp -> Left), Height(Temp -> Right)) + 1; 

	return Temp;
}

Position SingleRotateWithRight(Position P)
{
	Position Temp;
	Temp = P -> Right;
	P -> Right = Temp -> Left;
	Temp -> Left = P;

	P -> Height = Max(Height(P -> Left), Height(P -> Right)) + 1;
	Temp -> Height = Max(Height(Temp -> Left), Height(Temp -> Right)) + 1;
	
	return Temp;
}

Position DoubleRotateWithLeft(Position P)
{
	P -> Left = SingleRotateWithRight(P -> Left);
	return SingleRotateWithLeft(P);
}

Position DoubleRotateWithRight(Position P)
{
	P -> Right = SingleRotateWithLeft(P -> Right);
	return SingleRotateWithRight(P);
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Height(AvlTree T)
{
	if (T == NULL)
		return 0;

	return T -> Height;
	// if (T == NULL)
	// 	return 0;

	// return Max(Height(T -> Left), Height(T -> Right)) + 1;
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct AvlNode));
		T -> Left = T -> Right = NULL;
		T -> Element = X;
		T -> Height = 1;
	}
	else
	{
		if (T -> Element > X)
		{
			T -> Left = Insert(X, T -> Left);	
			if (Height(T -> Left) - Height(T -> Right) >= 2)
			{
				if (T -> Left -> Element > X)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
			}
		}
		else if (T -> Element < X)
		{
			T -> Right = Insert(X, T -> Right);
			if (Height(T -> Right) - Height(T -> Left) >= 2)
			{
				if (T -> Right -> Element > X)
					T = DoubleRotateWithRight(T);
				else
					T = SingleRotateWithRight(T);
			}
		}
	}

	T -> Height = Max(Height(T -> Left), Height(T -> Right)) + 1;

	return T;
}

// AvlTree Delete(ElementType X, AvlTree T)
// {
// 	if (T != NULL)
// 	{
// 		if (T -> Element > X)
// 		{
// 			T -> Left = Delete(X, T -> Left);
// 		}
// 	}
// }