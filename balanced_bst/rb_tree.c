#include <stdio.h>
#include <stdlib.h>

#include "rb_tree.h"

typedef enum ColorType { Red, Black } ColorType;

#define ColorText(Color) (((Color) == Black) ? "Black" : "Red" )

struct TreeNode
{
  ElementType Element;
  RBTree Left;
  RBTree Right;
  ColorType Color;
};

RBTree RotateLeft(RBTree T)
{
  RBTree P;

  P = T -> Left;
  T -> Left = P -> Right;
  P -> Right = T;
  return P;
}

RBTree RotateRight(RBTree T)
{
  RBTree P;

  P = T -> Right;
  T -> Right = P -> Left;
  P -> Left = T;

  return P;
}

ColorType Color(Position P)
{
  if (P == NULL)
    return Black;

  return P -> Color;
}

RBTree RBInsert(ElementType X, RBTree T, int SW)
{
  if (T == NULL)
  {
    T = malloc(sizeof(struct TreeNode));
    T -> Element = X;
    T -> Left = T -> Right = NULL;
    T -> Color = Red;
    return T;
  }

  if ((Color(T -> Right) == Red) && (Color(T -> Left) == Red))
  {
    T -> Color = Red;
    T -> Right -> Color = T -> Left -> Color = Black;
  }

  if (T -> Element < X)
  {
    T -> Right = RBInsert(X, T -> Right, 1);
    if ((Color(T) == Red) && (Color(T -> Right) == Red) && (SW == 0))
      T = RotateRight(T);
    if ((Color(T -> Right) == Red) && (Color(T -> Right -> Right) == Red))
    {
      T = RotateRight(T);
      T -> Color = Black;
      T -> Left -> Color = Red;
    }
  }
  else if (T -> Element > X)
  {
    T -> Left = RBInsert(X, T -> Left, 0);
    if ((Color(T) == Red) && (Color(T -> Left) == Red) && (SW == 1))
      T = RotateLeft(T);
    if ((Color(T -> Left) == Red) && (Color(T -> Left -> Left) == Red))
    {
      T = RotateLeft(T);
      T -> Color = Black;
      T -> Right -> Color = Red;
    }
  }

  return T;
}

RBTree Insert(ElementType X, RBTree T)
{
  T = RBInsert(X, T, 0);
  T -> Color = Black;
  return T;
}

void PreOrderTraverse(RBTree T)
{
  if (T == NULL)
    return;

  printf("%c(%s) ", T -> Element, ColorText(T -> Color));
  PreOrderTraverse(T -> Left);
  PreOrderTraverse(T -> Right);
}

void InOrderTraverse(RBTree T)
{
  if (T == NULL)
    return;

  InOrderTraverse(T -> Left);
  printf("%c(%s) ", T -> Element, ColorText(T -> Color));
  InOrderTraverse(T -> Right);
}


void PostOrderTraverse(RBTree T)
{
  if (T == NULL)
    return;

  PostOrderTraverse(T -> Left);
  PostOrderTraverse(T -> Right);
  printf("%c(%s) ", T -> Element, ColorText(T -> Color));
}