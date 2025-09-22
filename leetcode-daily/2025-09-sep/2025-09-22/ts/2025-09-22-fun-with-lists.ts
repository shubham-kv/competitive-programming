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

