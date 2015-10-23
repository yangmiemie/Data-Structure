#define QueueElementType char

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmptyQueue(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue);
void Enqueue(QueueElementType X, Queue Q);
QueueElementType Front(Queue Q);
void Dequeue(Queue Q);
QueueElementType FrontAndDequeue(Queue Q);

struct QueueRecord
{
  int Size;
  int Capacity;
  int Front;
  int Rear;
  QueueElementType *Array;
};

