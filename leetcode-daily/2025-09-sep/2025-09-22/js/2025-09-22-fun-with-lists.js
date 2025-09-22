// Title: Fun with linked list
// Date: 2025-09-22
// Created: `Mon, 22 Sep 2025 11:35:58 +0530`
// Tags: [linked-list, daily-practice]

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

/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: `Easy`
/// Timestamp: `Mon, 22 Sep 2025 11:35:58 +0530`


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


/// {{
/// Problem: 2181. Merge Nodes in Between Zeros
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Timestamp: `Mon, 22 Sep 2025 12:15:36 +0530`

/**
 * @param {ListNode} head
 * @return {ListNode | null}
 */
function mergeNodes(head) {
  if (!head) {
    return null;
  }

  /** @type {(ListNode | null)[]} */
  let [prevZeroth, cur, next] = [null, head, null];
  let sum = 0;

  for (; cur; cur = next) {
    next = cur.next;

    if (cur.val !== 0) {
      sum += cur.val;
      continue;
    }

    if (prevZeroth) {
      prevZeroth.val = sum;
      sum = 0;

      if (cur.next) {
        prevZeroth.next = cur;
        prevZeroth = cur;
        cur.next = null;
      }
    } else {
      prevZeroth = cur;
      cur.next = null;
    }
  }

  return head;
}

/// }}

