#include <stdlib.h>

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
