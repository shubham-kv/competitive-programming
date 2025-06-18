// Title: Fun with lists
// Date: 2025-06-18
// Created: Wed, 18 Jun 2025 14:37:16 +0530
// Tags: [lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 160. Intersection of Two Linked Lists
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/intersection-of-two-linked-lists/
/// Topics: `hash-table`, `linked-list`, `two-pointers`
/// Timestamp: Wed, 18 Jun 2025 14:41:30 +0530

// Definition for singly-linked list.
struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *getIntersectionNode(
    struct ListNode *headA,
    struct ListNode *headB)
{
  struct ListNode *p1 = headA, *p2 = headB;
  int listASize = 0, listBSize = 0;

  if (!(headA != NULL && headB != NULL)) {
    return NULL;
  }

  // 1. Count the number of nodes in both lists
  for (
      p1 = headA, listASize = 1;
      p1->next != NULL;
      p1 = p1->next, listASize++)
  { }

  for (
      p2 = headB, listBSize = 1;
      p2->next != NULL;
      p2 = p2->next, listBSize++)
  { }

  if (!(listASize > 0 && listBSize > 0)) {
    return NULL;
  }

  // 2. Check if the last node is the same node in both lists
  if (!(p1 == p2)) {
    // The tow lists don't intersect
    return NULL;
  }

  // 3. Offset both pointers to equal distance from the end
  p1 = headA;
  p2 = headB;

  if (listASize > listBSize) {
    int i, skip = listASize - listBSize;

    for (
        i = 0, p1 = headA;
        i < skip && p1->next != NULL;
        i++, p1 = p1->next)
    { }
  } else if (listBSize > listASize) {
    int i, skip = listBSize - listASize;

    for (
        i = 0, p2 = headB;
        i < skip && p2->next != NULL;
        i++, p2 = p2->next)
    { }
  }

  for (
    ;
    p1 != NULL && p2 != NULL;
    p1 = p1->next, p2 = p2->next
  ) {
    if (p1 == p2 && p1->val == p2->val) {
      return p1;
    }
  }

  return NULL;
}

/// }}
