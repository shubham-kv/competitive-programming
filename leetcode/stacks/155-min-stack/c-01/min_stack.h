#if !defined(min_stack_h)
#define min_stack_h

#include <stdlib.h>

/**
 * Structure for every node within the MinStack.
 * Uses a `min` pointer to point to the minimum value at this node's level in the stack.
 */
struct Node {
  int data;
  struct Node *next;

  // Points to a `struct Node` with the smallest value at this node level in the
  // stack.
  struct Node *min;
};

typedef struct
{
  uint32_t size;
  struct Node *top;
} MinStack;

MinStack *minStackCreate();
void minStackFree(MinStack *obj);

void minStackPush(MinStack *obj, int val);
void minStackPop(MinStack *obj);
int minStackTop(MinStack *obj);
int minStackGetMin(MinStack *obj);

#define MIN_STACK_SIZE(p) (((MinStack *)p)->size)
#define IS_MIN_STACK_EMPTY(p) (((MinStack *)p)->size == 0)

#endif // min_stack_h
