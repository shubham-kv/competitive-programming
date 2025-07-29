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