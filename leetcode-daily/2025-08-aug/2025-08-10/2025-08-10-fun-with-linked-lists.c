// Title: Fun with linked lists
// Date: 2025-08-10
// Created: `Sun, 10 Aug 2025 20:34:24 +0530`
// Tags: [linked-lists, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 707. Design Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-linked-list/
/// Topics: `linked-list`, `design`
/// Timestamp: `Sun, 10 Aug 2025 20:34:24 +0530`

typedef int Val;

struct MyListNode {
  struct MyListNode *next;
  Val val;
};
typedef struct MyListNode *Node;

typedef struct {
  Node first;
  int size;
} MyLinkedList;

typedef MyLinkedList *List;

#define IS_LIST_EMPTY(list) (((List) list)->first == NULL)

const size_t LINKED_LIST_WIDTH = sizeof(MyLinkedList);
const size_t NODE_WIDTH = sizeof(struct MyListNode);

static Node getNodeAt(List list, int index);

List myLinkedListCreate();
void myLinkedListFree(List list);
 Val myLinkedListGet(List list, int index);
void myLinkedListAddAtHead(List list, Val val);
void myLinkedListAddAtTail(List list, Val val);
void myLinkedListAddAtIndex(List list, int index, Val val);
void myLinkedListDeleteAtIndex(List list, int index);

static Node getNodeAt(List list, int index) {
  if (!(0 <= index && index < list->size)) {
    return NULL;
  }

  if (index == 0) {
    return list->first;
  }

  Node node = list->first;

  for (int i = 1; i < (index + 1); i++) {
    if (node->next) {
      node = node->next;
    } else {
      return NULL;
    }
  }

  return node;
}

List myLinkedListCreate() {
  return calloc(1, LINKED_LIST_WIDTH);
}

void myLinkedListFree(List list) {
  while (!IS_LIST_EMPTY(list)) {
    myLinkedListDeleteAtIndex(list, 0);
  }
  free(list), (list = NULL);
}

int myLinkedListGet(List list, int index) {
  Node node = getNodeAt(list, index);
  return node ? node->val : -1;
}

inline void myLinkedListAddAtHead(List list, int val) {
  myLinkedListAddAtIndex(list, 0, val);
}

inline void myLinkedListAddAtTail(List list, int val) {
  myLinkedListAddAtIndex(list, list->size, val);
}

void myLinkedListAddAtIndex(List list, int index, int val) {
  if (!(0 <= index && index <= list->size)) {
    return;
  }

  Node cur = calloc(1, NODE_WIDTH);
  cur->val = val;

  Node prev = getNodeAt(list, index - 1);

  if (prev) {
    Node next = prev->next;
    prev->next = cur;
    cur->next = next;
    list->size++;
  } else {
    if (index == 0) {
      cur->next = list->first;
      list->first = cur;
      list->size++;
    }
  }
}

void myLinkedListDeleteAtIndex(List list, int index) {
  if (!(0 <= index && index < list->size)) {
    return;
  }
  Node prev = getNodeAt(list, index - 1);

  if (prev) {
    if (prev->next) {
      Node next = prev->next->next;
      free(prev->next), (prev->next = NULL);
      prev->next = next;
      list->size--;
    }
  } else {
    if (list->first) {
      Node next = list->first->next;
      free(list->first), (list->first = NULL);
      list->first = next;
      list->size--;
    }
  }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * List list = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
*/

/// }}

