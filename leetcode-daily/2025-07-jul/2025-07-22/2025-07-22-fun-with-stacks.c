// Title: Fun with stacks
// Date: 2025-07-22
// Created: `Tue, 22 Jul 2025 12:24:14 +0530`
// Tags: [stacks, daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 1598. Crawler Log Folder
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/crawler-log-folder/
/// Topics: `array`, `string`, `stack`
/// Timestamp: `Tue, 22 Jul 2025 12:24:14 +0530`

#define IS_ALPHA_NUMERIC(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c <= '9'))

int minOperations(char **logs, int logsSize) {
  char *stack[logsSize];
  int stackSize = 0;

  for (int i = 0; i < logsSize; i++) {
    const char *log = logs[i];

    if (strcmp(log, "../") == 0) {
      if (stackSize > 0) {
        stack[--stackSize] = NULL;
      }
    }
    else if (strcmp(log, "./") == 0) {
    }
    else if (IS_ALPHA_NUMERIC(log[0])) {
      stack[stackSize++] = log;
    }
  }

  return stackSize;
}

/// }}


/// {{
/// Problem: 71. Simplify Path
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/simplify-path/
/// Topics: `string`, `stack`
/// Timestamp: `Tue, 22 Jul 2025 13:08:52 +0530`

#define IS_ALPHA(c) (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || (c == '_'))
#define IS_NUMERIC(c) ('0' <= c  && c <= '9')
#define IS_WORD_CHAR(c) (IS_ALPHA(c) || IS_NUMERIC(c) || c == '.')

char *simplifyPath(char *path) {
  const int pathLen = strlen(path);

  int outputSize = 0;
  char *output = calloc(pathLen + 1, sizeof(char));

  int stack[pathLen];
  memset(stack, 0, pathLen);
  int stackSize = 0;

  for (int i = 0; i < pathLen; i++) {
    if (path[i] == '/') {
      // Consume all slashes
      for (; i + 1 < pathLen && path[i + 1] == '/'; i++) { }

      if (outputSize == 0) {
        output[outputSize++] = '/';
      }
    }
    else if (path[i] == '.') {
      int tokenStart = i, tokenLen = 1;
      for (; i + 1 < pathLen && path[i + 1] == '.'; i++, tokenLen++) {}

      if (tokenLen == 2 && (path[i + 1] == '\0' || path[i + 1] == '/')) {
        if (stackSize > 0) {
          int lastPos = stack[stackSize - 1];
          stack[--stackSize] = 0;
          memset(&output[lastPos], 0, (pathLen - lastPos) * sizeof(char));
          outputSize = lastPos;
        }
      }
      else if (tokenLen == 1 && (path[i + 1] == '\0' || path[i + 1] == '/')) {
        // No op
      }
      else {
        stack[stackSize++] = outputSize;

        if (outputSize > 1) {
          output[outputSize++] = '/';
        }

        // Copy
        for (
          int j = tokenStart;
          j < tokenLen + 1;
          (output[outputSize++] = path[j]), j++
        ) {}

        for (
          ;
          i + 1 < pathLen && (IS_WORD_CHAR(path[i + 1]));
          (output[outputSize++] = path[i + 1]), i++
        ) { }
      }
    }
    else if (IS_ALPHA(path[i]) || IS_NUMERIC(path[i])) {
      stack[stackSize++] = outputSize;

      if (outputSize > 1) {
        output[outputSize++] = '/';
      }
      output[outputSize++] = path[i];

      for (
        ;
        i + 1 < pathLen && (IS_WORD_CHAR(path[i + 1]));
        (output[outputSize++] = path[i + 1]), i++
      ) { }
    }
  }

  return output;
}

/// }}
