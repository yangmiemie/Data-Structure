#include "splay.h"

#include <stdio.h>
#include <stdlib.h>


Position SingleRotateWithLeft(Position P1)
{
  Position P2;
  P2 = P1 -> Left;
  P1 -> Left = P2 -> Right;
  P2 -> Right = P1;

  return P2;
}

Position SingleRotateWithRight(Position P1)
{
  Position P2;
  P2 = P1 -> Right;
  P1 -> Right = P2 -> Left;
  P2 -> Left = P1;

  return P2;
}

SplayTree Splay(ElementType X, SplayTree T)
{
  struct SplayNode Header;
  Position LeftMax, RightMin;

  Header.Left = Header.Right = NULL;
  LeftMax = RightMin = &Header;

  while(T -> Element != X)
  {
    if (T -> Element > X)
    {
      if (T -> Left != NULL && T -> Left -> Element > X)
        T = SingleRotateWithLeft(T);
      if (T -> Left == NULL)
        break;

      RightMin -> Left = T;
      RightMin = T;
      T = T -> Left;
    }
    else if (T -> Element < X)
    {
      if (T -> Right != NULL && T -> Right -> Element < X)
        T = SingleRotateWithRight(T);
      if (T -> Right == NULL)
        break;

      LeftMax -> Right = T;
      LeftMax = T;
      T = T -> Right;
    }
  }

  LeftMax -> Right = T -> Left;
  RightMin -> Left = T -> Right;

  T -> Right = Header.Left;
  T -> Left = Header.Right;

  return T;
}

SplayTree Insert(ElementType X, SplayTree T)
{
  SplayTree P;
  Position NewNode;

  if (T == NULL)
  {
    T = malloc(sizeof(struct SplayNode));
    T -> Left = T -> Right = NULL;
    T -> Element = X;
    return T;
  }

  P = Splay(X, T);
  NewNode = malloc(sizeof(struct SplayNode));
  NewNode -> Left = NewNode -> Right = NULL;
  NewNode -> Element = X;

  if (P -> Element > X)
  {
    NewNode -> Left = P -> Left;
    P -> Left = NULL;
    NewNode -> Right = P;
  }
  else if (P -> Element < X)
  {
    NewNode -> Right = P -> Right;
    P -> Right = NULL;
    NewNode -> Left = P;
  }
  else
    return P;

  return NewNode;
}

SplayTree BSTInsert(ElementType X, SplayTree T)
{
  if (T == NULL)
  {
    T = malloc(sizeof(struct SplayNode));
    T -> Left = T -> Right = NULL;
    T -> Element = X;
    return T;
  }

  if (T -> Element > X)
    T -> Left = BSTInsert(X, T -> Left);
  else if (T -> Element < X)
    T -> Right = BSTInsert(X, T -> Right);

  return T;
}

void PreOrderTraverse(SplayTree T)
{
  if (T == NULL)
    return;

  printf("%d ", T -> Element);
  PreOrderTraverse(T -> Left);
  PreOrderTraverse(T -> Right);
}

void InOrderTraverse(SplayTree T)
{
  if (T == NULL)
    return;

  InOrderTraverse(T -> Left);
  printf("%d ", T -> Element);
  InOrderTraverse(T -> Right);
}

void PostOrderTraverse(SplayTree T)
{
  if (T == NULL)
    return;

  PostOrderTraverse(T -> Left);
  PostOrderTraverse(T -> Right);
  printf("%d ", T -> Element);
}
