// Title: Fun with linked list
// Date: 2025-09-18
// Created: `Thu, 18 Sep 2025 11:13:28 +0530`
// Tags: [linked-list, daily-practice]

/// {{
/// Problem: 24. Swap Nodes in Pairs
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/swap-nodes-in-pairs/
/// Timestamp: `Thu, 18 Sep 2025 11:13:28 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function swapPairs(head) {
  if (!head) {
    return head;
  }

  const savedHead = head;

  if (head.next) {
    head = head.next;
  }

  for (
    let prev = null, cur = savedHead;
    cur && cur.next;
  ) {
    const [next, fastNext] = [cur.next, cur.next.next];

    if (prev) {
      prev.next = next;
    }

    // Swap cur & next
    next.next = cur;
    cur.next = fastNext;

    prev = cur;
    cur = fastNext;
  }

  return head;
}

/// }}


/// {{
/// Problem: 83. Remove Duplicates from Sorted List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/// Timestamp: `Thu, 18 Sep 2025 19:29:25 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates(head) {
  if (!head || !head.next) {
    return head;
  }

  /** @type {(ListNode | null)[]} */
  let [prevUnique, cur, next] = [head, head.next, null];
  prevUnique.next = null; // break link

  for (; cur; cur = next) {
    next = cur.next;

    if (cur.val > prevUnique.val) {
      cur.next = null;
      prevUnique.next = cur;
      prevUnique = prevUnique.next;
    }
  }

  return head;
}

/// }}


/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Timestamp: `Thu, 18 Sep 2025 20:15:24 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
function reorderList(head) {
  if (!head) {
    return null;
  }

  const middle = middleNode(head);
  const next = middle.next;
  middle.next = null;

  const head2 = reverseList(next);

  for (let n1 = head, n2 = head2; n1 && n2; ) {
    const savedNext1 = n1.next;
    const savedNext2 = n2.next;

    n1.next = n2;
    n2.next = savedNext1;

    n1 = savedNext1;
    n2 = savedNext2;
  }
}

/** @returns {ListNode | null} */
function middleNode(
  /** @type {ListNode} */ head
) {
  let slow = head, fast = head;
  for (; fast && fast.next; ) {
    slow = slow.next;
    fast = fast.next.next;
  }
  return slow;
}

/** @returns {ListNode | null} */
function reverseList(
  /** @type {ListNode} */ head
) {
  if (!head) {
    return null;
  }
  /** @type {(ListNode | null)[]} */
  let [prev, cur, next] = [null, head, head.next];
  for (; cur; prev = cur, cur = next) {
    next = cur.next;
    cur.next = prev;
  }
  return prev;
}

/// }}

