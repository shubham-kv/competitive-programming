#include <stdlib.h>
#include "stack.h"

void stackInit(struct Stack *stack)
{
  stack->size = 0;
  stack->top = NULL;
}

void stackClear(struct Stack *stack)
{
  while (!IS_STACK_EMPTY(stack))
    stackPop(stack);

  stack->size = 0;
  stack->top = NULL;
}

void stackPush(struct Stack *stack, int data)
{
  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = data;
  newNode->next = stack->top;

  stack->top = newNode;
  stack->size++;
}

int stackPop(struct Stack *stack)
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
