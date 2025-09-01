// Title: Fun with graphs
// Date: 2025-09-01
// Created: `Mon, 01 Sep 2025 15:33:46 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 547. Number of Provinces
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/number-of-provinces/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Mon, 01 Sep 2025 15:33:46 +0530`

class Graph {
  #verticesCount: number;
  #adjLists: number[][];

  constructor(verticesCount: number) {
    this.#verticesCount = verticesCount;
    this.#adjLists = Array(verticesCount).fill(0).map(() => []);
  }

  get verticesCount() { return this.#verticesCount; }

  addEdge(v: number, w: number) {
    this.#adjLists[v].push(w);
    this.#adjLists[w].push(v);
  }

  adjList(v: number) {
    return [...this.#adjLists[v]];
  }
}

class GraphCC {
  #count: number
  #marked: boolean[];

  constructor(graph: Graph) {
    const verticesCount = graph.verticesCount;
    this.#count = 0;
    this.#marked = Array(verticesCount).fill(false);

    for (let v = 0; v < verticesCount; v++) {
      if (!this.#marked[v]) {
        this.#dfs(graph, v);
        this.#count++;
      }
    }
  }

  get count() { return this.#count; }

  #dfs(graph: Graph, v: number) {
    this.#marked[v] = true;

    for (const w of graph.adjList(v)) {
      if (!this.#marked[w]) {
        this.#dfs(graph, w);
      }
    }
  }
}

function findCircleNum(isConnected: number[][]): number {
  const rows = isConnected.length;
  const cols = isConnected[0].length;
  const graph = new Graph(rows);

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (isConnected[i][j] === 1) {
        graph.addEdge(i, j);
      }
    }
  }

  const graphCC = new GraphCC(graph);
  const componentsCount = graphCC.count;

  return componentsCount;
};

/// }}

