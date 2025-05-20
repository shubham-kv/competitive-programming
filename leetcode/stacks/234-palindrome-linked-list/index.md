---
Title: 234. Palindrome Linked List
Created: "Tue, 20 May 2025 09:55:01 +0530"
Last Edited: "Tue, 20 May 2025 17:40:23 +0530"
---

> **Difficulty**: Easy  
> **Topics**: `linked-list`, `two-pointers`, `stack`, `recursion`  
> **Link**: [234. Palindrome Linked List | Leetcode][leetcode-234]  
> **Status**: Solved

### Problem Statement

> Given the head of a singly linked list, return true if it is a palindrome or
> false otherwise.

### Approach

**Initial Approach:**

`push` items onto stack until the first half of the linked list & `pop` items
from stack for the second half of the list, while popping items off the list
check for a match with the node being iterated.

The solution with this approach only beat ~5% which is the lowest I've ever got.
So I looked up into the solutions forum trying to find a better approach.

**A more performant & efficient approach:**

1. Find the middle node using fast & slow pointers (fast pointer increments by 2
& slow pointer increments by 1 every iteration)
2. Reverse the list from the middle node
3. Compare the two halved linked lists

### Solutions

- [C](./c/palindrome_validator.c)
- [Typescript](./ts/palindrome-validator.ts)

---

[<< Go Back](../../index.md)

[leetcode-234]: https://leetcode.com/problems/palindrome-linked-list/
