#include <stdlib.h>

/// {{
/// Problem: 206. Reverse Linked List
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/reverse-linked-list/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Thu, 19 Jun 2025 18:30:55 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode *prev, *cur, *next;

  for (
    prev = NULL, cur = head, next = NULL;
    cur != NULL;
    cur = next
  ) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
  }

  return prev;
}

// Case 1: head = [1, 2, 3, 4, 5]
// [Initial]
// head =       1 -> 2 -> 3 -> 4 -> 5
// prev = NULL
//  cur = 1     ^
// next = NULL

// [Running]
// [ret] prev=5

// [loop increment 5] (cur = next)
// head =     NULL <- 1 <- 2 <- 3 <- 4 <- 5    NULL
// prev = 5                               ^
//  cur = NULL                                 ^
// next = NULL                                 ^
// 
// [loop entry check 6] (cur != NULL), (NULL != NULL), false, exit
// 

// [loop increment 4] (cur = next)
// head =     NULL <- 1 <- 2 <- 3 <- 4    5 -> NULL
// prev = 4                          ^
//  cur = 5                               ^
// next = 5                               ^
// 
// [loop entry check 5] (cur != NULL), (5 != NULL), true, enter
// 
// [iteration 5]
// head =     NULL <- 1 <- 2 <- 3 <- 4 <- 5    NULL
// prev = 5                               ^
//  cur = 5                               ^
// next = NULL                                 ^


// [loop increment 3] (cur = next)
// head =     NULL <- 1 <- 2 <- 3    4 -> 5 -> NULL
// prev = 3                     ^
//  cur = 4                          ^
// next = 4                          ^
// 
// [loop entry check 4] (cur != NULL), (4 != NULL), true, enter
// 
// [iteration 4]
// head =     NULL <- 1 <- 2 <- 3 <- 4    5 -> NULL
// prev = 4                          ^
//  cur = 4                          ^
// next = 5                               ^


// [loop increment 2] (cur = next)
// head =     NULL <- 1 <- 2    3 -> 4 -> 5 -> NULL
// prev = 2                ^
//  cur = 3                     ^
// next = 3                     ^
// 
// [loop entry check 3] (cur != NULL), (3 != NULL), true, enter
// 
// [iteration 3]
// head =     NULL <- 1 <- 2 <- 3    4 -> 5 -> NULL
// prev = 3                     ^
//  cur = 3                     ^
// next = 4                          ^


// [loop increment 1] (cur = next)
// head =     NULL <- 1    2 -> 3 -> 4 -> 5 -> NULL
// prev = 1           ^    
//  cur = 2                ^
// next = 2                ^
// [loop  entry check 2] (cur != NULL), (2 != NULL), true, enter
// [iteration 2]
// head =     NULL <- 1 <- 2    3 -> 4 -> 5 -> NULL
// prev = 2                ^
//  cur = 2                ^
// next = 3                     ^
// .
// .
// .
// [loop entry check 1] (cur != NULL), (1 != NULL), true, enter
// [iteration 1]
// head =     NULL <- 1   2 -> 3 -> 4 -> 5 -> NULL
// prev = 1           ^
//  cur = 1           ^
// next = 2               ^

/// }}
