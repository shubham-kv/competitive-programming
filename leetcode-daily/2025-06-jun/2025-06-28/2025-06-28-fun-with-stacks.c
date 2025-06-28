// Title: Fun with stacks
// Date: 2025-06-28
// Created: Sat, 28 Jun 2025 08:40:22 +0530
// Tags: [stacks daily-practice]

#include <stdbool.h>
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
