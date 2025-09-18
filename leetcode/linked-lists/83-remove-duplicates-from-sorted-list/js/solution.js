/// {{
/// Problem: 83. Remove Duplicates from Sorted List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/// Timestamp: `Thu, 18 Sep 2025 19:29:25 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates(head) {
  if (!head || !head.next) {
    return head;
  }

  /** @type {(ListNode | null)[]} */
  let [prevUnique, cur, next] = [head, head.next, null];
  prevUnique.next = null; // break link

  for (; cur; cur = next) {
    next = cur.next;

    if (cur.val > prevUnique.val) {
      cur.next = null;
      prevUnique.next = cur;
      prevUnique = prevUnique.next;
    }
  }

  return head;
}

/// }}

