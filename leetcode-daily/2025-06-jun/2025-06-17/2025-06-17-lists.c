// Title: Fun with lists
// Date: 2025-06-17
// Created: Tue, 17 Jun 2025 12:52:02 +0530
// Tags: [lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 2. Add Two Numbers
/// Links: https://leetcode.com/problems/add-two-numbers/

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

#define IS_NOT_NULL(p) (NULL != p)

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *p1 = l1, *p2 = l2;
  struct ListNode *l3 = NULL, *p3 = l3;
  int carry = 0, sum = 0;

  while (IS_NOT_NULL(p1) || IS_NOT_NULL(p2) || carry == 1) {
    sum = 0;
    (IS_NOT_NULL(p1)) && (sum += p1->val);
    (IS_NOT_NULL(p2)) && (sum += p2->val);
    sum += carry;

    if (sum > 9) {
      carry = 1;
      sum = sum % 10;
    } else {
      carry = 0;
    }

    struct ListNode *sumNode = calloc(1, sizeof(struct ListNode));
    sumNode->val = sum;
    sumNode->next = NULL;

    if (IS_NOT_NULL(p3)) {
      p3->next = sumNode;
      p3 = sumNode;
    } else {
      l3 = sumNode;
      p3 = l3;
    }

    (IS_NOT_NULL(p1)) && (p1 = p1->next);
    (IS_NOT_NULL(p2)) && (p2 = p2->next);
  }

  return l3;
}

/// }}

/// {{
/// Problem: 148. Sort List
/// Links: https://leetcode.com/problems/sort-list/
/// Created: Tue, 17 Jun 2025 15:04:59 +0530

struct ListNode *mergeList(
  struct ListNode *l1,
  struct ListNode *l2
) {
  struct ListNode dest = {.val = 0, .next = NULL};
  struct ListNode *cur1 = l1, *cur2 = l2, *cur3 = &dest;

  for (;;) {
    if (cur1 == NULL) {
      cur3->next = cur2;
      break;
    }
    else if (cur2 == NULL) {
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

struct ListNode *sortList(struct ListNode *head) {
  struct ListNode *prev = NULL, *l1 = head;

  for (; ;) {
    // Make left sub-list
    struct ListNode *cur = l1;

    for (
      cur = l1;
      cur != NULL && cur->next != NULL && cur->val <= cur->next->val;
      cur = cur->next
    ) { }

    if (cur == NULL || cur->next == NULL) {
      if (l1 == head) {
        // Nothing to sort
        break;
      } else {
        // Loop from the start of the list
        prev = NULL;
        l1 = head;
        continue;
      }
    }

    // Break the list here to make left sub-list
    struct ListNode *next = cur->next;
    cur->next = NULL;

    // Make right sub-list
    struct ListNode *l2 = next;

    // Iterate until an out of order node or null node is found
    for (
      cur = l2;
      cur != NULL && cur->next != NULL && cur->val <= cur->next->val;
      cur = cur->next
    ) { }

    // Break the list here at cur node to make right sub-list
    next = NULL;
    if (cur != NULL && cur->next != NULL) {
      next = cur->next;
      cur->next = NULL;
    }

    // Merge the two sub-lists
    struct ListNode *merged = mergeList(l1, l2);

    // Link the new merged list between prev & next nodes
    if (prev != NULL) {
      prev->next = merged;
    } else {
      head = merged;
    }

    // Iterate to find the last node of the new merged list
    for (
      cur = merged;
      cur != NULL && cur->next != NULL;
      cur = cur->next
    ) { }

    prev = cur;
    l1 = next;
    prev->next = l1;
  }

  return head;
}

/// }}
