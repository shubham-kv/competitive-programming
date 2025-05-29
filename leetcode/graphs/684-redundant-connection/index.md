---
Title: 684. Redundant Connection
Created: "Sat, 24 May 2025 19:26:54 +0530"
Last Edited: "Thu, 29 May 2025 12:59:30 +0530"
---

> **Difficulty**: Medium  
> **Topics**: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
> **Leetcode**: [684. Redundant Connection][leetcode-684]  
> **Status**: Solved

### Problem Statement

> In this problem, a tree is an undirected graph that is connected and has no
> cycles.
>
> You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`,
> with one additional edge added. The added edge has two different vertices chosen
> from `1` to `n`, and was not an edge that already existed. The graph is represented
> as an array `edges` of length `n` where `edges[i] = [ai, bi]` indicates that
> there is an edge between nodes <code>a<sub>i</sub></code> and
> <code>b<sub>i</sub></code> in the graph.
>
> Return an edge that can be removed so that the resulting graph is a tree of `n`
> nodes. If there are multiple answers, return the answer that occurs last in the
> input.

### Approach

Solve this with Weighted quick union.

### Implementations

- [C](./c/redundant_connection.c), [Typescript](./ts/redundant-connection.ts)

---

[<< Go Back](../../index.md)

[leetcode-684]: https://leetcode.com/problems/redundant-connection/
