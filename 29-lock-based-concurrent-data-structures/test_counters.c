#include "./counter_approximate.h"
#include "./counter_with_locks.h"
#include "./counter_without_locks.h"
#include <stdlib.h>

int test_no_lock() {
  counter_t counter = {};
  counter_t *cp = &counter;
  assert(cp != NULL);
  printf("counter pointer value: %d\n", cp->value);

  init(cp);

  printf("counter pointer: %p\n", cp);
  printf("counter pointer value: %d\n", cp->value);
  assert(get(cp) == 0);
  increment(cp);
  increment(cp);
  increment(cp);
  assert(get(cp) == 3);
  printf("counter pointer value after increment: %d\n", cp->value);
  decrement(cp);
  assert(get(cp) == 2);
}

int test_locked() {
  locked_counter_t counter = {};
  locked_counter_t *cp = &counter;
  assert(cp != NULL);
  printf("locked counter pointer value: %d\n", cp->value);

  init_locked(cp);

  printf("locked counter pointer: %p\n", cp);
  printf("locked counter pointer value: %d\n", cp->value);
  assert(get_locked(cp) == 0);
  increment_locked(cp);
  increment_locked(cp);
  increment_locked(cp);
  assert(get_locked(cp) == 3);
  printf("locked counter pointer value after increment: %d\n", cp->value);
  decrement_locked(cp);
  assert(get_locked(cp) == 2);
}

int test_approx() {
  printf("\n");
  pthread_t thread = pthread_self();
  printf("pthread_t pointer: %p\n", thread);
  int id = abs(* (int *) (void *) thread);
  printf("pthread_t int id: %d\n", id);
  approx_counter_t counter = {};
  approx_counter_t *cp = &counter;
  assert(cp != NULL);

  printf("approx counter pointer value: %d\n", get_approx(cp));

  int threshold = 3;
  init_approx(cp, threshold);

  printf("approx counter pointer: %p\n", cp);
  printf("approx counter value: %d\n", get_approx(cp));
  assert(get_approx(cp) == 0);
  update_approx(cp, id, 10);

  printf("approx counter value after increment: %d\n", get_approx(cp));
  assert(get_approx(cp) == 10);

  update_approx(cp, id, 100);
  printf("approx counter value after increment: %d\n", get_approx(cp));
  assert(get_approx(cp) == 110);
}

int main() {
  test_no_lock();
  test_locked();
  test_approx();
  return 0;
}