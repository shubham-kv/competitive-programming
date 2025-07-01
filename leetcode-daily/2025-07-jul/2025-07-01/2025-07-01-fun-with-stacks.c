// Title: Fun with stacks
// Date: 2025-07-01
// Created: Tue, 01 Jul 2025 12:09:01 +0530
// Tags: [stacks, daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/// {{
/// Problem: 1598. Crawler Log Folder
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/crawler-log-folder/
/// Topics: `array`, `string`, `stack`
/// Timestamp: `Tue, 01 Jul 2025 12:09:52 +0530`

#define IS_ALPHA_NUMERIC(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))

int minOperations(char** logs, int logsSize) {
  char *stack[logsSize];
  int stackSize = 0;

  for (int i = 0; i < logsSize; i++) {
    const char *log = logs[i];

    if (strcmp(log, "../") == 0) {
      if (stackSize > 0) {
        // stack pop
        stack[--stackSize] = NULL;
      }
    } else if (strcmp(log, "./") == 0) {
      // No op
    } else if (IS_ALPHA_NUMERIC(log[0])) {
      stack[stackSize++] = log;
    }
  }

  return stackSize;
}

/// }}


/// {{
/// Problem: 3174. Clear Digits
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/clear-digits/
/// Topics: `string`, `stack`, `simulation`
/// Timestamp: `Tue, 01 Jul 2025 12:25:46 +0530`

#define IS_DIGIT(c) ('0' <= c && c <= '9')

char *clearDigits(char *s) {
  int n = strlen(s);
  char *stack = calloc(n + 1, sizeof(char));
  int stackSize = 0;

  for (int i = 0; i < n; i++) {
    const char cur = s[i];

    if (IS_DIGIT(cur)) {
      stack[--stackSize] = '\0';
    } else {
      stack[stackSize++] = cur;
    }
  }

  return stack;
}

/// }}


/// {{
/// Problem: 227. Basic Calculator II
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/basic-calculator-ii/
/// Topics: `math`, `string`, `stack`
/// Timestamp: `Tue, 01 Jul 2025 12:39:56 +0530`

#define IS_DIGIT(c) ('0' <= c && c <= '9')
#define IS_ADDITIVE_OP(op) (op == '+' || op == '-')
#define IS_MULTIPLICATIVE_OP(op) (op == '*' || op == '/')

int evaluate(char op, int operandA, int operandB) {
  int result = 0;

  switch (op) {
    case '+': result = operandA + operandB; break;
    case '-': result = operandA - operandB; break;
    case '*': result = operandA * operandB; break;
    case '/': result = operandA / operandB; break;
    default:
      break;
  }

  return result;
}

int calculate(char *s) {
  int ogInputLen = strlen(s);

  char input[ogInputLen + 1];
  int inputLen = 0;

  // Build a new input string without spaces
  for (int i = 0; i < ogInputLen; i++) {
    if (s[i] != ' ') {
      input[inputLen++] = s[i];
    }
  }

  int operatorsCapacity = 8, operatorsStackSize = 0;
  char *operators = calloc(operatorsCapacity, sizeof(char));
  int numsCapacity = 8, numsStackSize = 0;
  int *nums = calloc(numsCapacity, sizeof(int));

  for (int i = 0; i < inputLen; i++) {
    char curChar = input[i];

    if (IS_DIGIT(curChar)) {
      int tokenStart = i, tokenLength = 1;

      for (
        ;
        i + 1 < inputLen && IS_DIGIT(input[i + 1]);
        i++, tokenLength++
      ) { }

      char digits[tokenLength + 1];
      memset(digits, 0, tokenLength + 1);
      strncpy(digits, &input[tokenStart], tokenLength);
      int curOperand = atoi(digits);
      bool canEvaluate = false;

      if (operatorsStackSize > 0 && numsStackSize > 0) {
        if (i + 1 < inputLen) {
          char peekedOp = operators[operatorsStackSize - 1];
          char nextChar = input[i + 1];

          if (
            (IS_MULTIPLICATIVE_OP(peekedOp)) ||
            (IS_ADDITIVE_OP(peekedOp) && IS_ADDITIVE_OP(nextChar))
          ) {
            canEvaluate = true;
          }
        } else {
          canEvaluate = true;
        }
      }

      if (canEvaluate) {
        char op = operators[--operatorsStackSize];
        int lastOperand = nums[--numsStackSize];
        curOperand = evaluate(op, lastOperand, curOperand);
      }

      if (numsStackSize >= numsCapacity) {
        numsCapacity *= 2;
        nums = realloc(nums, numsCapacity * sizeof(int));
      }
      nums[numsStackSize++] = curOperand;
    }
    else if (IS_ADDITIVE_OP(curChar) || IS_MULTIPLICATIVE_OP(curChar)) {
      if (operatorsStackSize >= operatorsCapacity) {
        operatorsCapacity *= 2;
        operators = realloc(operators, operatorsCapacity * sizeof(char));
      }
      operators[operatorsStackSize++] = curChar;
    }
  }

  while (operatorsStackSize > 0) {
    char op = operators[--operatorsStackSize];
    int operandB = nums[--numsStackSize];
    int operandA = nums[--numsStackSize];
    nums[numsStackSize++] = evaluate(op, operandA, operandB);
  }

  int result = nums[numsStackSize - 1];
  free(operators), operators = NULL;
  free(nums), nums = NULL;

  return result;
}

/// }}
