---
Title: 20. Valid Parentheses
Created: "Mon, 19 May 2025 10:05:47 +0530"
Last Edited: "Tue, 20 May 2025 17:40:23 +0530"
---

> **Difficulty**: Easy  
> **Topics**: `string`, `stack`  
> **Link**: [20. Valid Parentheses | LeetCode][leetcode-20]  
> **Status**: Solved

### Problem Statement

> Given a string s containing just the characters `(`, `)`, `{`, `}`, `[` and
> `]`, determine if the input string is valid.  

### Approach

1. While iterating through the individual characters, push opening braces `(`,
`{` and `[` on the stack
2. When a closing brace (like `)`, `}`, `]`) is encountered pop from the stack
and check for matching parentheses.

### Notes

- C version demonstrates modular design: `stack` and `parentheses_validator`

### Implementations

- [C](./c/parentheses_validator.c)
- [Typescript](./ts/parentheses_validator.ts)

---

[<< Go Back to Index](../../index.md)

[leetcode-20]: https://leetcode.com/problems/valid-parentheses
