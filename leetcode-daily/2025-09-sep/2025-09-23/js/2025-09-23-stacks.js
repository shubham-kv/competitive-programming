// Title: Fun with stacks
// Date: 2025-09-23
// Created: `Tue, 23 Sep 2025 11:05:03 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Timestamp: `Tue, 23 Sep 2025 11:09:11 +0530`

/**
 * @param {string} s
 * @return {boolean}
 */
function isValid(s) {
  /** @type {string[]} */
  const stack = [];

  const bracketsMap = {
    '(': ')',
    '{': '}',
    '[': ']'
  };
  const openingBrackets = Object.keys(bracketsMap);
  const closingBrackets = Object.values(bracketsMap);

  for (const ch of s) {
    if (openingBrackets.includes(ch)) {
      stack.push(ch);
    }
    else if (closingBrackets.includes(ch)) {
      const poppedCh = stack.pop();
      if (!poppedCh) {
        return false;
      }

      if (bracketsMap[poppedCh] !== ch) {
        return false;
      }
    }
  }

  if (stack.length > 0) {
    return false;
  }

  return true;
}

/// }}

