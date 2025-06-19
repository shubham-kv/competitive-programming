#include <stdbool.h>
#include <stdlib.h>

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
