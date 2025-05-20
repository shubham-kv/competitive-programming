#if !defined(stack_linked_list_h)
#define stack_linked_list_h

#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct StackNode
{
  uint32_t size;
  struct Node *top;
};

// One of the goals with this implementation where `stackInit()` takes in a
// pointer is to use less storage in heap

void stackInit(struct StackNode *stack);
void stackClear(struct StackNode *stack);

void stackPush(struct StackNode *stack, int data);
int stackPop(struct StackNode *stack);

#define STACK_SIZE(p) (((struct Stack *) p)->size)
#define IS_STACK_EMPTY(p) (((struct Stack *) p)->top == NULL)

#endif // stack_linked_list_h
