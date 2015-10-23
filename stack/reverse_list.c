#include "list.h"
#include <stdio.h>

List ReverseList(List L);

int main(int argc, char const *argv[])
{
  List L;
  Position Tmp;

  int i = 100;

  L = malloc(sizeof(struct Node));
  L -> Next = NULL;
  Tmp = L;

  while(i < 120)
  {
    Insert(i++, L, Tmp);
    Tmp = Tmp -> Next;    
  }

  L = ReverseList(L); 
  printList(L);

  DeleteList(L);
  return 0;
}

List ReverseList(List L)
{
  Position Header, Tmp1, Tmp2;
  Header = L;

  L = L -> Next;
  Tmp1 = NULL;
  Tmp2 = L;
  while(L != NULL)
  {
    Tmp2 = Tmp2 -> Next;
    L -> Next = Tmp1;
    Tmp1 = L;
    L = Tmp2;
  }

  Header -> Next = Tmp1;
  return Header;
}