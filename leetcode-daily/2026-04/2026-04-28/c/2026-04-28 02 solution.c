#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 641. Design Circular Deque
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-circular-deque/
/// Topics: `array`, `linked-list`, `design`, `queue`
/// Timestamp: `Tue, 28 Apr 2026 11:12:37 +0530`

#ifndef __deque_h
#define __deque_h

struct Deque;
typedef struct Deque MyCircularDeque;
typedef struct Deque *DEQUE;

DEQUE myCircularDequeCreate(int k);
 void myCircularDequeFree(DEQUE deque);

bool myCircularDequeInsertFront(DEQUE deque, int value);
bool myCircularDequeInsertLast(DEQUE deque, int value);
bool myCircularDequeDeleteFront(DEQUE deque);
bool myCircularDequeDeleteLast(DEQUE deque);
 int myCircularDequeGetFront(DEQUE deque);
 int myCircularDequeGetRear(DEQUE deque);
bool myCircularDequeIsEmpty(DEQUE deque);
bool myCircularDequeIsFull(DEQUE deque);

#endif // __deque_h

struct DequeNode;
typedef struct DequeNode *DEQUE_NODE;

struct DequeNode {
  struct DequeNode *prev;
  struct DequeNode *next;
  int val;
};

struct Deque {
  struct DequeNode *front;
  struct DequeNode *last;
  size_t size;
  size_t capacity;
};

DEQUE myCircularDequeCreate(int capacity) {
  DEQUE deque = calloc(1, sizeof(*deque));
  deque->front = NULL;
  deque->last = NULL;
  deque->size = 0;
  deque->capacity = capacity;

  return deque;
}

void myCircularDequeFree(DEQUE deque) {
  while (!myCircularDequeIsEmpty(deque)) {
    myCircularDequeDeleteLast(deque);
  }
  free(deque), (deque = NULL);
}

bool myCircularDequeInsertFront(DEQUE deque, int value) {
  if (myCircularDequeIsFull(deque))
    return false;

  DEQUE_NODE node = calloc(1, sizeof(*node));
  node->next = deque->front;
  node->val = value;

  if (deque->front != NULL) {
    deque->front->prev = node;
  } else {
    deque->last = node;
  }
  deque->front = node;
  deque->size++;

  return true;
}

bool myCircularDequeInsertLast(DEQUE deque, int value) {
  if (myCircularDequeIsFull(deque))
    return false;

  DEQUE_NODE node = calloc(1, sizeof(*node));
  node->prev = deque->last;
  node->val = value;

  if (deque->last != NULL) {
    deque->last->next = node;
  } else {
    deque->front = node;
  }
  deque->last = node;
  deque->size++;

  return true;
}

bool myCircularDequeDeleteFront(DEQUE deque) {
  if (myCircularDequeIsEmpty(deque))
    return false;

  DEQUE_NODE next = deque->front->next;

  if (next != NULL) {
    next->prev = NULL;
  }
  deque->front->next = NULL;

  free(deque->front), (deque->front = NULL);
  deque->front = next;
  deque->size--;

  if (myCircularDequeIsEmpty(deque)) {
    deque->last = NULL;
  }

  return true;
}

bool myCircularDequeDeleteLast(DEQUE deque) {
  if (myCircularDequeIsEmpty(deque))
    return false;

  DEQUE_NODE prev = deque->last->prev;

  if (prev != NULL) {
    prev->next = NULL;
  }
  deque->last->prev = NULL;

  free(deque->last), (deque->last = NULL);
  deque->last = prev;
  deque->size--;

  if (myCircularDequeIsEmpty(deque)) {
    deque->front = NULL;
  }

  return true;
}

inline int myCircularDequeGetFront(DEQUE deque) {
  return myCircularDequeIsEmpty(deque) ? -1 : deque->front->val;
}

inline int myCircularDequeGetRear(DEQUE deque) {
  return myCircularDequeIsEmpty(deque) ? -1 : deque->last->val;
}

inline bool myCircularDequeIsEmpty(DEQUE deque) {
  return deque->size == 0;
}

inline bool myCircularDequeIsFull(DEQUE deque) {
  return deque->size == deque->capacity;
}

/// }}
