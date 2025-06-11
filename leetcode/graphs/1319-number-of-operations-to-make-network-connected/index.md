---
Title: 1319. Number of Operations to Make Network Connected
Created: "Sun, 25 May 2025 12:19:54 +0530"
Last Edited: "Wed, 11 Jun 2025 15:58:42 +0530"
---

> **Difficulty**: Medium  
> **Topics**: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
> **Leetcode**: [1319. Number of Operations to Make Network Connected][leetcode-1319]  
> **Status**: Attempting

### Problem Statement

> There are n computers numbered from 0 to n - 1 connected by ethernet cables
> connections forming a network where connections[i] = [ai, bi] represents a
> connection between computers ai and bi. Any computer can reach any other
> computer directly or indirectly through the network.
>
> You are given an initial computer network connections. You can extract certain
> cables between two directly connected computers, and place them between any pair
> of disconnected computers to make them directly connected.
>
> Return the minimum number of times you need to do this in order to make all the
> computers connected. If it is not possible, return -1

### Approach

Try to solve with Weighted quick union & count the number of redundant connections.

### Notes

- Simply counting the number of redundant connections didn't work

### Implementations

- [Typescript](./ts/solution.ts)

---

[<< Go Back to Index](../../index.md)

[leetcode-1319]: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
