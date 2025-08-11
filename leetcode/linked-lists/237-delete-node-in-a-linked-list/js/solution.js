/// {{
/// Problem: 237. Delete Node in a Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/delete-node-in-a-linked-list
/// Topics: `linked-list`
/// Timestamp: `Mon, 11 Aug 2025 18:06:51 +0530`

// Definition for singly-linked list.
function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
function deleteNode(node) {
  node.val = node.next.val;
  node.next = node.next.next;
}

/// }}

