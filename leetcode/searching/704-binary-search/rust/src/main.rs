
// {{
/// Problem: 704. Binary Search
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/binary-search/
/// Topics: `array`, `binary-search`
// Timestamp: `Wed, 30 Jul 2025 00:44:30 +0530`

struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut low: i32 = 0;
        let mut high: i32 = (nums.len() - 1) as i32;

        while low <= high {
            let mid = (low + high) / 2;
            let mid_val = match nums.get(mid as usize) {
                Some(v) => *v,
                None => return -1
            };

            if target < mid_val {
                high = mid - 1;
            } else if target > mid_val {
                low = mid + 1;
            } else {
                return mid as i32;
            }
        }

        return -1;
    }
}

fn main() {
    let nums = Vec::from([1, 2, 3, 4]);
    let target = 0;
    let index = Solution::search(nums.clone(), target);
    dbg!(nums);
    println!("target: {target}, index: {index}");
}

// }}

