#include "../include/common_threads.h"
#include <stdio.h>

typedef struct locked_counter_t {
  int value;
  pthread_mutex_t lock;
} locked_counter_t;

void init_locked(locked_counter_t *c) {
  c->value = 0;
  pthread_mutex_init(&c->lock, NULL);
}

void increment_locked(locked_counter_t *c) {
  Pthread_mutex_lock(&c->lock);
  c->value++;
  Pthread_mutex_unlock(&c->lock);
}

void decrement_locked(locked_counter_t *c) {
  Pthread_mutex_lock(&c->lock);
  c->value--;
  Pthread_mutex_unlock(&c->lock);
}

int get_locked(locked_counter_t *c) {
  Pthread_mutex_lock(&c->lock);
  int rc = c->value;
  Pthread_mutex_unlock(&c->lock);
  return rc;
}
