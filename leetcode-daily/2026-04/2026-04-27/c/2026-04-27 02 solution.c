
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 641. Design Circular Deque
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-circular-deque/
/// Topics: `array`, `linked-list`, `design`, `queue`  
/// Timestamp: `Mon, 27 Apr 2026 06:50:55 +0530`

#ifndef __dequeue
#define __dequeue

struct Dequeue;
typedef struct Dequeue MyCircularDeque;
typedef struct Dequeue *DEQUEUE;

DEQUEUE myCircularDequeCreate(int k);
   bool myCircularDequeInsertFront(DEQUEUE dequeue, int value);
   bool myCircularDequeInsertLast(DEQUEUE dequeue, int value);
   bool myCircularDequeDeleteFront(DEQUEUE dequeue);
   bool myCircularDequeDeleteLast(DEQUEUE dequeue);
    int myCircularDequeGetFront(DEQUEUE dequeue);
    int myCircularDequeGetRear(DEQUEUE dequeue);
   bool myCircularDequeIsEmpty(DEQUEUE dequeue);
   bool myCircularDequeIsFull(DEQUEUE dequeue);
   void myCircularDequeFree(DEQUEUE dequeue);

#endif // __dequeue


struct Dequeue {
  int *arr;
  int first;
  int last;
  int size;
  int capacity;
};


DEQUEUE myCircularDequeCreate(int k) {
  DEQUEUE dequeue = calloc(1, sizeof(*dequeue));
  dequeue->arr = calloc(k, sizeof(*dequeue->arr));
  dequeue->first = 0;
  dequeue->last = 0;
  dequeue->size = 0;
  dequeue->capacity = k;

  return dequeue;
}

void myCircularDequeFree(DEQUEUE dequeue) {
  free(dequeue->arr), (dequeue->arr = NULL);
  free(dequeue), (dequeue = NULL);
}

bool myCircularDequeInsertFront(DEQUEUE dequeue, int value) {
  if (dequeue->size >= dequeue->capacity) return false;

  dequeue->arr[dequeue->first++] = value;
  
  return true;
}

bool myCircularDequeInsertLast(DEQUEUE dequeue, int value) {}

bool myCircularDequeDeleteFront(DEQUEUE dequeue) {}

bool myCircularDequeDeleteLast(DEQUEUE dequeue) {}

int myCircularDequeGetFront(DEQUEUE dequeue) {}

int myCircularDequeGetRear(DEQUEUE dequeue) {}

inline bool myCircularDequeIsEmpty(DEQUEUE dequeue) {
  return dequeue->size == 0;
}

bool myCircularDequeIsFull(DEQUEUE dequeue) {
  return dequeue->size == dequeue->capacity;
}


/// }}
