/**
 * @template T
 * @typedef {(a: T, b: T) => number} ComparatorFn
 */

/** @template T */
class MinPQ {
  /** @type {T[]} */ #keys;
  /** @type {ComparatorFn<T>} */ #keysCmp;

  constructor(
    /** @type {ComparatorFn<T>} */ keysCmp
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
    /** @type {T} */ key
  ) {
    this.#keys.push(key);
    this.#heapifyUp(this.#keys.length - 1);
  }

  /** @returns {T | null} */
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

  /** @returns {T | null} */
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

/// {{
/// Problem: 703. Kth Largest Element in a Stream
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/kth-largest-element-in-a-stream/
/// Topics: `tree`, `design`, `binary-search-tree`, `heap-(priority-queue)`, `binary-tree`, `data-stream`
/// Timestamp: `Sun, 14 Sep 2025 14:31:06 +0530`

/**
 * @param {number} k
 * @param {number[]} nums
 */
function KthLargest(k, nums) {
  /** @type {MinPQ<number>} */
  this.minPQ = new MinPQ((a, b) => a < b ? -1 : a > b ? 1 : 0);

  /** @type {number} */
  this.k = k;

  for (const key of nums) {
    this.minPQ.insert(key);

    if (this.minPQ.size() > this.k) {
      this.minPQ.delMin();
    }
  }
}

/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function(val) {
  this.minPQ.insert(val);

  if (this.minPQ.size() > this.k) {
    this.minPQ.delMin();
  }

  return this.minPQ.getMin();
}

/// }}

