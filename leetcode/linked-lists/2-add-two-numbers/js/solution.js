/// {{
/// Problem: 2. Add Two Numbers
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/add-two-numbers/
/// Topics: `linked-list`, `math`, `recursion`  
/// Timestamp: `Fri, 08 Aug 2025 14:38:44 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
   this.val = (val===undefined ? 0 : val)
   this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function addTwoNumbers(l1, l2) {
  /** @type {number} */
  let carry = 0;

  /** @type {(ListNode|null)[]} */
  let [l3, cur1, cur2, cur3] = [null, l1, l2, null];

  while (cur1 || cur2 || carry > 0) {
    let sum = (cur1?.val ?? 0) + (cur2?.val ?? 0) + carry;

    if (sum > 9) {
      carry = 1;
      sum %= 10;
    } else {
      carry = 0;
    }

    const newNode = new ListNode(sum);
    (cur3) ? (cur3.next = newNode) : (l3 = newNode);
    cur3 = newNode;

    cur1 = cur1?.next ?? null;
    cur2 = cur2?.next ?? null;
  }

  return l3;
};

/// }}
