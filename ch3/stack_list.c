#include "stack_list.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack()
{
	Stack S;
	S = malloc(sizeof(struct Node));

	S->Next = NULL;
	return S;
}

void MakeEmpty(Stack S)
{
	if (S != NULL)
	{
		while(!IsEmpty(S))
		{
			Pop(S);
		}
	}
}

void Pop(Stack S)
{
	PtrToNode TmpCell;
	if (!IsEmpty(S))
	{
		TmpCell = S->Next;
		S->Next = TmpCell->Next;
		free(TmpCell);
	}
	else
		fprintf(stderr, "Empty Stack\n");
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		fprintf(stderr, "Empty Stack\n");
	}
	else
	{
		return S->Next->Element;
	}
}


void Push(ElementType X, Stack S)
{
	PtrToNode P;
	P = malloc(sizeof(struct Node));
	P->Element = X;

	P->Next = S->Next;
	S->Next = P;
}

void DisposeStack(Stack S)
{
	free(S);
}