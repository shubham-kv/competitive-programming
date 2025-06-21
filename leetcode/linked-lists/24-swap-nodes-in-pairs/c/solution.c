#include <stdlib.h>

/// {{
/// Problem: 24. Swap Nodes in Pairs
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/swap-nodes-in-pairs/
/// Topics: `linked-list`, `recursion`  
/// Timestamp: `Sat, 21 Jun 2025 12:02:12 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) {
  struct ListNode *prev, *cur, *next;

  for(
    prev = NULL, cur = head, next = NULL;
    cur != NULL && cur->next != NULL;
    cur = next
  ) {
    // Swap cur & cur.next
    struct ListNode *p1 = cur, *p2 = cur->next;
    next = p2->next;
    p1->next = p2->next;
    p2->next = p1;

    if (p1 == head) {
      head = p2;
    }

    if (prev != NULL) {
      prev->next = p2;
    }

    prev = p1;
  }

  return head;
}

// Case 1: head = [1 -> 2 -> 3 -> 4]

// [Running]
// (loop entry check): (cur != NULL), (4 != NULL), true, enter
// (loop iteration 2)
//   list =      1 -> 2 -> 3 -> 4 -> NULL
//   mod. =      2 -> 1 -> 3 -> 4 -> NULL
//   mod. =      2 -> 1 -> 3 ------> NULL
//   mod. =      2 -> 1 -> 3 <- 4    NULL
//   head = 2    ^
//   prev = 3              ^
//    cur = 4                   ^
//   next = NULL                     ^
// !! incorrect

// (loop initialization):
//   list =     [1 -> 2 -> 3 -> 4]
//   head = 1    ^
//   prev = 1    ^
//    cur = 2         ^
//   next = NULL
// 
// (loop entry check): (cur != NULL), (1 != NULL), true, enter
// (loop iteration 1)
//   list =     [1 -> 2 -> 3 -> 4]
//   mod. =     [1 ------> 3 -> 4]
//   mod. =     [1 <- 2    3 -> 4]
//   head = 2         ^
//   prev = 1    ^
//    cur = 2         ^
//   next = 3              ^
// 
// (loop increment 1)
//   list =     [1 -> 2 -> 3 -> 4]
//   mod. =     [2 -> 1 -> 3 -> 4]
//   head = 2    ^
//   prev = 3              ^
//    cur = 2                   ^
//   next = 3              ^

/// }}
