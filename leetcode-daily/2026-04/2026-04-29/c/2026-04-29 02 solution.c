#include <assert.h>
#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Wed, 29 Apr 2026 21:28:51 +0530`

// Recursive Binary Search

int search_recursive(int *arr, int target, int low, int high) {
  if (!(low <= high)) {
    return -1;
  }

  const int mid = (low + high) / 2;

  if (target < arr[mid]) {
    return search_recursive(arr, target, low, mid - 1);
  } else if (target > arr[mid]) {
    return search_recursive(arr, target, mid + 1, high);
  } else {
    return mid;
  }
}

int search(int *nums, int n, int target) {
  const int low = 0, high = n - 1;
  return search_recursive(nums, target, low, high);
}

/// }}
