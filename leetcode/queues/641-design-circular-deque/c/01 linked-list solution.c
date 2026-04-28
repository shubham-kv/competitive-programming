#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 641. Design Circular Deque
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-circular-deque/
/// Topics: `array`, `linked-list`, `design`, `queue`  
/// Timestamp: `Wed, 30 Jul 2025 19:54:51 +0530`

typedef int Val;

struct DequeNode {
  struct DequeNode *prev, *next;
  Val value;
};
typedef struct DequeNode *Node;

typedef struct {
  Node first;
  Node last;
  size_t capacity;
  size_t size;
} MyCircularDeque;
typedef MyCircularDeque *Deque;

const size_t DEQUE_NODE_WIDTH = sizeof(struct DequeNode);
const size_t DEQUE_WIDTH = sizeof(MyCircularDeque);

#define IS_DEQUE_EMPTY(deque) (((Deque) deque)->size == 0)
#define IS_DEQUE_FULL(deque) (((Deque) deque)->size == ((Deque) deque)->capacity)

Deque myCircularDequeCreate(int capacity);
void myCircularDequeFree(Deque deque);

bool myCircularDequeInsertFront(Deque deque, Val v);
bool myCircularDequeInsertLast(Deque deque, Val v);
bool myCircularDequeDeleteFront(Deque deque);
bool myCircularDequeDeleteLast(Deque deque);
 Val myCircularDequeGetFront(Deque deque);
 Val myCircularDequeGetRear(Deque deque);
bool myCircularDequeIsEmpty(Deque deque);
bool myCircularDequeIsFull(Deque deque);


Deque myCircularDequeCreate(int capacity) {
  Deque deque = calloc(1, DEQUE_WIDTH);
  deque->capacity = capacity;
  return deque;
}

void myCircularDequeFree(Deque deque) {
  while (!IS_DEQUE_EMPTY(deque)) {
    myCircularDequeDeleteLast(deque);
  }
  free(deque), (deque = NULL);
}

bool myCircularDequeInsertFront(Deque deque, Val val) {
  if (IS_DEQUE_FULL(deque)) {
    return false;
  }

  Node node = calloc(1, DEQUE_NODE_WIDTH);
  node->value = val;

  if (deque->first) {
    deque->first->prev = node;
    node->next = deque->first;
    deque->first = node;
  } else {
    deque->first = node;
    deque->last = deque->first;
  }

  deque->size++;
  return true;
}

bool myCircularDequeInsertLast(Deque deque, Val value) {
  if (IS_DEQUE_FULL(deque)) {
    return false;
  }

  Node node = calloc(1, DEQUE_NODE_WIDTH);
  node->value = value;

  if (deque->last) {
    node->prev = deque->last;
    deque->last->next = node;
    deque->last = node;
  } else {
    deque->first = node;
    deque->last = deque->first;
  }

  deque->size++;
  return true;
}

bool myCircularDequeDeleteFront(Deque deque) {
  if (IS_DEQUE_EMPTY(deque)) {
    return false;
  }

  Node next = deque->first->next;
  free(deque->first), (deque->first = NULL);

  if (next) {
    next->prev = NULL;
    deque->first = next;
  } else {
    deque->first = NULL;
    deque->last = deque->first;
  }

  deque->size--;
  return true;
}

bool myCircularDequeDeleteLast(Deque deque) {
  if (IS_DEQUE_EMPTY(deque)) {
    return false;
  }

  Node prev = deque->last->prev;
  free(deque->last), (deque->last = NULL);

  if (prev) {
    prev->next = NULL;
    deque->last = prev;
  } else {
    deque->first = NULL;
    deque->last = deque->first;
  }

  deque->size--;
  return true;
}

inline Val myCircularDequeGetFront(Deque deque) {
  return IS_DEQUE_EMPTY(deque) ? -1 : deque->first->value;
}

inline Val myCircularDequeGetRear(Deque deque) {
  return IS_DEQUE_EMPTY(deque) ? -1 : deque->last->value;
}

inline bool myCircularDequeIsEmpty(Deque deque) {
  return IS_DEQUE_EMPTY(deque);
}

inline bool myCircularDequeIsFull(Deque deque) {
  return IS_DEQUE_FULL(deque);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 *
 * Deque deque = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(deque, value);
 * bool param_2 = myCircularDequeInsertLast(deque, value);
 * bool param_3 = myCircularDequeDeleteFront(deque);
 * bool param_4 = myCircularDequeDeleteLast(deque);
 * int param_5 = myCircularDequeGetFront(deque);
 * int param_6 = myCircularDequeGetRear(deque);
 * bool param_7 = myCircularDequeIsEmpty(deque);
 * bool param_8 = myCircularDequeIsFull(deque);
 * myCircularDequeFree(deque);
*/

/// }}
