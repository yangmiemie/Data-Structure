#define ElementType int

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

struct QueueRecord
{
	int Size;
	int Capacity;
	int Front;
	int Rear;
	ElementType *Array;
};

