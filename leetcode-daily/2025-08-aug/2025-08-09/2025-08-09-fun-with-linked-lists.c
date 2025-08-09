// Title: Fun with linked lists
// Date: 2025-08-09
// Created: `Sat, 09 Aug 2025 16:18:33 +0530`
// Tags: [linked-lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`
/// Timestamp: `Sat, 09 Aug 2025 16:18:33 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode *Node;

Node middleNode(Node head);
Node reverseList(Node head);

void reorderList(Node head) {
  Node subList1 = head;

  // Break the list into two halves from the middle node
  Node middle = middleNode(head);
  Node subList2 = middle->next;
  middle->next = NULL;

  // Reverse the second sub list
  subList2 = reverseList(subList2);

  // Re-order the two sub lists
  Node node1, node2, node1Next, node2Next;

  for (
      node1 = subList1, node2 = subList2;
      node1 && node2;
      node1 = node1Next, node2 = node2Next
  ) {
    node1Next = node1->next;
    node2Next = node2->next;
    node1->next = node2;
    node2->next = node1Next;
  }
}

Node middleNode(Node head) {
  Node fast, slow;
  for (
      fast = slow = head;
      fast && fast->next;
      slow = slow->next, fast = fast->next->next
  ) { }
  return slow;
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

