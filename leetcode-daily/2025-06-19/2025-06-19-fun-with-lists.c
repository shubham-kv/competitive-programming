// Title: Fun with lists
// Date: 2025-06-19
// Created: Thu, 19 Jun 2025 18:29:34 +0530
// Tags: [lists, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 206. Reverse Linked List
/// Difficulty: Easy
/// Links: https://leetcode.com/problems/reverse-linked-list/
/// Topics: `linked-list`, `recursion`
/// Timestamp: Thu, 19 Jun 2025 18:30:55 +0530

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
// [loop increment 5] (cur = next)
// head =     NULL <- 1 <- 2 <- 3 <- 4 <- 5    NULL
// prev = 5                               ^
//  cur = NULL                                 ^
// next = NULL                                 ^
// 
// [loop entry check 6] (cur != NULL), (NULL != NULL), false, exit
// 

// [ret] prev=5


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


/// {{
/// Problem: 234. Palindrome Linked List  
/// Difficulty: Easy  
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Thu, 19 Jun 2025 19:41:12 +053`  

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return true;
  }

  struct ListNode *fast, *slow, *prev;

  for (
    fast = head, slow = fast, prev = NULL;
    fast != NULL && fast->next != NULL;
    fast = fast->next->next
  ) {
    prev = slow;
    slow = slow->next;
  }

  // Break the list at prev -> slow
  prev->next = NULL;

  struct ListNode *cur, *next;

  // Reverse the list from slow to last node
  for (
    prev = NULL, cur = slow, next = NULL;
    cur != NULL;
    cur = next
  ) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
  }

  // Compare the two broken lists
  struct ListNode *cur1, *cur2;

  for (
    cur1 = head, cur2 = prev;
    cur1 != NULL && cur2 != NULL;
    cur1 = cur1->next, cur2 = cur2->next
  ) {
    if (cur1->val != cur2->val) {
      return false;
    }
  }

  return true;
}

/// }}


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


/// {{
/// Problem: 237. Delete Node in a Linked List  
/// Difficulty: Medium  
/// Links: https://leetcode.com/problems/delete-node-in-a-linked-list  
/// Topics: `linked-list`  
/// Timestamp: `Thu, 19 Jun 2025 20:36:21 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

void deleteNode(struct ListNode *node) {
  struct ListNode *prev, *cur, *next;

  for (
    prev = NULL, cur = node;
    cur != NULL && cur->next != NULL;
    prev = cur, cur = cur->next
  ) {
    cur->val = cur->next->val;
  }

  if (prev != NULL) {
    prev->next = NULL;
  }
}

/// }}
