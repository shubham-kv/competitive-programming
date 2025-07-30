
// {{
// Problem: 641. Design Circular Deque
// Difficulty: `Medium`
// Links: https://leetcode.com/problems/design-circular-deque/
// Topics: `array`, `linked-list`, `design`, `queue`  
// Timestamp: `Wed, 30 Jul 2025 20:46:18 +0530`

struct MyCircularDeque {
    values: Vec<i32>,
    capacity: i32,
    size: i32,
    first: i32,
    last: i32
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCircularDeque {
    fn new(capacity: i32) -> Self {
        let mut values = Vec::new();

        for _ in 0..capacity {
            values.push(0);
        }

        Self {
            capacity,
            values,
            size: 0,
            first: -1,
            last: -1
        }
    }

    fn insert_front(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }

        if self.is_empty() {
            self.first = 0;
            self.last = self.first;
            self.values[self.first as usize] = value;
        } else {
            self.first = if self.first > 0 { self.first - 1 } else { self.capacity - 1 };
            self.values[self.first as usize] = value;
        }
        self.size += 1;
        true
    }

    fn insert_last(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }

        if self.is_empty() {
            self.first = 0;
            self.last = self.first;
            self.values[self.first as usize] = value;
        } else {
            self.last = (self.last + 1) % self.capacity;
            self.values[self.last as usize] = value;
        }
        self.size += 1;
        true
    }

    fn delete_front(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        self.values[self.first as usize] = 0;
        self.first = (self.first + 1) % self.capacity;
        self.size -= 1;
        true
    }

    fn delete_last(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        self.values[self.last as usize] = 0;
        self.last = if self.last > 0 { self.last - 1 } else { self.capacity - 1 };
        self.size -= 1;
        true
    }

    fn get_front(&self) -> i32 {
        if self.is_empty() { -1 } else { self.values[self.first as usize] }
    }

    fn get_rear(&self) -> i32 {
        if self.is_empty() { -1 } else { self.values[self.last as usize] }
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn is_full(&self) -> bool {
        self.size == self.capacity
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * let obj = MyCircularDeque::new(k);
 * let ret_1: bool = obj.insert_front(value);
 * let ret_2: bool = obj.insert_last(value);
 * let ret_3: bool = obj.delete_front();
 * let ret_4: bool = obj.delete_last();
 * let ret_5: i32 = obj.get_front();
 * let ret_6: i32 = obj.get_rear();
 * let ret_7: bool = obj.is_empty();
 * let ret_8: bool = obj.is_full();
 */

// }}

fn main() {
    println!("Hello, world!");
}

