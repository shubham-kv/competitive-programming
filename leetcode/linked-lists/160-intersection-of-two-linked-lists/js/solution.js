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
  }
  else if (list2Len > list1Len) {
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

