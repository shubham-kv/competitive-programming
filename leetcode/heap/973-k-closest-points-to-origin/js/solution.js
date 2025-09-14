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
    maxPQ.insert({ coords: { x, y }, dist: Math.sqrt(x * x + y * y) });

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

