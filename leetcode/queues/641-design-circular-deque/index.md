---
Title: 641. Design Circular Deque
Created: "Mon, 19 May 2025 19:19:04 +0530"
Last Edited: "Wed, 28 May 2025 15:13:25 +0530"
---

> **Difficulty**: Medium  
> **Topics**: `array`, `linked-list`, `design`, `queue`  
> **Link**: [641. Design Circular Deque | Leetcode][leetcode-641]  
> **Status**: Solved

### Problem Statement

> Design your implementation of the circular double-ended queue (deque).
>
> Implement the MyCircularDeque class:  
> MyCircularDeque(int k) Initializes the deque with a maximum size of k.
> `boolean insertFront()` Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
> `boolean insertLast()` Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
> `boolean deleteFront()` Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
> `boolean deleteLast()` Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
> `int getFront()` Returns the front item from the Deque. Returns -1 if the deque is empty.
> `int getRear()` Returns the last item from Deque. Returns -1 if the deque is empty.
> `boolean isEmpty()` Returns true if the deque is empty, or false otherwise.
> `boolean isFull()` Returns true if the deque is full, or false otherwise.

### Approach

Implement Fixed capacity Deque by using Doubly linked lists.

### Solutions

- [C](./c/fixed_capacity_deque.c), [Typescript](./ts/linked-list-deque.ts)

---

[<< Go Back](../../index.md)

[leetcode-641]: https://leetcode.com/problems/design-circular-deque
