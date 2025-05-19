import { IStack } from "./stack.interface";

class Node<T> {
  data: T;
  next: Node<T> | null;
}

export class Stack<T> implements IStack<T> {
  private _size: number = 0;
  private _top: Node<T> | null = null;

  push(data: T): void {
    const node: Node<T> = {
      data: data,
      next: this._top,
    };

    this._top = node;
    this._size++;
  }

  pop(): T | null {
    if (this.isEmpty()) {
      return null;
    }

    if (this._top) {
      const oldNode: Node<T> = this._top;
      this._top = this._top.next;
      this._size--;
      return oldNode.data;
    }

    return null;
  }

  size(): number {
    return this._size;
  }

  isEmpty(): boolean {
    return this._size == 0;
  }
}
