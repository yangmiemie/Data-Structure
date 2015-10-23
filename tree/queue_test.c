#include "queue.h"
#include <stdio.h>

#define QUEUESIZE 4

int main(int argc, char const *argv[])
{
  Queue Q;
  int i;

  Q = CreateQueue(QUEUESIZE + 1);

  printf("IsEmpty: %d\n", IsEmpty(Q));

  for (i = 0; i < QUEUESIZE; ++i)
  {
    Enqueue(i, Q);
  }

  printf("IsFull: %d\n", IsFull(Q));

  for (i = 0; i < QUEUESIZE; ++i)
  {
    printf("%d ", Front(Q));
    Dequeue(Q);
  }
  printf("\n");
  
  printf("IsEmpty: %d\n", IsEmpty(Q));

  for (i = 0; i < QUEUESIZE; ++i)
  {
    Enqueue(i, Q);
  }

  printf("IsFull: %d\n", IsFull(Q));

  for (i = 0; i < QUEUESIZE; ++i)
  {
    printf("%d ", FrontAndDequeue(Q));
  }
  printf("\n");

  printf("IsEmpty: %d\n", IsEmpty(Q));

  DisposeQueue(Q);
  return 0;
}