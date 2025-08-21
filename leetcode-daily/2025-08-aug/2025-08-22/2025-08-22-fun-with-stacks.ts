// Title: Fun with Stacks
// Date: 2025-08-21
// Created: `Fri, 22 Aug 2025 00:18:17 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Fri, 22 Aug 2025 00:18:17 +0530`

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

  const middle = lowerMiddleNode(head);
  if (!middle) { return false; }

  // Break the list at the middle
  const next = middle.next;
  middle.next = null;

  // Push nodes from second half onto stack
  const stack: ListNode[] = [];

  for (let cur = next; cur; cur = cur.next) {
    stack.push(cur);
  }

  // Compare nodes from first half & popped nodes from stack
  for (
    let node1: ListNode | null = head, node2 = stack.pop() ?? null;
    node1 && node2;
    node1 = node1.next ?? null, node2 = stack.pop() ?? null
  ) {
    if (node1.val !== node2.val) {
      return false;
    }
  }

  return true;
}

function lowerMiddleNode(head: ListNode | null) {
  let [prev, slow, fast]: (ListNode | null)[] = [null, null, null];

  for (
    prev = null, slow = fast = head;
    fast && fast.next;
    fast = fast.next.next
  ) {
    prev = slow;
    slow = slow?.next ?? null;
  }

  return prev;
}

/// }}

