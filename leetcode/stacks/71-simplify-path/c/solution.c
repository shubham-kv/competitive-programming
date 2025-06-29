#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
