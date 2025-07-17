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


/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Thu, 17 Jul 2025 19:43:49 +0530`

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

int search(int *nums, int numsSize, int target) {
  int i;

  for (i = 0; (i + 1) < numsSize; i++) {
    if (nums[i + 1] < nums[i]) {
      break;
    }
  }

  int index = binarySearch(nums, 0, i, target);
  if (index > -1) {
    return index;
  }

  index = binarySearch(nums, i + 1, numsSize - 1, target);
  return index;
}

/// }}
