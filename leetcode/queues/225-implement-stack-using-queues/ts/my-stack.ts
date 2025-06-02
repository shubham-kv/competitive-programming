class MyQueue {
  #entries: number[];

  constructor() {
    this.#entries = [];
  }

  enqueue(x: number) {
    this.#entries.push(x);
  }

  dequeue(): number | undefined {
    return !this.isEmpty() ? this.#entries.shift() : undefined;
  }

  peek(): number | undefined {
    return !this.isEmpty() ? this.#entries[0] : undefined;
  }

  isEmpty() {
    return this.#entries.length === 0;
  }

  size() {
    return this.#entries.length;
  }
}

class MyStack {
  #queue: MyQueue;

  constructor() {
    this.#queue = new MyQueue();
  }

  push(x: number): void {
    this.#queue.enqueue(x);
  }

  pop(): number {
    // Dequeue & Enqueue n-1 times to bring the last item to the front
    const queueSize = this.#queue.size();

    for (let i = 0; i < queueSize - 1; i++) {
      const dequeuedItem = this.#queue.dequeue();
      dequeuedItem && (this.#queue.enqueue(dequeuedItem));
    }

    const poppedItem = this.#queue.dequeue()!;
    return poppedItem;
  }

  top(): number {
    // Dequeue & Enqueue n-1 times to bring the last item to the front
    const queueSize = this.#queue.size();

    for (let i = 0; i < queueSize - 1; i++) {
      const dequeuedItem = this.#queue.dequeue();
      dequeuedItem && (this.#queue.enqueue(dequeuedItem));
    }

    const peekedItem = this.#queue.peek()!;

    // Move the first item to it's original position
    const dequeuedItem = this.#queue.dequeue();
    dequeuedItem && (this.#queue.enqueue(dequeuedItem));

    return peekedItem;
  }

  empty(): boolean {
    return this.#queue.isEmpty();
  }
}

const stack = new MyStack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.push(5);
console.log(stack.pop());
console.log(stack.pop());
console.log(stack.top());
console.log(stack.pop());
console.log(stack.top());
console.log(stack.empty());
