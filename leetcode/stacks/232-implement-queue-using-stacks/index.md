---
Title: 232. Implement Queue using Stacks
Created: "Tue, 27 May 2025 12:46:38 +0530"
Last Edited: "Tue, 27 May 2025 12:56:31 +0530"
---

> **Difficulty**: Easy  
> **Topics**: `stack`, `design`, `queue`  
> **Leetcode**: [232. Implement Queue using Stacks][leetcode-232]  
> **Status**: Solved

### Problem Statement

> Implement a first in first out (FIFO) queue using only two stacks. The
> implemented queue should support all the functions of a normal queue (push,
> peek, pop, and empty).
> ...

### Approach

Use two stacks, to `enqueue` push into the first stack, to `dequeue` pop from
first stack and push to second stack to reverse the order & finally pop from
second stack.

### Solutions

- [C](./c/queue_using_stacks.c), [Typescript](./ts/queue-using-stacks.ts)

---

[<< Go Back](../../index.md)

[leetcode-232]: https://leetcode.com/problems/implement-queue-using-stacks/
