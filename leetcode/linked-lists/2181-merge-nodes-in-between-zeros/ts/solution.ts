/// {{
/// Problem: 2181. Merge Nodes in Between Zeros
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Timestamp: `Mon, 22 Sep 2025 12:35:51 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function mergeNodes(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }

  let [prevZeroth, cur, next]: (ListNode | null)[] = [null, head, null];
  let sum = 0;

  for (; cur; cur = next) {
    next = cur.next;

    if (cur.val === 0) {
      cur.next = null;

      if (prevZeroth) {
        prevZeroth.val = sum;
        sum = 0;

        if (next) {
          prevZeroth.next = cur;
          prevZeroth = cur;
        }
      } else {
        prevZeroth = cur;
      }
    } else {
      sum += cur.val;
    }
  }

  return head;
}

/// }}

