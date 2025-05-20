// Definition for singly-linked list.
class ListNode {
  val: number;
  next: ListNode | null;

  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function isPalindrome(head: ListNode | null): boolean {
  if (!head || !head.next) {
    return true;
  }

  // Find the middle node
  let fast: ListNode | null = head;
  let slow: ListNode | null = head;

  while (fast != null && fast.next != null) {
    slow = slow!.next;
    fast = fast.next.next;
  }

  // Beak the list from middle & reverse the second half of the list
  let prev: ListNode | null = null;
  let cur: ListNode | null = slow;

  while (cur != null) {
    const next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }

  // Compare the two halved linked lists from each sides
  let first: ListNode | null = head;
  let second: ListNode | null = prev;

  while (first != null && second != null) {
    if (first.val != second.val) {
      return false;
    }
    first = first.next;
    second = second.next;
  }

  return true;
}
