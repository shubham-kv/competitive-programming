
#include <stdlib.h>
#include <stdbool.h>

/// {{
/// Problem: 225. Implement Stack using Queues
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-stack-using-queues/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Mon, 27 Apr 2026 05:43:29 +0530`

#ifndef __queue_h
#define __queue_h

struct QueueNode;
struct Queue;

typedef struct QueueNode *QUEUE_NODE;
typedef struct Queue *QUEUE;

QUEUE Queue_Create();
 void Queue_Delete(QUEUE *queue);
 void Queue_Enqueue(QUEUE queue, int val);
  int Queue_Dequeue(QUEUE queue);
  int Queue_Peek(QUEUE queue);
  int Queue_Size(QUEUE queue);
 bool Queue_IsEmpty(QUEUE queue);

#endif // __queue_h


struct QueueNode {
  int val;
  struct QueueNode *next;
};

struct Queue {
  QUEUE_NODE first;
  QUEUE_NODE last;
  size_t size;
};

QUEUE Queue_Create() {
  QUEUE queue = calloc(1, sizeof(*queue));
  return queue;
}

void Queue_Delete(QUEUE *queue) {
  while (!Queue_IsEmpty(*queue)) {
    Queue_Dequeue(*queue);
  }
  free(*queue), (*queue = NULL);
}

void Queue_Enqueue(QUEUE queue, int val) {
  QUEUE_NODE node = calloc(1, sizeof(*node));
  node->val = val;

  if (Queue_IsEmpty(queue)) {
    queue->first = node;
  } else {
    queue->last->next = node;
  }
  queue->last = node;
  queue->size++;
}

int Queue_Dequeue(QUEUE queue) {
  if (Queue_IsEmpty(queue)) return -1;

  int val = queue->first->val;
  QUEUE_NODE next = queue->first->next;
  free(queue->first), (queue->first = NULL);

  queue->first = next;
  if (queue->first == NULL) {
    queue->last = NULL;
  }
  queue->size--;

  return val;
}

inline int Queue_Peek(QUEUE queue) {
  return  Queue_IsEmpty(queue) ? -1 : queue->first->val;
}

inline int Queue_Size(QUEUE queue) {
  return queue->size;
}

inline bool Queue_IsEmpty(QUEUE queue) {
  return Queue_Size(queue) == 0;
}


#ifndef __stack_h
#define __stack_h

struct Stack;
typedef struct Stack MyStack;
typedef struct Stack *STACK;

STACK myStackCreate();
 void myStackFree(STACK stack);
 void myStackPush(STACK stack, int val);
  int myStackPop(STACK stack);
  int myStackTop(STACK stack);
 bool myStackEmpty(STACK stack);

#endif // __stack_h


struct Stack {
  QUEUE queue1;
  QUEUE queue2;
};

STACK myStackCreate() {
  STACK stack = calloc(1, sizeof(*stack));
  stack->queue1 = Queue_Create();
  stack->queue2 = Queue_Create();
  return stack;
}

void myStackFree(STACK stack) {
  while (!myStackEmpty(stack)) {
    myStackPop(stack);
  }
  Queue_Delete(&stack->queue1);
  Queue_Delete(&stack->queue2);
}

void myStackPush(STACK stack, int val) {
  while (!Queue_IsEmpty(stack->queue1)) {
    Queue_Enqueue(stack->queue2, Queue_Dequeue(stack->queue1));
  }
  Queue_Enqueue(stack->queue1, val);

  while (!Queue_IsEmpty(stack->queue2)) {
    Queue_Enqueue(stack->queue1, Queue_Dequeue(stack->queue2));
  }
}

inline int myStackPop(STACK stack) {
  return Queue_Dequeue(stack->queue1);
}

inline int myStackTop(STACK stack) {
  return Queue_Peek(stack->queue1);
}

inline bool myStackEmpty(STACK stack) {
  return Queue_IsEmpty(stack->queue1);
}

/// }}
