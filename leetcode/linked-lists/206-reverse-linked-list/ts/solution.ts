/// {{
/// Problem: 206. Reverse Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/reverse-linked-list/
/// Timestamp: `Fri, 19 Sep 2025 12:18:49 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function reverseList(head: ListNode | null): ListNode | null {
  if (!head) { return null; }

  let [prev, cur, next]: (ListNode | null)[] = [null, head, null];

  for (; cur; cur = next) {
    next = cur.next;
    cur.next = prev;
    prev = cur;
  }

  return prev;
}

/// }}

