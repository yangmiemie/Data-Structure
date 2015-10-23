#define _STACK_LIST 0

// #ifdef _STACK_LIST
#include "stack_array.h"
// #else
  // #include "stack_list.h"
// #endif

#include <stdio.h>

int main(int argc, char const *argv[])
{
  Stack stack;
  int i, tmp, size;

  size = 2;
  // stack = CreateStack();
  stack = CreateStack(size);

  for (i = 0; i < 100; ++i)
  {
    Push(i, stack);
  }

  while(!IsEmpty(stack))
  {
    tmp = Top(stack);
    Pop(stack);
    printf("%d ", tmp);
  }

  printf("\n");

  return 0;
}