// Timestamp: `Fri, 24 Apr 2026 10:14:40 +0530`
// Tags: [search, daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`
/// Timestamp: `Fri, 24 Apr 2026 10:14:40 +0530`

bool isValid(char *s) {
  const size_t n = strlen(s);
  char stack[n];
  size_t stackSize = 0;

  for (int i = 0; i < n; i++) {
    const char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      stack[stackSize++] = ch;
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (stackSize <= 0) {
        return false;
      }

      const char prevChar = stack[--stackSize];

      if ((ch == ')' && prevChar != '(') || (ch == '}' && prevChar != '{') ||
          (ch == ']' && prevChar != '[')) {
        return false;
      }
    }
  }

  return stackSize == 0;
}

/// }}

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Fri, 24 Apr 2026 10:40:58 +0530`

#ifndef __stack_h
#define __stack_h

struct StackNode;
struct Stack;

typedef struct StackNode *STACK_NODE;
typedef struct Stack *STACK;

STACK Stack_Create();
 void Stack_Delete(STACK stack);
 void Stack_Push(STACK stack, int val);
  int Stack_Pop(STACK stack);
  int Stack_Peek(STACK stack);
  int Stack_Size(STACK stack);
 bool Stack_IsEmpty(STACK stack);

#endif // __stack_h


struct StackNode {
  int val;
  struct StackNode *next;
};

struct Stack {
  struct StackNode *top;
  size_t size;
};

STACK Stack_Create() {
  STACK stack = calloc(1, sizeof(*stack));
  return stack;
}

void Stack_Delete(STACK stack) {
  while (!Stack_IsEmpty(stack)) {
    Stack_Pop(stack);
  }
  free(stack), (stack = NULL);
}

void Stack_Push(STACK stack, int val) {
  STACK_NODE node = calloc(1, sizeof(*node));
  node->val = val;
  node->next = stack->top;

  stack->top = node;
  stack->size++;
}

int Stack_Pop(STACK stack) {
  if (Stack_IsEmpty(stack)) {
    return -1;
  }

  int val = stack->top->val;
  STACK_NODE next = stack->top->next;

  free(stack->top), (stack->top = NULL);
  stack->top = next;
  stack->size--;

  return val;
}

inline int Stack_Peek(STACK stack) {
  return Stack_IsEmpty(stack) ? -1 : stack->top->val;
}

inline int Stack_Size(STACK stack) {
  return stack->size;
}

inline bool Stack_IsEmpty(STACK stack) {
  return Stack_Size(stack) == 0;
}



typedef struct {
  STACK stack1;
  STACK stack2;
} MyQueue;

typedef MyQueue *QUEUE;

QUEUE myQueueCreate();
 void myQueueFree(QUEUE queue);
 void myQueuePush(QUEUE queue, int x);
  int myQueuePop(QUEUE queue);
  int myQueuePeek(QUEUE queue);
 bool myQueueEmpty(QUEUE queue);


QUEUE myQueueCreate() {
  QUEUE queue = calloc(1, sizeof(*queue));
  queue->stack1 = Stack_Create();
  queue->stack2 = Stack_Create();
  return queue;
}

void myQueueFree(QUEUE queue) {
  Stack_Delete(queue->stack1), (queue->stack1 = NULL);
  Stack_Delete(queue->stack2), (queue->stack2 = NULL);
  free(queue), (queue = NULL);
}

void myQueuePush(QUEUE queue, int x) {
  while (!Stack_IsEmpty(queue->stack1)) {
    Stack_Push(queue->stack2, Stack_Pop(queue->stack1));
  }
  Stack_Push(queue->stack2, x);
}

int myQueuePop(QUEUE queue) {
  while (!Stack_IsEmpty(queue->stack2)) {
    Stack_Push(queue->stack1, Stack_Pop(queue->stack2));
  }
  return Stack_Pop(queue->stack1);
}

int myQueuePeek(QUEUE queue) {
  while (!Stack_IsEmpty(queue->stack2)) {
    Stack_Push(queue->stack1, Stack_Pop(queue->stack2));
  }
  return Stack_Peek(queue->stack1);
}

bool myQueueEmpty(QUEUE queue) {
  return Stack_IsEmpty(queue->stack1) && Stack_IsEmpty(queue->stack2);
}


/// }}
