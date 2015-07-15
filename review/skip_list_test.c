#include <stdio.h>
#include <stdlib.h>

#define ElementType char
#define MaxLevelvalue 8

typedef struct SLNode* Link;
typedef struct SLNode* Position;
typedef struct SkipList* SkipList;

struct SLNode
{
	ElementType Element;
	int Level;
	Link* Next;
};

struct SkipList
{
	int MaxLevel;
	int CurLevel;
	Link Head;
};

Link NewNode(int Element, int Level)
{
	Link L;
	int i;

	L = malloc(sizeof(struct SLNode));
	L -> Element = Element;
	L -> Level = Level;
	L -> Next = malloc(Level * sizeof(Link));

	for (i = 0; i < Level; ++i)
		L -> Next[i] = NULL;

	return L;
}

SkipList Initialize()
{
	SkipList SL;
	SL = malloc(sizeof(struct SkipList));
	SL -> MaxLevel = MaxLevelvalue;
	SL -> CurLevel = 0;
	SL -> Head = NewNode(0, SL -> MaxLevel);

	return SL;
}

int Rand(SkipList SL)
{
	int i, j;

	for (i = 2, j = 1; i <= SL -> MaxLevel; i += 2, ++j)
		if (RAND_MAX / i > rand())
			break;

	j -= 1;

	if (j > SL -> CurLevel)
		SL -> CurLevel = j;

	return j;
}

ElementType Value(Link L)
{
	if (L == NULL)
		return 0x7f;

	return L -> Element;
}

void SLInsert(Link L, Link Head, int k)
{
	if (L -> Element < Value(Head -> Next[k]))
	{
		L -> Next[k] = Head -> Next[k];
		Head -> Next[k] = L;

		if (k == 0)
			return;

		return SLInsert(L, Head, k - 1);
	}

	SLInsert(L, Head -> Next[k], k);
}

void Insert(ElementType X, SkipList SL)
{
	int L;

	L = Rand(SL);
	SLInsert(NewNode(X, L), SL -> Head, L);
}

Link SLSearch(ElementType X, Link Head, int k)
{
	if (X == Value(Head -> Next[k]))
		return Head -> Next[k];

	if (X < Value(Head -> Next[k]) || Head -> Next[k] == NULL)
	{
		if (k == 0)
			return NULL;

		return SLSearch(X, Head, k - 1);
	}

	SLSearch(X, Head -> Next[k], k);
}

Link Search(ElementType X, SkipList SL)
{
	SLSearch(X, SL -> Head, SL -> CurLevel);
}

void freeNode(Link L)
{
	free(L -> Next);
	free(L);
}

void SLDelete(ElementType X, Link Head, int k)
{
	Position P;

	if (X == Value(Head -> Next[k]))
	{
		P = Head -> Next[k];
		Head -> Next[k] = P -> Next[k];

		if (k == 0)
		{
			freeNode(P);
			return;
		}

		return SLDelete(X, Head, k - 1);
	}

	if (X < Value(Head -> Next[k]))
	{
		if (k == 0)
			return;

		return SLDelete(X, Head, k - 1);
	}

	return SLDelete(X, Head -> Next[k], k);
}

void Delete(ElementType X, SkipList SL)
{
	int i;

	SLDelete(X, SL -> Head, SL -> CurLevel);

	for (i = SL -> CurLevel; i >= 0; --i)
		if (SL -> Head -> Next[i] == NULL)
			--SL -> CurLevel;
}

void PrintSkipList(SkipList SL)
{
	Link L;
	int i;

	i = 0;
	for (i = 0; i <= SL -> CurLevel; ++i)
	{
		for (L = SL -> Head -> Next[i]; L != NULL; L = L -> Next[i])
				printf("%c ", L -> Element);
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G'};
	int i, Len;
	SkipList SL;
	Link L;

	SL = Initialize();
	Len = sizeof(Array) / sizeof(Array[0]);
	for (i = 0; i < Len; ++i)
		Insert(Array[i], SL);

	PrintSkipList(SL);

	for (i = 0; i < Len; ++i)
	{
		L = Search(Array[i], SL);
		if (L == NULL)
			printf("Not Found\n");
		else
			printf("%c\n", L -> Element);
	}

	for (i = 0; i < Len; ++i)
	{
		Delete(Array[i], SL);
		PrintSkipList(SL);
		printf("\n");
	}

	// printf("%d\n", SL -> CurLevel);
	return 0;
}