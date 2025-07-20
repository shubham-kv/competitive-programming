// Title: Fun with stacks
// Date: 2025-07-18
// Created: `Sun, 20 Jul 2025 18:17:01 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`
/// Timestamp: `Sun, 20 Jul 2025 18:17:41 +0530`

/**
 * @param {string} s
 * @return {boolean}
 */
function isValid(s) {
  const len = s.length;

  /** @type {string[]} */
  const stack = [];

  for (let i = 0; i < len; i++) {
    const ch = s.charAt(i);

    if (ch === "(" || ch === "{" || ch === "[") {
      stack.push(ch);
    } else if (ch === ")" || ch === "}" || ch === "]") {
      if (!(stack.length > 0)) {
        return false;
      }

      const popped = stack.pop();

      if (
        (popped === "(" && ch !== ")") ||
        (popped === "{" && ch !== "}") ||
        (popped === "[" && ch !== "]")
      ) {
        return false;
      }
    }
  }

  return stack.length === 0;
}

/// }}


/// {{
/// Problem: 155. Min Stack
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/min-stack/
/// Topics: `stack`, `design`  
/// Timestamp: `Sun, 20 Jul 2025 18:42:40 +0530`

/**
 * @typedef {{data: number; min: number}} MinStackNode
 */

function MinStack() {
  /** @type {MinStackNode[]} */
  this.stack = []
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
  let min = val;
  if (this.stack.length > 0) {
    const lastMin = this.stack[this.stack.length - 1].min;
    min = lastMin < min ? lastMin : min;
  }

  this.stack.push({
    data: val,
    min: min
  })
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
  const len = this.stack.length;
  return len > 0 ? this.stack[len - 1].data : -1;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  const len = this.stack.length;
  return len > 0 ? this.stack[len - 1].min : -1;
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
