// Title: Fun with linked lists
// Date: 2025-08-10
// Created: `Sun, 10 Aug 2025 22:12:24 +0530`
// Tags: [linked-lists, daily-practice]

/// {{
/// Problem: 707. Design Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-linked-list/
/// Topics: `linked-list`, `design`
/// Timestamp: `Sun, 10 Aug 2025 22:12:24 +0530`

/** @typedef {{next: ListNode | null; data: number}} ListNode */

function MyLinkedList() {
  /** @type {ListNode | null} */
  this.first = null;

  /** @type {number} */
  this.size = 0;
};

/**
 * @param {MyLinkedList} list 
 * @param {number} index
 * @returns {ListNode | null}
 */
function getNodeAt(list, index) {
  if (!list || !(0 <= index && index < list.size)) {
    return null;
  }

  if (index === 0) {
    return list.first;
  }

  /** @type {ListNode | null} */
  let node = list.first;

  for (let i = 1; i < (index + 1); i++) {
    if (node.next) {
      node = node.next;
    } else {
      return null;
    }
  }

  return node;
}

/** 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
  const node = getNodeAt(this, index);
  return node ? node.data : -1;
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
  this.addAtIndex(0, val);
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
  this.addAtIndex(this.size, val);
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
  if (!(0 <= index && index <= this.size)) {
    return;
  }

  /** @type {ListNode} */
  const newNode = { next: null, data: val };
  const prev = getNodeAt(this, index - 1);

  if (prev) {
    const next = prev.next;
    prev.next = newNode;
    newNode.next = next;
    this.size++;
  } else {
    newNode.next = this.first;
    this.first = newNode;
    this.size++;
  }
};

/** 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {
  if (!(0 <= index && index < this.size)) {
    return;
  }

  const prev = getNodeAt(this, index - 1);

  if (prev) {
    if (prev.next) {
      const next = prev.next.next;
      prev.next = next;
      this.size--;
    }
  } else {
    if (this.first) {
      this.first = this.first.next;
      this.size--;
    }
  }
};

/** 
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */

/// }}

