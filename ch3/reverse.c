#define ElementType int

#include <stdio.h>
#include <stdlib.h>

typedef struct Node* List;
typedef struct Node* Position;

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L -> Next == NULL;
}

List CreateList()
{
	Position P;
	P = malloc(sizeof(struct Node));
	P -> Next = NULL;

	return P;
}

void Insert(Position P, List L, ElementType X)
{
	Position Tmp;
	Tmp = malloc(sizeof(struct Node));
	Tmp -> Element = X;

	Tmp -> Next = P -> Next;
	P -> Next = Tmp;
}

void PrintList(List L)
{
	Position P;

	if (IsEmpty(L))
		return;

	P = L -> Next;
	while(P)
	{
		printf("%d ", P -> Element);
		P = P -> Next;
	}

	printf("\n");
}

void DestoryList(List L)
{
	Position P;

	if (L)
	{
		P = L;

		while(P)
		{
			L = L -> Next;
			free(P);
			P = L;
		}
	}
}

void ReverseNonRecursively(List L)
{
	Position P1, P2, P3;
	
	if (IsEmpty(L) || L -> Next -> Next == NULL)
		return;

	P1 = L -> Next;
	P2 = P1 -> Next;
	P1 -> Next = NULL;

	while(P2)
	{
		P3 = P2 -> Next;
		P2 -> Next = P1;
		P1 = P2;
		P2 = P3;
	}

	L -> Next = P1;
}

List ReverseRecursively(List L)
{
	Position P;
	List ReversedList;

	if (L == NULL || L -> Next == NULL)
		return L;
	else
	{
		P = L;
		ReversedList = ReverseRecursively(P -> Next);
		P -> Next -> Next = P;
		P -> Next = NULL;

		return ReversedList;
	}
}

int main(int argc, char const *argv[])
{
	List L;
	Position P;
	int i;

	L = CreateList();

	P = L;

	for (i = 1; i <= 100; ++i)
	{
		Insert(P, L, i);
		P = P -> Next;
	}

	PrintList(L);

	L -> Next = ReverseRecursively(L -> Next);

	PrintList(L);

	DestoryList(L);
	return 0;
}