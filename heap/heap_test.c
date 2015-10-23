#include "heap.h"
#define BUFSIZE 15

void PrintPriorityQueue(PriorityQueue PQ)
{
  int i;

  for (i = 1; i <= PQ -> Size; ++i)
  {
    printf("%d ", PQ -> Elements[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int Array[] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
  int i;

  PriorityQueue PQ;

  PQ = CreatePQ(BUFSIZE);

  printf("IsEmpty: %d\n", IsEmpty(PQ));

  for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
    Insert(Array[i], PQ);

  PrintPriorityQueue(PQ);
  printf("IsFull: %d\n", IsFull(PQ));

  printf("The sorted Queue: ");
  for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
    printf("%d ", DeleteMin(PQ));

  printf("\n");
  Destory(PQ);
  return 0;
}