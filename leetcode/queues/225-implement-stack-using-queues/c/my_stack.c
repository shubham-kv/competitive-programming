#include <stdlib.h>
#include <stdbool.h>
#include "my_stack.h"
#include "queue_linked_list.h"

MyStack *myStackCreate() {
  MyStack *stack = calloc(1, sizeof(MyStack));
  stack->queue = queueCreate();
  return stack;
}

void myStackFree(MyStack *stack) {
  queueDelete(stack->queue);
  free(stack);
}

void myStackPush(MyStack *stack, int x) {
  queueEnqueue(stack->queue, x);
}

int myStackPop(MyStack *stack) {
  // Dequeue & Enqueue `n-1` times to bring the last item to front
  int size = queueSize(stack->queue);

  for (int i = 0; i < size - 1; i++) {
    int item = queueDequeue(stack->queue);
    queueEnqueue(stack->queue, item);
  }

  int poppedItem = queueDequeue(stack->queue);
  return poppedItem;
}

int myStackTop(MyStack *stack) {
  // Dequeue & Enqueue `n-1` times to bring the last item to front
  int size = queueSize(stack->queue);

  for (int i = 0; i < size - 1; i++) {
    int item = queueDequeue(stack->queue);
    queueEnqueue(stack->queue, item);
  }

  int peekedItem = queuePeek(stack->queue);

  // Put the first item back to it's last position
  int item = queueDequeue(stack->queue);
  queueEnqueue(stack->queue, item);

  return peekedItem;
}

bool myStackEmpty(MyStack *stack) {
  return isQueueEmpty(stack->queue);
}
