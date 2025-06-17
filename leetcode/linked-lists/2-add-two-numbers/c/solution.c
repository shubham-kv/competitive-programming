#include <stdlib.h>

/// {{
/// Problem: 2. Add Two Numbers
/// Links: https://leetcode.com/problems/add-two-numbers/
/// Date: Tue, 17 Jun 2025 15:01:01 +0530

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
