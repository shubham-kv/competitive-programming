// Title: Fun with stacks
// Date: 2025-07-23
// Created: `Wed, 23 Jul 2025 15:39:23 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 71. Simplify Path
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/simplify-path/
/// Topics: `string`, `stack`
/// Timestamp: `Wed, 23 Jul 2025 16:21:12 +0530`

const isAlpha = (c) => ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || (c == '_')
const isNumeric = (c) => ('0' <= c && c <= '9')
const isWordChar = (c) => isAlpha(c) || isNumeric(c) || (c == '.')

/**
 * @param {string} path
 * @return {string}
 */
function simplifyPath(path) {
  const pathLen = path.length;

  /** @type {string} */
  let output = '';

  /**
   * Stack of indices of inserted `/` in the output string after the first `/`.
   * @type {number[]}
   */
  const stack = [];

  for (let i = 0; i < pathLen; i++) {
    if (path[i] === '/') {
      // Consume all slashes
      for (; i + 1 < pathLen && path[i + 1] === '/'; i++) { }

      if (output.length < 1) {
        output = "/";
      }
    } else if (path[i] === '.') {
      let tokenStart = i, tokenLen = 1;

      // Consume all dots
      for (; i + 1 < pathLen && path[i + 1] === '.'; i++, tokenLen++) { }

      if (tokenLen === 1 && (i + 1 >= pathLen || path[i + 1] === '/')) {
        // No op
      }
      else if (tokenLen === 2 && (i + 1 >= pathLen || path[i + 1] === '/')) {
        // Pop from stack
        if (stack.length > 0) {
          const lastIndex = stack.pop();
          output = output.substring(0, lastIndex);
        }
      }
      else {
        stack.push(output.length);

        for (; i + 1 < pathLen && isWordChar(path[i + 1]); i++, tokenLen++) { }

        if (output.length > 1) {
          output += "/";
        }
        output += path.substring(tokenStart, tokenLen + 1);
      }
    } else if (isAlpha(path[i]) || isNumeric(path[i])) {
      let tokenStart = i, tokenLen = 1;
      stack.push(output.length);

      for (; i + 1 < pathLen && isWordChar(path[i + 1]); i++, tokenLen++) { }

      if (output.length > 1) {
        output += '/';
      }
      output += path.substring(tokenStart, tokenLen + 1);
    }
  }

  return output;
}

/// }}
