// Title: Fun with linked list
// Date: 2025-09-18
// Created: `Thu, 18 Sep 2025 12:13:52 +0530`
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
/// Problem: 24. Swap Nodes in Pairs
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/swap-nodes-in-pairs/
/// Timestamp: `Thu, 18 Sep 2025 12:13:52 +0530`

function swapPairs(head: ListNode | null): ListNode | null {
  const savedHead = head;

  if (!head) {
    return null;
  }

  if (head.next) {
    head = head.next;
  }

  let prev: ListNode | null = null;
  let cur: ListNode | null = savedHead;

  // Swapping n1 & n2
  // Before: (prev ->)? n1 -> n2 -> n3
  //  After: (prev ->)? n2 -> n1 -> n3

  while (cur && cur.next) {
    const [n1, n2, n3]: (ListNode | null)[] = [
      cur,
      cur.next,
      cur.next.next ?? null,
    ];

    if (prev) {
      prev.next = n2;
    }

    // Swap n1 & n2
    n2.next = n1;
    n1.next = n3;

    prev = n1;
    cur = n3;
  }

  return head;
}

/// }}


/// {{
/// Problem: 83. Remove Duplicates from Sorted List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/// Timestamp: `Thu, 18 Sep 2025 19:59:32 +0530`

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


/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Timestamp: `Thu, 18 Sep 2025 20:33:13 +0530`

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
  if (!head) {
    return;
  }

  const middle = middleNode(head);
  if (!middle) {
    return;
  }

  const next = middle.next;
  middle.next = null;

  const head2 = reverseList(next);
  let [n1, n2]: (ListNode | null)[] = [head, head2];

  while (n1 && n2) {
    const next1 = n1.next;
    const next2 = n2.next;

    n1.next = n2;
    n2.next = next1;
    n1 = next1;
    n2 = next2;
  }
}

function middleNode(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }
  let [slow, fast]: (ListNode | null)[] = [head, head];
  for (; fast && fast.next; fast = fast.next.next) {
    slow = slow?.next ?? null;
  }
  return slow;
}

function reverseList(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }
  let [prev, cur, next]: (ListNode | null)[] = [null, head, head.next];
  for (; cur; prev = cur, cur = next) {
    next = cur.next;
    cur.next = prev;
  }
  return prev;
}

/// }}

