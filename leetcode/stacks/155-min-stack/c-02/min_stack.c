#include <stdlib.h>
#include "min_stack.h"

MinStack *minStackCreate()
{
  MinStack *minStack = calloc(1, sizeof(MinStack));
  minStack->size = 0;
  minStack->top = NULL;
  return minStack;
}

void minStackFree(MinStack *minStack)
{
  while (!IS_MIN_STACK_EMPTY(minStack))
    minStackPop(minStack);

  free(minStack);
}

void minStackPush(MinStack *minStack, int val)
{
  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = val;
  newNode->next = minStack->top;
  newNode->min =
      IS_MIN_STACK_EMPTY(minStack)
          ? val
          : (minStack->top->min < val ? minStack->top->min : val);

  minStack->top = newNode;
  minStack->size++;
}

void minStackPop(MinStack *minStack)
{
  if (IS_MIN_STACK_EMPTY(minStack))
    return;

  struct Node *oldTop = minStack->top;
  minStack->top = minStack->top->next;
  minStack->size--;
  free(oldTop);
}

int minStackTop(MinStack *minStack)
{
  if (IS_MIN_STACK_EMPTY(minStack))
    return -1;

  return minStack->top->data;
}

int minStackGetMin(MinStack *minStack)
{
  if (IS_MIN_STACK_EMPTY(minStack))
    return -1;

  return minStack->top->min;
}
