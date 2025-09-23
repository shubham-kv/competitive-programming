// Title: Fun with stacks
// Date: 2025-09-23
// Created: `Tue, 23 Sep 2025 12:11:28 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Timestamp: `Tue, 23 Sep 2025 12:11:30 +0530`

const bracketsMap = {
  '(': ')',
  '{': '}',
  '[': ']'
};
type OpeningBracket = keyof typeof bracketsMap;

function isValid(s: string): boolean {
  const openingBrackets = Object.keys(bracketsMap) as OpeningBracket[];
  const closingBrackets = Object.values(bracketsMap);

  const stack: OpeningBracket[] = [];
  const n = s.length;

  for (let i = 0; i < n; i++) {
    const c = s.charAt(i);

    if (openingBrackets.includes(c as OpeningBracket)) {
      stack.push(c as OpeningBracket);
    }
    else if (closingBrackets.includes(c)) {
      const popped = stack.pop();
      if (popped === undefined) {
        return false;
      }

      if (!(bracketsMap[popped] === c)) {
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

