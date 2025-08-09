#include <stdlib.h>

/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: `Easy`
/// Topics: `linked-list`, `two-pointers`
/// Timestamp: `Sat, 09 Aug 2025 19:11:09 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode *Node;

Node middleNode(Node head) {
  Node slow, fast;

  for (
      slow = fast = head;
      fast && fast->next;
      slow = slow->next, fast = fast->next->next
  ) { }

  return slow;
}

/// }}

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

