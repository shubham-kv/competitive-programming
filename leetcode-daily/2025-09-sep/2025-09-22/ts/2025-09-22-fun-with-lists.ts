// Title: Fun with linked list
// Date: 2025-09-20
// Created: `Mon, 22 Sep 2025 11:52:40 +0530`
// Tags: [linked-list, daily-practice]

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: `Easy`
/// Timestamp: `Mon, 22 Sep 2025 11:52:53 +0530`

function middleNode(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }

  let slow: ListNode | null = head;
  let fast: ListNode | null = head;

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
/// Timestamp: `Mon, 22 Sep 2025 12:35:51 +0530`

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeNodes(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }

  let [prevZeroth, cur, next]: (ListNode | null)[] = [null, head, null];
  let sum = 0;

  for (; cur; cur = next) {
    next = cur.next;

    if (cur.val === 0) {
      cur.next = null;

      if (prevZeroth) {
        prevZeroth.val = sum;
        sum = 0;

        if (next) {
          prevZeroth.next = cur;
          prevZeroth = cur;
        }
      } else {
        prevZeroth = cur;
      }
    } else {
      sum += cur.val;
    }
  }

  return head;
}

/// }}

