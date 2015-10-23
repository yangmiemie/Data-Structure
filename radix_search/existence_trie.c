#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElementType char*
#define R 26
#define NULLDigit -1

typedef struct TreeNode* Link;
typedef struct TreeNode* Tree;

struct TreeNode
{
  Link Next[26];
};

Link NewNode()
{
  Link L;
  int i;

  L = malloc(sizeof(struct TreeNode));
  for (i = 0; i < R; ++i)
    L -> Next[i] = NULL;
}

int Digit(ElementType X, int W)
{
  if (strlen(X) <= W)
    return NULLDigit;

  return X[W] - 'a';
}

Tree TrieInsert(Tree T, ElementType X, int W)
{
  int i;

  i = Digit(X, W);
  
  // Even at end of string, still need create a node.
  // The leaf of the tree is an node whose element of next is null.
  if (T == NULL)
    T = NewNode();

  if (i == NULLDigit)
    return T;

  T -> Next[i] = TrieInsert(T -> Next[i], X, W + 1);
  return T;
}

Tree Insert(Tree T, ElementType X)
{
  return TrieInsert(T, X, 0);
}

Tree TrieSearch(Tree T, ElementType X, int W)
{
  int i;

  i = Digit(X, W);

  if (T == NULL)
    return NULL;

  if (i == NULLDigit)
    return T;

  return TrieSearch(T -> Next[i], X, W + 1);
}

Tree Search(Tree T, ElementType X)
{
  return TrieSearch(T, X, 0);
}

void PrintTree(Tree T)
{
  int i, j;

  for (i = 0, j = 0; i < R; ++i)
    if (T -> Next[i] != NULL)
      ++j;

  if (j == 0)
  {
    printf("\n");
    return;
  }

  for (i = 0; i < R; ++i)
  {
    if (T -> Next[i] != NULL)
    {
      printf("%c", i + 'a');
      PrintTree(T -> Next[i]);
    }
  }
}

int main(int argc, char const *argv[])
{
  char* Array[] = {"for", "is", "now", "the", "time"};
  // char* Array[] = {"for"};
  Tree T;
  Link L;
  int Len, i;

  T = NewNode();
  Len = sizeof(Array) / sizeof(Array[0]);

  for (i = 0; i < Len; ++i)
    T = Insert(T, Array[i]);

  PrintTree(T);

  for (i = 0; i < Len; ++i)
  {
    L = Search(T, Array[i]);

    if (L == NULL)
      printf("NOT FOUND\n");
    else
      printf("FOUND\n");
  }
    
  return 0;
}

