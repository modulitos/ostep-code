#include "./linked_list.h"

int main() {
  list_t list = {};
  list_t *p = &list;
  List_Init(p);
  printf("list initialized.\n");
  assert(p != NULL);
  List_Insert(p, 1);
  assert(List_Lookup(p, 1) == 0);
  printf("lookup of 1 found.\n");
  assert(List_Lookup(p, 2) == -1);
  printf("lookup of 2 failed.\n");
  List_Insert(p, 2);
  assert(List_Lookup(p, 2) == 0);
  printf("lookup of 2 succeeds after inserting.\n");
  return 0;
}