#if !defined(my_stack_h)
#define my_stack_h

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  void *queue;
} MyStack;

MyStack *myStackCreate();
void myStackFree(MyStack *stack);

void myStackPush(MyStack *stack, int x);
int myStackPop(MyStack *stack);
int myStackTop(MyStack *stack);
bool myStackEmpty(MyStack *stack);

#endif // my_stack_h
