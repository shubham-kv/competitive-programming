// Title: Fun with stacks
// Date: 2025-06-28
// Created: Sat, 28 Jun 2025 08:40:22 +0530
// Tags: [stacks daily-practice]

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`  
/// Timestamp: `Sat, 28 Jun 2025 11:09:10 +0530`

bool isValid(char *s) {
  int n = strlen(s);
  char stack[n];
  int stackSize = 0;

  for (int i = 0; i < n; i++) {
    const char cur = s[i];

    if (cur == '(' || cur == '{' || cur == '[') {
      stack[stackSize++] = cur;
    } else if (cur == ')' || cur == '}' || cur == ']') {
      if (stackSize <= 0) {
        return false;
      }

      char popped = stack[--stackSize];

      if (
        popped == '(' && cur != ')' ||
        popped == '{' && cur != '}' ||
        popped == '[' && cur != ']'
      ) {
        return false;
      }
    }
  }

  return stackSize == 0;
}

/// }}


/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Difficulty: Medium
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/
/// Topics: `array`, `math`, `stack`
/// Timestamp: `Sat, 28 Jun 2025 11:44:36 +0530`

int evalRPN(char **tokens, int tokensSize) {
  int n = tokensSize;
  int operandsStack[n], stackSize = 0;

  for (int i = 0; i < n; i++) {
    const char *token = tokens[i];
    int tokenLength = strlen(token);

    if (
      tokenLength == 1 &&
      (*token == '+' || *token == '-' || *token == '*' || *token == '/')
    ) {
      // Error check
      if (stackSize <= 1) {
        return -1; 
      }

      const int opB = operandsStack[--stackSize];
      const int opA = operandsStack[--stackSize];
      int result;

      switch (*token) {
        case '+': result = opA + opB; break;
        case '-': result = opA - opB; break;
        case '*': result = opA * opB; break;
        case '/': result = opA / opB; break;
        default:
          break;
      }

      operandsStack[stackSize++] = result;
    } else {
      int operand;
      sscanf(token, "%d", &operand);
      operandsStack[stackSize++] = operand;
    }
  }

  return operandsStack[--stackSize];
}

/// }}


/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Topics: `stack`, `design`  
/// Timestamp: `Sat, 28 Jun 2025 12:07:48 +0530`

struct Node {
  int data;
  struct Node *next;
  struct Node *min;
};

typedef struct {
  struct Node *top;
} MinStack;

MinStack *minStackCreate();
void minStackFree(MinStack *minStack);

void minStackPush(MinStack *minStack, int val);
void minStackPop(MinStack *minStack);
int minStackTop(MinStack *minStack);
int minStackGetMin(MinStack *minStack);

MinStack *minStackCreate() {
  MinStack *minStack = calloc(1, sizeof(MinStack));
  minStack->top = NULL;
  return minStack;
}

void minStackFree(MinStack *minStack) {
  while (minStack->top != NULL) {
    minStackPop(minStack);
  }
  free(minStack);
}

void minStackPush(MinStack *minStack, int val) {
  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = val;
  newNode->next = minStack->top;
  newNode->min = newNode;

  if (minStack->top != NULL) {
    newNode->min = minStack->top->min->data < newNode->min->data
      ? minStack->top->min
      : newNode->min;
  }

  minStack->top = newNode;
}

void minStackPop(MinStack *minStack) {
  if (minStack->top == NULL) {
    return;
  }

  struct Node *next = minStack->top->next;
  free(minStack->top);
  minStack->top = next;
}

int minStackTop(MinStack *minStack) {
  return minStack->top != NULL ? minStack->top->data : -1;
}

int minStackGetMin(MinStack *minStack) {
  return minStack->top != NULL ? minStack->top->min->data : -1;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* minStack = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

/// }}
