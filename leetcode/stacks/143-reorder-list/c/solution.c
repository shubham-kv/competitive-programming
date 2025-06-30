#include <stdlib.h>

/// {{
/// Problem: 143. Reorder List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/reorder-list/
/// Topics: `linked-list`, `two-pointers`, `stack`, `recursion`
/// Timestamp: `Mon, 30 Jun 2025 14:08:44 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

void reorderList(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return;
  }

  struct ListNode *fast, *prev, *slow;
  int listLength = 0;

  // Get to the middle node
  for (
    listLength = 0, fast = head, prev = NULL, slow = head;
    fast != NULL && fast->next != NULL;
    listLength += 2, fast = fast->next->next, prev = slow, slow = slow->next
  ) { }

  // Break the list in two halves
  prev->next = NULL;

  struct ListNode *cur, *next;
  struct ListNode *stack[listLength];
  int stackSize = 0;

  // Push the second half nodes onto stack
  for (
    cur = slow, next = NULL;
    cur != NULL;
    next = cur->next, cur->next = NULL, stack[stackSize++] = cur, cur = next
  ) { }

  // Re-order the list
  struct ListNode *popped;

  for (
    cur = head, next = NULL;
    cur != NULL;
    prev = popped, cur = next
  ) {
    next = cur->next;
    popped = stack[stackSize - 1];
    stack[--stackSize] = NULL;
    cur->next = popped;
    popped->next = next;
  }

  if (stackSize > 0) {
    for (cur = prev; stackSize > 0; cur = next) {
      next = stack[stackSize - 1];
      stack[--stackSize] = NULL;
      cur->next = next;
    }
  }
}

// Case 1: list = [1 -> 2 -> 3 -> 4]

/// Re-order the list
// (loop entry check) (cur != NULL), false

// (loop entry check) (cur != NULL), true
// (loop iteration 2)
//       list =       1 -> 4 -> 2 -> 3 -> NULL
//       head = 1     ^
//        cur = NULL                      ^
//       next = NULL                      ^
//     popped = 3                    ^
//      stack =      [NULL, NULL]
//  stackSize = 0

// (loop entry check) (cur != NULL), true
// (loop iteration 1)
//       list =                 3 -> NULL
//       list =       1 -> 4 -> 2 -> NULL
//       head = 1     ^
//        cur = 2               ^
//       next = 2               ^
//     popped = 4                    ^
//      stack =      [3, NULL]
//  stackSize = 1

// (loop init)
//       list =       1 -> 2 -> NULL
//       list =                 3 -> NULL
//       list =                      4 -> NULL
//       head = 1     ^
//        cur = 1     ^
//       next = NULL
//      stack =      [3, 4]
//  stackSize = 2

/// Push second half onto stack
// listLength = 4
//       list =       1 -> 2 -> NULL
//       list =                 3 -> NULL
//       list =                      4 -> NULL
//       head = 1     ^
//       slow = 3               ^
//        cur = 4                         ^
//       next = NULL                      ^
//      stack =      [3, 4]
//  stackSize = 2

// (exec) prev->next = NULL;
// listLength = 4
//       list =       1 -> 2 -> NULL
//       list =                 3 -> 4 -> NULL
//       fast = NULL                      ^
//       prev = 2          ^
//       slow = 3               ^

// (loop entry check 3), (fast != NULL && fast->next != NULL), false

// (loop entry check 2), (fast != NULL && fast->next != NULL), true
// (loop iteration 2)
// listLength = 4
//       list =       1 -> 2 -> 3 -> 4 -> NULL
//       fast = NULL                      ^
//       prev = 2          ^
//       slow = 3               ^

// (loop entry check 1), (fast != NULL && fast->next != NULL), true
// (loop iteration 1)
// listLength = 2
//       list =      [1 -> 2 -> 3 -> 4]
//       fast = 3               ^
//       prev = 1     ^
//       slow = 2          ^

// (loop init)
// listLength = 0
//       list =      [1 -> 2 -> 3 -> 4]
//       fast = 1     ^
//       prev = NULL
//       slow = 1     ^

/// }}
