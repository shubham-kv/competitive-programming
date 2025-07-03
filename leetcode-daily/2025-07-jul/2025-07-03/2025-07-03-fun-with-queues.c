// Title: Fun with queues
// Date: 2025-07-03
// Created: Thu, 03 Jul 2025 15:28:11 +0530
// Tags: [queues, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 225. Implement Stack using Queues
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-stack-using-queues/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Thu, 03 Jul 2025 15:30:18 +0530`

#if !defined(__queue_h)
#define __queue_h

struct Node {
	int data;
	struct Node *next;
};

struct Queue {
	int size;
	struct Node *first;
	struct Node *last;
};

struct Queue *Queue_create();
void Queue_free(struct Queue *queue);

void Queue_enqueue(struct Queue *queue, int data);
int Queue_dequeue(struct Queue *queue);
int Queue_front(struct Queue *queue);

#define QUEUE_SIZE(ptr) (((struct Queue *)ptr)->size)
#define IS_QUEUE_EMPTY(ptr) (((struct Queue *)ptr)->size == 0)

#endif // __queue_h


struct Queue *Queue_create() {
	struct Queue *queue = calloc(1, sizeof(struct Queue));
	queue->first = NULL;
	queue->last = NULL;
	queue->size = 0;
	return queue;
}

void Queue_free(struct Queue *queue) {
	while (!IS_QUEUE_EMPTY(queue)) {
		Queue_dequeue(queue);
	}
	free(queue);
}

void Queue_enqueue(struct Queue *queue, int data) {
	struct Node *newNode = calloc(1, sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (IS_QUEUE_EMPTY(queue)) {
		queue->first = newNode;
	} else {
		queue->last->next = newNode;
	}
	queue->last = newNode;
	queue->size++;
}

int Queue_dequeue(struct Queue *queue) {
	if (IS_QUEUE_EMPTY(queue)) {
		return -1;
	}

	struct Node *oldFirst = queue->first;
	int data = oldFirst->data;
	queue->first = oldFirst->next;
	queue->size--;

	if (IS_QUEUE_EMPTY(queue)) {
		queue->last = NULL;
	}
	free(oldFirst);
	return data;
}

inline int Queue_front(struct Queue *queue) {
	return IS_QUEUE_EMPTY(queue) ? -1 : queue->first->data;
}


#if !defined(__my_stack_h)
#define __my_stack_h

typedef struct {
	struct Queue *q1;
	struct Queue *q2;
} MyStack;

MyStack *myStackCreate();
void myStackFree(MyStack *stack);

void myStackPush(MyStack *stack, int x);
int myStackPop(MyStack *stack);
int myStackTop(MyStack *stack);
bool myStackEmpty(MyStack *stack);

#endif // __my_stack_h


MyStack *myStackCreate() {
	MyStack *stack = calloc(1, sizeof(MyStack));
	stack->q1 = Queue_create();
	stack->q2 = Queue_create();
	return stack;
}

void myStackFree(MyStack *stack) {
	Queue_free(stack->q1);
	Queue_free(stack->q2);
	free(stack);
}

/**
 * On stackPush(1), enqueue into q2
 * q1 = [   ]
 * q2 = [ 1 ]
 *
 * On stackPush(2), enqueue into q2
 * q1 = [   ]
 * q2 = [ 1, 2 ]
 */
void myStackPush(MyStack *stack, int data) {
	while (!IS_QUEUE_EMPTY(stack->q1)) {
		Queue_enqueue(stack->q2, Queue_dequeue(stack->q1));
	}

	Queue_enqueue(stack->q2, data);
}

/**
 * On stackPop(), 
 * q1 = [   ]
 * q2 = [ 1, 2, 3 ]
 *
 * 1. Enqueue n-1 items into q1.
 * q1 = [ 1, 2 ]
 * q2 = [ 3 ]
 *
 * 2. Dequeue from q2.
 */
int myStackPop(MyStack *stack) {
	while (QUEUE_SIZE(stack->q2) >= 2) {
		Queue_enqueue(stack->q1, Queue_dequeue(stack->q2));
	}

	int data = Queue_dequeue(stack->q2);

	while(!IS_QUEUE_EMPTY(stack->q1)) {
		Queue_enqueue(stack->q2, Queue_dequeue(stack->q1));
	}

	return data;
}

int myStackTop(MyStack *stack) {
	while (QUEUE_SIZE(stack->q2) >= 2) {
		Queue_enqueue(stack->q1, Queue_dequeue(stack->q2));
	}

	int top = Queue_front(stack->q2);
	Queue_enqueue(stack->q1, Queue_dequeue(stack->q2));

	while(!IS_QUEUE_EMPTY(stack->q1)) {
		Queue_enqueue(stack->q2, Queue_dequeue(stack->q1));
	}

	return top;
}

bool myStackEmpty(MyStack *stack) {
	return IS_QUEUE_EMPTY(stack->q1) && IS_QUEUE_EMPTY(stack->q2);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack *stack = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
*/

/// }}

