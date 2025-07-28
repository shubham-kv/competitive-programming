// Title: Fun with queues
// Date: 2025-07-28
// Created: `Mon, 28 Jul 2025 18:25:50 +0530`
// Tags: [queues, daily-practice]

use std::collections::VecDeque;

/// {{
/// Problem: 225. Implement Stack using Queues
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/implement-stack-using-queues/
/// Topics: `stack`, `design`, `queue`
/// Timestamp: `Mon, 28 Jul 2025 18:25:50 +0530`

struct MyStack {
    queue: VecDeque<i32>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {
    fn new() -> Self {
        Self { queue: VecDeque::new() }
    }

    fn push(&mut self, x: i32) {
        self.queue.push_back(x);
    }

    fn pop(&mut self) -> i32 {
        for _ in 0..(self.queue.len() - 1) {
            match self.queue.pop_front() {
                None => { return -1; },
                Some(i) => self.queue.push_back(i),
            }
        }

        match self.queue.pop_front() {
            None => -1,
            Some(x) => x
        }
    }

    fn top(&mut self) -> i32 {
        for _ in 0..(self.queue.len() - 1) {
            match self.queue.pop_front() {
                None => { return -1; },
                Some(i) => self.queue.push_back(i),
            }
        }

        match self.queue.pop_front() {
            None => -1,
            Some(top) => {
                self.queue.push_back(top);
                top
            }
        }
    }

    fn empty(&self) -> bool {
        self.queue.is_empty()
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */

/// }}

fn main() {
    let mut stack = MyStack::new();
    stack.push(10);
    stack.push(9);
    stack.push(8);

    println!("Top of the stack is {}", stack.top());
    stack.pop();

    println!("Top of the stack is {}", stack.top());
    stack.pop();
    println!("Is the stack empty ? {}", stack.empty());
}

