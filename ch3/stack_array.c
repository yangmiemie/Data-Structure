#include "stack_array.h"
#include <stdio.h>
#include <stdlib.h>

Stack CreateStackArray(int MaxElements)
{
	Stack S;
	S = malloc(sizeof(struct StackRecord));
	S->array = malloc(sizeof(ElementType) * MaxElements);
	S->TopOfStack = -1;
	S->Capacity = MaxElements;
}

void DisposeStackArray(Stack S)
{
	if (S)
	{
		free(S->array);
		free(S);
	}
}

int IsEmptyStackArray(Stack S)
{
	return S->TopOfStack == -1;
}

void MakeEmptyStackArray(Stack S)
{
	S->TopOfStack = -1;
}

int IsFullStackArray(Stack S)
{
	return S->TopOfStack + 1 == S->Capacity;
}

void PushArray(ElementType X, Stack S)
{
	if (IsFullStackArray(S))
	{
		S->array = realloc(S->array, S->Capacity * 2);
		S->Capacity *= 2;
	}

	S->array[++S->TopOfStack] = X;
}

ElementType TopArray(Stack S)
{
	if (IsEmptyStackArray(S))
		fprintf(stderr, "Empty Stack\n");
	else
		return S->array[S->TopOfStack];
}

void PopArray(Stack S)
{
	if (IsEmptyStackArray(S))
		fprintf(stderr, "Empty Stack\n");
	else
		S->TopOfStack--;		

	return;
}

int TopAndPop(Stack S)
{
	if (IsEmptyStackArray(S))
		fprintf(stderr, "Empty Stack\n");
	else
	  return S->array[S->TopOfStack--];
}


