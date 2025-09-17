// Title: Fun with linked list
// Date: 2025-09-17
// Created: `Wed, 17 Sep 2025 15:57:28 +0530`
// Tags: [linked-list, daily-practice]

// Definition for singly-linked list.
class ListNode {
  /**
   * @param {number} [val]
   * @param {undefined} [next]
   */
  constructor(val, next) {
    this.val = (val === undefined ? 0 : val);

    /** @type {ListNode} */
    this.next = (next === undefined ? null : next);
  }
}

/// {{
/// Problem: 2. Add Two Numbers
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/add-two-numbers/
/// Topics: `linked-list`, `math`, `recursion`  
/// Timestamp: `Wed, 17 Sep 2025 16:03:49 +0530`

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function addTwoNumbers(l1, l2) {
  const l3 = new ListNode();

  for (
    let n1 = l1, n2 = l2, n3 = l3, carry = 0;
    n1 || n2 || carry > 0;
    (n1 && (n1 = n1.next)), (n2 && (n2 = n2.next))
  ) {
    let sum = 0;
    n1 && (sum += n1.val);
    n2 && (sum += n2.val);
    sum += carry;
    carry = 0;

    if (sum > 9) {
      sum %= 10;
      carry = 1;
    }

    n3.next = new ListNode(sum);
    n3 = n3.next;
  }

  return l3.next;
}

/// }}

