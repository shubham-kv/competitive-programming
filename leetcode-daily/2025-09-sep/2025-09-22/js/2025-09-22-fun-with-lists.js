// Title: Fun with linked list
// Date: 2025-09-22
// Created: `Mon, 22 Sep 2025 11:35:58 +0530`
// Tags: [linked-list, daily-practice]

/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: `Easy`
/// Timestamp: `Mon, 22 Sep 2025 11:35:58 +0530`

// Definition for singly-linked list.
function ListNode(
  /** @type {number} */ val,
  /** @type {ListNode | null | undefined} */ next
) {
  /** @type {number} */
  this.val = (val === undefined ? 0 : val);

  /** @type {ListNode | null} */
  this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @return {ListNode | null | undefined}
 */
function middleNode(head) {
  if (!head) {
    return head;
  }

  /** @type {(ListNode | null)[]} */
  let [slow, fast] = [head, head];

  for (; fast && fast.next; fast = fast.next.next) {
    slow = slow?.next ?? null;
  }

  return slow;
}

/// }}
