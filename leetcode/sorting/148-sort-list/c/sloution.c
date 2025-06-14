#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *linkedListMerge(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *merged = calloc(1, sizeof(struct ListNode));
  merged->next = NULL;

  struct ListNode *cur1 = list1, *cur2 = list2, *cur3 = merged;

  for(;;) {
    if (cur1 == NULL) {
      cur3->next = cur2;
      break;
    }
    else if (cur2 == NULL) {
      cur3->next = cur1;
      break;
    }
    else if (cur2->val < cur1->val) {
      cur3->next = cur2;
      cur2 = cur2->next;
      cur3 = cur3->next;
    }
    else {
      cur3->next = cur1;
      cur1 = cur1->next;
      cur3 = cur3->next;
    }
  }

  return merged->next;
}

struct ListNode *sortList(struct ListNode *head) {
  struct ListNode *prev, *list1;

  for (prev = NULL, list1 = head; ;) {
    struct ListNode *cur;

    // 1. Find the left sub-array
    // Loop until a node is out of order or it's next is null
    for (
      cur = list1;
      cur != NULL && cur->next != NULL && cur->val <= cur->next->val;
      cur = cur->next
    ) { }

    // Check if something's left
    if (cur == NULL || cur->next == NULL) {
      if (list1 == head) {
        // Nothing left to sort
        break;
      } else {
        prev = NULL;
        list1 = head;
        continue;
      }
    }

    // 2. Find the right sub-array
    struct ListNode *list2 = cur->next;

    // Break the list here at current node
    cur->next = NULL;

    // Loop until a node is out of order or it's next is null
    for (
      cur = list2;
      cur != NULL && cur->next != NULL && cur->val <= cur->next->val;
      cur = cur->next
    ) { }

    struct ListNode *next = NULL;

    if (cur != NULL && cur->next != NULL) {
      next = cur->next;
      cur->next = NULL;
    }

    // 3. Merge the two sub-arrays
    struct ListNode *merged = linkedListMerge(list1, list2);

    // Link the returned merged list with previous node
    if (list1 == head) {
      head = merged;
    } else {
      prev->next = merged;
    }

    // Iterate to the last node of the returned list
    for (
      cur = merged;
      cur != NULL && cur->next != NULL;
      cur = cur->next
    ) {}

    // Link the returned merged list with the next node
    prev = cur;
    list1 = next;
    prev->next = list1;
  }

  return head;
}
