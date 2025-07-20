// Title: Fun with stacks
// Date: 2025-07-18
// Created: `Sun, 20 Jul 2025 18:05:34 +0530`
// Tags: [stacks, daily-practice]

#include <memory.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`  
/// Timestamp: `Sun, 20 Jul 2025 18:05:34 +0530`

bool isValid(char *s) {
  int len = strlen(s);
  char stack[len];
  int stackSize = 0;

  for (int i = 0; i < len; i++) {
    const char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      stack[stackSize++] = ch;
    }
    else if (ch == ')' || ch == '}' || ch == ']') {
      if (!(stackSize > 0)) {
        return false;
      }

      char popped = stack[--stackSize];

      if (
          (popped == '(' && ch != ')') ||
          (popped == '{' && ch != '}') ||
          (popped == '[' && ch != ']')) {
        return false;
      }
    }
    else {
      return false;
    }
  }

  if (stackSize > 0) {
    return false;
  }

  return true;
}

/// }}


/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Topics: `stack`, `design`  
/// Timestamp: `Sun, 20 Jul 2025 18:27:28 +0530`

struct Node {
  struct Node *next;
  int data;
  int min;
};

typedef struct {
  struct Node *top;
} MinStack;

const int NODE_WIDTH = sizeof(struct Node);
const int MIN_STACK_WIDTH = sizeof(MinStack);

MinStack *minStackCreate();
void minStackFree(MinStack *minStack);
void minStackPush(MinStack *minStack, int val);
void minStackPop(MinStack *minStack);
int minStackTop(MinStack *minStack);
int minStackGetMin(MinStack *minStack);


MinStack *minStackCreate() {
  return calloc(1, MIN_STACK_WIDTH);
}

void minStackFree(MinStack *minStack) {
  while (minStack->top != NULL) {
    minStackPop(minStack);
  }
  memset(minStack, 0, MIN_STACK_WIDTH);
  free(minStack);
}

void minStackPush(MinStack *minStack, int val) {
  struct Node *node = calloc(1, NODE_WIDTH);
  node->next = minStack->top;
  node->data = val;
  node->min = (minStack->top != NULL) ? ((val < minStack->top->min) ? val : minStack->top->min) : val;

  minStack->top = node;
}

void minStackPop(MinStack *minStack) {
  if (minStack->top == NULL) {
    return;
  }

  struct Node *next = minStack->top->next;
  free(minStack->top), (minStack->top = NULL);
  minStack->top = next;
}

int minStackTop(MinStack *minStack) {
  return (minStack->top == NULL) ? -1 : minStack->top->data;
}

int minStackGetMin(MinStack *minStack) {
  return (minStack->top == NULL) ? -1 : minStack->top->min;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* minStack = minStackCreate();
 * minStackPush(minStack, val);
 * minStackPop(minStack);
 * int param_3 = minStackTop(minStack);
 * int param_4 = minStackGetMin(minStack);
 * minStackFree(minStack);
*/

/// }}
