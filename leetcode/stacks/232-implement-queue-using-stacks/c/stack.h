#if !defined(stack_h)
#define stack_h

#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct
{
  uint32_t size;
  Node *top;
} Stack;

Stack *stackCreate();
void stackDelete(Stack *stack);

void stackPush(Stack *stack, int data);
int stackPop(Stack *stack);
int stackPeek(Stack *stack);

#define STACK_SIZE(stack) (((Stack *)stack)->size)
#define IS_STACK_EMPTY(stack) (((Stack *)stack)->size == 0)

#endif // stack_h
