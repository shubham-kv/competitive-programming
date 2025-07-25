// Title: Fun with maths
// Date: 2025-07-25
// Created: `Fri, 25 Jul 2025 18:14:23 +0530`
// Tags: [maths, daily-practice]

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/// {{
/// Problem: 412. Fizz Buzz
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/fizz-buzz/
/// Topics: `math`, `string`, `simulation`
/// Timestamp: `Fri, 25 Jul 2025 18:14:23 +0530`

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize) {
  char **answers = calloc(n, sizeof(char *));
  const size_t bufferSize = 16;

  for (int i = 0; i < n; i++) {
    char *buffer = calloc(bufferSize, sizeof(char));
    const int num = i + 1;
    const bool divisibleBy3 = num % 3 == 0;
    const bool divisibleBy5 = num % 5 == 0;

    if (divisibleBy3 && divisibleBy5) {
      snprintf(buffer, bufferSize, "FizzBuzz");
    } else if (divisibleBy3) {
      snprintf(buffer, bufferSize, "Fizz");
    } else if (divisibleBy5) {
      snprintf(buffer, bufferSize, "Buzz");
    } else {
      snprintf(buffer, bufferSize, "%d", num);
    }

    answers[i] = buffer;
  }

  *returnSize = n;
  return answers;
}

/// }}
