// Title: Fun with stacks
// Date: 2025-09-25
// Created: `Thu, 25 Sep 2025 10:01:58 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Timestamp: `Thu, 25 Sep 2025 10:02:46 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
  if (!head || !head.next) {
    return;
  }

  const middle = middleNode(head);
  if (!middle) { return; }

  const next = middle.next;
  middle.next = null;

  const stack: ListNode[] = [];
  for (let node = next; node; node = node.next) {
    stack.push(node);
  }

  let n1: ListNode | null = head;
  let n1Next: ListNode | null = null;
  let n2: ListNode | null = stack.pop() ?? null;

  for (; n1 && n2; n1 = n1Next, n2 = stack.pop() ?? null) {
    n1Next = n1.next;
    n1.next = n2;
    n2.next = n1Next;
  }
}

function middleNode(head: ListNode): ListNode | null {
  let slow: ListNode | null = head;
  let fast: ListNode | null = head;
  for (; fast && fast.next; fast = fast.next.next) {
    slow = slow?.next ?? null;
  }
  return slow ?? null;
}

/// }}

