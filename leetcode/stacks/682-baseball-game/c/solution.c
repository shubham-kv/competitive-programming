#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 682. Baseball Game
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/baseball-game/
/// Topics: `array`, `stack`, `simulation`  
/// Timestamp: `Sun, 29 Jun 2025 21:40:36 +0530`

#if !defined(__resizing_array_stack_h)
#define __resizing_array_stack_h

struct ResizingArrayStack {
  int *items;
  int size;
  int capacity;
};

void *Stack_create();
void Stack_free(void *_stack);
void Stack_push(void *_stack, int data);
int Stack_pop(void *_stack);
int Stack_peek(void *_stack);

#define STACK_INITIAL_CAPCITY 4
#define STACK_SIZE(ptr) (((struct ResizingArrayStack *)ptr)->size)
#define IS_STACK_EMPTY(ptr) (((struct ResizingArrayStack *)ptr)->size == 0)
#define IS_STACK_FULL(ptr) (((struct ResizingArrayStack *)ptr)->size == ((struct ResizingArrayStack *)ptr)->capacity)

#endif // __resizing_array_stack_h

void *Stack_create() {
  struct ResizingArrayStack *stack = calloc(1, sizeof(struct ResizingArrayStack));
  stack->capacity = STACK_INITIAL_CAPCITY;
  stack->items = calloc(stack->capacity, sizeof(int));
  stack->size = 0;
  return stack;
}

void Stack_free(void *stack) {
  while (!IS_STACK_EMPTY(stack)) {
    Stack_pop(stack);
  }
  free(stack);
}

void Stack_resize(void *_stack, int newCapcity) {
  struct ResizingArrayStack *stack = _stack;
  stack->items = realloc(stack->items, newCapcity * sizeof(int));
  stack->capacity = newCapcity;
}

void Stack_push(void *_stack, int data) {
  struct ResizingArrayStack *stack = _stack;

  if (IS_STACK_FULL(stack)) {
    Stack_resize(stack, stack->capacity * 2);
  }

  stack->items[stack->size++] = data;
}

int Stack_pop(void *_stack) {
  struct ResizingArrayStack *stack = _stack;
  int popped = stack->items[--stack->size];

  if (stack->size <= stack->capacity / 4) {
    Stack_resize(stack, stack->capacity / 2);
  }

  return popped;
}

int Stack_peek(void *_stack) {
  if (IS_STACK_EMPTY(_stack)) {
    return -1;
  }

  struct ResizingArrayStack *stack = _stack;
  return stack->items[stack->size - 1];
}


int calPoints(char **operations, int operationsSize) {
  void *stack = Stack_create();

  for (int i = 0; i < operationsSize; i++) {
    const char *operation = operations[i];

    if (strcmp(operation, "+") == 0) {
      int scoreA, scoreB, scoreC;
      scoreB = Stack_pop(stack);
      scoreA = Stack_peek(stack);
      scoreC = scoreA + scoreB;
      Stack_push(stack, scoreB);
      Stack_push(stack, scoreC);
    } else if (strcmp(operation, "D") == 0) {
      int lastScore = Stack_peek(stack);
      Stack_push(stack, lastScore * 2);
    } else if (strcmp(operation, "C") == 0) {
      Stack_pop(stack);
    } else {
      int score = atoi(operation);
      Stack_push(stack, score);
    }
  }

  int result = 0;
  while (!IS_STACK_EMPTY(stack)) {
    result += Stack_pop(stack);
  }

  Stack_free(stack);
  stack = NULL;
  return result;
}

/// }}
