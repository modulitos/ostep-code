#include "../include/common_threads.h"
#include <stdlib.h>

#ifndef OSTEP_CODE_QUEUE_H
#define OSTEP_CODE_QUEUE_H

#endif // OSTEP_CODE_QUEUE_H

typedef struct node_t {
  int value;
  struct node_t *next;
} node_t;

typedef struct queue_t {
  node_t *head;
  node_t *tail;
  pthread_mutex_t headLock;
  pthread_mutex_t tailLock;
} queue_t;

void Queue_Init(queue_t *q) {

  // this dummy node enables separation of head and tail operations. This is
  // useful for maintaining separate head and tail locks.

  node_t *tmp = malloc(sizeof(node_t));
  tmp->next = NULL;
  q->head = q->tail = tmp;
  pthread_mutex_init(&q->headLock, NULL);
  pthread_mutex_init(&q->tailLock, NULL);
}

void Queue_Enqueue(queue_t *q, int value) {
  node_t *tmp = malloc(sizeof(node_t));
  assert(tmp != NULL);
  tmp->value = value;
  tmp->next = NULL;

  pthread_mutex_lock(&q->tailLock);
  q->tail->next = tmp;
  q->tail = tmp;
  pthread_mutex_unlock(&q->tailLock);
}

int Queue_Dequeue(queue_t *q, int *value) {
  pthread_mutex_lock(&q->headLock);
  node_t *tmp = q->head; // this is our dummy node
  node_t *new_head = tmp->next;
  if (new_head == NULL) {
    pthread_mutex_unlock(&q->headLock);
    return -1; // queue was empty
  }
  *value = new_head->value;
  q->head = new_head; // this will be our new dummy node
  pthread_mutex_unlock(&q->headLock);
  free(tmp);
  return 0;
}