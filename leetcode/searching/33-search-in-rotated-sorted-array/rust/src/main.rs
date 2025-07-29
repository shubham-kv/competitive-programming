
// {{
// Problem: 33. Search in Rotated Sorted Array
// Difficulty: `Medium`
// Links: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Topics: `array`, `binary-search`
// Timestamp: `Wed, 30 Jul 2025 01:02:21 +0530`

struct Solution;

impl Solution {
    fn binary_search(nums: &Vec<i32>, mut low: i32, mut high: i32, target: i32) -> Option<i32> {
        while low <= high {
            let mid = (low + high) / 2;
            let mid_val: i32 = match nums.get(mid as usize) {
                None => return None,
                Some(v) => *v
            };

            if target < mid_val {
                high = mid - 1;
            } else if target > mid_val {
                low = mid + 1;
            } else {
                return Some(mid);
            }
        }
        None
    }

    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut i: i32 = 0;
        let n: i32 = nums.len() as i32;

        while i + 1 < n && nums[i as usize] < nums[(i + 1) as usize] {
            i += 1;
        }

        match Self::binary_search(&nums, 0, i, target) {
            Some(v) => v,
            None => {
                match Self::binary_search(&nums, i + 1, n - 1, target) {
                    Some(v) => v,
                    None => -1
                }
            }
        }
    }
}


fn main() {
    println!("Hello, world!");
}

// }}

