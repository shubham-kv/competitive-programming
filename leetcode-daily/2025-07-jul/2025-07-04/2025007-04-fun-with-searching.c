// Title: Fun with searching
// Date: 2025-07-04
// Created: Fri, 04 Jul 2025 16:15:57 +0530
// Tags: [search, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Fri, 04 Jul 2025 16:15:57 +0530`

// Solution 1: Iterative

int search(int* nums, int numsSize, int target) {
  int low = 0, high = numsSize - 1;

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

// Solution 2: Recursive

int searchRecursive(int *nums, int target, int low, int high) {
  if (low <= high) {
    int mid = (low + high) / 2;

    if (target < nums[mid]) {
      return searchRecursive(nums, target, low, mid - 1);
    } else if (target > nums[mid]) {
      return searchRecursive(nums, target, mid + 1, high);
    } else {
      return mid;
    }
  } else {
    return -1;
  }
}

int search(int* nums, int numsSize, int target) {
  int low = 0, high = numsSize - 1;

  return searchRecursive(nums, target, low, high);
}

/// }}


/// {{
/// Problem: 153. Find Minimum in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Fri, 04 Jul 2025 18:17:54 +0530`

int findMin(int* nums, int numsSize) {
  int low = 0, high = numsSize - 1;
  int min = nums[low];

  while (low <= high) {
    int mid = (low + high) / 2;

    if (nums[low] <= nums[mid]) {
      if (nums[mid] <= nums[high]) {
        min = nums[low];
        break;
      } else {
        low = mid + 1;
      }
    } else {
      low = low + 1;
    }
  }

  return min;
}

/// }}

