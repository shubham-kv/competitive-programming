#include <stdlib.h>
#include "stack.h"

struct Stack *stackCreate()
{
  struct Stack *stack = calloc(1, sizeof(struct Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

void stackDelete(struct Stack *stack)
{
  while (!IS_STACK_EMPTY(stack))
    stackPop(stack);

  free(stack);
}

void stackPush(struct Stack *stack, void *item)
{
  struct Node *newTopNode = calloc(1, sizeof(struct Node));
  newTopNode->item = item;
  newTopNode->next = stack->top;

  stack->top = newTopNode;
  stack->size++;
}

void *stackPop(struct Stack *stack)
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
