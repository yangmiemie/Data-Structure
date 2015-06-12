#define ElementType int
#define NULL 0

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack();
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void DisposeStack(Stack S);

struct Node
{
	ElementType Element;
	PtrToNode Next;
};
