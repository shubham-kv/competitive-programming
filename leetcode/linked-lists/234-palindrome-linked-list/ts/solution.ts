/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/
/// Timestamp: `Sat, 20 Sep 2025 11:46:51 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function isPalindrome(head: ListNode | null): boolean {
  if (!head) { return false; }
  if (!head.next) { return true; }

  const middle = lowerMiddleNode(head)!;
  const next = middle.next!;
  middle.next = null;

  const head2 = reverseList(next);
  let [n1, n2]: (ListNode | null)[] = [head, head2];

  for (; n1 && n2; n1 = n1.next, n2 = n2.next) {
    if (!(n1.val === n2.val)) {
      return false;
    }
  }

  return true;
}

function lowerMiddleNode(head: ListNode): ListNode | null {
  if (!head) { return null; }
  let [prev, slow, fast]: (ListNode | null)[] = [null, head, head];
  for (; fast && fast.next; fast = fast.next.next) {
    prev = slow;
    slow = slow?.next ?? null;
  }
  return prev!;
}

function reverseList(head: ListNode): ListNode | null {
  if (!head) { return null; }
  let [prev, cur, next]: (ListNode | null)[] = [null, head, head];
  for (; cur; cur = next) {
    next = cur.next;
    cur.next = prev ?? null;
    prev = cur;
  }
  return prev!;
}

/// }}

