// Title: Fun with lists
// Date: 2025-06-23
// Created: Mon, 23 Jun 2025 10:05:03 +0530
// Tags: [lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 707. Design Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-linked-list/
/// Topics: `linked-list`, `design`
/// Timestamp: `Mon, 23 Jun 2025 10:06:49 +0530`

#if !defined(__my_linked_list_h)
#define __my_linked_list_h

struct MyListNode {
  int val;
  struct MyListNode *next;
};

typedef struct MyLinkedList {
  int size;
  struct MyListNode *head;
} MyLinkedList;

MyLinkedList *myLinkedListCreate();
void myLinkedListFree(MyLinkedList *list);

int myLinkedListGet(MyLinkedList *list, int index);
void myLinkedListAddAtHead(MyLinkedList *list, int val);
void myLinkedListAddAtTail(MyLinkedList *list, int val);
void myLinkedListAddAtIndex(MyLinkedList *list, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList *list, int index);

#define MY_LINKED_LIST_SIZE(ptr) (((MyLinkedList *)ptr)->size)
#define MY_LINKED_LIST_IS_EMPTY(ptr) (((MyLinkedList *)ptr)->size == 0)

#endif // __my_linked_list_h

MyLinkedList *myLinkedListCreate() {
  MyLinkedList *list = calloc(1, sizeof(MyLinkedList));
  list->head = NULL;
  list->size = 0;
  return list;
}

void myLinkedListFree(MyLinkedList *list) {
  while (!MY_LINKED_LIST_IS_EMPTY(list)) {
    myLinkedListDeleteAtIndex(list, 0);
  }
  free(list);
}

int myLinkedListGet(MyLinkedList *list, int index) {
  if (MY_LINKED_LIST_IS_EMPTY(list)) {
    return -1;
  }

  if (!(0 <= index && index <= MY_LINKED_LIST_SIZE(list) - 1)) {
    return - 1;
  }

  struct MyListNode *cur;
  int i;

  for (
    i = 0, cur = list->head;
    i < index && cur != NULL && cur->next != NULL;
    i++, cur = cur->next
  ) { }

  return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList *list, int val) {
  myLinkedListAddAtIndex(list, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList *list, int val) {
  myLinkedListAddAtIndex(list, MY_LINKED_LIST_SIZE(list), val);
}

void myLinkedListAddAtIndex(MyLinkedList *list, int index, int val) {
  if (!(0 <= index && index <= MY_LINKED_LIST_SIZE(list))) {
    return;
  }

  struct MyListNode *newNode = calloc(1, sizeof(struct MyListNode));
  newNode->val = val;
  newNode->next = NULL;

  if (index == 0) {
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
  } else {
    struct MyListNode *cur, *next;
    int i; 

    for (
      i = 0, cur = list->head, next = cur->next;
      i < (index - 1) && cur != NULL && cur->next != NULL;
      i++, cur = next, next = cur->next
    ) { }

    cur->next = newNode;
    newNode->next = next;
    list->size++;
  }
}

void myLinkedListDeleteAtIndex(MyLinkedList *list, int index) {
  if (!(0 <= index && index <= MY_LINKED_LIST_SIZE(list) - 1)) {
    return;
  }

  if (index == 0) {
    struct MyListNode *next = list->head->next;
    free(list->head);
    list->head = next;
    list->size--;
  } else {
    struct MyListNode *cur, *next;
    int i; 

    for (
      i = 0, cur = list->head, next = cur->next;
      i < (index - 1) && cur != NULL && cur->next != NULL;
      i++, cur = next, next = cur->next
    ) { }

    cur->next = next->next;
    free(next);
    list->size--;
  }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 *
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

/// }}


/// {{
/// Problem: 19. Remove Nth Node From End of List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/// Topics: `linked-list`, `two-pointers`
/// Timestamp: `Mon, 23 Jun 2025 11:56:21 +0530`

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  if (head == NULL) {
    return NULL;
  }

  int size;
  struct ListNode *cur, *next;

  for (
    size = 0, cur = head;
    cur != NULL;
    size++, cur = cur->next
  ) { }

  int i;
  for (
    i = 0, cur = head, next = cur->next;
    i < (size - n - 1) && cur != NULL && cur->next != NULL;
    i++, cur = cur->next, next = cur->next
  ) { }

  if (i == 0) {
    if (next == NULL) {
      cur->next = NULL;
      head = NULL;
    } else {
      cur->next = next->next;
      head = next->next;
    }
  } else {
    if (next == NULL) {
      cur->next = NULL;
    } else {
      cur->next = next->next;
    }
  }

  return head;
}

/// }}
