// Title: Fun with Stacks
// Date: 2025-08-21
// Created: `Thu, 21 Aug 2025 22:58:50 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 20. Valid Parentheses
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/valid-parentheses/
/// Topics: `string`, `stack`  
/// Timestamp: `Thu, 21 Aug 2025 22:58:50 +0530`

const openingToClosingBracketMap = {
  '(': ')',
  '{': '}',
  '[': ']'
};

const openingBrackets = Object.keys(openingToClosingBracketMap);
const closingBrackets = Object.values(openingToClosingBracketMap);

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

    if (openingBrackets.includes(ch)) {
      stack.push(ch);
    }
    else if (closingBrackets.includes(ch)) {
      if (!(stack.length > 0)) {
        return false;
      }

      const popped = stack.pop();
      if (openingToClosingBracketMap[popped] !== ch) {
        return false;
      }
    }
  }

  if (!(stack.length === 0)) {
    return false;
  }

  return true;
}

/// }}


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


/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Sat, 09 Aug 2025 18:25:21 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

/** @returns {ListNode | null} */
function lowerMiddleNode(/** @type {ListNode|null} */ head) {
  /** @type {(ListNode | null)[]} */
  let [prev, slow, fast] = [null, null, null];

  for (
    prev = null, slow = fast = head;
    fast && fast.next;
    fast = fast.next.next
  ) {
    prev = slow;
    slow = slow.next;
  }

  return prev;
}

/**
 * @param {ListNode} head
 * @return {boolean}
 */
function isPalindrome(head) {
  if (!head.next) {
    return true;
  }

  // Break the list from middle
  const middle = lowerMiddleNode(head);
  const next = middle.next;
  middle.next = null;

  /** @type {ListNode[]} */
  const stack = [];

  for (let cur = next; cur; cur = cur.next) {
    stack.push(cur);
  }

  for (
    let node1 = head, node2 = stack.pop();
    node1 && node2;
    node1 = node1.next, node2 = stack.pop()
  ) {
    if (node1.val !== node2.val) {
      return false;
    }
  }

  return true;
}

/// }}

