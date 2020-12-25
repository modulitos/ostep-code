#include "./hash_table.h"
#include <assert.h>
#include <stdio.h>

int main() {
  hash_t hash = {};
  hash_t *hp = &hash;

  assert(hp != NULL);

  Hash_Init(hp);
  Hash_Insert(hp, 42);
  Hash_Insert(hp, 43);
  Hash_Insert(hp, 49);
  Hash_Insert(hp, 142);
  Hash_Insert(hp, 143);
  // printf("val: %d\n", Hash_Lookup(hp, 42));
  assert(Hash_Lookup(hp, 42) == 0);
  assert(Hash_Lookup(hp, 142) == 0);
  assert(Hash_Lookup(hp, 13) == -1);
  assert(Hash_Lookup(hp, 98) == -1);

  printf("\nfinished testing hash tables!\n");

  Hash_Free(hp);
  return 0;
}