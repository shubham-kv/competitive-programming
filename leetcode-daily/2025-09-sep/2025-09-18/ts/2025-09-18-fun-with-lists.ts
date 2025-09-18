// Title: Fun with linked list
// Date: 2025-09-18
// Created: `Thu, 18 Sep 2025 12:13:52 +0530`
// Tags: [linked-list, daily-practice]

/// {{
/// Problem: 24. Swap Nodes in Pairs
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/swap-nodes-in-pairs/
/// Timestamp: `Thu, 18 Sep 2025 12:13:52 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function swapPairs(head: ListNode | null): ListNode | null {
  const savedHead = head;

  if (!head) {
    return null;
  }

  if (head.next) {
    head = head.next;
  }

  let prev: ListNode | null = null;
  let cur: ListNode | null = savedHead;

  // Swapping n1 & n2
  // Before: (prev ->)? n1 -> n2 -> n3
  //  After: (prev ->)? n2 -> n1 -> n3

  while (cur && cur.next) {
    const [n1, n2, n3]: (ListNode | null)[] = [
      cur,
      cur.next,
      cur.next.next ?? null,
    ];

    if (prev) {
      prev.next = n2;
    }

    // Swap n1 & n2
    n2.next = n1;
    n1.next = n3;

    prev = n1;
    cur = n3;
  }

  return head;
}

/// }}
