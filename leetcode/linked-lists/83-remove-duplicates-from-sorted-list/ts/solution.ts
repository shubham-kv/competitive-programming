/// {{
/// Problem: 83. Remove Duplicates from Sorted List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/// Timestamp: `Thu, 18 Sep 2025 19:59:32 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function deleteDuplicates(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }

  let [prevUnique, cur, next]: (ListNode | null)[] = [head, head.next, null];
  head.next = null;   // break the link

  for (; cur; cur = next) {
    next = cur.next;

    if (prevUnique.val < cur.val) {
      cur.next = null;

      prevUnique.next = cur;
      prevUnique = cur;
    }
  }

  return head;
}

/// }}

