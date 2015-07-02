#define ElementType char

struct SkipList;
struct SLNode;
typedef struct SLNode* Link;
typedef struct SLNode* Position;
typedef struct SkipList* SkipList;

Link NewNode(ElementType X, int size);
SkipList SLInit();
Link Insert(SkipList SL, ElementType X);
Link Search(SkipList SL, ElementType X);
Link PrintLink(SkipList SL);
int Size(SkipList SL);
ElementType Value(Position P);
void Delete(SkipList SL, ElementType X);
