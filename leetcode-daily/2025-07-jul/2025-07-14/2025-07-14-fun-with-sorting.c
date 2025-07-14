// Title: Fun with sorting
// Date: 2025-07-14
// Created: Mon, 14 Jul 2025 14:25:32 +0530
// Tags: [sorting, daily-practice]

#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-lsit`, `recursion`
/// Timestamp: `Mon, 14 Jul 2025 14:25:32 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode result = {.val = 0, .next = NULL};
  struct ListNode *l1 = list1, *l2 = list2, *dest = &result;

  for (;;) {
    if (l1 == NULL) {
      dest->next = l2;
      break;
    } else if (l2 == NULL) {
      dest->next = l1;
      break;
    } else if (l2->val < l1->val) {
      dest->next = l2;
      l2 = l2->next;
      dest = dest->next;
    } else {
      dest->next = l1;
      l1 = l1->next;
      dest = dest->next;
    }
  }

  return result.next;
}

/// }}
