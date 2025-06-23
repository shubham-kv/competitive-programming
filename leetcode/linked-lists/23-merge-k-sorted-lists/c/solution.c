#include <stdlib.h>

/// {{
/// Problem: 23. Merge k Sorted Lists
/// Difficulty: `Hard`
/// Links: https://leetcode.com/problems/merge-k-sorted-lists/
/// Topics: `linked-list`, `divide-and-conquer`, `heap-(priority-queue)`, `merge-sort`
/// Timestamp: `Mon, 23 Jun 2025 12:34:58 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(
    struct ListNode *list1,
    struct ListNode *list2)
{
  struct ListNode dest = { .val = 0, .next = NULL };
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

struct ListNode *mergeKLists(
    struct ListNode **lists,
    int listsSize)
{
  if (listsSize == 0) {
    return NULL;
  } else if (listsSize == 1) {
    return lists[0];
  }

  struct ListNode result = { .val = 0, .next = NULL };
  const int n = listsSize;

  for (int l = 1; l < n; l *= 2) {
    for (int i = 0; (i + l) <= n - 1; i += 2 * l) {
      lists[i] = mergeTwoLists(lists[i], lists[i + l]);
      lists[i + l] = NULL;
    }
  }

  return lists[0];
}

// Idea:
// lists = [listA, listB, listC, listD, listE]
// Merge listA & listB
// [listAandBMerged, NULL, listC, listD, listE]

// Merge listC & listD
// [listAandBMerged, NULL, listCandDMerged, NULL, listE]

// Merge listAandBMerged & listCandDMerged
// [listABandCDMerged, NULL, NULL, NULL, listE]

// Merge listABandCDMerged & listE
// [listABCDandEMerged, NULL, NULL, NULL, NULL]

// return lists[0]

/// }}
