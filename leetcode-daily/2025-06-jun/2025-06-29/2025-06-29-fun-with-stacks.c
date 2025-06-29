// Title: Fun with stacks
// Date: 2025-06-29
// Created: Sun, 29 Jun 2025 20:31:41 +0530
// Tags: [stacks daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Sun, 29 Jun 2025 20:38:58 +0530`

#if !defined(__linked_list_stack_h)
#define __linked_list_stack_h

struct Node {
  int data;
  struct Node *next;
};

struct Stack {
  struct Node *top;
  int size;
};

struct Stack *Stack_create();
void Stack_free(struct Stack *stack);
void Stack_push(struct Stack *stack, int data);
int Stack_pop(struct Stack *stack);

#define STACK_SIZE(ptr) (((struct Stack *)ptr)->size)
#define IS_STACK_EMPTY(ptr) (((struct Stack *)ptr)->top == NULL)
#define STACK_PEEK(ptr) (((struct Stack *)ptr)->top == NULL ? -1 : ((struct Stack *)ptr)->top->data)

#endif // __linked_list_stack_h

struct Stack *Stack_create() {
  struct Stack *stack = calloc(1, sizeof(struct Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

void Stack_free(struct Stack *stack) {
  while (!IS_STACK_EMPTY(stack)) {
    Stack_pop(stack);
  }
  free(stack);
}

void Stack_push(struct Stack *stack, int data) {
  struct Node *newTopNode = calloc(1, sizeof(struct Node));
  newTopNode->data = data;
  newTopNode->next = stack->top;
  stack->top = newTopNode;
  stack->size++;
}

int Stack_pop(struct Stack *stack) {
  if (IS_STACK_EMPTY(stack)) {
    return -1;
  }

  struct Node *oldTopNode = stack->top;
  int data = oldTopNode->data;

  stack->top = oldTopNode->next;
  stack->size--;
  free(oldTopNode);

  return data;
}


#if !defined(__my_queue_h)
#define __my_queue_h

typedef struct {
  void *stackA;
  void *stackB;
} MyQueue;

MyQueue *myQueueCreate();
void myQueueFree(MyQueue *queue);

void myQueuePush(MyQueue *queue, int x);
int myQueuePop(MyQueue *queue);
int myQueuePeek(MyQueue *queue);
bool myQueueEmpty(MyQueue *queue);

#endif // __my_queue_h

MyQueue *myQueueCreate() {
  MyQueue *queue = calloc(1, sizeof(MyQueue));
  queue->stackA = Stack_create();
  queue->stackB = Stack_create();
  return queue;
}

void myQueueFree(MyQueue *queue) {
  Stack_free(queue->stackA);
  Stack_free(queue->stackB);
}

void myQueuePush(MyQueue *queue, int x) {
  while (!IS_STACK_EMPTY(queue->stackA)) {
    int data = Stack_pop(queue->stackA);
    Stack_push(queue->stackB, data);
  }

  Stack_push(queue->stackB, x);
}

int myQueuePop(MyQueue *queue) {
  while (!IS_STACK_EMPTY(queue->stackB)) {
    int data = Stack_pop(queue->stackB);
    Stack_push(queue->stackA, data);
  }

  return Stack_pop(queue->stackA);
}

int myQueuePeek(MyQueue *queue) {
  while (!IS_STACK_EMPTY(queue->stackB)) {
    int data = Stack_pop(queue->stackB);
    Stack_push(queue->stackA, data);
  }

  return STACK_PEEK(queue->stackA);
}

bool myQueueEmpty(MyQueue *queue) {
  return IS_STACK_EMPTY(queue->stackA) && IS_STACK_EMPTY(queue->stackB);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 *
 * MyQueue* queue = myQueueCreate();
 * myQueuePush(queue, x);
 * int param_2 = myQueuePop(queue);
 * int param_3 = myQueuePeek(queue);
 * bool param_4 = myQueueEmpty(queue);
 * myQueueFree(queue);
*/

/// }}
