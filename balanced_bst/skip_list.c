#include "skip_list.h"

#include <stdio.h>
#include <stdlib.h>

struct SLNode
{
  ElementType Element;
  Link* Next;
  int Level;
};

struct SkipList
{
  int MaxLevel;
  int CurrentLevel;
  int Size;
  Link Head;
};

Link NewNode(ElementType X, int MaxLevel)
{
  Position P;
  int i;

  P = malloc(sizeof(struct SLNode));
  P -> Element = X;
  P -> Level = MaxLevel;
  P -> Next = malloc(MaxLevel * sizeof(Link));

  for (i = 0; i <= MaxLevel; ++i)
    P -> Next[i] = NULL;

  return P;
}

SkipList SLInit()
{
  SkipList SL;

  SL = malloc(sizeof(struct SkipList));
  SL -> MaxLevel = 4;
  SL -> CurrentLevel = 0;
  SL -> Size = 0;
  SL -> Head = NewNode(0, SL -> MaxLevel);

  return SL;
}

ElementType Value(Position P)
{
  if (P == NULL)
    return 0x7f;

  return P -> Element;
}

void SLInsert(Link X, Link L, int K)
{
  if (X -> Element < Value(L -> Next[K]))
  {
    if (K <= X -> Level)
    {
      X -> Next[K] = L -> Next[K];
      L -> Next[K] = X;
    }

    if (K == 0) return;
    SLInsert(X, L, K - 1);
    return;
  }

  SLInsert(X, L -> Next[K], K);
}

int RandX(SkipList SL)
{
  int i, j, r;

  r = rand();
  for (i = 0, j = 2; i < SL -> MaxLevel; ++i, j += 2)
    if (r > RAND_MAX / j) break;

  if (SL -> CurrentLevel < i)
    SL -> CurrentLevel = i;

  return i;
}

Link Insert(SkipList SL, ElementType X)
{
  Position P;
  P = NewNode(X, RandX(SL));
  SLInsert(P ,SL -> Head, SL -> CurrentLevel);
  ++ SL -> Size;
}

Link SLSearch(Link L, ElementType X, int K)
{
  if (L == NULL)
    return NULL;

  if (X == Value(L))
    return L;

  if (X < Value(L -> Next[K]))
  {
    if (K == 0) return NULL;
    return SLSearch(L, X, K - 1);
  }

  return SLSearch(L -> Next[K], X, K);
}

Link Search(SkipList SL, ElementType X)
{
  return SLSearch(SL -> Head, X, SL -> CurrentLevel);
}

Link PrintLink(SkipList SL)
{
  Link L;
  int i;

  for (i = SL -> CurrentLevel; i >= 0; --i)
  {
    L = SL -> Head -> Next[i];
    printf("%d: ", i);

    while(L)
    {
      printf("%c(%d) ", L -> Element, L -> Level);
      L = L -> Next[i];
    }

    printf("\n");
  }
}

int Size(SkipList SL)
{
  if (SL == NULL)
    return 0;

  return SL -> Size;
}

void SLDelete(Link L, ElementType X, int K)
{
  Position P;

  P = L -> Next[K];

  if (L == NULL)
    return;

  if (X == Value(P))
  {
    L -> Next[K] = P -> Next[K];

    if (K == 0)
    {
      free(P);
      return;
    }

    SLDelete(L, X, K - 1);
  }

  if (X < Value(P))
  {
    if (K == 0) return;
    SLDelete(L, X, K - 1);
    return;   
  }

  SLDelete(P, X, K);
}

void Delete(SkipList SL, ElementType X)
{
  SLDelete(SL -> Head, X, SL -> CurrentLevel);
  --SL -> Size;
}