/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Timestamp: `Thu, 18 Sep 2025 20:33:13 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

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
  let [n1, n2]: (ListNode)[] = [head, head2];

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

