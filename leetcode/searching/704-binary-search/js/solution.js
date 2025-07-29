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
