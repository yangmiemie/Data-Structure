#include <stdio.h>
#include <stdlib.h>

#define ElementType char
#define BytesWord 5

typedef struct TreeNode* Position;
typedef struct TreeNode* DSTTree;

struct TreeNode
{
  ElementType Element;
  DSTTree Left;
  DSTTree Right;
};

int Digit(ElementType S, int W)
{
  return S >> (BytesWord - W - 1) & 1;
}

DSTTree DSTInsert(DSTTree T, ElementType X, int W)
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

  if (Digit(X, W) == 0)
    T -> Left = DSTInsert(T -> Left, X, W + 1);
  else
    T -> Right = DSTInsert(T -> Right, X, W + 1);

  return T;
}

DSTTree Insert(DSTTree T, ElementType X)
{
  return DSTInsert(T, X, 0);
}

DSTTree DSTSearch(DSTTree T, ElementType X, int W)
{
  if (T == NULL)
    return NULL;

  if (T -> Element == X)
    return T;

  if (Digit(X, W) == 0)
    return DSTSearch(T -> Left, X, W + 1);
  else
    return DSTSearch(T -> Right, X, W + 1);
}

DSTTree Search(DSTTree T, ElementType X)
{
  return DSTSearch(T, X, 0);
}

void PreOrderTraverse(DSTTree T)
{
  if (T == NULL)
    return;

  printf("%c ", T -> Element);
  PreOrderTraverse(T -> Left);
  PreOrderTraverse(T -> Right);
}

void InOrderTraverse(DSTTree T)
{
  if (T == NULL)
    return;

  InOrderTraverse(T -> Left);
  printf("%c ", T -> Element);
  InOrderTraverse(T -> Right);
}

void PostOrderTraverse(DSTTree T)
{
  if (T == NULL)
    return;

  PostOrderTraverse(T -> Left);
  PostOrderTraverse(T -> Right);
  printf("%c ", T -> Element);
}

void MakeEmpty(DSTTree T)
{
  if (T == NULL)
    return;

  MakeEmpty(T -> Left);
  MakeEmpty(T -> Right);
  free(T);
}

int main(int argc, char const *argv[])
{
  char Array[] = {'A', 'E', 'C', 'G', 'H', 'N', 'S', 'R', 'X'};
  int Len, i;
  DSTTree T;
  Position P;

  Len = sizeof(Array) / sizeof(Array[0]);
  T = NULL;

  for (i = 0; i < Len; ++i)
    T = Insert(T, Array[i]);

  PreOrderTraverse(T);
  printf("\n");

  InOrderTraverse(T);
  printf("\n");


  P = Search(T, 'G');
  printf("%c\n", P -> Element);

  P = Search(T, 'Z');
  printf("%c\n", P -> Element);

  MakeEmpty(T);
  return 0;
}