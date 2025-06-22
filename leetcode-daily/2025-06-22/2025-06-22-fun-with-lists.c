// Title: Fun with lists
// Date: 2025-06-22
// Created: Sun, 22 Jun 2025 12:14:53 +0530
// Tags: [lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Sun, 22 Jun 2025 12:16:33 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(
    struct ListNode *list1,
    struct ListNode *list2)
{
  struct ListNode dest = {.val = 0, .next = NULL};
  struct ListNode *p1 = list1, *p2 = list2, *p3 = &dest;

  for (;;) {
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

  return dest.next;
}

/// }}
