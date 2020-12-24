#include "./queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  queue_t queue = {};
  queue_t *qp = &queue;
  assert(qp != NULL);
  Queue_Init(qp);
  int value = 0;
  assert(Queue_Dequeue(qp, &value) == -1);
  assert(value == 0);
  Queue_Enqueue(qp, 42);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 42);
  Queue_Enqueue(qp, 5);
  Queue_Enqueue(qp, 8);
  Queue_Enqueue(qp, 7);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 5);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 8);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 7);
  Queue_Enqueue(qp, 4);
  Queue_Enqueue(qp, 5);
  Queue_Enqueue(qp, 6);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 4);
  Queue_Enqueue(qp, 7);
  Queue_Enqueue(qp, 8);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 5);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 6);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 7);
  assert(Queue_Dequeue(qp, &value) == 0);
  assert(value == 8);

  printf("finished!\n");
  free(qp->head);
  return 0;
}
