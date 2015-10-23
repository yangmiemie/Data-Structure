#include <stdio.h>
#include <stdlib.h>

#define ElementType int

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

void DestroyRing(List L)
{
  Position P, Header, Tmp;

  // Header = L -> Next;
  P = L -> Next;

  while(P -> Next != P)
  {
    Tmp = P -> Next;
    P -> Next = Tmp -> Next;
    free(Tmp);
  }

  free(P);
  free(L);
}

void PrintRing(List L, int HasHeader)
{
  Position P, Header, Tmp;

  // Header = L -> Next;
  if (HasHeader)
    P = L -> Next;
  else
    P = L;

  Tmp = P -> Next;

  printf("%d ", P -> Element);
  while(Tmp != P)
  {
    printf("%d ", Tmp -> Element);
    Tmp = Tmp -> Next;
  }

  printf("\n");
}

int Remove(Position P, List L)
{
  Position Tmp;
  ElementType Value;

  if (P -> Next == NULL)
  {
    free(P);
    P = NULL;
  }
  else
  {
    Value = P -> Element;
    P -> Element = P -> Next -> Element;
    Tmp = P -> Next;
    P -> Next = Tmp -> Next;
    free(Tmp);
  }

  return Value;
}

Position Josephus(List L, int N)
{
  int Counter = 0, Value;
  Position P = L -> Next;

  while(P -> Next != P)
  {
    if (Counter == N)
    {
      Value = Remove(P, L);
      printf("%d ", Value); 
      Counter = 0;  
    }
    else
    {
      ++Counter;
      P = P -> Next;
    }
  }

  printf("\n");
  return P;
}

int main(int argc, char const *argv[])
{
  List L;
  Position P;
  int i;

  L = CreateList();

  P = L;

  for (i = 1; i <= 100; ++i)
  {
    Insert(P, L, i);
    P = P -> Next;
  }

  P -> Next = L -> Next;

  PrintRing(L, 1);

  P = Josephus(L, 10);
  printf("The last one is %d\n", P -> Element);
  // PrintList(L);


  // DestoryList(L);
  return 0;
}