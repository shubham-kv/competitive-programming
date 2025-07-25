/// {{
/// Problem: 412. Fizz Buzz
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/fizz-buzz/
/// Topics: `math`, `string`, `simulation`
/// Timestamp: `Fri, 25 Jul 2025 19:45:56 +0530`

struct Solution {}

impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut answers: Vec<String> = Vec::new();

        for i in 1..=n {
            let mut ans = String::new();

            if i % 3 == 0 {
                ans.push_str("Fizz");
            }
            if i % 5 == 0 {
                ans.push_str("Buzz");
            }
            if ans == "" {
                ans = i.to_string();
            }

            answers.push(String::from(ans));
        }

        return answers;
    }
}

fn main() {
    let num = 10;
    Solution::fizz_buzz(num);
    println!("Hello World!");
}

/// }}
