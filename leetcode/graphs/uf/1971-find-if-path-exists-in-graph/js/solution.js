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
