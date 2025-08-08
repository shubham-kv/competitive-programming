// Title: Fun with linked lists
// Date: 2025-08-08
// Created: `Fri, 08 Aug 2025 14:38:44 +0530`
// Tags: [linked-lists, daily-practice]

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


/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Mon, 14 Jul 2025 14:25:32 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
function mergeTwoLists (list1, list2) {
  let l3 = new ListNode(0);

  /** @type {(ListNode|null)[]} */
  let [cur1, cur2, cur3] = [list1, list2, l3];

  for (;;) {
    if (cur1 === null) {
      cur3.next = cur2;
      break;
    }
    else if (cur2 === null) {
      cur3.next = cur1;
      break;
    }
    else if (cur2.val < cur1.val) {
      cur3.next = cur2;
      cur2 = cur2.next;
      cur3 = cur3.next;
    }
    else {
      cur3.next = cur1;
      cur1 = cur1.next;
      cur3 = cur3.next;
    }
  }

  return l3.next;
};

//}}


/// {{
/// Problem: 24. Swap Nodes in Pairs
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/swap-nodes-in-pairs/
/// Topics: `linked-list`, `recursion`  
/// Timestamp: `Fri, 08 Aug 2025 16:20:04 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function swapPairs (head) {
  /** @type {(ListNode | null)[]} */
  let [prev, fast, node1, node2, node3] = [null, head, null, null, null];

  while (fast && fast.next) {
   [node1, node2, node3] = [fast, fast.next, fast.next.next];

    // Swap
    (prev) && (prev.next = node2);
    node1.next = node3;
    node2.next = node1;

    if (node1 === head) {
      head = node2;
    }

    // Increment
    prev = node1, fast = node3;
  }

  return head;
}

/// }}

