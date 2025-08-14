/// {{
/// Problem: 684. Redundant Connection
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/redundant-connection/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Thu, 14 Aug 2025 19:59:30 +0530`

class QuickUnion {
  /** @type {number[]} */
  #entries;

  /** @type {number[]} */
  #sizes;

  /** @param {number} n */
  constructor(n) {
    this.#entries = Array(n).fill(1).map((_, i) => i);
    this.#sizes = Array(n).fill(1);
  }

  /**
    * @param {number} p
    * @returns {number}
    */
  #find(p) {
    while (this.#entries[p] != p) {
      this.#entries[p] = this.#entries[this.#entries[p]];
      p = this.#entries[p];
    }
    return p;
  }

  /**
    * @param {number} p
    * @param {number} q
    * @returns {boolean}
    */
  union(p, q) {
    const rootP = this.#find(p);
    const rootQ = this.#find(q);

    if (rootP === rootQ) {
      return false;
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

    return true;
  }
}

/**
 * @param {number[][]} edges
 * @return {number[]}
 */
function findRedundantConnection (edges) {
  const n = edges.length;
  const quickUnion = new QuickUnion(n + 1);

  /** @type {number[]} */
  let redundantEdge = [];

  for (const edge of edges) {
    if (!quickUnion.union(edge[0], edge[1])) {
      redundantEdge = edge;
    }
  }

  return redundantEdge;
}

/// }}

