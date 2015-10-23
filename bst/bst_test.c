#include "bst.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
  char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G', 'X', 'M', 'P', 'L'};
  char Array1[] = {'G', 'E', 'A', 'M', 'I', 'R'};
  char Array2[] = {'N', 'H', 'C', 'X', 'S', 'P'};

  BSTree T, T1, T2;
  int i;
  Position P;

  T = NULL; 
  for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
    T = Insert3(Array[i], T);

  PreOrderTraverse(T);
  printf("\n"); 

  InOrderTraverse(T);
  printf("\n"); 

  SortTree(T);
  printf("\n");

  printf("T -> Number = %d\n", Count(T));

  P = Select(4, T);
  printf("%c\n", Value(P));

  T = Partition(4, T);
  printf("%c\n", Value(P));
  PreOrderTraverse(P);
  printf("\n");

  T = Delete('H', T);
  PreOrderTraverse(T);
  printf("\n");

  T1 = T2 = NULL;
  for (i = 0; i < sizeof(Array1) / sizeof(Array1[0]); ++i)
    T1 = Insert(Array1[i], T1);

  for (i = 0; i < sizeof(Array2) / sizeof(Array2[0]); ++i)
    T2 = Insert(Array2[i], T2);

  PreOrderTraverse(T1);
  printf("\n");
  InOrderTraverse(T1);
  printf("\n");
  PreOrderTraverse(T2);
  printf("\n");
  InOrderTraverse(T2);
  printf("\n");

  T2 = Join(T1, T2);
  PreOrderTraverse(T2);
  printf("\n");
  return 0;
}