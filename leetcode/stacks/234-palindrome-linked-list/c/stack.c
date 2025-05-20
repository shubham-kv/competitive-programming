#include <stdlib.h>
#include "stack.h"

void stackInit(struct StackNode *stack)
{
  stack->size = 0;
  stack->top = NULL;
}

void stackClear(struct StackNode *stack)
{
  while (!IS_STACK_EMPTY(stack))
    stackPop(stack);

  stack->size = 0;
  stack->top = NULL;
}

void stackPush(struct StackNode *stack, int data)
{
  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = data;
  newNode->next = stack->top;

  stack->top = newNode;
  stack->size++;
}

int stackPop(struct StackNode *stack)
{
  if (IS_STACK_EMPTY(stack))
    return -1;

  struct Node *oldTop = stack->top;
  int data = oldTop->data;

  stack->top = stack->top->next;
  stack->size--;
  free(oldTop);

  return data;
}
