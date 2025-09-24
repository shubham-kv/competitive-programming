// Title: Fun with stacks
// Date: 2025-09-24
// Created: `Wed, 24 Sep 2025 11:19:00 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 71. Simplify Path
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/simplify-path/
/// Timestamp: `Wed, 24 Sep 2025 12:24:32 +0530`

/**
 * @param {string} path
 * @return {string}
 */
function simplifyPath(path) {
  /** @type {string[]} */
  const stack = [];

  for (const name of path.split('/')) {
    if (!name || name === '.') {
      continue;
    } else if (name === '..') {
      stack.pop();
    } else {
      stack.push(name);
    }
  }

  return '/' + stack.join('/');
}

/// }}

