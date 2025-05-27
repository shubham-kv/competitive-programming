---
Title: 990. Satisfiability of Equality Equations
Created: "Tue, 27 May 2025 11:37:11 +0530"
Last Edited: "Tue, 27 May 2025 11:47:13 +0530"
---

> **Difficulty**: Medium  
> **Topics**: `array`, `string`, `union-find`, `graph`  
> **Leetcode**: [990. Satisfiability of Equality Equations][leetcode-990]  
> **Status**: Solved

### Problem Statement

> You are given an array of strings equations that represent relationships
> between variables where each string equations[i] is of length 4 and takes one of
> two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters
> (not necessarily different) that represent one-letter variable names.
>
> Return true if it is possible to assign integers to variable names so as to
> satisfy all the given equations, or false otherwise.

### Approach

Solve this with Weighted quick union.

### Solutions

- [Typescript](./ts/solution.ts)

---

[<< Go Back](../../index.md)

[leetcode-990]: https://leetcode.com/problems/satisfiability-of-equality-equations/
