#include <stdlib.h>

/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Topics: `stack`, `design`  
/// Timestamp: `Sat, 28 Jun 2025 12:07:48 +0530`

struct Node {
  int data;
  struct Node *next;
  struct Node *min;
};

typedef struct {
  struct Node *top;
} MinStack;

MinStack *minStackCreate();
void minStackFree(MinStack *minStack);

void minStackPush(MinStack *minStack, int val);
void minStackPop(MinStack *minStack);
int minStackTop(MinStack *minStack);
int minStackGetMin(MinStack *minStack);

MinStack *minStackCreate() {
  MinStack *minStack = calloc(1, sizeof(MinStack));
  minStack->top = NULL;
  return minStack;
}

void minStackFree(MinStack *minStack) {
  while (minStack->top != NULL) {
    minStackPop(minStack);
  }
  free(minStack);
}

void minStackPush(MinStack *minStack, int val) {
  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = val;
  newNode->next = minStack->top;
  newNode->min = newNode;

  if (minStack->top != NULL) {
    newNode->min = minStack->top->min->data < newNode->min->data
      ? minStack->top->min
      : newNode->min;
  }

  minStack->top = newNode;
}

void minStackPop(MinStack *minStack) {
  if (minStack->top == NULL) {
    return;
  }

  struct Node *next = minStack->top->next;
  free(minStack->top);
  minStack->top = next;
}

int minStackTop(MinStack *minStack) {
  return minStack->top != NULL ? minStack->top->data : -1;
}

int minStackGetMin(MinStack *minStack) {
  return minStack->top != NULL ? minStack->top->min->data : -1;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* minStack = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

/// }}
