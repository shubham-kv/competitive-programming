#if !defined(min_stack_h)
#define min_stack_h

#include <stdlib.h>

struct Node {
  int data;
  int min;
  struct Node *next;
};

typedef struct
{
  uint32_t size;
  struct Node *top;
} MinStack;

MinStack *minStackCreate();
void minStackFree(MinStack *minStack);

void minStackPush(MinStack *minStack, int val);
void minStackPop(MinStack *minStack);
int minStackTop(MinStack *minStack);
int minStackGetMin(MinStack *minStack);

#define IS_MIN_STACK_EMPTY(p) (((MinStack *) p)->size == 0)

#endif // min_stack_h
