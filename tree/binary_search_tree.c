#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

// static SearchTree MakeEmpty(SearchTree T)
// {
//  if (T == NULL)
//    return NULL;

//  MakeEmpty(T -> Left);
//  MakeEmpty(T -> Right);
//  free(T);
// }

Position Find(BinarySearchTreeElementType X, SearchTree T)
{
  if (T == NULL)
    return NULL;

  if (T -> Element > X)
    return Find(X, T -> Right);
  else if (T -> Element < X)
    return Find(X, T -> Left);
  else
    return T;
}

Position FindMin(SearchTree T)
{
  if (T -> Left)
    return FindMin(T -> Left);
  else
    return T;
}

Position FindMax(SearchTree T)
{
  if (T -> Right)
    return FindMax(T -> Right);
  else
    return T;
}

SearchTree Insert(BinarySearchTreeElementType X, SearchTree T)
{
  if (T == NULL)
  {
    T = malloc(sizeof(struct TreeNode));
    T -> Left = NULL;
    T -> Right = NULL;
    T -> Element = X;
  }
  else if(T -> Element < X)
  {
    T -> Right = Insert(X, T -> Right);
  }
  else if (T -> Element > X)
  {
    T -> Left = Insert(X, T -> Left);
  }

  return T;
}

SearchTree Delete(BinarySearchTreeElementType X, SearchTree T)
{
  Position TmpCell;

  if (T != NULL)
  {
    if (T -> Element > X)
    {
      T -> Left = Delete(X, T -> Left);
    } 
    else if (T -> Element < X)
    {
      T -> Right = Delete(X, T -> Right);
    }
    else
    {
      if (T -> Right && T -> Left)
      {
        TmpCell = FindMin(T -> Right);
        T -> Element = TmpCell -> Element;
        T -> Right = Delete(TmpCell -> Element, T -> Right);
      }
      else
      {
        TmpCell = T;
        if (T -> Right == NULL)
          T = T -> Left;
        else if (T -> Left == NULL)
          T = T -> Right;
        free(TmpCell);
      }
    }
  }

  return T;
}
