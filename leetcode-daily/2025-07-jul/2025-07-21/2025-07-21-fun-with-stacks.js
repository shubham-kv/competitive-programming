// Title: Fun with stacks
// Date: 2025-07-21
// Created: `Mon, 21 Jul 2025 12:35:55 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 232. Implement Queue using Stacks
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/implement-queue-using-stacks/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Mon, 21 Jul 2025 12:35:55 +0530`

function MyQueue() {
  /** @type {number[]} */
  this.stack1 = [];

  /** @type {number[]} */
  this.stack2 = [];
}

/**
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function (x) {
  while (this.stack1.length > 0) {
    this.stack2.push(this.stack1.pop());
  }

  this.stack2.push(x);
};

/** @return {number} */
MyQueue.prototype.pop = function () {
  while (this.stack2.length > 0) {
    this.stack1.push(this.stack2.pop());
  }

  return this.stack1.pop();
};

/** @return {number} */
MyQueue.prototype.peek = function () {
  while (this.stack2.length > 0) {
    this.stack1.push(this.stack2.pop());
  }

  return this.stack1.length > 0 ? this.stack1[this.stack1.length - 1] : -1;
};

/** @return {boolean} */
MyQueue.prototype.empty = function () {
  return this.stack1.length === 0 && this.stack2.length === 0;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */

/// }}
