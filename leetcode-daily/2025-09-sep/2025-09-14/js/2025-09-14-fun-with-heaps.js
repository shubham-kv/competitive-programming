// Title: Fun with heaps
// Date: 2025-09-14
// Created: `Sun, 14 Sep 2025 13:04:41 +0530`
// Tags: [heaps, daily-practice]

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
/// Problem: 347. Top K Frequent Elements
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/top-k-frequent-elements/
/// Topics: `array`, `hash-table`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Sun, 14 Sep 2025 13:04:41 +0530`

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
/// Problem: 378. Kth Smallest Element in a Sorted Matrix
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
/// Topics: `array`, `binary search`, `sorting`, `heap-(priority-queue)`, `matrix`
/// Timestamp: `Sun, 14 Sep 2025 20:16:10 +0530`

/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
function kthSmallest(matrix, k) {
  const rows = matrix.length;
  const cols = matrix[0].length;

  /** @type {MaxPQ<number>} */
  const maxPQ = new MaxPQ((a, b) => a < b ? -1 : a > b ? 1 : 0);

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      maxPQ.insert(matrix[i][j]);

      if (maxPQ.size() > k) {
        maxPQ.delMax();
      }
    }
  }

  return maxPQ.getMax();
}

/// }}


/// {{
/// Problem: 973. K Closest Points to Origin
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/k-closest-points-to-origin/
/// Topics: `array`, `math`, `divide-and-conquer`, `geometry`, `sorting`, `heap-(priority-queue)`, `matrix`, `quickselect`
/// Timestamp: `Sun, 14 Sep 2025 21:23:01 +0530`

/**
 * @typedef {{coords: {x: number; y: number}; dist: number}} Point
 */

/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
function kClosest(points, k) {
  /** @type {MaxPQ<Point>} */
  const maxPQ = new MaxPQ((a, b) => a.dist < b.dist ? -1 : a.dist > b.dist ? 1 : 0);

  for (const [x, y] of points) {
    maxPQ.insert({coords: {x, y}, dist: Math.sqrt(x * x + y * y)});

    if (maxPQ.size() > k) {
      maxPQ.delMax();
    }
  }

  /** @type {[number, number][]} */
  const closestPoints = [];

  while (!maxPQ.isEmpty()) {
    const entry = maxPQ.delMax();
    closestPoints.push([entry.coords.x, entry.coords.y]);
  }

  return closestPoints;
}

/// }}

