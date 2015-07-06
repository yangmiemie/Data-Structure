#include <stdio.h>
#include <stdlib.h>

#define ElementType char
#define BytesWord 5

typedef struct TreeNode* Position;
typedef struct TreeNode* TrieTree;

struct TreeNode
{
	ElementType Element;
	TrieTree Left;
	TrieTree Right;
};

int Digit(ElementType S, int W)
{
	return S >> (BytesWord - W - 1) & 1;
}

Position NewNode(ElementType X)
{
	Position P;

	P = malloc(sizeof(struct TreeNode));
	P -> Left = P -> Right = NULL;
	P -> Element = X;

	return P;
}

TrieTree Split(Position P1, Position P2, int W)
{
	Position P;

	P = NewNode(-1);

	switch(Digit(P1 -> Element, W) * 2 + Digit(P2 -> Element, W))
	{
		case 0:
			P -> Left = Split(P1, P2, W + 1);
			break;
		case 1:
			P -> Left = P1, P -> Right = P2;
			break;
		case 2:
			P -> Left = P2, P -> Right = P1;
			break;
		case 3:
			P -> Right = Split(P1, P2, W + 1);
			break;
	}

	return P;
}

TrieTree TrieInsert(TrieTree T, ElementType X, int W)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		T -> Left = T -> Right = NULL;
		T -> Element = X;
		return T;
	}

	if (T -> Element == X)
		return T;
	
	if (T -> Left == NULL && T -> Right == NULL)
		return Split(NewNode(X), T, W);

	if (Digit(X, W) == 0)
		T -> Left = TrieInsert(T -> Left, X, W + 1);
	else
		T -> Right = TrieInsert(T -> Right, X, W + 1);

	return T;
}

TrieTree Insert(TrieTree T, ElementType X)
{
	return TrieInsert(T, X, 0);
}

Position TrieSearch(TrieTree T, ElementType X, int W)
{
	if (T == NULL)
		return NULL;

	if (T -> Left == NULL && T -> Right == NULL)
		return T -> Element == X ? T : NULL;

	if (Digit(X, W) == 0)
		return TrieSearch(T -> Left, X, W + 1);
	else
		return TrieSearch(T -> Right, X, W + 1);
}

Position Search(TrieTree T, ElementType X)
{
	return TrieSearch(T, X, 0);
}

void PreOrderTraverse(TrieTree T)
{
	if (T == NULL)
		return;

	printf("%c ", T -> Element);
	PreOrderTraverse(T -> Left);
	PreOrderTraverse(T -> Right);
}

void InOrderTraverse(TrieTree T)
{
	if (T == NULL)
		return;

	InOrderTraverse(T -> Left);
	printf("%c ", T -> Element);
	InOrderTraverse(T -> Right);
}

void PostOrderTraverse(TrieTree T)
{
	if (T == NULL)
		return;

	PostOrderTraverse(T -> Left);
	PostOrderTraverse(T -> Right);
	printf("%c ", T -> Element);
}

void MakeEmpty(TrieTree T)
{
	if (T == NULL)
		return;

	MakeEmpty(T -> Left);
	MakeEmpty(T -> Right);
	free(T);
}

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N'};
	// char Array[] = {'A', 'S', 'E'};
	int Len, i;
	TrieTree T;
	Position P;

	Len = sizeof(Array) / sizeof(Array[0]);
	T = NULL;

	for (i = 0; i < Len; ++i)
		T = Insert(T, Array[i]);

	PreOrderTraverse(T);
	printf("\n");

	InOrderTraverse(T);
	printf("\n");


	P = Search(T, 'E');
	printf("%c\n", (P == NULL) ? '0' : P -> Element);

	P = Search(T, 'Z');
	printf("%c\n", (P == NULL) ? '0' : P -> Element);

	MakeEmpty(T);
	return 0;
}