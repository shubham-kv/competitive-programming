// Title: Fun with queues
// Date: 2025-07-26
// Created: `Sat, 26 Jul 2025 19:36:58 +0530`
// Tags: [queues, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 225. Implement Stack using Queues
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-stack-using-queues/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Sat, 26 Jul 2025 19:36:58 +0530`

struct QueueNode {
  struct QueueNode *next;
  int data;
};

struct Queue {
  struct QueueNode *first;
  struct QueueNode *last;
  size_t size;
};

const size_t QUEUE_WIDTH = sizeof(struct Queue);
const size_t QUEUE_NODE_WIDTH = sizeof(struct QueueNode);

struct Queue *Queue_create();
void Queue_delete(struct Queue *queue);
void Queue_enqueue(struct Queue *queue, int data);
int Queue_dequeue(struct Queue *queue);
int Queue_peek(struct Queue *queue);

#define QUEUE_SIZE(q) (((struct Queue *)q)->size)
#define IS_QUEUE_EMPTY(q) (((struct Queue *)q)->first == NULL)

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
int Queue_peek(struct Queue *queue) {
  return !IS_QUEUE_EMPTY(queue) ? queue->first->data : -1;
}


typedef struct {
  void *queueA;
  void *queueB;
} MyStack;

const size_t MY_STACK_WIDTH = sizeof(MyStack);

MyStack *myStackCreate();
void myStackFree(MyStack *stack);
void myStackPush(MyStack *stack, int x);
int myStackPop(MyStack *stack);
int myStackTop(MyStack *stack);
bool myStackEmpty(MyStack *stack);

MyStack *myStackCreate() {
  MyStack *stack = calloc(1, MY_STACK_WIDTH);
  stack->queueA = Queue_create();
  stack->queueB = Queue_create();
  return stack;
}
void myStackFree(MyStack *stack) {
  Queue_delete(stack->queueA), (stack->queueA = NULL);
  Queue_delete(stack->queueB), (stack->queueB = NULL);
  free(stack), (stack = NULL);
}

void myStackPush(MyStack *stack, int x) {
  while (!IS_QUEUE_EMPTY(stack->queueB)) {
    Queue_enqueue(stack->queueA, Queue_dequeue(stack->queueB));
  }
  Queue_enqueue(stack->queueA, x);
}

int myStackPop(MyStack *stack) {
  while (QUEUE_SIZE(stack->queueA) > 1) {
    Queue_enqueue(stack->queueB, Queue_dequeue(stack->queueA));
  }
  int popped = Queue_dequeue(stack->queueA);

  while (!IS_QUEUE_EMPTY(stack->queueB)) {
    Queue_enqueue(stack->queueA, Queue_dequeue(stack->queueB));
  }

  return popped;
}

int myStackTop(MyStack *stack) {
  while (QUEUE_SIZE(stack->queueA) > 1) {
    Queue_enqueue(stack->queueB, Queue_dequeue(stack->queueA));
  }

  int peeked = Queue_peek(stack->queueA);
  Queue_enqueue(stack->queueB, Queue_dequeue(stack->queueA));

  while (!IS_QUEUE_EMPTY(stack->queueB)) {
    Queue_enqueue(stack->queueA, Queue_dequeue(stack->queueB));
  }

  return peeked;
}

inline bool myStackEmpty(MyStack *stack) {
  return IS_QUEUE_EMPTY(stack->queueA) && IS_QUEUE_EMPTY(stack->queueB);
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
