// Title: Fun with stacks
// Date: 2025-07-23
// Created: `Wed, 23 Jul 2025 15:39:23 +0530`
// Tags: [stacks, daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 71. Simplify Path
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/simplify-path/
/// Topics: `string`, `stack`
/// Timestamp: `Wed, 23 Jul 2025 15:39:23 +0530`

#define IS_ALPHA(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_')
#define IS_NUMERIC(c) ('0' <= c && c <= '9')
#define IS_WORD_CHAR(c) (IS_ALPHA(c) || IS_NUMERIC(c) || (c == '.'))

char *simplifyPath(char *path) {
  int pathLen = strlen(path);
  int stack[pathLen], stackSize = 0;

  char *output = calloc(pathLen + 1, sizeof(char));
  int outputSize = 0;

  for (int i = 0; i < pathLen; i++) {
    if (path[i] == '/') {
      // Consume all the slashes
      for (; i + 1 < pathLen && path[i + 1] == '/'; i++) { }

      // Add '/' only for the first time
      if (outputSize == 0) {
        output[outputSize++] = '/';
      }
    }
    else if (path[i] == '.') {
      // Consume all dots
      int tokenStart = i, tokenLen = 1;
      for (; i + 1 < pathLen && path[i + 1] == '.'; i++, tokenLen++) { }

      if (tokenLen == 1 && (path[i + 1] == '\0' || path[i + 1] == '/')) {
        // No op
      }
      else if (tokenLen == 2 && (path[i + 1] == '\0' || path[i + 1] == '/')) {
        // Pop the current name from the simplified path
        if (stackSize > 0) {
          int lastPos = stack[stackSize - 1];
          stack[--stackSize] = 0;
          memset(&output[lastPos], 0, (pathLen - lastPos) * sizeof(char));
          outputSize = lastPos;
        }
      }
      else {
        // Save the curent position onto stack
        stack[stackSize++] = outputSize;

        // Consume all alphanumeric, '_' & '.' characters
        for (; i + 1 < pathLen && IS_WORD_CHAR(path[i + 1]); i++, tokenLen++) { }

        if (outputSize > 1) {
          output[outputSize++] = '/';
        }

        strncpy(&output[outputSize], &path[tokenStart], tokenLen);
        outputSize += tokenLen;
      }
    }
    else if (IS_ALPHA(path[i]) || IS_NUMERIC(path[i])) {
      int tokenStart = i, tokenLen = 1;

      // Save the curent position onto stack
      stack[stackSize++] = outputSize;

      // Consume all alphanumeric, '_' & '.' characters
      for (; i + 1 < pathLen && IS_WORD_CHAR(path[i + 1]); i++, tokenLen++) { }

      if (outputSize > 1) {
        output[outputSize++] = '/';
      }

      strncpy(&output[outputSize], &path[tokenStart], tokenLen);
      outputSize += tokenLen;
    }
  }

  return output;
}

/// }}
