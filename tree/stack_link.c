#include "stack_link.h"

struct LinkStackNode
{
  LinkStackElementType Element;
  LinkStackPosition Next; 
};

int IsEmpty(LinkStack S)
{
  return S -> Next == NULL;
}

LinkStack CreateStack()
{
  LinkStack S;
  S = malloc(sizeof(struct LinkStackNode));
  S -> Next = NULL;
  return S;
}

void DisposeStack(LinkStack S)
{
  LinkStackPosition P;
  if (S)
  {
    while(S -> Next)
    {
      P = S -> Next;
      S -> Next = P -> Next;
      free(P);
    }

    free(S);
  }
}

LinkStackElementType Top(LinkStack S)
{
  if (IsEmpty(S))
  {
    fprintf(stderr, "Empty Stack");
    exit(1);
  }

  return S -> Next -> Element;
}

void Pop(LinkStack S)
{
  LinkStackPosition P;
  if (IsEmpty(S))
  {
    fprintf(stderr, "Empty Stack");
    exit(1);
  }

  P = S -> Next;
  S -> Next = P -> Next;
  free(P);
}

LinkStackElementType TopAndPop(LinkStack S)
{
  LinkStackPosition P;
  LinkStackElementType Temp;

  if (IsEmpty(S))
  {
    fprintf(stderr, "Empty Stack");
    exit(1);
  }

  P = S -> Next;
  S -> Next = P -> Next;
  Temp = P -> Element;
  free(P);
  return Temp;
}

void Push(LinkStackElementType X, LinkStack S)
{
  LinkStackPosition P;
  P = malloc(sizeof(struct LinkStackNode));
  P -> Element = X;
  P -> Next = S -> Next;
  S -> Next = P;
}