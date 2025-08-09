#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Sat, 09 Aug 2025 18:25:21 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode *Node;

Node lowerMiddleNode(Node head);
Node reverseList(Node head);

bool isPalindrome(Node head) {
  if (head->next == NULL) {
    return true;
  }

  Node l1, l2;
  l1 = head;

  // Break the list into two halves from the middle
  Node middle = lowerMiddleNode(head);
  l2 = middle->next;
  middle->next = NULL;

  // Reverse the second half
  l2 = reverseList(l2);

  // Check the first half with reversed second half
  Node node1, node2;
  for (
      node1 = l1, node2 = l2;
      node1 && node2;
      node1 = node1->next, node2 = node2->next
  ) {
    if (node1->val != node2->val) {
      return false;
    }
  }

  return true;
}

Node lowerMiddleNode(Node head) {
  Node fast, slow, prev;
  for (
      fast = slow = head, prev = NULL;
      fast && fast->next;
      prev = slow, slow = slow->next, fast = fast->next->next
  ) { }
  return prev;
}

Node reverseList(Node head) {
  Node prev, cur, next;
  for (
      prev = next = NULL, cur = head;
      cur;
      prev = cur, cur = next
  ) {
    next = cur->next;
    cur->next = prev;
  }
  return prev;
}

/// }}
