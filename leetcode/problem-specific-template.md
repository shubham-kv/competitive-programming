
# 232. Implement Queue Using Stacks

> Design a queue using stacks.  
> [LeetCode Link](https://leetcode.com/problems/implement-queue-using-stacks)

## 🧠 Approaches

- Two-stack simulation: enqueue to stack1, dequeue via reverse to stack2.

## 📋 Notes

- Be mindful of amortized vs. worst-case time
- C version includes test harness
- Two-stack technique
- Push: O(1), Pop: Amortized O(1)
- C version demonstrates modular design: `stack` and `queue_using_stack`

## 🌐 Implementations

- [C](./c/) — Modular, uses `stack.{h,c}` and `queue_using_stack.{h,c}`
- [Java](./java/QueueUsingStacks.java) — OOP-based, cleaner interface
- [TypeScript](./typescript/queueUsingStacks.ts) — Functional approach
