/**
 * @template T
 * @typedef {(a: T, b: T) => number} ComparatorFn
 */

/** @template K */
class MaxPQ {
  /** @type {K[]} */ #keys;
  /** @type {ComparatorFn<K>} */ #keysCmp;

  constructor(
    /** @type {ComparatorFn<K>} */ keysCmp
  ) {
    this.#keysCmp = keysCmp;
    this.#keys = [];
  }

  /** @returns {void} */
  #swapKeysAtIndex(
    /** @type {number} */ i,
    /** @type {number} */ j,
  ) {
    [this.#keys[i], this.#keys[j]] = [this.#keys[j], this.#keys[i]];
  }

  /** @returns {void} */
  #heapifyUp(
    /** @type {number} */ c
  ) {
    for (
      let p = Math.floor((c - 1) / 2);
      p >= 0;
      c = p, p = Math.floor((c - 1) / 2)
    ) {
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) < 0) {
        this.#swapKeysAtIndex(p, c);
      } else {
        break;
      }
    }
  }

  /** @returns {void} */
  #heapifyDown(
    /** @type {number} */ p
  ) {
    const n = this.#keys.length;

    for (
      let c = Math.floor(2 * p + 1);
      c < n;
      p = c, c = Math.floor(2 * p + 1)
    ) {
      if ((c + 1) < n && this.#keysCmp(this.#keys[c], this.#keys[c + 1]) < 0) {
        c = c + 1;
      }
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) < 0) {
        this.#swapKeysAtIndex(p, c);
      } else {
        break;
      }
    }
  }

  /** @returns {void} */
  insert(
    /** @type {K} */ key
  ) {
    this.#keys.push(key);
    this.#heapifyUp(this.#keys.length - 1);
  }

  /** @returns {K | null} */
  delMax() {
    const n = this.#keys.length;

    if (n <= 0) {
      return null;
    }

    const max = this.#keys[0];
    this.#keys[0] = this.#keys[n - 1];
    this.#keys.pop();
    this.#heapifyDown(0);
    return max;
  }

  /** @returns {K | null} */
  getMax() {
    const n = this.#keys.length;
    return (n <= 0) ? null : this.#keys[0];
  }

  /** @returns {number} */
  size() {
    return this.#keys.length;
  }

  /** @returns {boolean} */
  isEmpty() {
    return this.size() === 0;
  }
}

/// {{
/// Problem: 1337. The K Weakest Rows in a Matrix
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
/// Topics: `array`, `binary-search`, `sorting`, `heap-(priority-queue)`, `matrix`
/// Timestamp: `Tue, 16 Sep 2025 11:24:49 +0530`

/**
 * @typedef {{count: number; index: number}} Item
 */

/** @type {(a: number, b: number) => number} */
const numericOrder = (a, b) => a < b ? -1 : a > b ? 1 : 0;

/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
function kWeakestRows(mat, k) {
  /** @type {MaxPQ<Item>} */
  const maxPQ = new MaxPQ((a, b) => {
    const count = numericOrder(a.count, b.count);
    if (count !== 0) {
      return count;
    }
    return numericOrder(a.index, b.index);
  });

  const rows = mat.length;

  for (let i = 0; i < rows; i++) {
    const row = mat[i];
    let count = 0;
    row.forEach(val => val === 1 && count++);

    maxPQ.insert({ index: i, count });

    if (maxPQ.size() > k) {
      maxPQ.delMax();
    }
  }

  /** @type {number[]} */
  const kWeakestIndices = [];

  while (!maxPQ.isEmpty()) {
    const item = maxPQ.delMax();
    kWeakestIndices.unshift(item.index);
  }

  return kWeakestIndices;
}

/// }}

