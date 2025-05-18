#include <stdlib.h>
#include "stack.h"

Stack *stackCreate()
{
  Stack *stack = calloc(1, sizeof(Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

void stackDelete(Stack *stack)
{
  while (!IS_STACK_EMPTY(stack))
    stackPop(stack);

  free(stack);
}

void stackPush(Stack *stack, int data)
{
  Node *newNode = calloc(1, sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;

  stack->top = newNode;
  stack->size++;
}

int stackPop(Stack *stack)
{
  if (IS_STACK_EMPTY(stack))
    return -1;

  Node *oldTop = stack->top;
  int data = oldTop->data;

  stack->top = oldTop->next;
  stack->size--;
  free(oldTop);

  return data;
}

int stackPeek(Stack *stack)
{
  if (IS_STACK_EMPTY(stack))
    return -1;
  
  return stack->top->data;
}
