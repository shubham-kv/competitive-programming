// Title: Fun with stacks
// Date: 2025-07-01
// Created: Tue, 01 Jul 2025 12:09:01 +0530
// Tags: [stacks, daily-practice]

#include <stdlib.h>
#include <string.h>

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
