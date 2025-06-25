#include <stdlib.h>

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`
/// Timestamp: `Wed, 25 Jun 2025 10:42:34 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

void reorderList(struct ListNode *head) {
  if (head == NULL || head->next == NULL || head->next->next == NULL) {
    return;
  }

  struct ListNode *prev, *fast, *slow;

  // Get to the middle node
  for (
    fast = head, prev = NULL, slow = head;
    fast != NULL && fast->next != NULL;
    fast = fast->next->next, prev = slow, slow = slow->next
  ) { }

  // Break the list at the middle node
  prev->next = NULL;

  struct ListNode *cur, *next;

  // Reverse the second sub-list
  for (
    prev = NULL, cur = slow, next = NULL;
    cur != NULL;
    cur = next
  ) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
  }

  struct ListNode dest = {.val = 0, .next = NULL};
  struct ListNode *p1, *p2, *p3;

  for (
    p1 = head, p2 = prev, p3 = &dest;
    p1 != NULL || p2 != NULL;
  ) {
    p3->next = p1;
    if (p3->next != NULL) {
      p3 = p3->next;
    }
    if (p1 != NULL) {
      p1 = p1->next;
    }

    p3->next = p2;
    if (p3->next != NULL) {
      p3 = p3->next;
    }
    if (p2 != NULL) {
      p2 = p2->next;
    }
  }

  if (head->next != NULL) {
    head->next = dest.next->next;
  }
}

/// }}
