
// {{
// Problem: 74. Search a 2D Matrix
// Difficulty: `Medium`
// Links: https://leetcode.com/problems/search-a-2d-matrix/
// Topics: `array`, `binary-search`, `matrix`
// Timestamp: `Wed, 30 Jul 2025 01:17:35 +0530`

struct Solution;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows: i32 = matrix.len() as i32;
        let cols: i32 = matrix[0].len() as i32;
        let mut low: i32 = 0;
        let mut high: i32 = (rows * cols) as i32 - 1;

        while low <= high {
            let mid = (low + high) / 2;
            let row_index = mid / cols;
            let col_index = mid % cols;
            let mid_val = matrix[row_index as usize][col_index as usize];

            if target < mid_val {
                high = mid - 1;
            } else if target > mid_val {
                low = mid + 1;
            } else {
                return true;
            }
        }

        false
    }
}


// }}

fn main() {
    println!("Hello, world!");
}

