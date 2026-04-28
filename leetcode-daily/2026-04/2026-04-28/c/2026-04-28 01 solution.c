#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 641. Design Circular Deque
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-circular-deque/
/// Topics: `array`, `linked-list`, `design`, `queue`
/// Timestamp: `Tue, 28 Apr 2026 09:39:20 +0530`

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

struct Deque {
  int *arr;
  int first, last;
  int size;
  int capacity;
};

DEQUE myCircularDequeCreate(int capacity) {
  DEQUE deque = calloc(1, sizeof(*deque));
  deque->arr = calloc(capacity, sizeof(*deque->arr));
  deque->size = 0;
  deque->capacity = capacity;
  deque->first = 0;
  deque->last = capacity - 1;

  return deque;
}

void myCircularDequeFree(DEQUE deque) {
  free(deque->arr), (deque->arr = NULL);
  free(deque), (deque = NULL);
}

bool myCircularDequeInsertFront(DEQUE deque, int value) {
  if (myCircularDequeIsFull(deque))
    return false;

  deque->first =
      (deque->first - 1 >= 0) ? deque->first - 1 : deque->capacity - 1;
  deque->arr[deque->first] = value;
  deque->size++;

  return true;
}

bool myCircularDequeInsertLast(DEQUE deque, int value) {
  if (myCircularDequeIsFull(deque))
    return false;

  deque->last = (deque->last + 1 < deque->capacity) ? deque->last + 1 : 0;
  deque->arr[deque->last] = value;
  deque->size++;

  return true;
}

bool myCircularDequeDeleteFront(DEQUE deque) {
  if (myCircularDequeIsEmpty(deque))
    return false;

  deque->arr[deque->first] = 0;
  deque->first = (deque->first + 1 < deque->capacity) ? deque->first + 1 : 0;
  deque->size--;

  return true;
}

bool myCircularDequeDeleteLast(DEQUE deque) {
  if (myCircularDequeIsEmpty(deque))
    return false;

  deque->arr[deque->last] = 0;
  deque->last = (deque->last - 1 >= 0) ? deque->last - 1 : deque->capacity - 1;
  deque->size--;

  return true;
}

inline int myCircularDequeGetFront(DEQUE deque) {
  return myCircularDequeIsEmpty(deque) ? -1 : deque->arr[deque->first];
}

inline int myCircularDequeGetRear(DEQUE deque) {
  return myCircularDequeIsEmpty(deque) ? -1 : deque->arr[deque->last];
}

inline bool myCircularDequeIsEmpty(DEQUE deque) {
  return deque->size == 0;
}

inline bool myCircularDequeIsFull(DEQUE deque) {
  return deque->size == deque->capacity;
}

/// }}
