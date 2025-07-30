// Title: Fun with searching
// Date: 2025-07-30
// Created: `Wed, 30 Jul 2025 00:04:38 +0530`
// Tags: [searching, daily-practice]

/// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
/// Timestamp: `Wed, 30 Jul 2025 00:50:56 +0530`

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function search(nums, target) {
  const n = nums.length;

  for (
    let low = 0, high = n - 1;
    low <= high;
  ) {
    const mid = Math.floor((low + high) / 2);

    if (target < nums[mid]) {
      high = mid - 1;
    } else if (target > nums[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
};

/// }}


/// {{
/// Problem: 33. Search in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Wed, 30 Jul 2025 00:04:38 +0530`

/**
 * @param {number[]} arr 
 * @param {number} low
 * @param {number} high
 * @param {number} target
 */
function binarySearch(arr, low, high, target) {
  for (
    let mid = Math.floor((low + high) / 2);
    low <= high;
    mid = Math.floor((low + high) / 2)
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

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function search(nums, target) {
  const n = nums.length;
  let i;
  for (i = 0; i + 1 < n && nums[i] < nums[i + 1]; i++) {}

  let index = binarySearch(nums, 0, i, target);
  if (index > -1) {
    return index;
  }

  index = binarySearch(nums, i + 1, n - 1, target);
  return index;
};

/// }}


/// {{
/// Problem: 74. Search a 2D Matrix
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-a-2d-matrix/
/// Topics: `array`, `binary-search`, `matrix`
/// Timestamp: `Wed, 30 Jul 2025 01:17:35 +0530`

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
function searchMatrix(matrix, target) {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const n = rows * cols;

  for (
    let low = 0, high = n - 1;
    low <= high;
  ) {
    const mid = Math.floor((low + high) / 2);
    const rowIndex = Math.floor(mid / cols);
    const colIndex = mid % cols;
    const midVal = matrix[rowIndex][colIndex];

    if (target < midVal) {
      high = mid - 1;
    } else if (target > midVal) {
      low = mid + 1;
    } else {
      return true;
    }
  }

  return false;
};

/// }}


/// {{
/// Problem: 153. Find Minimum in Rotated Sorted Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
/// Topics: `array`, `binary-search`
/// Timestamp: `Wed, 30 Jul 2025 01:57:13 +0530`

/**
 * @param {number[]} nums
 * @return {number}
 */
function findMin(nums) {
  const n = nums.length;
  let low = 0, high = n - 1;

  while (low < high) {
    const mid = Math.floor((low + high) / 2);

    if (nums[mid] <= nums[high]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return nums[low];
};

// }}

