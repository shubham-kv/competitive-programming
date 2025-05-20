#include <stdlib.h>
#include "stack.h"

void stackInit(struct Stack *stack) {
  stack->size = 0;
  stack->top = NULL;
}

void stackClear(struct Stack *stack) {
  stack->size = 0;
  stack->top = NULL;
}

void stackPush(struct Stack *stack, struct Node *node) {
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}

struct Node *stackPop(struct Stack *stack) {
  if (IS_STACK_EMPTY(stack)) {
    return NULL;
  }

  struct Node *oldTop = stack->top;
  stack->top = stack->top->next;
  stack->size--;

  return oldTop;
}
