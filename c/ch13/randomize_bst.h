#define ElementType char

struct BSTNode;
typedef struct BSTNode* Position;
typedef struct BSTNode* BSTree;

BSTree Insert(ElementType X, BSTree T);
int Count(BSTree T);
ElementType Value(Position P);
BSTree Select(int k, BSTree T);
BSTree Partition(int k, BSTree T);
BSTree Balance(BSTree T);
BSTree InsertRandomize(ElementType X, BSTree T);
