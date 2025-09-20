/// {{
/// Problem: 707. Design Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-linked-list/
/// Timestamp: `Sat, 20 Sep 2025 13:22:35 +0530`

type _Node = {
  val: number;
  next: _Node | null;
}

class MyLinkedList {
  #first: _Node | null = null;
  #size: number = 0;

  constructor() { }

  #ithNode(index: number): _Node | null {
    const n = this.#size;
    if (!(0 <= index && index < n)) {
      return null;
    }

    let node = this.#first!;
    for (let i = 1; i <= index; i++) {
      if (node?.next) {
        node = node.next
      } else {
        throw new Error('Invalid state');
      }
    }
    return node;
  }

  get(index: number): number {
    const node = this.#ithNode(index);
    return node?.val ?? -1;
  }

  addAtHead(val: number): void {
    this.addAtIndex(0, val);
  }

  addAtTail(val: number): void {
    this.addAtIndex(this.#size, val);
  }

  addAtIndex(index: number, val: number): void {
    if (!(0 <= index && index <= this.#size)) {
      return;
    }

    const node: _Node = { val: val, next: null };

    if (index === 0) {
      node.next = this.#first;
      this.#first = node;
    } else {
      const prev = this.#ithNode(index - 1);
      if (!prev) {
        throw new Error('Invalid state');
      }

      node.next = prev.next;
      prev.next = node;
    }
    this.#size++;
  }

  deleteAtIndex(index: number): void {
    if (!(0 <= index && index < this.#size)) {
      return;
    }

    if (index === 0) {
      this.#first = this.#first?.next ?? null;
    } else {
      const prev = this.#ithNode(index - 1);
      if (!prev) {
        throw new Error('Invalid state');
      }

      const next = prev.next;
      prev.next = prev.next?.next ?? null;
      if (next) {
        next.next = null;
      }
    }
    this.#size--;
  }
}

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

