#include "stack_link.h"

#define BUFSIZE 2

int main(int argc, char const *argv[])
{
  int i;
  LinkStack S;
  S = CreateStack();

  for (i = 0; i < 16; ++i)
  {
    Push(i, S);
  }
  // printf("IsFull: %d\n", IsFull(S));

  for (i = 0; i < 16; ++i)
  {
    printf("%d ", TopAndPop(S));
  }
  printf("\n");
  printf("IsEmpty: %d\n", IsEmpty(S));

  for (i = 0; i < 16; ++i)
  {
    Push(i, S);
  }
  // printf("IsFull: %d\n", IsFull(S));
  printf("Top: %d\n", Top(S));

  for (i = 0; i < 1; ++i)
  {
    Pop(S);
  }
  printf("IsEmpty: %d\n", IsEmpty(S));

  DisposeStack(S);
  return 0;
}