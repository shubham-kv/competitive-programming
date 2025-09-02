// Title: Fun with graphs
// Date: 2025-09-02
// Created: `Tue, 02 Sep 2025 12:56:22 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 1971. Find if Path Exists in Graph
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
/// Timestamp: `Tue, 02 Sep 2025 12:56:22 +0530`

class Graph {
  /** @type {number} */ #verticesCount;
  /** @type {number[][]} */ #adjLists;

  constructor(/** @type {number} */ verticesCount) {
    this.#verticesCount = verticesCount;
    this.#adjLists = Array(verticesCount).fill(0).map(() => []);
  }

  /** @returns {number} */
  get verticesCount() { return this.#verticesCount; }

  /** @returns {void} */
  addEdge(/** @type {number} */ v, /** @type {number} */ w) {
    this.#adjLists[v].push(w);
    this.#adjLists[w].push(v);
  }

  /** @returns {number[]} */
  adjList(/** @type {number} */ v) {
    return [...this.#adjLists[v]];
  }
}

class GraphDFS {
  /** @type {boolean[]} */ #marked;

  constructor(/** @type {Graph} */ graph, /** @type {number} */ s) {
    const verticesCount = graph.verticesCount;
    this.#marked = Array(verticesCount).fill(false);
    this.#dfs(graph, s);
  }

  #dfs(/** @type {Graph} */ graph, /** @type {number} */ v) {
    this.#marked[v] = true;

    for (const w of graph.adjList(v)) {
      if (!this.#marked[w]) {
        this.#dfs(graph, w);
      }
    }
  }

  /** @returns {boolean} */
  marked(/** @type {number} */ v) {
    return this.#marked[v];
  }
}

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
function validPath(n, edges, source, destination) {
  const graph = new Graph(n);

  for (const edge of edges) {
    graph.addEdge(edge[0], edge[1]);
  }

  const dfs = new GraphDFS(graph, source);
  return dfs.marked(destination);
}

/// }}

