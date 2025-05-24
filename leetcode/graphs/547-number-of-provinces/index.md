---
Title: 547. Number of Provinces
Created: "Sat, 24 May 2025 21:06:42 +0530"
Last Edited: "Sat, 24 May 2025 21:08:53 +0530"
---

> **Difficulty**: Medium  
> **Topics**: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
> **Leetcode**: [547. Number of Provinces][leetcode-547]  
> **Status**: Solved

### Problem Statement

> There are `n` cities. Some of them are connected, while some are not. If city `a` is
> connected directly with city `b`, and city `b` is connected directly with city `c`,
> then city `a` is connected indirectly with city `c`.
>
> A province is a group of directly or indirectly connected cities and no other
> cities outside of the group.
>
> You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the ith
> city and the jth city are directly connected, and `isConnected[i][j] = 0`
> otherwise.
>
> Return the total number of provinces.

### Approach

Solve this with Weighted quick union.

### Implementations

- [Typescript](./ts/number-of-provinces.ts)

---

[<< Go Back to Index](../../index.md)

[leetcode-547]: https://leetcode.com/problems/number-of-provinces/
