// Date: 2026-04-23
// Created: Thu, 23 Apr 2026 14:42:05 +0530
// Tags: [search, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Thu, 23 Apr 2026 14:42:20 +0530`

int search(int *nums, int numsSize, int target) {
  int low = 0, high = numsSize - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (target < nums[mid]) {
      high = mid - 1;
    } else if (target > nums[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

/// }}

/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium
/// Links: https://leetcode.com/problems/min-stack/
/// Topics: `stack`, `design`
/// Timestamp: `Thu, 23 Apr 2026 15:01:23 +0530`

#define IS_NULL(ptr) (NULL == ptr)

struct MinStackNode;

typedef struct {
  struct MinStackNode *top;
} MinStack;

MinStack *minStackCreate();
void minStackFree(MinStack *minStack);
void minStackPush(MinStack *minStack, int val);
void minStackPop(MinStack *minStack);
int minStackTop(MinStack *minStack);
int minStackGetMin(MinStack *minStack);

struct MinStackNode {
  int val;
  int min;
  struct MinStackNode *next;
};

MinStack *minStackCreate() {
  MinStack *minStack = calloc(1, sizeof(*minStack));
  return minStack;
}

void minStackFree(MinStack *minStack) {
  while (!IS_NULL(minStack->top)) {
    minStackPop(minStack);
  }
  free(minStack), (minStack = NULL);
}

void minStackPush(MinStack *minStack, int val) {
  struct MinStackNode *node = calloc(1, sizeof(*node));
  node->min = (!IS_NULL(minStack->top) && minStack->top->min < val)
                  ? minStack->top->min
                  : val;
  node->val = val;
  node->next = minStack->top;

  minStack->top = node;
}

void minStackPop(MinStack *minStack) {
  if (IS_NULL(minStack->top))
    return;

  struct MinStackNode *next = minStack->top->next;
  free(minStack->top), (minStack->top = NULL);
  minStack->top = next;
}

int minStackTop(MinStack *minStack) {
  return !IS_NULL(minStack->top) ? minStack->top->val : -1;
}

int minStackGetMin(MinStack *minStack) {
  return !IS_NULL(minStack->top) ? minStack->top->min : -1;
}

/// }}
