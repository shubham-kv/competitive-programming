/// {{
/// Problem: 2181. Merge Nodes in Between Zeros
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Timestamp: `Mon, 22 Sep 2025 12:15:36 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode | null}
 */
function mergeNodes(head) {
  if (!head) {
    return null;
  }

  /** @type {(ListNode | null)[]} */
  let [prevZeroth, cur, next] = [null, head, null];
  let sum = 0;

  for (; cur; cur = next) {
    next = cur.next;

    if (cur.val !== 0) {
      sum += cur.val;
      continue;
    }

    if (prevZeroth) {
      prevZeroth.val = sum;
      sum = 0;

      if (cur.next) {
        prevZeroth.next = cur;
        prevZeroth = cur;
        cur.next = null;
      }
    } else {
      prevZeroth = cur;
      cur.next = null;
    }
  }

  return head;
}

/// }}

