#include "stack.h"

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	StackElementType* Array;
};

Stack CreateStack(int MaxElements)
{
	Stack S;

	S = malloc(sizeof(struct StackRecord));
	S -> Capacity = MaxElements;
	S -> TopOfStack = -1;
	S -> Array = malloc((sizeof(StackElementType)) * MaxElements);

	return S;
}

void DisposeStack(Stack S)
{
	if (S)
	{
		free(S -> Array);
		free(S);
	}
}

void Pop(Stack S)
{
	if (IsEmpty(S))
	{
		fprintf(stderr, "Empty Stack\n");
		exit(1);		
	}

	-- S -> TopOfStack;
}

void Push(StackElementType X, Stack S)
{
	if (IsFull(S))
	{
		fprintf(stderr, "Full Stack\n");
		exit(1);
	}

	S -> Array[++S -> TopOfStack] = X;
}

StackElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		fprintf(stderr, "Empty Stack\n");
		exit(1);		
	}

	return S -> Array[S -> TopOfStack];
}

StackElementType TopAndPop(Stack S)
{
	StackElementType Temp;

	if (IsEmpty(S))
	{
		fprintf(stderr, "Empty Stack\n");
		exit(1);	
	}

	Temp = S -> Array[S -> TopOfStack];
	-- S -> TopOfStack;

	return Temp;
}
int IsFull(Stack S)
{
	return S -> TopOfStack + 1 == S -> Capacity;
}
int IsEmpty(Stack S)
{
	return S -> TopOfStack == -1;
}
