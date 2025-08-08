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

