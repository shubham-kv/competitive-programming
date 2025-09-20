// Title: Fun with linked list
// Date: 2025-09-20
// Created: `Sat, 20 Sep 2025 11:24:07 +0530`
// Tags: [linked-list, daily-practice]

/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/
/// Timestamp: `Sat, 20 Sep 2025 11:24:07 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {boolean}
 */
function isPalindrome(head) {
  if (!head) { return false; }
  if (!head.next) { return true; }

  const middle = lowerMiddleNode(head);
  const next = middle.next;
  middle.next = null;

  const head2 = reverseList(next);

  /** @type {(ListNode | null)[]} */
  let [n1, n2] = [head, head2];

  for (; n1 && n2; n1 = n1.next, n2 = n2.next) {
    if (!(n1.val === n2.val)) {
      return false;
    }
  }

  return true;
}

/** @returns {ListNode | null} */
function lowerMiddleNode(
  /** @type {ListNode} */ head
) {
  if (!head) { return null; }

  /** @type {(ListNode | null)[]} */
  let [prev, slow, fast] = [null, head, head];
  for (; fast && fast.next; fast = fast.next.next) {
    prev = slow;
    slow = slow.next;
  }
  return prev;
}

/** @returns {ListNode | null} */
function reverseList(
  /** @type {ListNode} */ head
) {
  if (!head) { return null; }

  /** @type {(ListNode | null)[]} */
  let [prev, cur, next] = [null, head, null];
  for (; cur; cur = next) {
    next = cur.next;
    cur.next = prev;
    prev = cur;
  }
  return prev;
}

/// }}
