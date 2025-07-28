// Title: Fun with queues
// Date: 2025-07-28
// Created: `Mon, 28 Jul 2025 17:27:01 +0530`
// Tags: [queues, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 225. Implement Stack using Queues
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-stack-using-queues/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Mon, 28 Jul 2025 17:27:01 +0530`

struct QueueNode {
  struct QueueNode *next;
  int data;
};

struct Queue {
  struct QueueNode *first;
  struct QueueNode *last;
  int size;
};

const size_t QUEUE_NODE_WIDTH = sizeof(struct QueueNode);
const size_t QUEUE_WIDTH = sizeof(struct Queue);

#define QUEUE_SIZE(q) (((struct Queue *)q)->size)
#define IS_QUEUE_EMPTY(q) (((struct Queue *)q)->size == 0)

struct Queue *Queue_create();
void Queue_delete(struct Queue *queue);
void Queue_enqueue(struct Queue *queue, int data);
int Queue_dequeue(struct Queue *queue);
int Queue_peek(struct Queue *queue);

inline struct Queue *Queue_create() {
  return calloc(1, QUEUE_WIDTH);
}

void Queue_delete(struct Queue *queue) {
  while (!IS_QUEUE_EMPTY(queue)) {
    Queue_dequeue(queue);
  }
  free(queue), (queue = NULL);
}

void Queue_enqueue(struct Queue *queue, int data) {
  struct QueueNode *node = calloc(1, QUEUE_NODE_WIDTH);
  node->data = data;

  if (queue->last) {
    queue->last->next = node;
    queue->last = node;
  } else {
    queue->first = node;
    queue->last = queue->first;
  }
  queue->size++;
}

int Queue_dequeue(struct Queue *queue) {
  if (IS_QUEUE_EMPTY(queue)) {
    return -1;
  }

  struct QueueNode *next = queue->first->next;
  int data = queue->first->data;
  free(queue->first), (queue->first = NULL);

  if (next) {
    queue->first = next;
  } else {
    queue->first = NULL;
    queue->last = queue->first;
  }
  queue->size--;
  return data;
}

inline int Queue_peek(struct Queue *queue) {
  return IS_QUEUE_EMPTY(queue) ? -1 : queue->first->data;
}



typedef struct {
  void *queue;
} MyStack;

const size_t MY_STACK_SIZE = sizeof(MyStack);

MyStack *myStackCreate();
void myStackFree(MyStack *stack);
void myStackPush(MyStack *stack, int x);
int myStackPop(MyStack *stack);
int myStackTop(MyStack *stack);
bool myStackEmpty(MyStack *stack);

MyStack *myStackCreate() {
  MyStack *stack = calloc(1, MY_STACK_SIZE);
  stack->queue = Queue_create();
  return stack;
}

void myStackFree(MyStack *stack) {
  Queue_delete(stack->queue), (stack->queue = NULL);
  free(stack), (stack = NULL);
}

void myStackPush(MyStack *stack, int x) {
  Queue_enqueue(stack->queue, x);
}

int myStackPop(MyStack *stack) {
  const int size = QUEUE_SIZE(stack->queue);

  for (int i = 0; i < size - 1; i++) {
    Queue_enqueue(stack->queue, Queue_dequeue(stack->queue));
  }

  return Queue_dequeue(stack->queue);
}

int myStackTop(MyStack *stack) {
  const int size = QUEUE_SIZE(stack->queue);

  for (int i = 0; i < size - 1; i++) {
    Queue_enqueue(stack->queue, Queue_dequeue(stack->queue));
  }

  const int data = Queue_peek(stack->queue);
  Queue_enqueue(stack->queue, Queue_dequeue(stack->queue));

  return data;
}

inline bool myStackEmpty(MyStack *stack) {
  return IS_QUEUE_EMPTY(stack->queue);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* stack = myStackCreate();
 * myStackPush(stack, x);
 * int param_2 = myStackPop(stack);
 * int param_3 = myStackTop(stack);
 * bool param_4 = myStackEmpty(stack);
 * myStackFree(stack);
*/

/// }}
