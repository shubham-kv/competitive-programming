#include <stdlib.h>

/// {{
/// Problem: 160. Intersection of Two Linked Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/intersection-of-two-linked-lists/
/// Topics: `hash-table`, `linked-list`, `two-pointers`
/// Timestamp: `Sat, 09 Aug 2025 17:25:56 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode *Node;

int listSize(Node head);

Node getIntersectionNode(Node headA, Node headB) {
  int l1Size = listSize(headA);
  int l2Size = listSize(headB);

  Node node1 = headA, node2 = headB;

  if (l1Size > l2Size) {
    const int skip = l1Size - l2Size;
    for (int i = 0; i < skip && node1->next; i++, node1 = node1->next) { }
  }
  else if (l2Size > l1Size) {
    const int skip = l2Size - l1Size;
    for (int i = 0; i < skip && node2->next; i++, node2 = node2->next) { }
  }

  for (; node1 && node2; node1 = node1->next, node2 = node2->next) {
    if (node1 == node2) {
      return node1;
    }
  }

  return NULL;
}

int listSize(Node head) {
  int size = 0;
  Node cur;
  for (cur = head; cur; cur = cur->next, size++) { }
  return size;
}

/// }}

