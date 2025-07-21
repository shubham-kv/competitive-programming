// Title: Fun with stacks
// Date: 2025-07-21
// Created: `Mon, 21 Jul 2025 12:07:13 +0530`
// Tags: [stacks, daily-practice]

#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Mon, 21 Jul 2025 12:07:13 +0530`

struct Node {
  struct Node *next;
  int data;
};

struct Stack {
  struct Node *top;
};

const int NODE_WIDTH = sizeof(struct Node);
const int STACK_WIDTH = sizeof(struct Stack);

struct Stack *Stack_create();
void Stack_free(struct Stack *stack);
void Stack_push(struct Stack *stack, int data);
int Stack_pop(struct Stack *stack);

#define IS_STACK_EMPTY(stack) (((struct Stack *) stack)->top == NULL)
#define STACK_PEEK(stack) (IS_STACK_EMPTY(stack) ? -1 : ((struct Stack *) stack)->top->data)


inline struct Stack *Stack_create() {
  return calloc(1, STACK_WIDTH);
}

void Stack_free(struct Stack *stack) {
  while (!IS_STACK_EMPTY(stack)) {
    Stack_pop(stack);
  }
  free(stack);
}

void Stack_push(struct Stack *stack, int data) {
  struct Node *node = calloc(1, NODE_WIDTH);
  node->data = data;
  node->next = stack->top;
  stack->top = node;
}

int Stack_pop(struct Stack *stack) {
  if (IS_STACK_EMPTY(stack)) {
    return -1;
  }

  int data = stack->top->data;
  struct Node *next = stack->top->next;
  free(stack->top), (stack->top = NULL);
  stack->top = next;

  return data;
}



typedef struct {
  void *stack1;
  void *stack2;
} MyQueue;

const int MY_QUEUE_WIDTH = sizeof(MyQueue);

MyQueue *myQueueCreate();
void myQueueFree(MyQueue *queue);
void myQueuePush(MyQueue *queue, int x);
int myQueuePop(MyQueue *queue);
int myQueuePeek(MyQueue *queue);
bool myQueueEmpty(MyQueue *queue);

MyQueue *myQueueCreate() {
  MyQueue *queue = calloc(1, MY_QUEUE_WIDTH);
  queue->stack1 = Stack_create();
  queue->stack2 = Stack_create();
  return queue;
}

void myQueueFree(MyQueue *queue) {
  Stack_free(queue->stack1);
  Stack_free(queue->stack2);
  memset(queue, 0, MY_QUEUE_WIDTH);
  free(queue);
}

void myQueuePush(MyQueue *queue, int x) {
  while (!IS_STACK_EMPTY(queue->stack1)) {
    Stack_push(queue->stack2, Stack_pop(queue->stack1));
  }

  Stack_push(queue->stack2, x);
}

int myQueuePop(MyQueue *queue) {
  while (!IS_STACK_EMPTY(queue->stack2)) {
    Stack_push(queue->stack1, Stack_pop(queue->stack2));
  }

  return Stack_pop(queue->stack1);
}

int myQueuePeek(MyQueue *queue) {
  while (!IS_STACK_EMPTY(queue->stack2)) {
    Stack_push(queue->stack1, Stack_pop(queue->stack2));
  }

  return STACK_PEEK(queue->stack1);
}

inline bool myQueueEmpty(MyQueue *queue) {
  return IS_STACK_EMPTY(queue->stack1) && IS_STACK_EMPTY(queue->stack2);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* queue = myQueueCreate();
 * myQueuePush(queue, x);
 * int param_2 = myQueuePop(queue);
 * int param_3 = myQueuePeek(queue);
 * bool param_4 = myQueueEmpty(queue);
 * myQueueFree(queue);
*/

/// }}
