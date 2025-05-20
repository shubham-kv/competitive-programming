---
Title: 234. Palindrome Linked List
Created: "Tue, 20 May 2025 09:55:01 +0530"
Last Edited: "Tue, 20 May 2025 11:07:57 +0530"
---

> **Difficulty**: Easy  
> **Topics**: `linked-list`, `two-pointers`, `stack`, `recursion`  
> **Link**: [234. Palindrome Linked List | Leetcode](https://leetcode.com/problems/palindrome-linked-list/)  
> **Status**: Attempting

### Problem Statement

> Given the head of a singly linked list, return true if it is a palindrome or
> false otherwise.

### Approach

`push` items onto stack until the first half of the linked list & `pop` items
from stack for the second half of the list, while popping items off the list
check for a match with the node being iterated.

### Solutions

- [C](./c/palindrome_validator.c)
