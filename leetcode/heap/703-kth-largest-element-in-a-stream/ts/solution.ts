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

/// {{
/// Problem: 703. Kth Largest Element in a Stream
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/kth-largest-element-in-a-stream/
/// Topics: `tree`, `design`, `binary-search-tree`, `heap-(priority-queue)`, `binary-tree`, `data-stream`
/// Timestamp: `Sun, 14 Sep 2025 14:48:04 +0530`

class KthLargest {
  #minPQ: MinPQ<number>;
  #k: number;

  constructor(k: number, nums: number[]) {
    this.#minPQ = new MinPQ((a, b) => a < b ? -1 : a > b ? 1 : 0);
    this.#k = k;

    for (const key of nums) {
      this.#minPQ.insert(key);

      if (this.#minPQ.size() > this.#k) {
        this.#minPQ.delMin();
      }
    }
  }

  add(val: number): number {
    this.#minPQ.insert(val);

    if (this.#minPQ.size() > this.#k) {
      this.#minPQ.delMin();
    }

    return this.#minPQ.getMin()!;
  }
}

/// }}

