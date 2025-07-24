// Title: Fun with stacks
// Date: 2025-07-24
// Created: `Thu, 24 Jul 2025 18:12:05 +0530`
// Tags: [stacks, daily-practice]

#include <string.h>
#include <stdlib.h>

/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/
/// Topics: `array`, `math`, `stack`
/// Timestamp: `Thu, 24 Jul 2025 18:12:05 +0530`

#define IS_ADDITIVE_OP(c) (c == '+' || c == '-')
#define IS_MULTIPLICATIVE_OP(c) (c == '*' || c == '/')
#define IS_OPERATOR(c) (IS_ADDITIVE_OP(c) || IS_MULTIPLICATIVE_OP(c))

int evalRPN(char **tokens, int tokensSize) {
  int operandsStack[tokensSize], operandsStackSize = 0;
  memset(operandsStack, 0, tokensSize * sizeof(int));

  for (int i = 0; i < tokensSize; i++) {
    const char *token = tokens[i];
    int tokenLen = strlen(token);

    if (tokenLen == 1 && IS_OPERATOR(token[0])) {
      if (operandsStackSize > 1) {
        const int operandB = operandsStack[operandsStackSize - 1];
        operandsStack[--operandsStackSize] = 0;

        const int operandA = operandsStack[operandsStackSize - 1];
        operandsStack[--operandsStackSize] = 0;

        int result = 0;

        switch(token[0]) {
          case '+': result = operandA + operandB; break;
          case '-': result = operandA - operandB; break;
          case '*': result = operandA * operandB; break;
          case '/': result = operandA / operandB; break;
          default: break;
        }

        operandsStack[operandsStackSize++] = result;
      }
    } else {
      int operand = atoi(token);
      operandsStack[operandsStackSize++] = operand;
    }
  }

  return operandsStackSize > 0 ? operandsStack[0] : 0;
}

/// }}
