/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-lsit`, `recursion`
/// Timestamp: `Wed, 17 Sep 2025 16:49:58 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function mergeTwoLists(
  list1: ListNode | null,
  list2: ListNode | null,
): ListNode | null {
  const l3 = new ListNode();
  let n1 = list1, n2 = list2, n3 = l3;

  for (; ;) {
    if (n1 === null) {
      n3.next = n2;
      break;
    } else if (n2 === null) {
      n3.next = n1;
      break;
    } else if (n2.val < n1.val) {
      n3.next = n2;
      n2 = n2.next;
      n3 = n3.next;
    } else {
      n3.next = n1;
      n1 = n1.next;
      n3 = n3.next;
    }
  }

  return l3.next;
}

/// }}
