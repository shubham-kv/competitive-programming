/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Sat, 09 Aug 2025 18:47:31 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {boolean}
 */
function isPalindrome(head) {
  if (head.next === null) {
    return true;
  }

  /** @type {(ListNode | null)[]} */
  let [l1, l2] = [head, null];

  // Break the list into two halves at the lower middle node
  const middle = lowerMiddleNode(head);
  if (!middle) {
    return true;
  }

  l2 = middle.next;
  middle.next = null;

  // Reverse the second half
  l2 = reverseList(l2);

  /** @type {(ListNode | null)[]} */
  let [node1, node2] = [null, null];

  for (
    node1 = l1, node2 = l2;
    node1 && node2;
    node1 = node1.next, node2 = node2.next
  ) {
    if (node1.val !== node2.val) {
      return false;
    }
  }

  return true;
}

/** @returns {ListNode | null} */
function lowerMiddleNode(/** @type {ListNode | null} */ head) {
  /** @type {(ListNode | null)[]} */
  let [prev, slow, fast] = Array(3).fill(null);

  for (
    prev = null, slow = fast = head;
    fast && fast.next;
    prev = slow, slow = slow.next, fast = fast.next.next
  ) { }

  return prev;
}

/** @returns {ListNode | null} */
function reverseList(/** @type {ListNode | null} */ head) {
  /** @type {(ListNode | null)[]} */
  let [prev, cur, next] = Array(3).fill(null);

  for (
    prev = next = null, cur = head;
    cur;
    prev = cur, cur = next
  ) {
    next = cur.next;
    cur.next = prev;
  }

  return prev;
}

/// }}

