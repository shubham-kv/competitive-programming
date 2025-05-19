#include <stdbool.h>
#include <stdlib.h>
#include "fixed_capacity_deque.h"

MyCircularDeque *myCircularDequeCreate(int k)
{
  MyCircularDeque *deque = calloc(1, sizeof(MyCircularDeque));
  deque->capacity = k;
  deque->size = 0;
  deque->first = NULL;
  deque->last = NULL;
  return deque;
}

void myCircularDequeFree(MyCircularDeque *deque)
{
  while (!IS_DEQUE_EMPTY(deque))
    myCircularDequeDeleteLast(deque);
  
  free(deque);
}

bool myCircularDequeInsertFront(MyCircularDeque *deque, int value)
{
  if (IS_DEQUE_FULL(deque))
    return false;

  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = value;
  newNode->prev = NULL;
  newNode->next = deque->first;

  if (IS_DEQUE_EMPTY(deque)) {
    deque->first = newNode;
    deque->last = newNode;
  } else {
    deque->first->prev = newNode;
    deque->first = newNode;
  }
  deque->size++;

  return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *deque, int value)
{
  if (IS_DEQUE_FULL(deque))
    return false;

  struct Node *newNode = calloc(1, sizeof(struct Node));
  newNode->data = value;
  newNode->prev = deque->last;
  newNode->next = NULL;

  if (IS_DEQUE_EMPTY(deque)) {
    deque->first = newNode;
    deque->last = newNode;
  } else {
    deque->last->next = newNode;
    deque->last = newNode;
  }
  deque->size++;

  return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *deque)
{
  if (IS_DEQUE_EMPTY(deque))
    return false;

  struct Node *oldFirstNode = deque->first;
  struct Node *newFirstNode = deque->first->next;

  if (newFirstNode) {
    newFirstNode->prev = NULL;
  } else {
    deque->last = NULL;
  }

  deque->first = newFirstNode;
  deque->size--;
  free(oldFirstNode);

  return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *deque)
{
  if (IS_DEQUE_EMPTY(deque))
    return false;

  struct Node *oldLastNode = deque->last;
  struct Node *newLastNode = deque->last->prev;

  if (newLastNode) {
    newLastNode->next = NULL;
  }

  if (newLastNode == NULL) {
    deque->first = NULL;
  }
  deque->last = newLastNode;
  deque->size--;
  free(oldLastNode);

  return true;
}

int myCircularDequeGetFront(MyCircularDeque *deque)
{
  return IS_DEQUE_EMPTY(deque) ? -1 : deque->first->data;
}

int myCircularDequeGetRear(MyCircularDeque *deque)
{
  return IS_DEQUE_EMPTY(deque) ? -1 : deque->last->data;
}

bool myCircularDequeIsEmpty(MyCircularDeque *deque)
{
  return IS_DEQUE_EMPTY(deque);
}

bool myCircularDequeIsFull(MyCircularDeque *deque)
{
  return IS_DEQUE_FULL(deque);
}
