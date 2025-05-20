#include <stdlib.h>
#include "stack.h"

struct StackNode *stackCreate()
{
  struct StackNode *stack = calloc(1, sizeof(struct StackNode));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

void stackDelete(struct StackNode *stack)
{
  while (!IS_STACK_EMPTY(stack))
    stackPop(stack);

  free(stack);
}

void stackPush(struct StackNode *stack, void *item)
{
  struct Node *newTopNode = calloc(1, sizeof(struct Node));
  newTopNode->item = item;
  newTopNode->next = stack->top;

  stack->top = newTopNode;
  stack->size++;
}

void *stackPop(struct StackNode *stack)
{
  if (IS_STACK_EMPTY(stack))
    return NULL;

  struct Node *oldTopNode = stack->top;
  void *item = oldTopNode->item;

  stack->top = oldTopNode->next;
  stack->size--;
  free(oldTopNode);

  return item;
}
