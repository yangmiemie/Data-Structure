#include "hash_chain.h"
#include <stdlib.h>

int Hash(ElementType Key, int TableSize)
{
	return Key % TableSize;
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct HashTbl));
	H -> TableSize = TableSize;

	H -> TheList = malloc(sizeof(struct HashTbl) * H -> TableSize);

	for (i = 0; i < TableSize; ++i)
	{
		H -> TheList[i] = malloc(sizeof(struct ListNode));
		H -> TheList[i] -> Next = NULL;
	}

	return H;
}

// void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;

	L = H -> TheList[Hash(Key, H -> TableSize)];
	P = L -> Next;

	while(P != NULL && P -> Element != Key)
		P = P -> Next;

	return P;
}

void Insert(ElementType Key, HashTable H)
{
	Position P, TmpCell;
	List L;
	P = Find(Key, H);

	if (P == NULL)
	{
		L = H -> TheList[Hash(Key, H -> TableSize)];
		TmpCell = malloc((sizeof(struct ListNode)));
		TmpCell -> Element = Key;
		TmpCell -> Next =  L -> Next;
		L -> Next = TmpCell;
	}
}
