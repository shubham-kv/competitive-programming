// Title: Fun with stacks
// Date: 2025-09-24
// Created: `Wed, 24 Sep 2025 11:19:13 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 71. Simplify Path
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/simplify-path/
/// Timestamp: `Wed, 24 Sep 2025 11:22:08 +0530`

function simplifyPath(path: string): string {
  const stack: string[] = [];

  for (const token of path.split("/")) {
    if (token === "" || token === ".") {
      continue;
    } else if (token === "..") {
      stack.pop();
    } else {
      stack.push(token);
    }
  }

  const simplifiedPath = "/" + stack.join('/');
  return simplifiedPath;
}

/// }}

