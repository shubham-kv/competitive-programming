// Title: Fun with stacks
// Date: 2025-09-27
// Created: `Sat, 27 Sep 2025 10:00:18 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Timestamp: `Sat, 27 Sep 2025 10:01:02 +0530`

class MinStackNode {
  constructor(
    public val: number,
    public min: number,
    public next: MinStackNode | null = null,
  ) { }
}

class MinStack {
  #top: MinStackNode | null;

  constructor() {
    this.#top = null;
  }

  push(val: number): void {
    const min = (this.#top) ? (this.#top.min < val ? this.#top.min : val) : val;
    const node = new MinStackNode(val, min, this.#top);
    this.#top = node;
  }

  pop(): void {
    if (!this.#top) {
      return;
    }
    this.#top = this.#top.next;
  }

  top(): number {
    return this.#top?.val ?? 0;
  }

  getMin(): number {
    return this.#top?.min ?? 0;
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */

/// }}
