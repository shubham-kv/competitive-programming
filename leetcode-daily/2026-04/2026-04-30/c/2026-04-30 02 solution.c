#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Thu, 30 Apr 2026 11:23:05 +0530`

int binary_search(const int *arr, const int target, int low, int high) {
  while (low <= high) {
    const int mid = (low + high) / 2;

    if (target < arr[mid]) {
      high = mid - 1;
    } else if (target > arr[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int search(int *nums, int n, int target) {
  int i = 0;
  for (; i + 1 < n && nums[i] < nums[i + 1]; i++) { }

  int index = binary_search(nums, target, 0, i);

  if (index >= 0) {
    return index;
  }

  index = binary_search(nums, target, i + 1, n - 1);

  return index;
}

/// }}
