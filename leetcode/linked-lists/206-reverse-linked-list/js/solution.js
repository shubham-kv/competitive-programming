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

