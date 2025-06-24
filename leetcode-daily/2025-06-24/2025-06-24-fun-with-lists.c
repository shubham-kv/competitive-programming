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
