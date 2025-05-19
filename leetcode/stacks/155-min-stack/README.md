---
Title: 155. Min Stack
Created: "Mon, 19 May 2025 11:45:29 +0530"
Last Edited: "Mon, 19 May 2025 12:57:47 +0530"
---

> **Problem**: [155. Min Stack](https://leetcode.com/problems/min-stack/)  
> **Difficulty**: Medium  
> **Topics**: `stack`, `design`  
> **Status**: Solved

### Problem Statement

> Design a stack that supports `push`, `pop`, `top`, and retrieving the minimum
> element in constant time.
>
> Implement the `MinStack` class:  
> ...  
> `int getMin()` retrieves the minimum element in the stack.
>
> You must implement a solution with `O(1)` time complexity for each function.

### Approach

Data Structure:

```c
struct Node {
  // Node's integer data
  int data;

  // Pointer to the next node in the linked list
  struct Node *next;

  // Pointer to a node holding the most smallest value at this node level in the
  // stack
  struct Node *min;
};
```

Interpretation:

For every node in the stack, maintain a pointer to a node with minimum value
at that node level in the stack.

### Notes

I was initially worried about the order of the minimum items / items in
ascending order from the top of the stack. Wasted time in the beginning trying
to think how would popping items work while maintaining their ascending oder.

### Implementations

- [C](./c/min_stack.c) — Modular, uses `min_stack.{h,c}`
