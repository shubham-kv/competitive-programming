// Title: Fun with Stacks
// Date: 2025-08-24
// Created: `Sun, 24 Aug 2025 15:33:15 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`
/// Timestamp: `Sun, 24 Aug 2025 15:33:15 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
function reorderList(head) {
  if (!head) { return; }

  // Get the middle & break the list after middle node
  const middle = middleNode(head);
  if (!middle) { return; }

  const next = middle.next;
  middle.next = null;

  // Push nodes onto the stack
  /** @type {ListNode[]} */
  const nodesStack = [];

  for (let node = next; node; node = node.next) {
    nodesStack.push(node);
  }

  // Iterate through the first half and the nodes in LIFO order from stack and re-order list
  for (
    let node1 = head, node1Next = null, node2 = nodesStack.pop() ?? null;
    node1 && node2;
    node1 = node1Next, node2 = nodesStack.pop() ?? null
  ) {
    node1Next = node1.next;
    node1.next = node2;
    node2.next = node1Next;
  }
}

/** @returns {ListNode | null} */
function middleNode(/** @type {ListNode} */ head) {
  /** @type {(ListNode | null)[]} */
  let [slow, fast] = [null, null];

  for (
    slow = (fast = head);
    fast && fast.next;
    slow = slow.next, fast = fast.next.next
  ) {
  }

  return slow;
}

/// }}

