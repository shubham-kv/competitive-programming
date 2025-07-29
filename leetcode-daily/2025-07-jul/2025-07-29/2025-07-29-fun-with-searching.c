// Title: Fun with queues
// Date: 2025-07-29
// Created: `Tue, 29 Jul 2025 23:54:04 +0530`
// Tags: [queues, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Tue, 29 Jul 2025 23:54:04 +0530`

int binarySearch(int *arr, int low, int high, int target) {
  for (
    int mid = (low + high) / 2;
    low <= high;
    mid = (low + high) / 2
  ) {
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
  int i;
  for (i = 0; i + 1 < n && nums[i] < nums[i + 1]; i++) { }

  int index = binarySearch(nums, 0, i, target);

  if (index > -1) {
    return index;
  }

  return binarySearch(nums, i + 1, n - 1, target);
}

/// }}
