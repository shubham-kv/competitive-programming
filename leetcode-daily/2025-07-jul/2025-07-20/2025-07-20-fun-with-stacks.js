// Title: Fun with stacks
// Date: 2025-07-18
// Created: `Sun, 20 Jul 2025 18:17:01 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`
/// Timestamp: `Sun, 20 Jul 2025 18:17:41 +0530`

/**
 * @param {string} s
 * @return {boolean}
 */
function isValid(s) {
  const len = s.length;

  /** @type {string[]} */
  const stack = [];

  for (let i = 0; i < len; i++) {
    const ch = s.charAt(i);

    if (ch === "(" || ch === "{" || ch === "[") {
      stack.push(ch);
    } else if (ch === ")" || ch === "}" || ch === "]") {
      if (!(stack.length > 0)) {
        return false;
      }

      const popped = stack.pop();

      if (
        (popped === "(" && ch !== ")") ||
        (popped === "{" && ch !== "}") ||
        (popped === "[" && ch !== "]")
      ) {
        return false;
      }
    }
  }

  return stack.length === 0;
}

/// }}
