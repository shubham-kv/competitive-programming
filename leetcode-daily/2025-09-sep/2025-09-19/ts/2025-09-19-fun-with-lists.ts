// Title: Fun with linked list
// Date: 2025-09-19
// Created: `Fri, 19 Sep 2025 11:51:55 +0530`
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
/// Problem: 160. Intersection of Two Linked Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/intersection-of-two-linked-lists/
/// Timestamp: `Fri, 19 Sep 2025 11:52:47 +0530`

function getIntersectionNode(
  headA: ListNode | null,
  headB: ListNode | null,
): ListNode | null {
  if (!(headA && headB)) {
    return null;
  }

  const { tail: tailA, size: sizeA } = processList(headA);
  const { tail: tailB, size: sizeB  } = processList(headB);

  if (!(tailA !== null && tailB !== null && tailA === tailB)) {
    return null;
  }

  let node1 = headA;
  let node2 = headB;

  if (sizeA > sizeB) {
    const skip = sizeA - sizeB;
    node1 = ithNode(headA, skip);
  } else if (sizeB > sizeA) {
    const skip = sizeB - sizeA;
    node2 = ithNode(headB, skip);
  }

  for (; node1 && node2; node1 = node1.next, node2 = node2.next) {
    if (node1 === node2) {
      return node1;
    }
  }

  return null;
}

function processList(
  head: ListNode | null,
): { tail: ListNode; size: number } | null {
  if (!head) { return null; }
  let node = head;
  let size = 1;
  for (; node.next; node = node.next, size++) {}
  return { tail: node, size };
}

function ithNode(head: ListNode, index: number): ListNode | null {
  if (!head) { return null; }
  if (!(0 <= index)) { return null; }
  let node = head;
  for (let i = 1; i <= index; i++) {
    if (node?.next) {
      node = node.next;
    } else {
      return null;
    }
  }
  return node;
}

/// }}
