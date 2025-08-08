/// {{
/// Problem: 83. Remove Duplicates from Sorted List  
/// Difficulty: Easy  
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-list/  
/// Topics: `linked-list`  
/// Timestamp: `Fri, 08 Aug 2025 16:56:45 +0530`  

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates(head) {
  /** @type {(ListNode | null)[]} */
  let [prev, cur, next] = [head, head?.next ?? null, null];

  for (; prev && cur; cur = next) {
    next = cur.next;

    if (prev.val < cur.val) {
      prev.next = cur;
      cur.next = null;
      prev = cur;
    } else {
      prev.next = null;
    }
  }

  return head;
}

/// }}

