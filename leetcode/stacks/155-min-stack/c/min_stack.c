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
  newNode->min = newNode;

  if (!IS_MIN_STACK_EMPTY(minStack))
  {
    struct Node *min = minStack->top->min;
    newNode->min = (newNode->data < min->data) ? newNode : min;
  }

  minStack->top = newNode;
  minStack->size++;
}

void minStackPop(MinStack *minStack)
{
  if (!IS_MIN_STACK_EMPTY(minStack))
    return;

  struct Node *oldTopNode = minStack->top;
  minStack->top = oldTopNode->next;
  minStack->size--;
  free(oldTopNode);
}

int minStackTop(MinStack *minStack)
{
  return minStack->top->data;
}

int minStackGetMin(MinStack *minStack)
{
  return minStack->top->min->data;
}
