#include "stack.h"

struct ArrayStackRecord
{
  int TopOfStack;
  int Capacity;
  ArrayStackElementType* Array;
};

int IsArrayStackEmpty(ArrayStack S)
{
  return S -> TopOfStack == -1;
}

int IsArrayStackFull(ArrayStack S)
{
  return (S -> TopOfStack + 1) == S -> Capacity;
}

ArrayStack CreateArrayStack(int MaxElements)
{
  ArrayStack S;
  S = malloc(sizeof(struct ArrayStackRecord));
  S -> Array = malloc((sizeof(ArrayStackElementType)) * MaxElements);
  S -> Capacity = MaxElements;
  S -> TopOfStack = -1;
  return S; 
}

void DisposeStack(ArrayStack S)
{
  if (S != NULL)
  {
    free(S -> Array);
    free(S);
  }
}

ArrayStackElementType Top(ArrayStack S)
{
  if (IsArrayStackEmpty(S))
  {
    fprintf(stderr, "Empty Stack");
    exit(1);
  }

  return S -> Array[S -> TopOfStack];
}

void Pop(ArrayStack S)
{
  if (IsArrayStackEmpty(S))
  {
    fprintf(stderr, "Empty Stack");
    exit(1);
  }

  -- S -> TopOfStack;
}

ArrayStackElementType TopAndPop(ArrayStack S)
{
  ArrayStackElementType Temp;

  if (IsArrayStackEmpty(S))
  {
    fprintf(stderr, "Empty Stack");
    exit(1);
  }

  Temp = S -> Array[S -> TopOfStack];
  -- S -> TopOfStack;
  return Temp;  
}

void Push(ArrayStackElementType X, ArrayStack S)
{
  if (IsArrayStackFull(S))
  {
    S -> Array = realloc(S -> Array, S -> Capacity * 2 * sizeof(ArrayStackElementType));
    S -> Capacity *= 2;
  }

  S -> Array[++S -> TopOfStack] = X;
}