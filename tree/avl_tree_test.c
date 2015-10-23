#include "avl_tree.h"
#include <stdio.h>

void PreOrderTraverse(AvlTree T)
{
  if (T != NULL)
  {
    printf("%d ", T -> Element);
    PreOrderTraverse(T -> Left);
    PreOrderTraverse(T -> Right);
  }
}

void InOrderTraverse(AvlTree T)
{
  if (T != NULL)
  {
    InOrderTraverse(T -> Left);
    printf("%d ", T -> Element);
    InOrderTraverse(T -> Right);
  }
}


void PostOrderTraverse(AvlTree T)
{
  if (T != NULL)
  {
    PostOrderTraverse(T -> Left);
    PostOrderTraverse(T -> Right);
    printf("%d ", T -> Element);
  }
}


int main(int argc, char const *argv[])
{
  int Array[] = {2, 1, 4, 5, 9, 3, 6, 7};
  // int Array[] = {3, 2, 1};
  int i;
  AvlTree T;

  for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
    T = Insert(Array[i], T);

  PreOrderTraverse(T);
  printf("\n");

  InOrderTraverse(T);
  printf("\n");

  PostOrderTraverse(T);
  printf("\n");

  MakeEmpty(T);
  return 0;
}r