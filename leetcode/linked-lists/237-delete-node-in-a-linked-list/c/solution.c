#include <stdlib.h>

/// {{
/// Problem: 237. Delete Node in a Linked List  
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/delete-node-in-a-linked-list  
/// Topics: `linked-list`  
/// Timestamp: `Thu, 19 Jun 2025 20:36:21 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

void deleteNode(struct ListNode *node) {
  struct ListNode *prev, *cur, *next;

  for (
    prev = NULL, cur = node;
    cur != NULL && cur->next != NULL;
    prev = cur, cur = cur->next
  ) {
    cur->val = cur->next->val;
  }

  if (prev != NULL) {
    prev->next = NULL;
  }
}

/// }}
