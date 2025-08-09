/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: `Easy`
/// Topics: `linked-list`, `two-pointers`
/// Timestamp: `Sat, 09 Aug 2025 19:16:24 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function middleNode(head) {
  /** @type {(ListNode | null)[]} */
  let [slow, fast] = [null, null];

  for (
    slow = fast = head;
    fast && fast.next;
    slow = slow.next, fast = fast.next.next
  ) { }

  return slow;
};

/// }}

