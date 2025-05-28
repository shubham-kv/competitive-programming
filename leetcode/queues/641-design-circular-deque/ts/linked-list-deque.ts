type DequeNode = {
  data: number;
  prev: DequeNode | null;
  next: DequeNode | null;
};

class MyCircularDeque {
  private first: DequeNode | null = null;
  private last: DequeNode | null = null;
  private size: number = 0;
  private capacity: number;

  constructor(k: number) {
    this.capacity = k;
  }

  insertFront(data: number): boolean {
    if (this.isFull()) {
      return false;
    }

    const newNode: DequeNode = {
      data,
      prev: null,
      next: this.first,
    };

    this.first && (this.first.prev = newNode);
    this.first = newNode;
    !this.last && (this.last = newNode);
    this.size++;

    return true;
  }

  insertLast(data: number): boolean {
    if (this.isFull()) {
      return false;
    }

    const newNode: DequeNode = {
      data,
      prev: this.last,
      next: null,
    };

    this.last && (this.last.next = newNode);
    this.last = newNode;
    !this.first && (this.first = newNode);
    ++this.size;

    return true;
  }

  deleteFront(): boolean {
    if (this.isEmpty()) {
      return false;
    }

    const oldFirstNode = this.first;
    const nextFirstNode = this.first?.next ?? null;

    oldFirstNode && (oldFirstNode.next = null);
    nextFirstNode && (nextFirstNode.prev = null);

    if (this.first === this.last) {
      this.last = nextFirstNode;
    }

    this.first = nextFirstNode;
    --this.size;
    return true;
  }

  deleteLast(): boolean {
    if (this.last === null) {
      return false;
    }

    const oldLastNode = this.last;
    const newLastNode = this.last.prev;

    oldLastNode && (oldLastNode.prev = null);
    newLastNode && (newLastNode.next = null);

    if (this.first === this.last) {
      this.first = newLastNode;
    }

    this.last = newLastNode;
    --this.size;
    return true;
  }

  getFront(): number {
    return this.first ? this.first.data : -1;
  }

  getRear(): number {
    return this.last ? this.last.data : -1;
  }

  isEmpty(): boolean {
    return this.size === 0;
  }

  isFull(): boolean {
    return this.size === this.capacity;
  }
}

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
