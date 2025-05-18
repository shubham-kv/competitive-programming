#if !defined(queue_using_stacks_h)
#define queue_using_stacks_h

#include "stack.h"

typedef struct
{
  Stack *stackA;
  Stack *stackB;
} MyQueue;

MyQueue *myQueueCreate();

void myQueuePush(MyQueue *obj, int x);
int myQueuePop(MyQueue *obj);
int myQueuePeek(MyQueue *obj);
bool myQueueEmpty(MyQueue *obj);

void myQueueFree(MyQueue *obj);

#endif // queue_using_stacks_h
