// Title: Fun with searching
// Date: 2026-04-23
// Created: Thu, 23 Apr 2026 14:42:05 +0530
// Tags: [search, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Thu, 23 Apr 2026 14:42:20 +0530`

int search(int *nums, int numsSize, int target) {
  int low = 0, high = numsSize -1;

  while (low <= high) {
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
