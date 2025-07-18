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


/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Fri, 18 Jul 2025 19:05:15 +0530`

int binarySearch(int *arr, int target, int low, int high) {
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

  for (i = 0; (i + 1) < n; i++) {
    if (nums[i + 1] < nums[i]) {
      break;
    }
  }

  int index = binarySearch(nums, target, 0, i);

  if (index > -1) {
    return index;
  }

  index = binarySearch(nums, target, i + 1, n - 1);
  return index;
}

/// }}
