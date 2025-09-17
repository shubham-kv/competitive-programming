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

/** @type {(a: number, b: number) => number} */
const cmpNumber = (a, b) => a < b ? -1 : a > b ? 1 : 0;

/// {{
/// Problem: 1046. Last Stone Weight
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/last-stone-weight/
/// Topics: `array`, `heap-(priority-queue)`
/// Timestamp: `Wed, 17 Sep 2025 12:13:27 +0530`

/**
 * @param {number[]} stones
 * @return {number}
 */
function lastStoneWeight(stones) {
  /** @type {MaxPQ<number>} */
  const maxPQ = new MaxPQ(cmpNumber);

  for (const stoneWight of stones) {
    maxPQ.insert(stoneWight);
  }

  while (maxPQ.size() > 1) {
    const stoneXWeight = maxPQ.delMax();
    const stoneYWeight = maxPQ.delMax();

    if (stoneXWeight === stoneYWeight) {
      // No OP
    } else {
      const stoneXNewWeight = stoneXWeight - stoneYWeight;
      maxPQ.insert(stoneXNewWeight);
    }
  }

  return !maxPQ.isEmpty() ? maxPQ.delMax() : 0;
}

/// }}

