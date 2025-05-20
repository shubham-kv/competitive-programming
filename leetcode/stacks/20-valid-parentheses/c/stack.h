#if !defined(stack_h)
#define stack_h

#include <stdlib.h>

struct Node
{
  void *item;
  struct Node *next;
};

struct StackNode
{
  uint32_t size;
  struct Node *top;
};

struct StackNode *stackCreate();
void stackDelete(struct StackNode *stack);

void stackPush(struct StackNode *stack, void *item);
void *stackPop(struct StackNode *stack);

#define STACK_SIZE(p) (((struct Stack *)p)->size)
#define IS_STACK_EMPTY(p) (((struct Stack *)p)->size == 0)

#endif // stack_h
