// Title: Fun with linked list
// Date: 2025-09-17
// Created: `Wed, 17 Sep 2025 16:15:27 +0530`
// Tags: [linked-list, daily-practice]

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

/// {{
/// Problem: 2. Add Two Numbers
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/add-two-numbers/
/// Topics: `linked-list`, `math`, `recursion`  
/// Timestamp: `Wed, 17 Sep 2025 16:15:27 +0530`

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  const result: ListNode = new ListNode();

  for (
    let n3 = result, carry = 0;
    l1 || l2 || carry > 0;
    (l1 && (l1 = l1.next)), (l2 && (l2 = l2.next))
  ) {
    let sum = 0;
    l1 && (sum += l1.val);
    l2 && (sum += l2.val);
    sum += carry;
    carry = Math.floor(sum / 10);

    const digit = sum % 10;

    n3.next = new ListNode(digit);
    n3 = n3.next;
  }

  return result.next;
}

/// }}


/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-lsit`, `recursion`
/// Timestamp: `Wed, 17 Sep 2025 16:49:58 +0530`

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
