#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Thu, 21 Aug 2025 23:56:31 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
typedef struct ListNode *Node;

Node lowerMiddleNode(Node head);

bool isPalindrome(Node head) {
  if (!head->next) {
    return true;
  }

  // Break the list from the middle
  Node middle = lowerMiddleNode(head);
  const Node next = middle->next;
  middle->next = NULL;

  // Push the second half onto stack
  int stackCapacity = 16, stackSize = 0;
  Node *stack = calloc(stackCapacity, sizeof(Node));

  for (Node cur = next; cur != NULL; cur = cur->next) {
    if (stackSize >= stackCapacity) {
      stackCapacity *= 2;
      stack = realloc(stack, stackCapacity * sizeof(Node));
    }
    stack[stackSize++] = cur;
  }

  // Compare
  for (
      Node node1 = head, node2 = stack[--stackSize];
      node1 && node2;
      node1 = node1->next, (node2 = stackSize > 0 ? stack[--stackSize] : NULL)
  ) {
    if (node1->val != node2->val) {
      free(stack), (stack = NULL);
      return false;
    }
  }

  free(stack), (stack = NULL);
  return true;
}

Node lowerMiddleNode(Node head) {
  Node prev = NULL, slow = NULL, fast = NULL;

  for (
      prev = NULL, slow = fast = head;
      fast && fast->next;
      fast = fast->next->next
  ) {
    prev = slow;
    slow = slow->next;
  }

  return prev;
}

/// }}

