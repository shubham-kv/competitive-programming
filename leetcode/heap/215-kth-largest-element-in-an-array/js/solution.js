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

/// {{
/// Problem: 215. Kth Largest Element in an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Mon, 15 Sep 2025 18:07:45 +0530`

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function findKthLargest(nums, k) {
  /** @type {MinPQ<number>} */
  const minPQ = new MinPQ((a, b) => a < b ? -1 : a > b ? 1 : 0);

  for (const num of nums) {
    minPQ.insert(num);

    if (minPQ.size() > k) {
      minPQ.delMin();
    }
  }

  return minPQ.getMin();
}

/// }}

