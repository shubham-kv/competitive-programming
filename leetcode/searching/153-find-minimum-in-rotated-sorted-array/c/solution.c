#include <stdlib.h>

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

