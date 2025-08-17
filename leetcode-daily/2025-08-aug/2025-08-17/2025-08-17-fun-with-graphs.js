// Title: Fun with Graphs
// Date: 2025-08-17
// Created: `Sun, 17 Aug 2025 16:44:43 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Sun, 17 Aug 2025 16:44:43 +0530`

class Graph {
  /** @type {number[][]} */ #adjList;
  /** @type {number} */ #vertices;

  /** @param {number} vertices  */
  constructor(vertices) {
    this.#vertices = vertices;
    this.#adjList = Array(vertices).fill([]).map(() => []);
  }

  /**
   * @param {number} v 
   * @param {number} w
   */
  addEdge(v, w) {
    if (!(0 <= v && v < this.#vertices)) {
      throw new Error(`Invalid v:${v}`);
    }
    if (!(0 <= w && w < this.#vertices)) {
      throw new Error(`Invalid w:${w}`);
    }
    this.#adjList[v].push(w);
    this.#adjList[w].push(v);
  }

  /**
   * @param {number} v 
   * @returns {number[]}
   */
  adjacent(v) {
    if (!(0 <= v && v < this.#vertices)) {
      throw new Error(`Invalid v:{v}`);
    }
    return [...this.#adjList[v]];
  }

  get vertices() {
    return this.#vertices;
  }
}

class DFS {
  /** @type {Graph} */ #graph;
  /** @type {boolean[]} */ #visited;

  /**
   * @param {Graph} graph 
   * @param {number} source
   */
  constructor(graph, source) {
    if (!(0 <= source && source < graph.vertices)) {
      throw new Error(`Invalid source vertex ${source}`);
    }

    this.#graph = graph;
    this.#visited = Array(graph.vertices).fill(false);
    this.#dfs(source);
  }

  /** @param {number} v  */
  #dfs(v) {
    if (!(0 <= v && v < this.#graph.vertices)) {
      throw new Error(`Invalid v:${v}`);
    }
    this.#visited[v] = true;

    for (const w of this.#graph.adjacent(v)) {
      if (!this.#visited[w]) {
        this.#dfs(w);
      }
    }
  }

  /**
   * @param {number} v
   * @returns {boolean}
   */
  marked(v) {
    if (!(0 <= v && v < this.#graph.vertices)) {
      throw new Error(`Invalid v:${v}`);
    }
    return this.#visited[v];
  }
}

/**
  * @param {string} ch
  * @returns {number}
  */
function charToIndex(ch) {
  return ch.charCodeAt(0);
}

/**
 * @param {string[]} equations
 * @return {boolean}
 */
function equationsPossible(equations) {
  const n = charToIndex('z') - charToIndex('a') + 1;
  const graph = new Graph(n);

  for (const eq of equations) {
    if (eq[1] === '=') {
      const v = charToIndex(eq[0]) - charToIndex('a');
      const w = charToIndex(eq[3]) - charToIndex('a');
      graph.addEdge(v, w);
    }
  }

  for (const eq of equations) {
    if (eq[1] === '!') {
      const v = charToIndex(eq[0]) - charToIndex('a');
      const w = charToIndex(eq[3]) - charToIndex('a');
      const dfs = new DFS(graph, v);

      if (dfs.marked(w)) {
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
/// Timestamp: `Sun, 17 Aug 2025 19:05:23 +0530`

class QuickUnion {
  /** @type {number[]} */ #entries;
  /** @type {number[]} */ #sizes;

  constructor(/** @type {number} */ n) {
    this.#entries = Array(n).fill(1).map((_, i) => i);
    this.#sizes = Array(n).fill(1);
  }

  #find(/** @type {number} */ p) {
    while (this.#entries[p] != p) {
      this.#entries[p] = this.#entries[this.#entries[p]];
      p = this.#entries[p];
    }
    return p;
  }

  union(/** @type {number} */ p, /** @type {number} */ q) {
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

  /** @returns {boolean} */
  connected(/** @type {number} */ p, /** @type {number} */ q) {
    return this.#find(p) === this.#find(q);
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
  const quickUnion = new QuickUnion(n);

  for (const edge of edges) {
    quickUnion.union(edge[0], edge[1]);
  }

  return quickUnion.connected(source, destination);
}

/// }}

