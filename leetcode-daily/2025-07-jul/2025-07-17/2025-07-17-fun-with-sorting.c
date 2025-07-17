// Title: Fun with Sorting
// Date: 2025-07-17
// Created: Thu, 17 Jul 2025 19:37:27 +0530
// Tags: [sorting, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Thu, 17 Jul 2025 19:38:31 +0530`

int search(int *nums, int numsSize, int target) {
  int n = numsSize;

  for (int low = 0, high = n - 1; low <= high; ) {
    int mid = (low + high) / 2;

    if (target < nums[mid]) {
      high = mid - 1;
    } else if (target > nums[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

/// }}
