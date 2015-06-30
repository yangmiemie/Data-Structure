#define ElementType char

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* RBTree;

RBTree Insert(ElementType X, RBTree T);
void PostOrderTraverse(RBTree T);
void InOrderTraverse(RBTree T);
void PreOrderTraverse(RBTree T);