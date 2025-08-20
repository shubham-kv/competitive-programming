// Title: Fun with Graphs
// Date: 2025-08-21
// Created: `Thu, 21 Aug 2025 00:16:09 +0530`
// Tags: [graphs, daily-practice]

/// {{
/// Problem: 226. Invert Binary Tree
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/invert-binary-tree/
/// Topics: `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`
/// Timestamp: `Thu, 21 Aug 2025 00:40:31 +0530`

// Definition for a binary tree node.
function TreeNode(val, left, right) {
  this.val = (val===undefined ? 0 : val)
  this.left = (left===undefined ? null : left)
  this.right = (right===undefined ? null : right)
}

function invertRecursive(/** @type {TreeNode|null} */ node) {
  if (!node) { return; }
  [node.left, node.right] = [node.right, node.left];
  invertRecursive(node.left);
  invertRecursive(node.right);
}

/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
function invertTree (root) {
  invertRecursive(root);
  return root;
}

/// }}

