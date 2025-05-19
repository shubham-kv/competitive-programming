#if !defined(deque_h)
#define deque_h

#include <stdbool.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

typedef struct
{
  uint32_t capacity;
  uint32_t size;
  struct Node *first;
  struct Node *last;
} MyCircularDeque;

MyCircularDeque *myCircularDequeCreate(int k);
void myCircularDequeFree(MyCircularDeque *obj);

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value);
bool myCircularDequeInsertLast(MyCircularDeque *obj, int value);

bool myCircularDequeDeleteFront(MyCircularDeque *obj);
bool myCircularDequeDeleteLast(MyCircularDeque *obj);

int myCircularDequeGetFront(MyCircularDeque *obj);
int myCircularDequeGetRear(MyCircularDeque *obj);

bool myCircularDequeIsEmpty(MyCircularDeque *obj);
bool myCircularDequeIsFull(MyCircularDeque *obj);

#define IS_DEQUE_EMPTY(p) (((MyCircularDeque *) p)->size == 0)
#define IS_DEQUE_FULL(p) (((MyCircularDeque *) p)->size == ((MyCircularDeque *) p)->capacity)

#endif // deque_h
