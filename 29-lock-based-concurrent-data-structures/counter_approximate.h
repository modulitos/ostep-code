#include "../include/common_threads.h"
#include <stdio.h>

#ifndef OSTEP_CODE_COUNTER_APPROXIMATE_H
#define OSTEP_CODE_COUNTER_APPROXIMATE_H

#define NUMCPUS 4

typedef struct approx_counter_t {
  int global;                     // global count
  pthread_mutex_t glock;          // global lock
  int local[NUMCPUS];             // local count (per CPU)
  pthread_mutex_t llock[NUMCPUS]; // .. and the locks
  int threshold;
} approx_counter_t;

// init: record threshold, init locks, init values of all local counts and
// global count
void init_approx(struct approx_counter_t *c, int threshold) {
  c->threshold = threshold;
  c->global = 0;
  pthread_mutex_init(&c->glock, NULL);
  int i;
  for (i = 0; i < NUMCPUS; i++) {
    c->local[i] = 0;
    pthread_mutex_init(&c->llock[i], NULL);
  }
}

// update: usually, just grab local lock and update local amount. Once local
// count has risen by `threshold`, grab global lock and transfer local values to
// it.

void update_approx(approx_counter_t *c, int threadID, int amt) {
  int cpu = threadID % NUMCPUS;
  printf("cpu: %d\n", cpu);
  pthread_mutex_lock(&c->llock[cpu]);
  c->local[cpu] += amt; // assumes amt > 0;

  if (c->local[cpu] >= c->threshold) {
    // transfer to global
    pthread_mutex_lock(&c->glock);
    c->global += c->local[cpu];
    pthread_mutex_unlock(&c->glock);
    c->local[cpu] = 0;
  }

  pthread_mutex_unlock(&c->llock[cpu]);
}

// get: just return global amount (which may not be perfect)
int get_approx(struct approx_counter_t *c) {
  pthread_mutex_lock(&c->glock);
  int val = c->global;
  pthread_mutex_unlock(&c->glock);
  return val;
}

#endif // OSTEP_CODE_COUNTER_APPROXIMATE_H
