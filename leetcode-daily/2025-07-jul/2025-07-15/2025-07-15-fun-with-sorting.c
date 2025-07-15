// Title: Fun with sorting
// Date: 2025-07-15
// Created: Tue, 15 Jul 2025 14:53:19 +0530
// Tags: [sorting, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 23. Merge k Sorted Lists
/// Difficulty: `Hard`
/// Links: https://leetcode.com/problems/merge-k-sorted-lists/
/// Topics: `linked-list`, `divide-and-conquer`, `heap-(priority-queue)`, `merge-sort`
/// Timestamp: `Tue, 15 Jul 2025 14:53:19 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode merged = {.next = NULL};
  struct ListNode *l1 = list1, *l2 = list2, *l3 = &merged;

  for (;;) {
    if (l1 == NULL) {
      l3->next = l2;
      break;
    } else if (l2 == NULL) {
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

  return merged.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  if (!(listsSize > 0)) {
    return NULL;
  }

  for (int l = 1; l < listsSize; l *= 2) {
    for (int i = 0; (i + l) < listsSize; i += 2 * l) {
      lists[i] = mergeLists(lists[i], lists[i + l]);
    }
  }

  return lists[0];
}

/// }}
