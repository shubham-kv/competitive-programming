// Title: Fun with linked lists
// Date: 2025-08-09
// Created: `Sat, 09 Aug 2025 16:18:33 +0530`
// Tags: [linked-lists, daily-practice]

#include <stdlib.h>
#include <stdbool.h>

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

Node middleNode1(Node head);
Node reverseList1(Node head);

void reorderList(Node head) {
  Node subList1 = head;

  // Break the list into two halves from the middle node
  Node middle = middleNode1(head);
  Node subList2 = middle->next;
  middle->next = NULL;

  // Reverse the second sub list
  subList2 = reverseList1(subList2);

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

Node middleNode1(Node head) {
  Node fast, slow;
  for (
      fast = slow = head;
      fast && fast->next;
      slow = slow->next, fast = fast->next->next
  ) { }
  return slow;
}

Node reverseList1(Node head) {
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


/// {{
/// Problem: 160. Intersection of Two Linked Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/intersection-of-two-linked-lists/
/// Topics: `hash-table`, `linked-list`, `two-pointers`
/// Timestamp: `Sat, 09 Aug 2025 17:25:56 +0530`

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
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


/// {{
/// Problem: 206. Reverse Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/reverse-linked-list/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Sat, 09 Aug 2025 18:08:27 +0530`

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

typedef struct ListNode *Node;

Node reverseLis2(Node head) {
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


/// {{
/// Problem: 234. Palindrome Linked List
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/palindrome-linked-list/  
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`  
/// Timestamp: `Sat, 09 Aug 2025 18:25:21 +0530`

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   struct ListNode *next;
// };
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


/// {{
/// Problem: 876. Middle of the Linked List
/// Link: https://leetcode.com/problems/middle-of-the-linked-list/
/// Difficulty: `Easy`
/// Topics: `linked-list`, `two-pointers`
/// Timestamp: `Sat, 09 Aug 2025 19:11:09 +0530`

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   struct ListNode *next;
// };
typedef struct ListNode *Node;

Node middleNode(Node head) {
  Node slow, fast;

  for (
      slow = fast = head;
      fast && fast->next;
      slow = slow->next, fast = fast->next->next
  ) { }

  return slow;
}

/// }}

