#include <stdlib.h>

struct TreeNode;
// typedef struct TreeNode *Position;

#define QueueElementType char
// #define QueueElementType struct TreeNode*

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty(Queue);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(QueueElementType X, Queue Q);
QueueElementType Front(Queue Q);
void Dequeue(Queue Q);
QueueElementType FrontAndDequeue(Queue Q);
