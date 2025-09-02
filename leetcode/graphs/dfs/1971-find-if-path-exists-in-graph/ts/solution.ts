/// {{
/// Problem: 1971. Find if Path Exists in Graph
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Tue, 02 Sep 2025 13:25:06 +0530`

function dfs(adjLists: number[][], marked: boolean[], v: number) {
  marked[v] = true;

  for (const w of adjLists[v]) {
    if (!marked[w]) {
      dfs(adjLists, marked, w);
    }
  }
}

function validPath(
  n: number,
  edges: number[][],
  source: number,
  destination: number
): boolean {
  const adjLists: number[][] = Array(n).fill(0).map(() => []);
  const marked: boolean[] = Array(n).fill(false);

  for (const [v, w] of edges) {
    adjLists[v].push(w);
    adjLists[w].push(v);
  }

  dfs(adjLists, marked, source);

  return marked[destination];
}

/// }}

