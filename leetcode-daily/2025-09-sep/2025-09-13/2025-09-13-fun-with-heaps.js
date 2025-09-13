// Title: Fun with heaps
// Date: 2025-09-13
// Created: `Sat, 13 Sep 2025 15:38:35 +0530`
// Tags: [heaps, daily-practice]

/// {{
/// Problem: 506. Relative Ranks
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/relative-ranks/
/// Topics: `array`, `sorting`, `heap-(priority-queue)`
/// Timestamp: `Sat, 13 Sep 2025 15:38:35 +0530`

/**
 * @template K
 * @typedef {(a: K, b: K) => number} CompareFn
 */

/** @template K */
class MaxPQ {
  /** @type {K[]} */ #keys;
  /** @type {CompareFn<K>} */ #keysCmp;

  constructor(
    /** @type {CompareFn<K>} */ keysCmp
  ) {
    this.#keysCmp = keysCmp;
    this.#keys = [];
  }

  /** @returns {void} */
  #swapKeys(
    /** @type {number} */ i,
    /** @type {number} */ j
  ) {
    [this.#keys[i], this.#keys[j]] = [this.#keys[j], this.#keys[i]];
  }

  /** @returns {void} */
  #sinkDown(
    /** @type {number} */ p
  ) {
    const n = this.#keys.length;

    for (
      let c = Math.floor(2 * p + 1);
      c < n;
      c = p, c = Math.floor(2 * p + 1)
    ) {
      if ((c + 1) < n && this.#keysCmp(this.#keys[c], this.#keys[c + 1]) < 0) {
        c = c + 1;
      }
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) < 0) {
        this.#swapKeys(p, c);
      } else {
        break;
      }
    }
  }

  /** @returns {void} */
  #swimUp(
    /** @type {number} */ c
  ) {
    for (
      let p = Math.floor((c - 1) / 2);
      p >= 0;
      c = p, p = Math.floor((c - 1) / 2)
    ) {
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) < 0) {
        this.#swapKeys(p, c);
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
    this.#swimUp(this.#keys.length - 1);
  }

  /** @returns {K | null} */
  delMax() {
    const n = this.#keys.length;

    if (n === 0) {
      return null;
    }

    if (n === 1) {
      return this.#keys.pop();
    }

    const max = this.#keys[0];
    this.#keys[0] = this.#keys.pop();
    this.#sinkDown(0);

    return max;
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

const top3Ranks = ["Gold Medal", "Silver Medal", "Bronze Medal"];

/**
 * @param {number[]} scores
 * @return {string[]}
 */
function findRelativeRanks(scores) {
  /** @typedef {{score: number; index: number}} Score */

  /** @type {number} */
  const n = scores.length;

  /** @type {MaxPQ<Score>} */
  const maxPQ = new MaxPQ((a, b) => a.score < b.score ? -1 : a.score > b.score ? 1 : 0);

  for (let i = 0; i < n; i++) {
    maxPQ.insert({
      score: scores[i],
      index: i
    });
  }

  /** @type {string[]} */
  const ranks = Array(n).fill(0).map(() => "");

  for (let rank = 1; !maxPQ.isEmpty(); rank++) {
    const {index} = maxPQ.delMax();
    ranks[index] = (rank <= 3) ? top3Ranks[rank - 1] : `${rank}`;
  }

  return ranks;
}

/// }}
