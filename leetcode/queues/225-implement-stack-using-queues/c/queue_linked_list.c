#include <stdlib.h>
#include "queue_linked_list.h"

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  uint32_t size;
  struct Node *first;
  struct Node *last;
};

void *queueCreate() {
  struct Queue *queue = calloc(1, sizeof(struct Queue));
  queue->size = 0;
  queue->first = NULL;
  queue->last = NULL;
  return (void *)queue;
}

void queueDelete(void *_queue) {
  while (!isQueueEmpty(_queue)) {
    queueDequeue(_queue);
  }

  free(_queue);
}

void queueEnqueue(void *_queue, int item) {
  struct Queue *queue = (struct Queue *)_queue;
  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = item;
  newNode->next = NULL;

  if (isQueueEmpty(queue)) {
    queue->first = newNode;
  } else {
    queue->last->next = newNode;
  }
  queue->last = newNode;
  queue->size++;
}

int queueDequeue(void *_queue) {
  if (isQueueEmpty(_queue)) {
    return -1;
  }

  struct Queue *queue = (struct Queue *)_queue;
  struct Node *oldFirst = queue->first;
  struct Node *newFirst = oldFirst->next;

  int data = oldFirst->data;
  free(oldFirst);

  if (newFirst == NULL) {
    queue->last = NULL;
  }
  queue->first = newFirst;
  queue->size--;

  return data;
}

int queuePeek(void *_queue) {
  struct Queue *queue = (struct Queue *)_queue;
  return queue->first->data;
}

int queueSize(void *_queue) {
  struct Queue *queue = (struct Queue *)_queue;
  return queue->size;
}

int isQueueEmpty(void *_queue) {
  struct Queue *queue = (struct Queue *)_queue;
  return queue->size == 0;
}
