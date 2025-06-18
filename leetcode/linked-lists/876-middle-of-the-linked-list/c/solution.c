#include <stdlib.h>

/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: Easy
/// Topics: `linked-list`, `two-pointers`
/// Timestamp: Wed, 18 Jun 2025 15:28:24 +0530

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head) {
  struct ListNode *fast, *slow;

  for (
      fast = head, slow = head;
      fast != NULL && fast->next != NULL;
      slow = slow->next, fast = fast->next->next)
  {
  }

  return slow;
}

// Case 1: list = [1, 2, 3, 4, 5]

// Running
// list = [1, 2, 3, 4, 5]
// slow =        ^
// fast =              ^

// Case 2: list = [1, 2, 3, 4, 5, 6]

// Running
// list = [1, 2, 3, 4, 5, 6]
// slow =           ^
// fast =                    ^

/// }}
