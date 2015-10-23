#define ElementType int

#include <stdio.h>
#include <stdlib.h>

typedef struct Node* List;
typedef struct Node* Position;

struct Node
{
  ElementType Element;
  Position Next;
};

int IsEmpty(List L)
{
  return L -> Next == NULL;
}

List CreateList()
{
  Position P;
  P = malloc(sizeof(struct Node));
  P -> Next = NULL;

  return P;
}

void Insert(Position P, List L, ElementType X)
{
  Position Tmp;
  Tmp = malloc(sizeof(struct Node));
  Tmp -> Element = X;

  Tmp -> Next = P -> Next;
  P -> Next = Tmp;
}

void PrintList(List L)
{
  Position P;

  if (IsEmpty(L))
    return;

  P = L -> Next;
  while(P)
  {
    printf("%d ", P -> Element);
    P = P -> Next;
  }

  printf("\n");
}

void DestoryList(List L)
{
  Position P;

  if (L)
  {
    P = L;

    while(P)
    {
      L = L -> Next;
      free(P);
      P = L;
    }
  }
}

void FindArray(ElementType* Array, int Size, ElementType X)
{
  int P, i;

  for (i = 0; i < Size; ++i)
  {
    if (Array[i] == X)
      break;
  }

  P = i;

  if (P != Size)
  {
    while(P > 0)
    {
      Array[P] = Array[P-1];
      --P;
    }
    Array[0] = X;
  }
}


void FindList(List L, ElementType X)
{
  Position P, Prev;
  P = L -> Next;

  while(P != NULL)
  {
    if (P -> Element == X)
      break;
    else
    {
      Prev = P;
      P = P -> Next;      
    }
  }

  if (P != NULL)
  {
    Prev -> Next = P -> Next;
    P -> Next = L -> Next;
    L -> Next = P;
  }
}

int main(int argc, char const *argv[])
{
  int Array[100];
  int i, Size;

  for (i = 0; i < 100; ++i)
  {
    Array[i] = i;
  }

  Size = sizeof(Array) / sizeof(Array[0]);
  for (i = 40; i < 45; ++i)
  {
    FindArray(Array, Size, i);
  }

  for (i = 0; i < Size; ++i)
  {
    printf("%d ", Array[i]);
  }

  printf("\n");

  List L;
  Position P;

  L = CreateList();

  P = L;

  for (i = 0; i < 100; ++i)
  {
    Insert(P, L, i);
    P = P -> Next;
  }

  for (i = 40; i < 45; ++i)
  {
    FindList(L,  i);
  }

  PrintList(L);

  return 0;
}