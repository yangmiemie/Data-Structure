#include <stdio.h>
#include <stdlib.h>

#define LinkStackElementType int

struct LinkStackNode;
typedef struct LinkStackNode* LinkStack;
typedef struct LinkStackNode* LinkStackPosition;

int IsEmpty(LinkStack S);
int IsFull(LinkStack S);
LinkStack CreateStack();
void DisposeStack(LinkStack S);
LinkStackElementType Top(LinkStack S);
void Pop(LinkStack S);
LinkStackElementType TopAndPop(LinkStack S);
void Push(LinkStackElementType X, LinkStack S);