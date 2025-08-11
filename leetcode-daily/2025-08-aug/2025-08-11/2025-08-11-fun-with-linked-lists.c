// Title: Fun with linked lists
// Date: 2025-08-11
// Created: `Mon, 11 Aug 2025 17:32:17 +0530`
// Tags: [linked-lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 2181. Merge Nodes in Between Zeros
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Topics: `linked-list`, `simulation`
/// Timestamp: `Mon, 11 Aug 2025 17:33:08 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode *Node;

Node mergeNodes(Node head) {
  Node cur, next, curZeroth;
  int sum;

  for (
      cur = head, next = NULL, curZeroth = NULL, sum = 0;
      cur;
      cur = next
  ) {
    next = cur->next;

    if (cur->val == 0) {
      cur->next = NULL;

      if (curZeroth) {
        curZeroth->val = sum;
        (next) && (curZeroth->next = cur);
        curZeroth = cur;
        sum = 0;
      } else {
        curZeroth = cur;
      }
    } else {
      sum += cur->val;
    }
  }

  return head;
}

/// }}


/// {{
/// Problem: 237. Delete Node in a Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/delete-node-in-a-linked-list
/// Topics: `linked-list`
/// Timestamp: `Mon, 11 Aug 2025 18:06:51 +0530`

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   struct ListNode *next;
// };

typedef struct ListNode *Node;

void deleteNode(Node node) {
  node->val = node->next->val;
  node->next = node->next->next;
}

/// }}

