// Title: Fun with searching
// Date: 2025-07-18
// Created: `Sat, 19 Jul 2025 10:27:12 +0530`
// Tags: [search, daily-practice]

#include <stdbool.h>
#include <stdint.h>
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


/// {{
/// Problem: 74. Search a 2D Matrix
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-a-2d-matrix/
/// Topics: `array`, `binary-search`, `matrix`
/// Timestamp: `Sat, 19 Jul 2025 11:00:58 +0530`

/**
 * matrix = [
 *   [0][0], [0][1], [0][2],
 *   [1][0], [1][1], [1][2],
 *   [2][0], [2][1], [2][2],
 * ]
 *
 * matrix = [
 *   [0], [1], [2],
 *   [3], [4], [5],
 *   [6], [7], [8],
 * ]
 *
 * rowIndex = mid / cols = 1 / 3 = 0
 * colIndex = mid % cols = 1 % 3 = 1

 * rowIndex = mid / cols = 4 / 3 = 1
 * colIndex = mid % cols = 4 % 3 = 1
 *
 * matrix = [
 *   [0][0], [0][1],
 * ]
 *
 * matrix = [
 *   0, 1
 * ]
 *
 * rowIndex = mid / cols = 0 / 2 = 0
 * colIndex = mid % cols = 0 % 2 = 0
 *
 * rowIndex = mid / cols = 1 / 2 = 0
 * colIndex = mid % cols = 1 % 2 = 1
 */
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
  int rows = matrixSize, cols = *matrixColSize;
  int n = rows * cols;
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int rowIndex = mid / cols, colIndex = mid % cols;

    if (target < matrix[rowIndex][colIndex]) {
      high = mid - 1;
    } else if (target > matrix[rowIndex][colIndex]) {
      low = mid + 1;
    } else {
      return true;
    }
  }

  return false;
}

/// }}


/// {{
/// Problem: 162. Find Peak Element
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/find-peak-element/
/// Topics: `array`, `binary-search`
/// Timestamp: `Sat, 19 Jul 2025 11:39:14 +0530`

int findPeakElement(int *nums, int n) {
  int low = 0, high = n - 1;
  int peak = low;

  while (low < high) {
    int mid = (low + high) / 2;
    int64_t left = (mid - 1 >= 0) ? nums[mid - 1] : INT64_MIN;
    int64_t right = (mid + 1 < n) ? nums[mid + 1] : INT64_MIN;

    if (nums[mid] > left && nums[mid] > right) {
      return mid;
    } else {
      high = mid;
    }
  }

  low = 0, high = n - 1;

  while (low < high) {
    int mid = (low + high) / 2;
    int64_t left = (mid - 1 >= 0) ? nums[mid - 1] : INT64_MIN;
    int64_t right = (mid + 1 < n) ? nums[mid + 1] : INT64_MIN;

    if (nums[mid] > left && nums[mid] > right) {
      return mid;
    } else {
      low = mid;
    }
  }

  return low;
}

/// }}
