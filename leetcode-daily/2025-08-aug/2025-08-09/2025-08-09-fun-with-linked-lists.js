// Title: Fun with linked lists
// Date: 2025-08-09
// Created: `Sat, 09 Aug 2025 15:51:25 +0530`
// Tags: [linked-lists, daily-practice]

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`
/// Timestamp: `Sat, 09 Aug 2025 15:51:25 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
function reorderList(head) {
  /** @type {(ListNode|null)[]} */
  let [l1, l2] = [head, null];

  // Divide the list into two sub-lists from middle
  const middle = middleNode(head);
  l2 = middle.next;
  middle.next = null;

  // Reverse the second half of the list
  l2 = reverseList(l2);

  /** @type {(ListNode|null)[]} */
  let [node1, node2, node1Next, node2Next] = Array(4).fill(null);

  // Reorder as needed
  for (
    node1 = l1, node2 = l2;
    node1 && node2;
    node1 = node1Next, node2 = node2Next
  ) {
    node1Next = node1.next;
    node2Next = node2.next;
    node1.next = node2;
    node2.next = node1Next;
  }
}

/** @returns {ListNode | null} */
function middleNode(/** @type {ListNode | null} */ head) {
  /** @type {(ListNode|null)[]} */
  let [fast, slow] = [null, null];
  for (
    fast = slow = head;
    fast && fast.next;
    slow = slow.next, fast = fast.next.next
  ) { }
  return slow;
}

/** @returns {ListNode | null} */
function reverseList(/** @type {ListNode | null} */ head) {
  /** @type {(ListNode|null)[]} */
  let [prev, cur, next] = [null, null, null];
  for (
    prev = next = null, cur = head;
    cur;
    prev = cur, cur = next
  ) {
    next = cur.next;
    cur.next = prev;
  }
  return prev;
}

/// }}


/// {{
/// Problem: 160. Intersection of Two Linked Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/intersection-of-two-linked-lists/
/// Topics: `hash-table`, `linked-list`, `two-pointers`
/// Timestamp: `Sat, 09 Aug 2025 17:12:51 +0530`

// Definition for singly-linked list.
function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
function getIntersectionNode(headA, headB) {
  const list1Len = listLen(headA);
  const list2Len = listLen(headB);

  /** @type {(ListNode|null)[]} */
  let [node1, node2] = [headA, headB];

  if (list1Len > list2Len) {
    const skip = list1Len - list2Len;
    for (let i = 0; i < skip && node1.next; node1 = node1.next, i++) { }

  } else if (list2Len > list1Len) {
    const skip = list2Len - list1Len;
    for (let i = 0; i < skip && node2.next; node2 = node2.next, i++) { }
  }

  for (; node1 && node2; node1 = node1.next, node2 = node2.next) {
    if (node1 === node2) {
      return node1;
    }
  }

  return null;
}

/** @returns {number} */
function listLen(/** @type {ListNode|null} */ head) {
  let nodesCount = 0;

  /** @type {ListNode|null} */
  let cur = head;
  for (; cur; nodesCount++, cur = cur.next) {}

  return nodesCount;
}

/// }}


/// {{
/// Problem: 206. Reverse Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/reverse-linked-list/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Sat, 09 Aug 2025 18:04:23 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function reverseList(head) {
  /** @type {(ListNode | null)[]} */
  let [prev, cur, next] = [null, null, null];

  for (
    prev = next = null, cur = head;
    cur;
    prev = cur, cur = next
  ) {
    next = cur.next;
    cur.next = prev;
  }

  return prev;
}

/// }}

