// Title: Fun with stacks
// Date: 2025-07-22
// Created: `Tue, 22 Jul 2025 12:24:14 +0530`
// Tags: [stacks, daily-practice]

#include <string.h>
#include <stdlib.h>

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
