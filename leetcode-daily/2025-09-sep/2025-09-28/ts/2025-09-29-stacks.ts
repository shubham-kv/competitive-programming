// Title: Fun with stacks
// Date: 2025-09-29
// Created: `Mon, 29 Sep 2025 12:34:59 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Timestamp: `Mon, 29 Sep 2025 12:35:32 +0530`

//
// ## Idea
//
// The idea is to use two stacks. When we want to enqueue to the queue, we'll
// use one stack to push item and to dequeue we'll use the other stack.
//
// Let's say that we use the first stack `stack1` for `Queue#pop()` and the
// second stack `stack2` for `Queue#push()`.
// Before pushing the item to `stack2` we'll need to save all the items from
// `stack1` to preserve relative order of items if the queue had been dequeued
// before.
// And likewise before popping items from `stack1` we'll save the others in
// `stack2`.
//

class MyQueue {
  #stack1: number[];
  #stack2: number[];

  constructor() {
    this.#stack1 = [];
    this.#stack2 = [];
  }

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
    return this.#stack1.pop() ?? 0;
  }

  peek(): number {
    while (this.#stack2.length > 0) {
      this.#stack1.push(this.#stack2.pop()!);
    }
    const first = this.#stack1[this.#stack1.length - 1];
    return first ?? 0;
  }

  empty(): boolean {
    return this.#stack1.length === 0 && this.#stack2.length === 0;
  }
}

//}}
