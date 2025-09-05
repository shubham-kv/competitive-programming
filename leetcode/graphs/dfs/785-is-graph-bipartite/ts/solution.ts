/// {{
/// Problem: 785. Is Graph Bipartite?
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/is-graph-bipartite/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Fri, 05 Sep 2025 10:37:53 +0530`

class GraphBipartite {
  #marked: boolean[];
  #color: boolean[];
  #isBipartite: boolean = true;

  constructor(graph: number[][]) {
    const n = graph.length;
    this.#marked = Array(n).fill(false);
    this.#color = Array(n).fill(false);

    for (let v = 0; v < n; v++) {
      if (!this.#marked[v]) {
        this.#dfs(graph, v);
      }
    }
  }

  #dfs(graph: number[][], v: number): void {
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

  get isBipartite(): boolean {
    return this.#isBipartite;
  }
}

function isBipartite(graph: number[][]): boolean {
  return new GraphBipartite(graph).isBipartite;
}

/// }}

