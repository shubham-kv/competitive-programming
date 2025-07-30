// Title: Fun with queues
// Date: 2025-07-30
// Created: `Wed, 30 Jul 2025 20:46:18 +0530`
// Tags: [queues, daily-practice]

/// {{
/// Problem: 641. Design Circular Deque
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-circular-deque/
/// Topics: `array`, `linked-list`, `design`, `queue`  
/// Timestamp: `Wed, 30 Jul 2025 20:46:18 +0530`

/** @param {number} capacity */
function MyCircularDeque(capacity) {
  /** @type {number} */
  this.capacity = capacity;

  /** @type {number[]} */
  this.values = [];

  for (let i = 0; i < capacity; i++) {
    this.values.push(0);
  }

  /** @type {number} */
  this.first = -1;

  /** @type {number} */
  this.last = -1;

  /** @type {number} */
  this.size = 0;
};

/**
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function(value) {
  if (this.isFull()) {
    return false;
  }

  if (this.isEmpty()) {
    this.first = 0;
    this.values[this.first] = value;
    this.last = this.first;
  } else {
    this.first = (this.first > 0) ? this.first - 1: this.capacity - 1;
    this.values[this.first] = value;
  }

  this.size++;
  return true;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function(value) {
  if (this.isFull()) {
    return false;
  }

  if (this.isEmpty()) {
    this.first = 0;
    this.values[this.first] = value;
    this.last = this.first;
  } else {
    this.last = (this.last + 1) % this.capacity;
    this.values[this.last] = value;
  }

  this.size++;
  return true;
};

/** @return {boolean} */
MyCircularDeque.prototype.deleteFront = function() {
  if (this.isEmpty()) {
    return false;
  }

  this.values[this.first] = 0;
  this.first = (this.first + 1) % this.capacity;
  this.size--;

  return true;
};

/** @return {boolean} */
MyCircularDeque.prototype.deleteLast = function() {
  if (this.isEmpty()) {
    return false;
  }

  this.values[this.last] = 0;
  this.last = (this.last > 0) ? this.last - 1: this.capacity - 1;
  this.size--;

  return true;
};

/** @return {number} */
MyCircularDeque.prototype.getFront = function() {
  return this.isEmpty() ? -1 : this.values[this.first];
};

/** @return {number} */
MyCircularDeque.prototype.getRear = function() {
  return this.isEmpty() ? -1 : this.values[this.last];
};

/** @return {boolean} */
MyCircularDeque.prototype.isEmpty = function() {
  return this.size === 0;
};

/** @return {boolean} */
MyCircularDeque.prototype.isFull = function() {
  return this.size === this.capacity;
};

/** 
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */

/// }}

