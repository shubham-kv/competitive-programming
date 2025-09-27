// Title: Fun with stacks
// Date: 2025-09-27
// Created: `Sat, 27 Sep 2025 10:12:37 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Timestamp: `Sat, 27 Sep 2025 10:12:49 +0530`

class MinStackNode {
  constructor(
    /** @type {number} */ val,
    /** @type {number} */ min,
    /** @type {MinStackNode | null | undefined} */ next = null
  ) {
    /** @type {number} */
    this.val = val;

    /** @type {number} */
    this.min = min;

    /** @type {MinStackNode | null | undefined} */
    this.next = next;
  }
}

class MinStack {
  /** @type {MinStackNode | null} */
  #top;

  constructor() {
    this.#top = null;
  }

  /**
   * @param {number} val
   * @return {void}
   */
  push(val) {
    const min = this.#top ? Math.min(this.#top.min, val) : val;
    const node = new MinStackNode(val, min, this.#top);
    this.#top = node;
  }

  /** @return {void} */
  pop() {
    if (!this.#top) {
      return;
    }
    this.#top = this.#top.next ?? null;
  }

  /** @return {number} */
  top() {
    return this.#top?.val ?? 0;
  }

  /** @return {number} */
  getMin() {
    return this.#top?.min ?? 0;
  }
}

/// }}

