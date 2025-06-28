#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
