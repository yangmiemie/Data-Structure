#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define BUFSIZE 8
#define RANGE 20

typedef struct StackRecord* Stack;

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreateStack(int MaxElement)
{
	Stack S;
	S = malloc((sizeof(struct StackRecord)));
	S -> Capacity = MaxElement;
	S -> TopOfStack = -1;
	S -> Array = malloc((sizeof(ElementType) * MaxElement));

	return S;
}

void DisposeStack(Stack S)
{
	if (S == NULL)
		return;

	free(S -> Array);
	free(S);
}

int IsEmpty(Stack S)
{
	return S -> TopOfStack == -1;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		fprintf(stderr, "Error Stack\n");
		exit(1);
	}

	return S -> Array[S -> TopOfStack];
}

void Pop(Stack S)
{
	if (IsEmpty)
	{
		fprintf(stderr, "Error Stack\n");
		exit(1);		
	}

	--S -> TopOfStack;
}

void Push(ElementType X, Stack S)
{
	if (S -> TopOfStack + 1 == S -> Capacity)
	{
		S -> Array = realloc(S -> Array, (sizeof(ElementType)) * S -> Capacity * 2);
	}

	S -> Array[++S -> TopOfStack] = X;
}

ElementType TopAndPop(Stack S)
{
	ElementType X;
	if (IsEmpty(S))
	{
		fprintf(stderr, "Error Stack\n");
		exit(1);		
	}

	X = S -> Array[S -> TopOfStack];
	--S -> TopOfStack;
	return X;
}

ElementType Min(ElementType a, ElementType b)
{
	return a > b ? b : a;
}

int main(int argc, char const *argv[])
{
	Stack DataStack, MinStack;
	int Value, i;

	DataStack = CreateStack(BUFSIZE);
	MinStack = CreateStack(BUFSIZE);

	for (i = 0 ; i < BUFSIZE; ++i )
	{
		Value = rand();

		Push(Value, DataStack);

		if (IsEmpty(MinStack))
			Push(Value, MinStack);
		else
		{
			Push(Min(Value, Top(MinStack)), MinStack);
		}
	}

	while(!IsEmpty(DataStack))
	{
		printf("%d ", TopAndPop(DataStack));
	}
	printf("\n");

	while(!IsEmpty(MinStack))
	{
		printf("%d ", TopAndPop(MinStack));
	}
	printf("\n");

	DisposeStack(DataStack);
	DisposeStack(MinStack);
	return 0;
}