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

// Case 1: list = [0,3,1,0,4,5,2,0]

// (loop entry check), (cur != NULL), true
// (loop iteration 8)
//   sum = 0
//  list =       4    3 -> 1 -> 11    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 11 ----------------> 0 -> NULL
//  curZ = 11                   ^
//   cur = 0                                         ^
//  next = NULL                                           ^

// (loop entry check), (cur != NULL), true
// (loop iteration 7)
//   sum = 11
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
//  curZ = 0                    ^
//   cur = 0                                        ^
//  next = 0                                        ^

// (loop entry check), (cur != NULL), true
// (loop iteration 6)
//   sum = 9
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
//  curZ = 0                    ^
//   cur = 2                                   ^
//  next = 2                                   ^

// (loop entry check), (cur != NULL), true
// (loop iteration 5)
//   sum = 4
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
//  curZ = 0                    ^
//   cur = 5                              ^
//  next = 5                              ^


// (loop entry check), (cur != NULL), true
// (loop iteration 4)
//   sum = 0
//  list =       4    3 -> 1 -> 0    4 -> 5 -> 2 -> 0 -> NULL
//  mod. =       4 -----------> 0 ---------------------> NULL
//  curZ = 0                    ^
//   cur = 4                         ^
//  next = 4                         ^

// (loop entry check), (cur != NULL), true
// (loop iteration 3)
//   sum = 4
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
//  curZ = 0     ^
//   cur = 0                    ^
//  next = 0                    ^

// (loop entry check), (cur != NULL), true
// (loop iteration 2)
//   sum = 3
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
//  curZ = 0     ^
//   cur = 1               ^
//  next = 1               ^

// (loop init)
//   sum = 0
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
//  curZ = NULL
//   cur = 0     ^
//  next = NULL
// 
// (loop entry check), (cur != NULL), true
// (loop iteration 1)
//   sum = 0
//  list =       0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0 -> NULL
//  curZ = 0     ^
//   cur = 3          ^
//  next = 3          ^

