// Title: Fun with Graphs
// Date: 2025-08-16
// Created: `Sat, 16 Aug 2025 21:18:53 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Sat, 16 Aug 2025 21:18:53 +0530`

class QuickUnion {
  /** @type {number[]} */
  #entries;

  /** @type {number[]} */
  #sizes;

  /** @param {number} n  */
  constructor(n) {
    this.#entries = Array(n).fill(1).map((_, i) => i);
    this.#sizes = Array(n).fill(1);
  }

  /** @param {number} p  */
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
    */
  union(p, q) {
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

  /**
    * @param {number} p
    * @param {number} q
    * @returns {boolean}
    */
  connected(p, q) {
    return this.#find(p) === this.#find(q);
  }
}

/**
 * @param {string[]} equations
 * @return {boolean}
 */
function equationsPossible(equations) {
  const capacity = 'z'.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
  const quickUnion = new QuickUnion(capacity);

  for (const equation of equations) {
    if (equation.charAt(1) === '=') {
      const p = equation.charCodeAt(0) - 'a'.charCodeAt(0);
      const q = equation.charCodeAt(3) - 'a'.charCodeAt(0);
      quickUnion.union(p, q);
    }
  }

  for (const equation of equations) {
    if (equation.charAt(1) === '!') {
      const p = equation.charCodeAt(0) - 'a'.charCodeAt(0);
      const q = equation.charCodeAt(3) - 'a'.charCodeAt(0);
      
      if (quickUnion.connected(p, q)) {
        return false;
      }
    }
  }

  return true;
}

/// }}

