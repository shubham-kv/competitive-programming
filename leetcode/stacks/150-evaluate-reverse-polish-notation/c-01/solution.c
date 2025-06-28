#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/

int evalRPN(char **tokens, int tokensSize) {
  int operandsStack[tokensSize], operandsStackSize = 0;

  for (int i = 0; i < tokensSize; i++) {
    const char *curToken = tokens[i];
    const int curTokenLength = strlen(curToken);

    if (
        curTokenLength == 1 && (*curToken == '+' ||
                                *curToken == '-' ||
                                *curToken == '*' ||
                                *curToken == '/'))
    {
      if (operandsStackSize >= 2)
      {
        const int operandB = operandsStack[--operandsStackSize];
        const int operandA = operandsStack[--operandsStackSize];
        int result;

        switch (*curToken) {
          case '+': {
            result = operandA + operandB;
            break;
          }
          case '-': {
            result = operandA - operandB;
            break;
          }
          case '*': {
            result = operandA * operandB;
            break;
          }
          case '/': {
            result = operandA / operandB;
            break;
          }
        }

        operandsStack[operandsStackSize++] = result;
      }
      else
      {
        break;
      }
    }
    else {
      int operand = 0;
      sscanf(curToken, "%d", &operand);
      operandsStack[operandsStackSize++] = operand;
    }
  }

  return operandsStack[0];
}

/// }}
