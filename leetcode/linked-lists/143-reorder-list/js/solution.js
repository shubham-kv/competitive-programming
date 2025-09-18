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

  for (let n1 = head, n2 = head2; n1 && n2;) {
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
  for (; fast && fast.next;) {
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

