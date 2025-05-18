#include <stdbool.h>
#include "queue_using_stacks.h"

MyQueue *myQueueCreate()
{
  MyQueue *queue = calloc(1, sizeof(MyQueue));
  queue->stackA = stackCreate();
  queue->stackB = stackCreate();
  return queue;
}

void myQueueFree(MyQueue *queue)
{
  stackDelete(queue->stackA);
  stackDelete(queue->stackB);
  free(queue);
}

void myQueuePush(MyQueue *queue, int x)
{
  while (!IS_STACK_EMPTY(queue->stackB))
  {
    int data = stackPop(queue->stackB);
    stackPush(queue->stackA, data);
  }

  stackPush(queue->stackA, x);
}

int myQueuePop(MyQueue *queue)
{
  // Pop all items from stackA & push them one by one to stackB to reverse their
  // relative order
  while (!IS_STACK_EMPTY(queue->stackA))
  {
    int data = stackPop(queue->stackA);
    stackPush(queue->stackB, data);
  }

  // stackB should now contain the item at the front of the queue at it's top
  int front = stackPop(queue->stackB);
  return front;
}

int myQueuePeek(MyQueue *queue)
{
  // Nearly Same operation as in queuePop
  // 1. Pop items from stackA (if there are any) & push them onto stackB
  while (!IS_STACK_EMPTY(queue->stackA))
  {
    int data = stackPop(queue->stackA);
    stackPush(queue->stackB, data);
  }

  // 2. Peek the top of stackB
  int front = stackPeek(queue->stackB);

  return front;
}

bool myQueueEmpty(MyQueue *queue)
{
  return IS_STACK_EMPTY(queue->stackA) && IS_STACK_EMPTY(queue->stackB);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * 
 * MyQueue* queue = myQueueCreate();
 * myQueuePush(queue, x);
 * int param_2 = myQueuePop(queue);
 * int param_3 = myQueuePeek(queue);
 * bool param_4 = myQueueEmpty(queue);
 * 
 * myQueueFree(queue);
*/
