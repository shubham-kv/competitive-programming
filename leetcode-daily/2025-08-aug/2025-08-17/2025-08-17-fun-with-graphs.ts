// Title: Fun with Graphs
// Date: 2025-08-17
// Created: `Sun, 17 Aug 2025 18:06:40 +0530`
// Tags: [graphs, daily-practice]

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


/// {{
/// Problem: 1971. Find if Path Exists in Graph
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
/// Timestamp: `Sun, 17 Aug 2025 19:18:38 +0530`

class QuickUnion {
  #entries: number[];
  #sizes: number[];

  constructor(n: number) {
    this.#entries = Array(n).fill(0).map((_, i) => i);
    this.#sizes = Array(n).fill(1);
  }

  #find(p: number): number {
    while (this.#entries[p] !== p) {
      this.#entries[p] = this.#entries[this.#entries[p]];
      p = this.#entries[p];
    }
    return p;
  }

  union(p: number, q: number): void {
    const rootP = this.#find(p);
    const rootQ = this.#find(q);

    if (rootP === rootQ) {
      return;
    }

    const sizeP = this.#sizes[rootP];
    const sizeQ = this.#sizes[rootQ];

    if (sizeP < sizeQ) {
      this.#entries[rootP] = rootQ;
      this.#sizes[rootQ] += sizeP;
    } else {
      this.#entries[rootQ] = rootP;
      this.#sizes[rootP] += sizeQ;
    }
  }

  connected(p: number, q: number): boolean {
    return this.#find(p) === this.#find(q);
  }
}

function validPath(
  n: number,
  edges: number[][],
  source: number,
  destination: number
): boolean {

  const quickUnion = new QuickUnion(n);

  for (const edge of edges) {
    quickUnion.union(edge[0], edge[1]);
  }

  return quickUnion.connected(source, destination);
};

/// }}

