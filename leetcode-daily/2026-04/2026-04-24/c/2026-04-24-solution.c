// Timestamp: `Fri, 24 Apr 2026 10:14:40 +0530`
// Tags: [search, daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`
/// Timestamp: `Fri, 24 Apr 2026 10:14:40 +0530`

bool isValid(char *s) {
  const size_t n = strlen(s);
  char stack[n];
  size_t stackSize = 0;

  for (int i = 0; i < n; i++) {
    const char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      stack[stackSize++] = ch;
    }
    else if (ch == ')' || ch == '}' || ch == ']') {
      if (stackSize <= 0) {
        return false;
      }

      const char prevChar = stack[--stackSize];

      if (
        (ch == ')' && prevChar != '(') || 
        (ch == '}' && prevChar != '{') || 
        (ch == ']' && prevChar != '[')
      ) {
        return false;
      }
    }
  }

  return stackSize == 0;
}

/// }}
