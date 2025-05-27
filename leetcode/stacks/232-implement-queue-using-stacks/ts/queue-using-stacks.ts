type StackNode = {
  data: number;
  next: StackNode | null;
};

class LinkedListStack {
  private top: StackNode | null = null;
  private size: number = 0;

  push(x: number) {
    const newNode: StackNode = {
      data: x,
      next: this.top,
    };

    this.top = newNode;
    this.size++;
  }

  pop(): number {
    if (this.isEmpty()) {
      return -1;
    }

    const oldTopNode: StackNode = this.top!;
    this.top = oldTopNode.next;
    this.size--;

    return oldTopNode.data;
  }

  peek(): number {
    return this.top?.data ?? -1;
  }

  isEmpty(): boolean {
    return this.top === null;
  }
}

class MyQueue {
  private stackA: LinkedListStack;
  private stackB: LinkedListStack;

  constructor() {
    this.stackA = new LinkedListStack();
    this.stackB = new LinkedListStack();
  }

  push(x: number): void {
    while (!this.stackB.isEmpty()) {
      const popped = this.stackB.pop();
      this.stackA.push(popped);
    }

    this.stackA.push(x);
  }

  pop(): number {
    while (!this.stackA.isEmpty()) {
      const popped = this.stackA.pop();
      this.stackB.push(popped);
    }

    return this.stackB.pop();
  }

  peek(): number {
    while (!this.stackA.isEmpty()) {
      const popped = this.stackA.pop();
      this.stackB.push(popped);
    }

    return this.stackB.peek();
  }

  empty(): boolean {
    return this.stackA.isEmpty() && this.stackB.isEmpty();
  }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
