/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Topics: `stack`, `design`  
/// Timestamp: `Thu, 21 Aug 2025 23:19:02 +0530`

/** @typedef {{val: number; min: number}} MinStackNode */

function MinStack() {
  /** @type {MinStackNode[]} */
  this.stack = [];
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
  const stackSize = this.stack.length;
  const top = (stackSize > 0) ? this.stack[stackSize - 1] : null;

  this.stack.push({
    val,
    min: top ? (val < top.min ? val : top.min) : val
  });
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.stack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  const stackSize = this.stack.length;
  return (stackSize > 0) ? this.stack[stackSize - 1].val : -1;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  const stackSize = this.stack.length;
  return (stackSize > 0) ? this.stack[stackSize - 1].min : -1;
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */

/// }}

