#define BinarySearchTreeElementType int

// struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

// static SearchTree MakeEmpty(SearchTree T);
Position Find(BinarySearchTreeElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(BinarySearchTreeElementType X, SearchTree T);
SearchTree Delete(BinarySearchTreeElementType X, SearchTree T);
// ElementType Retrieve(Position P);

struct TreeNode
{
	BinarySearchTreeElementType Element;
	SearchTree Left;
	SearchTree Right;
};