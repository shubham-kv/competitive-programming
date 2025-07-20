// Title: Fun with stacks
// Date: 2025-07-18
// Created: `Sun, 20 Jul 2025 18:05:34 +0530`
// Tags: [stacks, daily-practice]

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`  
/// Timestamp: `Sun, 20 Jul 2025 18:05:34 +0530`

bool isValid(char *s) {
  int len = strlen(s);
  char stack[len];
  int stackSize = 0;

  for (int i = 0; i < len; i++) {
    const char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      stack[stackSize++] = ch;
    }
    else if (ch == ')' || ch == '}' || ch == ']') {
      if (!(stackSize > 0)) {
        return false;
      }

      char popped = stack[--stackSize];

      if (
          (popped == '(' && ch != ')') ||
          (popped == '{' && ch != '}') ||
          (popped == '[' && ch != ']')) {
        return false;
      }
    }
    else {
      return false;
    }
  }

  if (stackSize > 0) {
    return false;
  }

  return true;
}

/// }}
