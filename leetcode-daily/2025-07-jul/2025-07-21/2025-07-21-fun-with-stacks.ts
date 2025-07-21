// Title: Fun with stacks
// Date: 2025-07-21
// Created: `Mon, 21 Jul 2025 12:57:12 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Mon, 21 Jul 2025 12:57:12 +0530`

class MyQueue {
  #stack1: number[] = [];
  #stack2: number[] = [];

  constructor() { }

  push(x: number): void {
    while (this.#stack1.length > 0) {
      this.#stack2.push(this.#stack1.pop()!);
    }

    this.#stack2.push(x);
  }

  pop(): number {
    while (this.#stack2.length > 0) {
      this.#stack1.push(this.#stack2.pop()!);
    }

    return this.#stack1.pop() ?? -1;
  }

  peek(): number {
    while (this.#stack2.length > 0) {
      this.#stack1.push(this.#stack2.pop()!);
    }

    const stack1Len = this.#stack1.length;
    return stack1Len > 0 ? this.#stack1[stack1Len - 1] : -1;
  }

  empty(): boolean {
    return this.#stack1.length === 0 && this.#stack2.length === 0;
  }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */

/// }}
