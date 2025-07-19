// Title: Fun with searching
// Date: 2025-07-18
// Created: `Sat, 19 Jul 2025 10:27:12 +0530`
// Tags: [search, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Sat, 19 Jul 2025 10:27:12 +0530`

int findMin(int *nums, int n) {
  int low = 0, high = n - 1;

  while (low < high) {
    int mid = (low + high) / 2;

    if (nums[mid] <= nums[high]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return nums[low];
}

/// }}
