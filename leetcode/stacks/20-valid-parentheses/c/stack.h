#if !defined(stack_h)
#define stack_h

#include <stdlib.h>

struct Node
{
  void *item;
  struct Node *next;
};

struct Stack
{
  uint32_t size;
  struct Node *top;
};

struct Stack *stackCreate();
void stackDelete(struct Stack *stack);

void stackPush(struct Stack *stack, void *item);
void *stackPop(struct Stack *stack);

#define STACK_SIZE(p) (((struct Stack *)p)->size)
#define IS_STACK_EMPTY(p) (((struct Stack *)p)->size == 0)

#endif // stack_h
