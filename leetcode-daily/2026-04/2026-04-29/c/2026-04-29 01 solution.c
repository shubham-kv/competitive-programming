#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Wed, 29 Apr 2026 21:22:04 +0530`

// Iteratve Binary Search

int search(int *nums, int n, int target) {
  int low = 0, high = n - 1;

  while (low <= high) {
    const int mid = (low + high) / 2;

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
