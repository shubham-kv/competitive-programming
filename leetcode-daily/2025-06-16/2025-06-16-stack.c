// Title: Fun with stacks
// Date: 2025-06-16
// Created: Mon, 16 Jun 2025 18:31:42 +0530
// Tags: [stacks, daily-practice]

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Links: https://leetcode.com/problems/valid-parentheses/

bool isValid(char* s) {
  int n = strlen(s);
  char stack[n];
  int stackSize = 0;

  bool doParensMatch = true;
  bool containsInvalidChars = false;

  for (int i = 0; i < n; i++) {
    const char cur = s[i];

    if (cur == '(' || cur == '{' || cur == '[') {
      stack[stackSize++] = cur;
    } else if (cur == ')' || cur == '}' || cur == ']') {
      if (stackSize > 0) {
        const char popped = stack[--stackSize];

        if (
          (popped == '(' && cur != ')') ||
          (popped == '{' && cur != '}') ||
          (popped == '[' && cur != ']')
        ) {
          doParensMatch = false;
          break;
        }
      } else {
        doParensMatch = false;
        break;
      }
    } else {
      containsInvalidChars = true;
      break;
    }
  }

  bool result = stackSize == 0 && !containsInvalidChars && doParensMatch;
  return result;
}

/// }}
