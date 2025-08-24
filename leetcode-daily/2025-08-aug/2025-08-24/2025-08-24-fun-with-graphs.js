// Title: Fun with Graphs
// Date: 2025-08-24
// Created: `Sun, 24 Aug 2025 15:57:57 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 1971. Find if Path Exists in Graph
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
/// Timestamp: `Sun, 24 Aug 2025 15:57:57 +0530`

class Graph1 {
  /** @type {number} */ #vertices;
  /** @type {number[][]} */ #adjLists;

  constructor(/** @type {number} */ nOfVertices) {
    this.#vertices = nOfVertices;
    this.#adjLists = Array(nOfVertices).fill(0).map(() => [])
  }

  get vertices() { return this.#vertices; }

  /** @returns {boolean} */
  vertexInRange(/** @type {number} */ v) {
    return 0 <= v && v < this.#vertices;
  }

  addEdge(/** @type {number} */ v, /** @type {number} */ w) {
    if (this.vertexInRange(v) && this.vertexInRange(w)) {
      this.#adjLists[v].push(w);
      this.#adjLists[w].push(v);
    }
  }

  /** @returns {number[]} */
  adjList(/** @type {number} */ v) {
    return this.vertexInRange(v) ? [...this.#adjLists[v]] : []
  }
}

class DepthFirstSearch {
  /** @type {Graph1} */ #graph;
  /** @type {boolean[]} */ #visited;

  constructor(/** @type {Graph1} */ graph, /** @type {number} */ sourceVertex) {
    this.#graph = graph;
    this.#visited = Array(graph.vertices).fill(false);
    this.#dfsRecursive(this.#graph, sourceVertex);
  }

  /** @returns {boolean} */
  visited(/** @type {number} */ v) {
    return this.#graph.vertexInRange(v) ? this.#visited[v] : false;
  }

  #dfsRecursive(/** @type {Graph1} */ graph, /** @type {number} */ v) {
    if (!graph.vertexInRange(v)) { return; }
    this.#visited[v] = true;

    for (const w of graph.adjList(v)) {
      if (!this.#visited[w]) {
        this.#dfsRecursive(graph, w);
      }
    }
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
  const graph = new Graph1(n);

  for (const edge of edges) {
    graph.addEdge(edge[0], edge[1]);
  }

  const dfs = new DepthFirstSearch(graph, source);
  return dfs.visited(destination);
}

/// }}


/// {{
/// Problem: 547. Number of Provinces
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/number-of-provinces/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Sun, 24 Aug 2025 15:57:57 +0530`

class Graph {
  /** @type {number} */ #vertices;
  /** @type {number[][]} */ #adjLists;

  constructor(/** @type {number} */ nOfVertices) {
    this.#vertices = nOfVertices;
    this.#adjLists = Array(nOfVertices).fill(0).map(() => [])
  }

  get vertices() { return this.#vertices; }

  /** @returns {boolean} */
  vertexInRange(/** @type {number} */ v) {
    return 0 <= v && v < this.#vertices;
  }

  addEdge(/** @type {number} */ v, /** @type {number} */ w) {
    if (this.vertexInRange(v) && this.vertexInRange(w)) {
      this.#adjLists[v].push(w);
      this.#adjLists[w].push(v);
    }
  }

  /** @returns {number[]} */
  adjList(/** @type {number} */ v) {
    return this.vertexInRange(v) ? [...this.#adjLists[v]] : []
  }
}

class ConnectedComponents {
  /** @type {number} */ #count;
  /** @type {number[]} */ #id;
  /** @type {boolean[]} */ #marked;

  constructor(/** @type {Graph} */ graph) {
    this.#count = 0;
    this.#id = Array(graph.vertices).fill(0).map((_, i) => i);
    this.#marked = Array(graph.vertices).fill(false);

    for (let s = 0; s < graph.vertices; s++) {
      if (!this.#marked[s]) {
        this.#dfsRecursive(graph, s);
        this.#count++;
      }
    }
  }

  #dfsRecursive(/** @type {Graph} */ graph, /** @type {number} */ v) {
    if (!graph.vertexInRange(v)) { return; }
    this.#marked[v] = true;
    this.#id[v] = this.#count;

    for (const w of graph.adjList(v)) {
      if (!this.#marked[w]) {
        this.#dfsRecursive(graph, w);
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
function findCircleNum(isConnected) {
  const rows = isConnected.length;
  const cols = isConnected[0].length;

  const graph = new Graph(cols);

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (i !== j && isConnected[i][j] === 1) {
        graph.addEdge(i, j);
      }
    }
  }

  const cc = new ConnectedComponents(graph);
  return cc.count;
}

/// }}

