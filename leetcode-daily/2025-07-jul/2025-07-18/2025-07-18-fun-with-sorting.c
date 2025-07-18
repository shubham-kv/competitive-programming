// Title: Fun with Sorting
// Date: 2025-07-18
// Created: Fri, 18 Jul 2025 18:58:26 +0530
// Tags: [sorting, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Fri, 18 Jul 2025 18:58:26 +0530`

int search(int *nums, int n, int target) {
  for (
    int low = 0, high = n - 1, mid = (low + high)/ 2;
    low <= high;
    mid = (low + high) / 2
  ) {
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
