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

