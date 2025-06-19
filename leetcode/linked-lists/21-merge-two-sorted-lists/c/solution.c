#include <stdlib.h>

/// {{
/// Problem: 21. Merge Two Sorted Lists  
/// Difficulty: Easy  
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/  
/// Topics: `linked-list`, `recursion`  
/// Timestamp: `Thu, 19 Jun 2025 18:30:55 +0530`

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
  struct ListNode *cur1 = list1, *cur2 = list2, *cur3 = &dest;

  for (;;) {
    if (cur1 == NULL) {
      cur3->next = cur2;
      break;
    } else if (cur2 == NULL) {
      cur3->next = cur1;
      break;
    } else if (cur2->val < cur1->val) {
      cur3->next = cur2;
      cur2 = cur2->next;
      cur3 = cur3->next;
    } else {
      cur3->next = cur1;
      cur1 = cur1->next;
      cur3 = cur3->next;
    }
  }

  return dest.next;
}

/// }}
