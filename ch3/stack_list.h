#include <stdio.h>

#define StackElementType unsigned char
// #define NULL 0

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmptyStack(Stack S);
Stack CreateStack();
void MakeEmptyStack(Stack S);
void Push(StackElementType X, Stack S);
StackElementType Top(Stack S);
void Pop(Stack S);
void DisposeStack(Stack S);

struct Node
{
	StackElementType Element;
	PtrToNode Next;
};
