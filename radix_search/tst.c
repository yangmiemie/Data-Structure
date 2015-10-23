#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElementType char*
#define NodeType char

#define R 26
#define NULLDigit -1

typedef struct TreeNode* Link;
typedef struct TreeNode* Tree;

struct TreeNode
{
  NodeType Element;
  Link Left;
  Link Right;
  Link Middle;
};

NodeType Digit(ElementType X, int W)
{
  if (strlen(X) <= W)
    return NULLDigit;

  return X[W];
}

Link NewNode(NodeType X)
{
  Link L;

  L = malloc(sizeof(struct TreeNode));
  L -> Left = L -> Right = L -> Middle = NULL;
  L -> Element = X;
  return L;
}

Tree TSTInsert(Tree T, ElementType X, int W)
{
  int i;

  i = Digit(X, W);

  if (i == NULLDigit)
    return T;

  if (T == NULL)
    T = NewNode(i);

  if (T -> Element < i)
    T -> Right = TSTInsert(T -> Right, X, W);
  else if (T -> Element == i)
    T -> Middle = TSTInsert(T -> Middle, X, W + 1);
  else
    T -> Left = TSTInsert(T -> Left, X, W);

  return T;
}

Tree Insert(Tree T, ElementType X)
{
  return TSTInsert(T, X, 0);
}

Tree TSTSearch(Tree T, ElementType X, int W)
{
  int i;

  i = Digit(X, W);

  if (i == NULLDigit)
    return T;

  if (T == NULL)
    return NULL;


  if (T -> Element > i)
    return TSTSearch(T -> Left, X, W);
  else if (T -> Element == i)
    return TSTSearch(T -> Middle, X, W + 1);
  else 
    return TSTSearch(T -> Right, X, W);
}

Tree Search(Tree T, ElementType X)
{
  return TSTSearch(T, X, 0);
}

void PrintTree(Tree T)
{
  if (T -> Left == NULL && T -> Middle == NULL && T -> Right == NULL)
  {
    printf("%c\n", T -> Element);
    return;
  }

  if (T -> Middle != NULL)
  {
    printf("%c", T -> Element);
    PrintTree(T -> Middle);
  }

  if (T -> Left != NULL)
    PrintTree(T -> Left);

  if (T -> Right != NULL)
    PrintTree(T -> Right);
}

int main(int argc, char const *argv[])
{
  char* Array[] = {"for", "is", "now", "the", "time", "xyz", "abc"};
  // char* Array[] = {"for"};
  Tree T;
  Link L;
  int Len, i;

  T = NULL;
  Len = sizeof(Array) / sizeof(Array[0]);

  for (i = 0; i < Len - 2; ++i)
    T = Insert(T, Array[i]);

  PrintTree(T);

  for (i = 0; i < Len; ++i)
  {
    L = Search(T, Array[i]);

    if (L == NULL)
      printf("NOT FOUND\n");
    else
      printf("FOUND\n");
  }
  return 0;
}