// Title: Fun with Graphs
// Date: 2025-08-12
// Created: `Tue, 12 Aug 2025 18:46:48 +0530`
// Tags: [linked-lists, daily-practice]

/// {{
/// Problem: 547. Number of Provinces
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/number-of-provinces/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Tue, 12 Aug 2025 21:35:08 +0530`

class QuickUnion {
  /** @type {number[]} */
  #entries;

  /** @type {number[]} */
  #sizes;

  /** @type {number} */
  #componentCount;

  /** @param {number} n */
  constructor(n) {
    this.#entries = Array(n).fill(0);
    this.#sizes = Array(n).fill(1);
    this.#componentCount = n;

    for (let i = 0; i < n; i++) {
      this.#entries[i] = i;
    }
  }

  /**
   * @param {number} p
   * @param {number} q
   */
  union(p, q) {
    const [rootP, rootQ] = [this.find(p), this.find(q)];

    if (rootP === rootQ) {
      return;
    }

    const [sizeP, sizeQ] = [this.#sizes[rootP], this.#sizes[rootQ]];

    if (sizeP < sizeQ) {
      this.#entries[rootP] = rootQ;
      this.#sizes[rootP] += this.#sizes[rootQ];
    } else {
      this.#entries[rootQ] = rootP;
      this.#sizes[rootQ] += this.#sizes[rootP];
    }
    this.#componentCount--;
  }

  /** @param {number} p */
  find(p) {
    while (this.#entries[p] != p) {
      this.#entries[p] = this.#entries[this.#entries[p]];
      p = this.#entries[p];
    }
    return p;
  }

  count() {
    return this.#componentCount;
  }
}

/**
 * @param {number[][]} isConnected
 * @return {number}
 */
function findCircleNum(isConnected) {
  const [rows, cols] = [isConnected.length, isConnected[0].length];
  const uf = new QuickUnion(rows);

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (isConnected[i][j] === 1) {
        uf.union(i, j);
      }
    }
  }

  return uf.count();
}

/// }}

