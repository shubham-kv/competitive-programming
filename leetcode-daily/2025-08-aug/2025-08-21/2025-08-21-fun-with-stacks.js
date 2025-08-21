// Title: Fun with Stacks
// Date: 2025-08-21
// Created: `Thu, 21 Aug 2025 22:58:50 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`  
/// Timestamp: `Thu, 21 Aug 2025 22:58:50 +0530`

const openingToClosingBracketMap = {
  '(': ')',
  '{': '}',
  '[': ']'
};

const openingBrackets = Object.keys(openingToClosingBracketMap);
const closingBrackets = Object.values(openingToClosingBracketMap);

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

    if (openingBrackets.includes(ch)) {
      stack.push(ch);
    }
    else if (closingBrackets.includes(ch)) {
      if (!(stack.length > 0)) {
        return false;
      }

      const popped = stack.pop();
      if (openingToClosingBracketMap[popped] !== ch) {
        return false;
      }
    }
  }

  if (!(stack.length === 0)) {
    return false;
  }

  return true;
}

/// }}
