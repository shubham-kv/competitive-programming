// Title: Fun with queues
// Date: 2025-07-26
// Created: `Sat, 26 Jul 2025 20:20:22 +0530`
// Tags: [queues, daily-practice]

/// {{
/// Problem: 225. Implement Stack using Queues
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-stack-using-queues/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Sat, 26 Jul 2025 20:20:22 +0530`

function MyStack() {
  /** @type {number[]} */
  this.queueA = [];

  /** @type {number[]} */
  this.queueB = [];
}

/**
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function (x) {
  this.queueA.push(x);
};

/** @return {number} */
MyStack.prototype.pop = function () {
  while (this.queueA.length > 1) {
    this.queueB.push(this.queueA.shift());
  }

  const data = this.queueA.shift();

  while (this.queueB.length > 0) {
    this.queueA.push(this.queueB.shift());
  }

  return data;
};

/** * @return {number} */
MyStack.prototype.top = function () {
  while (this.queueA.length > 1) {
    this.queueB.push(this.queueA.shift());
  }

  const top = this.queueA[0];
  this.queueB.push(this.queueA.shift());

  while (this.queueB.length > 0) {
    this.queueA.push(this.queueB.shift());
  }

  return top;
};

/** * @return {boolean} */
MyStack.prototype.empty = function () {
  return this.queueA.length === 0 && this.queueB.length === 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */

/// }}
