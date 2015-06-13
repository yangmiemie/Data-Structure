#define ElementType int

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmptyStackArray(Stack S);
int IsFullStackArray(Stack S);
Stack CreateStackArray(int MaxElements);
void DisposeStackArray(Stack S);
void MakeEmptyStackArray(Stack S);
void PushArray(ElementType X, Stack S);
ElementType TopArray(Stack S);
void PopArray(Stack S);
ElementType TopAndPop(Stack S);

#define MinStackSize 4
#define NULL 0

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *array;
};