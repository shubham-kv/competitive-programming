// Title: Fun with Stacks
// Date: 2025-08-24
// Created: `Sun, 24 Aug 2025 15:01:11 +0530`
// Tags: [stacks, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`
/// Timestamp: `Sun, 24 Aug 2025 15:01:11 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

#define IS_NULL(ptr) (NULL == ptr)
typedef struct ListNode *Node;

Node middleNode(Node head);

void reorderList(Node head) {
  if (IS_NULL(head)) { return; }

  Node middle = middleNode(head);
  if (IS_NULL(middle)) { return; }

  // Break the list in the middle
  Node next = middle->next;
  middle->next = NULL;

  // Push nodes onto stack
  int stackCapacity = 8, stackSize = 0;
  Node *stack = calloc(stackCapacity, sizeof(*stack));

  for (Node cur = next; cur; cur = cur->next) {
    if (stackSize >= stackCapacity) {
      stackCapacity *= 2;
      stack = realloc(stack, stackCapacity * sizeof(*stack));
    }
    stack[stackSize++] = cur;
  }

  // Iterate through and re-arrange the nodes
  for (
      Node node1 = head, node1Next = NULL, node2 = stackSize > 0 ? stack[--stackSize] : NULL;
      node1 && node2;
      node1 = node1Next, (node2 = stackSize > 0 ? stack[--stackSize] : NULL)
  ) {
    node1Next = node1->next;
    node1->next = node2;
    node2->next = node1Next;
  }

  free(stack), (stack = NULL);
}

Node middleNode(Node head) {
  Node slow, fast;
  for (slow = (fast = head); fast && fast->next;
       slow = slow->next, fast = fast->next->next) {
  }
  return slow;
}

/// }}

