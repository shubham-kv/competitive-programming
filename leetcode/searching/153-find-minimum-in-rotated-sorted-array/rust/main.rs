
// {{
// Problem: 153. Find Minimum in Rotated Sorted Array
// Difficulty: `Medium`
// Links: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Topics: `array`, `binary-search`
// Timestamp: `Wed, 30 Jul 2025 02:08:15 +0530`

struct Solution;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut low: i32 = 0;
        let mut high: i32 = nums.len() as i32 - 1;
        let mut mid: i32;

        while low < high {
            mid = (low + high) / 2;

            if nums[mid as usize] <= nums[high as usize] {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return nums[low as usize];
    }
}

// }}

fn main() {
    println!("Hello, world!");
}

