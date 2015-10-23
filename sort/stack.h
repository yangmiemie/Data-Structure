#define StackElementType int

#include <stdio.h>
#include <stdlib.h>

struct StackRecord;
typedef struct StackRecord* Stack;

Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void Pop(Stack S);
void Push(StackElementType X, Stack S);
StackElementType Top(Stack S);
StackElementType TopAndPop(Stack S);
int IsFull(Stack S);
int IsEmpty(Stack S);
