// Title: Fun with graphs
// Date: 2025-09-03
// Created: `Wed, 03 Sep 2025 12:20:31 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Wed, 03 Sep 2025 12:20:31 +0530`

function addEdge(
  /** @type {number[][]} */ adjLists,
  /** @type {number} */ v,
  /** @type {number} */ w
) {
  adjLists[v].push(w);
  adjLists[w].push(v);
}

function dfs(
  /** @type {number[][]} */ adjLists,
  /** @type {boolean[]} */ marked,
  /** @type {number} */ v,
) {
  marked[v] = true;

  for (const w of adjLists[v]) {
    if (!marked[w]) {
      dfs(adjLists, marked, w);
    }
  }
}

function charToIndex(/** @type {string} */ str) {
  return str.charCodeAt(0);
}

/**
 * @param {string[]} equations
 * @return {boolean}
 */
function equationsPossible(equations) {
  /** @type {number} */
  const n = charToIndex('z') - charToIndex('a') + 1;

  /** @type {number[][]} */
  const adjLists = Array(n).fill(0).map(() => []);

  for (const equation of equations) {
    if (equation[1] === '=') {
      const v = charToIndex(equation[0]) - charToIndex('a');
      const w = charToIndex(equation[3]) - charToIndex('a');
      addEdge(adjLists, v, w);
    }
  }

  for (const equation of equations) {
    if (equation[1] === '!') {
      const v = charToIndex(equation[0]) - charToIndex('a');
      const w = charToIndex(equation[3]) - charToIndex('a');

      /** @type {boolean[]} */
      const marked = Array(n).fill(false);
      dfs(adjLists, marked, v);

      if (marked[w]) {
        return false;
      }
    }
  }

  return true;
}

/// }}
