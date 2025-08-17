/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Sun, 17 Aug 2025 18:06:40 +0530`

class Graph {
  #vertices: number;
  #adjList: number[][];

  constructor(vertices: number) {
    this.#vertices = vertices;
    this.#adjList = Array(vertices).fill(0).map(() => []);
  }

  addEdge(v: number, w: number): void {
    this.#adjList[v].push(w);
    this.#adjList[w].push(v);
  }

  adjacent(v: number): number[] {
    return [...this.#adjList[v]];
  }

  get vertices(): number {
    return this.#vertices;
  }
}

class DFS {
  #graph: Graph;
  #visited: boolean[];

  constructor(graph: Graph, searchVertex: number) {
    this.#graph = graph;
    this.#visited = Array(graph.vertices).fill(false);
    this.#dfs(searchVertex);
  }

  #dfs(v: number): void {
    this.#visited[v] = true;
    for (const w of this.#graph.adjacent(v)) {
      if (!this.#visited[w]) {
        this.#dfs(w);
      }
    }
  }

  visited(v: number): boolean {
    return this.#visited[v];
  }
}

function charToIndex(ch: string): number {
  return ch.charCodeAt(0);
}

function equationsPossible(equations: string[]): boolean {
  const indexOfA = charToIndex('a');
  const n = charToIndex('z') - indexOfA + 1;
  const graph = new Graph(n);

  for (const eq of equations) {
    if (eq[1] === '=') {
      const v = charToIndex(eq[0]) - indexOfA;
      const w = charToIndex(eq[3]) - indexOfA;
      graph.addEdge(v, w);
    }
  }

  for (const eq of equations) {
    if (eq[1] === '!') {
      const v = charToIndex(eq[0]) - indexOfA;
      const w = charToIndex(eq[3]) - indexOfA;
      const dfs = new DFS(graph, v);

      if (dfs.visited(w)) {
        return false;
      }
    }
  }

  return true;
}

/// }}
