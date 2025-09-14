/// {{
/// Problem: 347. Top K Frequent Elements
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/top-k-frequent-elements/
/// Topics: `array`, `hash-table`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Sun, 14 Sep 2025 13:04:41 +0530`

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

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
function topKFrequent(nums, k) {
  /** @type {Map<number, number>} */
  const keyToCountMap = new Map();

  for (const key of nums) {
    if (keyToCountMap.has(key)) {
      keyToCountMap.set(key, keyToCountMap.get(key) + 1);
    } else {
      keyToCountMap.set(key, 1);
    }
  }

  /** @type {MinPQ<{key: number; count: number}>} */
  const minPq = new MinPQ((a, b) => a.count < b.count ? -1 : a.count > b.count ? 1 : 0);

  for (const [key, count] of keyToCountMap.entries()) {
    minPq.insert({key, count});

    if (minPq.size() > k) {
      minPq.delMin();
    }
  }

  /** @type {number[]} */
  const kFrequent = [];

  while (!minPq.isEmpty()) {
    const {key} = minPq.delMin();
    kFrequent.push(key);
  }

  return kFrequent;
}

/// }}
