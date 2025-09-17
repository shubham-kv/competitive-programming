// Title: Fun with heaps
// Date: 2025-09-17
// Created: `Wed, 17 Sep 2025 11:25:48 +0530`
// Tags: [heaps, daily-practice]

/**
 * @template T
 * @typedef {(a: T, b: T) => number} ComparatorFn
 */

/** @template K */
class MinPQ {
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
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) > 0) {
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
      if ((c + 1) < n && this.#keysCmp(this.#keys[c], this.#keys[c + 1]) > 0) {
        c = c + 1;
      }
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) > 0) {
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
  delMin() {
    const n = this.#keys.length;

    if (n <= 0) {
      return null;
    }

    const min = this.#keys[0];
    this.#keys[0] = this.#keys[n - 1];
    this.#keys.pop();
    this.#heapifyDown(0);
    return min;
  }

  /** @returns {K | null} */
  getMin() {
    const n = this.#keys.length;
    return n <= 0 ? null : this.#keys[0];
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
/// Problem: 658. Find K Closest Elements
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/find-k-closest-elements/
/// Topics: `array`, `two-pointers`, `binary-search`, `sliding-window`, `sorting`, `heap-(priority-queue)`
/// Timestamp: `Wed, 17 Sep 2025 11:25:48 +0530`

/** @type {(a: number, b: number) => number} */
const cmpNumber = (a, b) => a < b ? -1 : a > b ? 1 : 0;

/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
function findClosestElements (arr, k, x) {
  /** @type {MaxPQ<number>} */
  const maxPQ = new MaxPQ((a, b) => {
    const distA = Math.abs(a - x);
    const distB = Math.abs(b - x);
    const cmpDist = cmpNumber(distA, distB);

    if (cmpDist !== 0) {
      return cmpDist;
    }

    return cmpNumber(a, b);
  });

  for (const num of arr) {
    maxPQ.insert(num);

    if (maxPQ.size() > k) {
      maxPQ.delMax();
    }
  }

  /** @type {number[]} */
  const closestElements = [];

  while (!maxPQ.isEmpty()) {
    const num = maxPQ.delMax();
    closestElements.unshift(num);
  }

  closestElements.sort();

  return closestElements;
}

// # Notes
//
// Looks like there's room for improvement for this solution.
// Are there any ways to avoid the last `sort()` call ? or maybe use a
// different algorithm.
//
// #todo, #needs-improvement
// 

/// }}

