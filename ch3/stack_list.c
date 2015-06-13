#include "stack_list.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmptyStack(Stack S)
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

void MakeEmptyStack(Stack S)
{
	if (S != NULL)
	{
		while(!IsEmptyStack(S))
		{
			Pop(S);
		}
	}
}

void Pop(Stack S)
{
	PtrToNode TmpCell;
	if (!IsEmptyStack(S))
	{
		TmpCell = S->Next;
		S->Next = TmpCell->Next;
		free(TmpCell);
	}
	else
		fprintf(stderr, "Empty Stack\n");
}

StackElementType Top(Stack S)
{
	if (IsEmptyStack(S))
	{
		fprintf(stderr, "Empty Stack\n");
	}
	else
	{
		return S->Next->Element;
	}
}


void Push(StackElementType X, Stack S)
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