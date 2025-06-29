// Title: Fun with stacks
// Date: 2025-06-29
// Created: Sun, 29 Jun 2025 20:31:41 +0530
// Tags: [stacks daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Sun, 29 Jun 2025 20:38:58 +0530`

#if !defined(__linked_list_stack_h)
#define __linked_list_stack_h

struct Node {
  int data;
  struct Node *next;
};

struct Stack {
  struct Node *top;
  int size;
};

struct Stack *Stack_create();
void Stack_free(struct Stack *stack);
void Stack_push(struct Stack *stack, int data);
int Stack_pop(struct Stack *stack);

#define STACK_SIZE(ptr) (((struct Stack *)ptr)->size)
#define IS_STACK_EMPTY(ptr) (((struct Stack *)ptr)->top == NULL)
#define STACK_PEEK(ptr) (((struct Stack *)ptr)->top == NULL ? -1 : ((struct Stack *)ptr)->top->data)

#endif // __linked_list_stack_h

struct Stack *Stack_create() {
  struct Stack *stack = calloc(1, sizeof(struct Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

void Stack_free(struct Stack *stack) {
  while (!IS_STACK_EMPTY(stack)) {
    Stack_pop(stack);
  }
  free(stack);
}

void Stack_push(struct Stack *stack, int data) {
  struct Node *newTopNode = calloc(1, sizeof(struct Node));
  newTopNode->data = data;
  newTopNode->next = stack->top;
  stack->top = newTopNode;
  stack->size++;
}

int Stack_pop(struct Stack *stack) {
  if (IS_STACK_EMPTY(stack)) {
    return -1;
  }

  struct Node *oldTopNode = stack->top;
  int data = oldTopNode->data;

  stack->top = oldTopNode->next;
  stack->size--;
  free(oldTopNode);

  return data;
}


#if !defined(__my_queue_h)
#define __my_queue_h

typedef struct {
  void *stackA;
  void *stackB;
} MyQueue;

MyQueue *myQueueCreate();
void myQueueFree(MyQueue *queue);

void myQueuePush(MyQueue *queue, int x);
int myQueuePop(MyQueue *queue);
int myQueuePeek(MyQueue *queue);
bool myQueueEmpty(MyQueue *queue);

#endif // __my_queue_h

MyQueue *myQueueCreate() {
  MyQueue *queue = calloc(1, sizeof(MyQueue));
  queue->stackA = Stack_create();
  queue->stackB = Stack_create();
  return queue;
}

void myQueueFree(MyQueue *queue) {
  Stack_free(queue->stackA);
  Stack_free(queue->stackB);
}

void myQueuePush(MyQueue *queue, int x) {
  while (!IS_STACK_EMPTY(queue->stackA)) {
    int data = Stack_pop(queue->stackA);
    Stack_push(queue->stackB, data);
  }

  Stack_push(queue->stackB, x);
}

int myQueuePop(MyQueue *queue) {
  while (!IS_STACK_EMPTY(queue->stackB)) {
    int data = Stack_pop(queue->stackB);
    Stack_push(queue->stackA, data);
  }

  return Stack_pop(queue->stackA);
}

int myQueuePeek(MyQueue *queue) {
  while (!IS_STACK_EMPTY(queue->stackB)) {
    int data = Stack_pop(queue->stackB);
    Stack_push(queue->stackA, data);
  }

  return STACK_PEEK(queue->stackA);
}

bool myQueueEmpty(MyQueue *queue) {
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
 * myQueueFree(queue);
*/

/// }}


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


/// {{
/// Problem: 71. Simplify Path
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/simplify-path/
/// Topics: `string`, `stack`
/// Timestamp: `Sun, 29 Jun 2025 22:56:22 +0530`

#if !defined(__linked_list_stack)
#define __linked_list_stack

struct Node {
  void *data;
  struct Node *next;
};

struct Stack {
  struct Node *top;
  int size;
};

void *Stack_create();
void Stack_free(void *_stack);
void Stack_push(void *_stack, void *data);
void *Stack_pop(void *_stack);
void *Stack_peek(void *_stack);

#define STACK_SIZE(ptr) (((struct Stack *) ptr)->size)
#define IS_STACK_EMPTY(ptr) (((struct Stack *) ptr)->top == NULL)

#endif // __linked_list_stack

void *Stack_create() {
  struct Stack *stack = calloc(1, sizeof(struct Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

void Stack_free(void *_stack) {
  while (!IS_STACK_EMPTY(_stack)) {
    Stack_pop(_stack);
  }
  free(_stack);
}

void Stack_push(void *_stack, void *data) {
  struct Stack *stack = _stack;
  struct Node *newTopNode = calloc(1, sizeof(struct Node));
  newTopNode->data = data;
  newTopNode->next = stack->top;
  stack->top = newTopNode;
  stack->size++;
}

void *Stack_pop(void *_stack) {
  if (IS_STACK_EMPTY(_stack)) {
    return NULL;
  }

  struct Stack *stack = _stack;
  struct Node *oldTopNode = stack->top;
  void *data = oldTopNode->data;
  
  stack->top = oldTopNode->next;
  stack->size--;
  free(oldTopNode);

  return data;
}

void *Stack_peek(void *_stack) {
  if (IS_STACK_EMPTY(_stack)) {
    return NULL;
  }

  struct Stack *stack = _stack;
  return stack->top->data;
}

#define IS_ALPHA_NUMERIC(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_'))

char *simplifyPath(char *path) {
  void *stack = Stack_create();
  const int n = strlen(path);

  for (int i = 0; i < n; i++) {
    int tokenStart = i, tokenLength = 1;
    bool isWord = false;

    if (path[i] == '/') {
      // Skip all the slashes
      for (; i + 1 < n && path[i + 1] == '/'; i++) { }
    }
    else if (path[i] == '.') {
      for (; i + 1 < n && path[i + 1] == '.'; i++, tokenLength++) { }

      if (i + 1 < n && IS_ALPHA_NUMERIC(path[i + 1])) {
        isWord = true;
        for (;
              i + 1 < n && (path[i + 1] == '.' || IS_ALPHA_NUMERIC(path[i + 1]));
              i++, tokenLength++) { }
      }
      else {
        if (tokenLength == 2) {
          Stack_pop(stack);
        } else if (tokenLength > 2) {
          isWord = true;
        }
      }
    }
    else if (IS_ALPHA_NUMERIC(path[i])) {
      isWord = true;
      for (;
          i + 1 < n && (path[i + 1] == '.' || IS_ALPHA_NUMERIC(path[i + 1]));
          i++, tokenLength++) { }
    }
    else {
      return NULL;
    }

    if (isWord) {
      char *name = calloc(tokenLength + 1, sizeof(char));
      strncpy(name, &path[tokenStart], tokenLength);
      Stack_push(stack, name);
    }
  }

  // Stack to reverse the order of names
  void *stackB = Stack_create();
  while (!IS_STACK_EMPTY(stack)) {
    char *name = Stack_pop(stack);
    Stack_push(stackB, name);
  }

  int size = 0;
  char *simplifiedPath = calloc(n + 1, sizeof(char));
  simplifiedPath[size++] = '/';

  while (!IS_STACK_EMPTY(stackB)) {
    char *name = Stack_pop(stackB);
    const int nameLength = strlen(name);

    if (nameLength > 0) {
      if (size != 1) {
        simplifiedPath[size++] = '/';
      }
      strncpy(&simplifiedPath[size], name, nameLength);
      size += nameLength;
    }
    free(name);
  }

  Stack_free(stack), (stack = NULL);
  Stack_free(stackB), (stackB = NULL);
  return simplifiedPath;
}

/// }}
