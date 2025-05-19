---
Title: 138. Copy List with Random Pointer
Created: "Mon, 19 May 2025 10:05:47 +0530"
Last Edited: "Mon, 19 May 2025 17:23:33 +0530"
---

> **Difficulty**: Medium  
> **Topics**: `linked-list`, `hash table`  
> **Link**: [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer)  
> **Status**: Solved

### Problem Statement

> A linked list of length `n` is given such that each node contains an additional
> random pointer, which could point to any node in the list, or `null`.
>
> Construct a **deep copy** of the list. The deep copy should consist of exactly `n`
> brand new nodes, where each new node has its value set to the value of its
> corresponding original node. Both the `next` and `random` pointer of the new nodes
> should point to new nodes in the copied list such that the pointers in the
> original list and copied list represent the same list state. None of the
> pointers in the new list should point to nodes in the original list.

### Approach

Iterate through the original list, create copy of the list and fill in a map
that links original node to corresponding copy node.

Keep a map of original node to the new copy node, iterate through the copied
items again, get corresponding copy node by using map and update the random
pointer of the copy node.

### Implementations

- [Typescript](./ts/copy-random-list.ts)

---

[<< Go Back to Index](../../index.md)
