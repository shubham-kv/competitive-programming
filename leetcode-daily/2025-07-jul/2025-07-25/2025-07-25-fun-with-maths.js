// Title: Fun with maths
// Date: 2025-07-25
// Created: `Fri, 25 Jul 2025 18:42:29 +0530`
// Tags: [maths, daily-practice]

/// {{
/// Problem: 412. Fizz Buzz
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/fizz-buzz/
/// Topics: `math`, `string`, `simulation`
/// Timestamp: `Fri, 25 Jul 2025 18:42:29 +0530`

/**
 * @param {number} n
 * @return {string[]}
 */
function fizzBuzz(n) {
  /** @type {string[]} */
  const answers = [];

  for (let i = 0; i < n; i++) {
    const num = i + 1;
    let ans = "";

    if (num % 3 === 0) {
      ans += "Fizz";
    }
    if (num % 5 === 0) {
      ans += "Buzz";
    }
    if (ans === "") {
      ans = num.toString();
    }

    answers.push(ans);
  }

  return answers;
}

/// }}
