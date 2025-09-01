// Title: Fun with graphs
// Date: 2025-09-01
// Created: `Mon, 01 Sep 2025 15:03:39 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 547. Number of Provinces
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/number-of-provinces/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Mon, 01 Sep 2025 15:03:39 +0530`

class Graph {
  /** @type {number} */ #vertices;
  /** @type {number[][]} */ #adjList;

  constructor(/** @type {number} */ verticesCount) {
    this.#vertices = verticesCount;
    this.#adjList = Array(this.verticesCount).fill(0).map(() => []);
  }

  /** @returns {number} */
  get verticesCount() { return this.#vertices; }

  /** @returns {void} */
  addEdge(/** @type {number} */ v, /** @type {number} */ w) {
    this.#adjList[v].push(w);
    this.#adjList[w].push(v);
  }

  /** @returns {number[]} */
  adjList(/** @type {number} */ v) {
    return [...this.#adjList[v]];
  }
}

class ConnectedComponents {
  /** @type {number} */ #count;
  /** @type {boolean[]} */ #marked;

  constructor(/** @type {Graph} */ graph) {
    const verticesCount = graph.verticesCount;
    this.#count = 0;
    this.#marked = Array(verticesCount).fill(false);

    for (let s = 0; s < graph.verticesCount; s++) {
      if (!this.#marked[s]) {
        this.#dfs(graph, s);
        this.#count++;
      }
    }
  }

  #dfs(/** @type {Graph} */ graph, /** @type {number} */ v) {
    this.#marked[v] = true;

    for (const w of graph.adjList(v)) {
      if (!this.#marked[w]) {
        this.#dfs(graph, w);
      }
    }
  }

  /** @returns {number} */
  get count() {
    return this.#count;
  }
}

/**
 * @param {number[][]} isConnected
 * @return {number}
 */
function findCircleNum (isConnected) {
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

  const graphCC = new ConnectedComponents(graph);
  const componentsCount = graphCC.count;

  return componentsCount;
}

/// }}

