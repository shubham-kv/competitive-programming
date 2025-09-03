// Title: Fun with graphs
// Date: 2025-09-03
// Created: `Wed, 03 Sep 2025 13:01:03 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Wed, 03 Sep 2025 13:01:03 +0530`

function addEdge(adjLists: number[][], v: number, w: number): void {
  adjLists[v].push(w);
  adjLists[w].push(v);
}

function dfs(adjLists: number[][], marked: boolean[], v: number): void {
  marked[v] = true;

  for (const w of adjLists[v]) {
    if (!marked[w]) {
      dfs(adjLists, marked, w);
    }
  }
}

function charToIndex(str: string): number {
  return str.charCodeAt(0);
}

function equationsPossible(equations: string[]): boolean {
  const n: number = charToIndex('z') - charToIndex('a') + 1;
  const adjLists: number[][] = Array(n).fill([]).map(() => []);

  for (const eq of equations) {
    if (eq[1] === '=') {
      const v = charToIndex(eq[0]) - charToIndex('a');
      const w = charToIndex(eq[3]) - charToIndex('a');
      addEdge(adjLists, v, w);
    }
  }

  for (const eq of equations) {
    if (eq[1] === '!') {
      const v = charToIndex(eq[0]) - charToIndex('a');
      const w = charToIndex(eq[3]) - charToIndex('a');
      const marked: boolean[] = Array(n).fill(false);
      dfs(adjLists, marked, v);

      if (marked[w]) {
        return false;
      }
    }
  }

  return true;
}

/// }}
