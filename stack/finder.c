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

Position FindRecursively(List L, ElementType X)
{
  if (L == NULL)
    return;

  if (L -> Element == X)
    return L;
  else
    return FindRecursively(L -> Next, X);
}

Position FindNonRecursively(List L, ElementType X)
{
  Position Tmp;
  Tmp = L -> Next;

  while(Tmp != NULL)
  {
    if (Tmp -> Element == X)
      return Tmp;
    else
      Tmp = Tmp -> Next;
  }

  return Tmp;
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

  P = FindNonRecursively(L, 50);
  printf("FindNonRecursively: %d\n", P -> Element);

  P = FindRecursively(L, 101);
  if (P == NULL)
  {
    printf("FindNonRecursively Not Found\n");
  }
  else
  {
    printf("FindNonRecursively: %d\n", P -> Element);   
  }

  return 0;
}