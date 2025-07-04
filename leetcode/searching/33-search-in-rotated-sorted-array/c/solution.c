#include <stdlib.h>

/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Fri, 04 Jul 2025 18:33:38 +0530`

int binarySearch(int *nums, int target, int low, int high) {
  if (!(low <= high)) {
    return -1;
  }

  int mid = (low + high) / 2;

  if (target < nums[mid]) {
    return binarySearch(nums, target, low, mid - 1);
  } else if (target > nums[mid]) {
    return binarySearch(nums, target, mid + 1, high);
  } else {
    return mid;
  }
}

int search(int* nums, int numsSize, int target) {
  int low = 0, high = numsSize - 1;
  int i = 0;

  for (i = 1; i < numsSize; i++) {
    if (nums[i - 1] > nums[i]) {
      break;
    }
  }

  int index = binarySearch(nums, target, low, i - 1);

  if (index > -1) {
    return index;
  }

  index = binarySearch(nums, target, i, high);

  return index;
}

/// }}

