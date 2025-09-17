/// {{
/// Problem: 2. Add Two Numbers
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/add-two-numbers/
/// Topics: `linked-list`, `math`, `recursion`  
/// Timestamp: `Wed, 17 Sep 2025 16:15:27 +0530`

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

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

