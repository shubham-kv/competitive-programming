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

  // Get to the middle of the node with fast & slow pointers
  let fast: ListNode | null = head;
  let slow: ListNode | null = head;

  while(fast && fast.next) {
    slow = slow?.next ?? null;
    fast = fast.next.next;
  }

  // Reverse the list from middle
  let prev: ListNode | null = null;
  let cur: ListNode | null = slow;
  let next: ListNode | null = null;

  while (cur) {
    next = cur.next;
    cur.next = prev;
    prev = cur;
    cur = next;
  }

  // Compare the two halved lists
  let curFromStart: ListNode | null = head;
  let curFromEnd: ListNode | null = prev;

  while (curFromStart && curFromEnd) {
    if (curFromStart.val !== curFromEnd.val) {
      return false;
    }

    curFromStart = curFromStart.next;
    curFromEnd = curFromEnd.next;
  }

  return true;
}
