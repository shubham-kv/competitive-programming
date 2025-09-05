// Title: Fun with graphs
// Date: 2025-09-05
// Created: `Fri, 05 Sep 2025 09:54:30 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 785. Is Graph Bipartite?
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/is-graph-bipartite/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Fri, 05 Sep 2025 09:54:30 +0530`

class Bipartite {
  /** @type {boolean[]} */ #marked;
  /** @type {boolean[]} */ #color;
  /** @type {boolean} */ #isBipartite;

  constructor(
    /** @type {number[][]} */ graph,
  ) {
    const n = graph.length;
    this.#marked = Array(n).fill(false);
    this.#color = Array(n).fill(false);
    this.#isBipartite = true;

    for (let v = 0; v < n; v++) {
      if (!this.#marked[v]) {
        this.#dfs(graph, v);
      }
    }
  }

  /** @returns {void} */
  #dfs(
    /** @type {number[][]} */ graph,
    /** @type {number} */ v,
  ) {
    this.#marked[v] = true;

    for (const w of graph[v]) {
      if (!this.#marked[w]) {
        this.#color[w] = !this.#color[v];
        this.#dfs(graph, w);
      } else {
        if (this.#color[w] === this.#color[v]) {
          this.#isBipartite = false;
        }
      }
    }
  }

  /** @returns {boolean} */
  get isBipartite() {
    return this.#isBipartite;
  }
}

/**
 * @param {number[][]} graph
 * @return {boolean}
 */
function isBipartite(graph) {
  return new Bipartite(graph).isBipartite;
}

/// }}

