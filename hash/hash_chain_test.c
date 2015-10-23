#include "open_address_hash.h"

int main(int argc, char const *argv[])
{
  HashTable H;
  int Array[] = {4371, 1323,6173, 4199, 4344, 9679, 1989};
  int i, Len;

  Len = sizeof(Array) / sizeof(Array[0]);

  H = InitializeTable(HashSize);

  for (i = 0; i < Len; ++i)
    Insert(Array[i], H);

  return 0;
}