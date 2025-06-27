// Title: Fun with lists
// Date: 2025-06-24
// Created: Tue, 24 Jun 2025 10:21:37 +0530
// Tags: [lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 203. Remove Linked List Elements
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/remove-linked-list-elements/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Tue, 24 Jun 2025 10:22:59 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
  struct ListNode *prev, *cur;

  for (
    prev = NULL, cur = head;
    cur != NULL;
  ) {
    if (cur->val == val) {
      if (prev == NULL) {
        cur = cur->next;
        head = cur;
        continue;
      } else {
        prev->next = cur->next;
        cur = prev;   // As cur is out of the list now
      }
    }

    prev = cur;
    cur = cur->next;
  }

  return head;
}

// ==========================================
// Case 2: list = [7 -> 7 -> 7 -> 7], val = 7
// ==========================================

// (loop entry check), (cur != NULL), true
// (loop iteration 1)
// list =           [7 -> 7 -> 7 -> 7]
// mod. =           [7 ------> 7 -> 7]
// head = l[1] = 7        ^
// prev = l[0] = 7   ^
//  cur = l[1] = 7   ^
// !! this goes incorrect here

// (loop init)
// list =           [7 -> 7 -> 7 -> 7]
// head = l[0] = 7   ^
// prev = NULL       
//  cur = l[0] = 7   ^
// 
// (loop entry check), (cur != NULL), true
// (loop iteration 1)
// list =           [7 -> 7 -> 7 -> 7]
// head = l[1] = 7        ^
// prev = l[0] = 7   ^
//  cur = l[1] = 7        ^

// =========================================================
// Case 1: list = [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6], val = 6
// =========================================================

// (loop entry check), (cur != NULL), false
// (loop exit)

// (loop entry check), (cur != NULL), true
// (loop iteration 7)
// list =        1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6 -> NULL
// mod. =        1 -> 2 ------> 3 -> 4 -> 5 ------> NULL
// prev = 5                               ^             
//  cur = NULL                                      ^   

// (loop entry check), (cur != NULL), true
// (loop iteration 6)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// mod. =       [1 -> 2 ------> 3 -> 4 -> 5 -> 6]
// prev = 5                               ^     
//  cur = 6                                    ^

// (loop entry check), (cur != NULL), true
// (loop iteration 5)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// mod. =       [1 -> 2 ------> 3 -> 4 -> 5 -> 6]
// prev = 4                          ^
//  cur = 5                               ^

// (loop entry check), (cur != NULL), true
// (loop iteration 4)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// mod. =       [1 -> 2 ------> 3 -> 4 -> 5 -> 6]
// prev = 3                     ^
//  cur = 4                          ^

// (loop entry check), (cur != NULL), true
// (loop iteration 3)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// mod. =       [1 -> 2 ------> 3 -> 4 -> 5 -> 6]
// prev = 2           ^
//  cur = 3                     ^

// (loop entry check), (cur != NULL), true
// (loop iteration 2)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// prev = 2           ^
//  cur = 6                ^

// (loop init)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// prev = NULL
//  cur = 1      ^
// 
// (loop entry check), (cur != NULL), true
// (loop iteration 1)
// list =       [1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6]
// prev = 1      ^
//  cur = 2           ^

/// }}


/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Tue, 24 Jun 2025 11:26:31 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(
    struct ListNode *list1,
    struct ListNode *list2)
{
  struct ListNode merged = {.val = 0, .next = NULL};
  struct ListNode *p1 = list1, *p2 = list2, *p3 = &merged;

  for(;;) {
    if (p1 == NULL) {
      p3->next = p2;
      break;
    } else if (p2 == NULL) {
      p3->next = p1;
      break;
    } else if (p2->val < p1->val) {
      p3->next = p2;
      p2 = p2->next;
      p3 = p3->next;
    } else {
      p3->next = p1;
      p1 = p1->next;
      p3 = p3->next;
    }
  }

  return merged.next;
}

/// }}


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
