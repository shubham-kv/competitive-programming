// Title: Fun with sorting
// Date: 2025-07-14
// Created: Mon, 14 Jul 2025 14:25:32 +0530
// Tags: [sorting, daily-practice]

#include <memory.h>
#include <stdatomic.h>
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

/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-lsit`, `recursion`
/// Timestamp: `Mon, 14 Jul 2025 14:25:32 +0530`



// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   struct ListNode *next;
// };

struct ListNode *mergeLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode dummy = {.next = NULL};
  struct ListNode *l1 = list1, *l2 = list2, *l3 = &dummy;

  for (;;) {
    if (l1->next == NULL) {
      l3->next = l2;
      break;
    } else if (l2->next == NULL) {
      l3->next = l1;
      break;
    } else if (l2->val < l1->val) {
      l3->next = l2;
      l2 = l2->next;
      l3 = l3->next;
    } else {
      l3->next = l1;
      l1 = l1->next;
      l3 = l3->next;
    }
  }

  return dummy.next;
}

struct ListNode *sortList(struct ListNode *head) {
  struct ListNode *prev, *l1, *cur;

  for (prev = NULL, l1 = head;;) {
    // Build the first sub list
    for (
        cur = l1;
        cur && cur->next && (cur->val <= cur->next->val);
        cur = cur->next) {
    }

    if (!cur || !cur->next) {
      if (l1 == head) {
        break;
      } else {
        prev = NULL, l1 = head;
        continue;
      }
    }

    // Break the list
    struct ListNode *next = cur->next;
    cur->next = NULL;

    // Build the second sub list
    struct ListNode *l2 = next;

    for (
        cur = l2, next = cur->next;
        cur && cur->next && (cur->val <= cur->next->val);
        next = cur->next, cur = next) {
    }

    if (next) {
      cur->next = NULL;
    }

    // Merge the two sub lists l1 & l2
    struct ListNode *l3;
    l3 = mergeLists(l1, l2);

    // Link the merged list
    (prev) ? (prev->next = l3) : (head = l3);

    for (cur = l3; cur && cur->next; cur = cur->next) { }

    prev = cur;
    l1 = next;
    prev->next = next;
  }

  return head;
}

/// }}
