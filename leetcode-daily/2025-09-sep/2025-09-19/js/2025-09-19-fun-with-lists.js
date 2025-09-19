// Title: Fun with linked list
// Date: 2025-09-19
// Created: `Fri, 19 Sep 2025 11:21:56 +0530`
// Tags: [linked-list, daily-practice]

/// {{
/// Problem: 160. Intersection of Two Linked Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/intersection-of-two-linked-lists/
/// Timestamp: `Fri, 19 Sep 2025 11:23:07 +0530`

// Definition for singly-linked list.
function ListNode(val) {
  /** @type {number} */
  this.val = val;

  /** @type {ListNode | null} */
  this.next = null;
}

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode | null}
 */
function getIntersectionNode(headA, headB) {
  if (!(headA && headB)) {
    return null;
  }

  const {tail: tailA, size: sizeA} = processList(headA);
  const {tail: tailB, size: sizeB} = processList(headB);

  if (tailA !== tailB) {
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

/** @returns {{tail: ListNode; size: number} | null} */
function processList(
  /** @type {ListNode | null} */ head
) {
  if (!head) { return null; }
  let node = head;
  let size = 1;
  for (; node.next; node = node.next, size++) { }
  return { tail: node, size };
}

/** @returns {ListNode | null} */
function ithNode(
  /** @type {ListNode | null} */ head,
  /** @type {number} */ index
) {
  let node = head;
  for (let i = 1; i <= index; i++) {
    if (node && node.next) {
      node = node.next
    } else {
      return null;
    }
  }
  return node;
}

/// }}

