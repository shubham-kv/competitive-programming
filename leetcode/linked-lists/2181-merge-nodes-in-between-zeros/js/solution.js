/// {{
/// Problem: 2181. Merge Nodes in Between Zeros
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Topics: `linked-list`, `simulation`
/// Timestamp: `Mon, 11 Aug 2025 17:55:18 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function mergeNodes(head) {
  /** @type {(ListNode | null)[]} */
  let [curZeroth, cur, next] = [null, null, null];

  let sum = 0;

  for (curZeroth = null, cur = head, next = null; cur; cur = next) {
    next = cur.next;

    if (cur.val === 0) {
      cur.next = null;

      if (curZeroth) {
        curZeroth.val = sum;
        (next) && (curZeroth.next = cur);
        curZeroth = cur;
        sum = 0;
      } else {
        curZeroth = cur;
      }
    } else {
      sum += cur.val;
    }
  }

  return head;
}

/// }}

