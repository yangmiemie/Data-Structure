#include "stack_array.h"
#include <stdio.h>
#include <stdlib.h>

Stack CreateStack(int MaxElements)
{
	Stack S;
	S = malloc(sizeof(struct StackRecord));
	S->array = malloc(sizeof(ElementType) * MaxElements);
	S->TopOfStack = -1;
	S->Capacity = MaxElements;
}

void DisposeStack(Stack S)
{
	if (S)
	{
		free(S->array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == -1;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = -1;
}

int IsFull(Stack S)
{
	return S->TopOfStack + 1 == S->Capacity;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{
		S->array = realloc(S->array, S->Capacity * 2);
		S->Capacity *= 2;
	}

	S->array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
		fprintf(stderr, "Empty Stack\n");
	else
		return S->array[S->TopOfStack];
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		fprintf(stderr, "Empty Stack\n");
	else
		S->TopOfStack--;		

	return;
}

int TopAndPop(Stack S)
{
	if (IsEmpty(S))
		fprintf(stderr, "Empty Stack\n");
	else
	  return S->array[S->TopOfStack--];
}


