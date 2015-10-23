#include "list.h"
#include <stdio.h>

void PrintLots(List L, List P);

int main(int argc, char const *argv[])
{
  List L, P;
  Position Tmp;

  int i = 100;

  L = malloc(sizeof(struct Node));
  P = malloc(sizeof(struct Node));
  L -> Next = NULL;
  P -> Next = NULL;
  Tmp = L;

  while(i < 120)
  {
    Insert(i++, L, Tmp);
    Tmp = Tmp -> Next;    
  }

  Tmp = P;
  Insert(1, P, Tmp);
  Tmp = Tmp -> Next;  
  Insert(3, P, Tmp);
  Tmp = Tmp -> Next;  
  Insert(4, P, Tmp);
  Tmp = Tmp -> Next;  
  Insert(6, P, Tmp);
  Tmp = Tmp -> Next;  

  printList(L);
  printList(P);

  PrintLots(L, P);
  return 0;
}

void PrintLots(List L, List P)
{
  int Counter;
  
  L = L->Next;
  P = P->Next;
  Counter = 1;

  while(L != NULL && P != NULL)
  {
    if (P->Element == Counter++)
    {
      printf("%d ", L->Element);
      P = P -> Next;
    }

    L = L -> Next;
  }

  printf("\n");
}