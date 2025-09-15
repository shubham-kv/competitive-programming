// Title: Fun with heaps
// Date: 2025-09-15
// Created: `Mon, 15 Sep 2025 17:51:31 +0530`
// Tags: [heaps, daily-practice]

type ComparatorFn<T> = (a: T, b: T) => number

class MinPQ<T> {
  #keys: T[];
  #keysCmp: ComparatorFn<T>;

  constructor(keysCmp: ComparatorFn<T>) {
    this.#keysCmp = keysCmp;
    this.#keys = [];
  }

  #swapKeysAtIndex(i: number, j: number): void {
    [this.#keys[i], this.#keys[j]] = [this.#keys[j], this.#keys[i]];
  }

  #heapifyUp(c: number): void {
    for (
      let p = Math.floor((c - 1) / 2);
      p >= 0;
      c = p, p = Math.floor((c - 1) / 2)
    ) {
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) > 0) {
        this.#swapKeysAtIndex(p, c);
      } else {
        break;
      }
    }
  }

  #heapifyDown(p: number): void {
    const n = this.#keys.length;

    for (
      let c = Math.floor(2 * p + 1);
      c < n;
      p = c, c = Math.floor(2 * p + 1)
    ) {
      if (c + 1 < n && this.#keysCmp(this.#keys[c], this.#keys[c + 1]) > 0) {
        c = c + 1;
      }
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) > 0) {
        this.#swapKeysAtIndex(p, c);
      } else {
        break;
      }
    }
  }

  insert(key: T): void {
    this.#keys.push(key);
    this.#heapifyUp(this.#keys.length - 1);
  }

  delMin(): T | null {
    const n = this.#keys.length;

    if (n <= 0) {
      return null;
    }

    const min = this.#keys[0];
    this.#keys[0] = this.#keys[n - 1];
    this.#keys.pop();
    this.#heapifyDown(0);
    return min;
  }

  getMin(): T | null {
    const n = this.#keys.length;
    return n <= 0 ? null : this.#keys[0];
  }

  size(): number {
    return this.#keys.length;
  }

  isEmpty(): boolean {
    return this.size() === 0;
  }
}

class MaxPQ<T> {
  #keys: T[];
  #keysCmp: ComparatorFn<T>;

  constructor(keysCmp: ComparatorFn<T>) {
    this.#keysCmp = keysCmp;
    this.#keys = [];
  }

  #swapKeysAtIndex(i: number, j: number): void {
    [this.#keys[i], this.#keys[j]] = [this.#keys[j], this.#keys[i]];
  }

  #heapifyUp(c: number): void {
    for (
      let p = Math.floor((c - 1) / 2);
      p >= 0;
      c = p, p = Math.floor((c - 1) / 2)
    ) {
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) < 0) {
        this.#swapKeysAtIndex(p, c);
      } else {
        break;
      }
    }
  }

  #heapifyDown(p: number): void {
    const n = this.#keys.length;

    for (
      let c = Math.floor(2 * p + 1);
      c < n;
      p = c, c = Math.floor(2 * p + 1)
    ) {
      if (c + 1 < n && this.#keysCmp(this.#keys[c], this.#keys[c + 1]) < 0) {
        c = c + 1;
      }
      if (this.#keysCmp(this.#keys[p], this.#keys[c]) < 0) {
        this.#swapKeysAtIndex(p, c);
      } else {
        break;
      }
    }
  }

  insert(key: T): void {
    this.#keys.push(key);
    this.#heapifyUp(this.#keys.length - 1);
  }

  delMax(): T | null {
    const n = this.#keys.length;

    if (n <= 0) {
      return null;
    }

    const max = this.#keys[0];
    this.#keys[0] = this.#keys[n - 1];
    this.#keys.pop();
    this.#heapifyDown(0);
    return max;
  }

  getMax(): T | null {
    const n = this.#keys.length;
    return n <= 0 ? null : this.#keys[0];
  }

  size(): number {
    return this.#keys.length;
  }

  isEmpty(): boolean {
    return this.size() === 0;
  }
}

/// {{
/// Problem: 215. Kth Largest Element in an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Mon, 15 Sep 2025 17:51:31 +0530`

function findKthLargest(nums: number[], k: number): number {
  const minPQ: MinPQ<number> = new MinPQ((a, b) => a < b ? -1 : a > b ? 1 : 0);

  for (const num of nums) {
    minPQ.insert(num);

    if (minPQ.size() > k) {
      minPQ.delMin();
    }
  }

  return minPQ.getMin()!;
}

/// }}

