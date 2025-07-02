#include <stdlib.h>

/// {{
/// Problem: 227. Basic Calculator II
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/basic-calculator-ii/
/// Topics: `math`, `string`, `stack`
/// Timestamp: `Wed, 02 Jul 2025 11:24:20 +0530`

#define IS_DIGIT(c) ('0' <= c && c <= '9')
#define IS_ADDITIVE_OP(op) (op == '+' || op == '-')
#define IS_MULTIPLICATIVE_OP(op) (op == '*' || op == '/')

int calculate(char *s) {
  int inputLen = strlen(s);
  int numsCapacity = 8, numsStackSize = 0;
  int *numsStack = calloc(numsCapacity, sizeof(int));

  char lastOp = '+';
  int curInteger = 0;

  for (int i = 0; i < inputLen; i++) {
    char curChar = s[i];
    
    if (IS_DIGIT(curChar)) {
      char digits[2] = {curChar, '\0'};
      curInteger = curInteger * 10 + atoi(digits);
    }

    if ((IS_ADDITIVE_OP(curChar) || IS_MULTIPLICATIVE_OP(curChar)) || i == inputLen - 1) {
      if (numsStackSize >= numsCapacity) {
        numsCapacity *= 2;
        numsStack = realloc(numsStack, numsCapacity * sizeof(int));
      }

      if (lastOp == '+') {
        numsStack[numsStackSize++] = curInteger;
      } else if (lastOp == '-') {
        numsStack[numsStackSize++] = -curInteger;
      } else if (lastOp == '*') {
        numsStack[numsStackSize - 1] *= curInteger;
      } else if (lastOp == '/') {
        numsStack[numsStackSize - 1] /= curInteger;
      }

      curInteger = 0;
      lastOp = curChar;
    }
  }

  int result = 0;
  while (numsStackSize > 0) {
    result += numsStack[--numsStackSize];
  }

  free(numsStack), numsStack = NULL;

  return result;
}

/// }}
