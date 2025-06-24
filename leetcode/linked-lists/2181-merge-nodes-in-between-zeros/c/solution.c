#include <stdlib.h>

/// {{
/// Problem: 2181. Merge Nodes in Between Zeros
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-nodes-in-between-zeros/
/// Topics: `linked-list`, `simulation`
/// Timestamp: `Tue, 24 Jun 2025 11:43:39 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeNodes(struct ListNode *head) {
  struct ListNode *prevZeroth, *cur, *next;
  int sum = 0;

  for (
    prevZeroth = NULL, cur = head, next = NULL;
    cur != NULL;
    cur = next
  ) {
    next = cur->next;

    if (cur->val == 0) {
      if (prevZeroth != NULL) {
        prevZeroth->val = sum;
        sum = 0;

        if (next != NULL && next->val != 0) {
          prevZeroth->next = cur;
        }
      }
      cur->next = NULL;
      prevZeroth = cur;
    } else {
      sum += cur->val;
    }
  }

  return head;
}

// Case 1: list = [0,3,1,0,4,5,2,0]

// (loop entry check), (cur != NULL), true
// (loop iteration 8)
//   sum = 0
//  list =       4    3 -> 1 -> 11    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 11 ----------------> 0 -> NULL
// prevZ = 11                   ^
//   cur = 0                                         ^
//  next = NULL                                           ^

// (loop entry check), (cur != NULL), true
// (loop iteration 7)
//   sum = 11
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
// prevZ = 0                    ^
//   cur = 0                                        ^
//  next = 0                                        ^

// (loop entry check), (cur != NULL), true
// (loop iteration 6)
//   sum = 9
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
// prevZ = 0                    ^
//   cur = 2                                   ^
//  next = 2                                   ^

// (loop entry check), (cur != NULL), true
// (loop iteration 5)
//   sum = 4
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
// prevZ = 0                    ^
//   cur = 5                              ^
//  next = 5                              ^


// (loop entry check), (cur != NULL), true
// (loop iteration 4)
//   sum = 0
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
// prevZ = 0                    ^
//   cur = 4                         ^
//  next = 4                         ^

// (loop entry check), (cur != NULL), true
// (loop iteration 3)
//   sum = 4
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
// prevZ = 0     ^
//   cur = 0                    ^
//  next = 0                    ^

// (loop entry check), (cur != NULL), true
// (loop iteration 2)
//   sum = 3
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
// prevZ = 0     ^
//   cur = 1               ^
//  next = 1               ^

// (loop init)
//   sum = 0
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
// prevZ = NULL
//   cur = 0     ^
//  next = NULL
// 
// (loop entry check), (cur != NULL), true
// (loop iteration 1)
//   sum = 0
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
// prevZ = 0     ^
//   cur = 3          ^
//  next = 3          ^

/// }}
