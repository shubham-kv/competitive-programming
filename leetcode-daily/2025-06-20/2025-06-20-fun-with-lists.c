// Title: Fun with lists
// Date: 2025-06-20
// Created: Fri, 20 Jun 2025 10:40:38 +0530
// Tags: [lists, daily-practice]

#include <stdlib.h>
#include <math.h>

/// {{
/// Problem: 83. Remove Duplicates from Sorted List  
/// Difficulty: Easy  
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-list/  
/// Topics: `linked-list`  
/// Timestamp: `Fri, 20 Jun 2025 10:41:42 +0530`  

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode *cur, *next, *curNonDuplicate;

  for (
    cur = head, next = NULL, curNonDuplicate = cur;
    cur != NULL;
    cur = next
  ) {
    next = cur->next;

    if (cur->val > curNonDuplicate->val) {
      curNonDuplicate->next = cur;
      curNonDuplicate = curNonDuplicate->next;
    } else {
      curNonDuplicate->next = NULL;
    }
  }

  return head;
}

// Case 1: head = [1 -> 1 -> 2 -> 3 -> 3]

// [Running]
// (ret) head = 1 ------> 2 -> 3 -> 3 -> NULL
// which is incorrect

// (loop increment) (curOriginal = curOriginal->next)
//   original head =    [1 -> 1 -> 2 -> 3 -> 3]
//   modified head =     1 ------> 2 -> 3 -> 3 -> NULL
//     curOriginal = NULL                         ^
// curNonDuplicate = 3                  ^
// 
// (loop entry check) (curOriginal != NULL), (NULL != NULL), false, exit


// (loop increment) (curOriginal = curOriginal->next)
//   original head =    [1 -> 1 -> 2 -> 3 -> 3]
//   modified head =    [1 ------> 2 -> 3 -> 3]
//     curOriginal = 3                       ^
// curNonDuplicate = 3                  ^
// 
// (loop entry check) (curOriginal != NULL), (3 != NULL), true, enter
// (iteration 4)
//   original head =    [1 -> 1 -> 2 -> 3 -> 3]
//   modified head =    [1 ------> 2 -> 3 -> 3]
//     curOriginal = 3                       ^
// curNonDuplicate = 3                  ^


// (loop increment) (curOriginal = curOriginal->next)
//   original head =    [1 -> 1 -> 2 -> 3 -> 3]
//   modified head =    [1 ------> 2 -> 3 -> 3]
//     curOriginal = 3                  ^
// curNonDuplicate = 2             ^
// 
// (loop entry check) (curOriginal != NULL), (3 != NULL), true, enter
// (iteration 4)
//   original head =    [1 -> 1 -> 2 -> 3 -> 3]
//   modified head =    [1 ------> 2 -> 3 -> 3]
//     curOriginal = 3                  ^
// curNonDuplicate = 3                  ^


// (loop increment) (curOriginal = curOriginal->next)
//            head =    [1 -> 1 -> 2 -> 3 -> 3]
//     curOriginal = 2             ^
// curNonDuplicate = 1   ^
// 
// (loop entry check) (curOriginal != NULL), (2 != NULL), true, enter
// (iteration 3)
//   original head =    [1 -> 1 -> 2 -> 3 -> 3]
//   modified head =    [1 ------> 2 -> 3 -> 3]
//     curOriginal = 2             ^
// curNonDuplicate = 2             ^


// (loop increment) (curOriginal = curOriginal->next)
//            head =    [1 -> 1 -> 2 -> 3 -> 3]
//     curOriginal = 1        ^
// curNonDuplicate = 1   ^
// 
// (loop entry check) (curOriginal != NULL), (1 != NULL), true, enter
// (iteration 2)
//            head =    [1 -> 1 -> 2 -> 3 -> 3]
//     curOriginal = 1        ^
// curNonDuplicate = 1   ^


// (loop initialization)
//            head =    [1 -> 1 -> 2 -> 3 -> 3]
//     curOriginal = 1   ^
// curNonDuplicate = 1   ^
// 
// (loop entry check) (curOriginal != NULL), (1 != NULL), true, enter
// (iteration 1)
//            head =    [1 -> 1 -> 2 -> 3 -> 3]
//     curOriginal = 1   ^
// curNonDuplicate = 1   ^

/// }}


/// {{
/// Problem: 1290. Convert Binary Number in a Linked List to Integer
/// Difficulty: Easy  
/// Links: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
/// Topics: `linked-list`, `math`  
/// Timestamp: `Fri, 20 Jun 2025 11:23:18 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

int getDecimalValue(struct ListNode *head) {
  struct ListNode *cur;
  int numberOfNodes = 0, decimal, i;

  for (
    cur = head;
    cur != NULL;
    cur = cur->next, numberOfNodes++
  ) { }

  for (
    cur = head, i = numberOfNodes - 1, decimal = 0;
    cur != NULL;
    cur = cur->next, i--
  ) {
    if (i >= 0) {
      decimal += cur->val * pow(2, i);
    }
  }

  return decimal;
}

/// }}
