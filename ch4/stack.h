#include <stdio.h>
#include <stdlib.h>

struct ExpressionTreeNode;
typedef struct ExpressionTreeNode* Position;

#define ArrayStackElementType Position

struct ArrayStackRecord;
typedef struct ArrayStackRecord* ArrayStack;

int IsArrayStackEmpty(ArrayStack S);
int IsArrayStackFull(ArrayStack S);
ArrayStack CreateArrayStack(int MaxElements);
void DisposeStack(ArrayStack S);
ArrayStackElementType Top(ArrayStack S);
void Pop(ArrayStack S);
ArrayStackElementType TopAndPop(ArrayStack S);
void Push(ArrayStackElementType X, ArrayStack S);