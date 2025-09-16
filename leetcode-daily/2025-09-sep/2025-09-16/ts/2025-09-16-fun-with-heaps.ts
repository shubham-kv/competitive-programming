// Title: Fun with heaps
// Date: 2025-09-16
// Created: `Tue, 16 Sep 2025 11:53:31 +0530`
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

const cmpNumber = (a: number, b: number) => a < b ? -1 : a > b ? 1 : 0

/// {{
/// Problem: 1337. The K Weakest Rows in a Matrix
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
/// Topics: `array`, `binary-search`, `sorting`, `heap-(priority-queue)`, `matrix`
/// Timestamp: `Tue, 16 Sep 2025 11:53:31 +0530`

type Item = {
  index: number;
  count: number;
}

function kWeakestRows(mat: number[][], k: number): number[] {
  const maxPQ: MaxPQ<Item> = new MaxPQ((a, b) => {
    const countCmp = cmpNumber(a.count, b.count);
    if (countCmp !== 0) {
      return countCmp;
    }
    return cmpNumber(a.index, b.index);
  });

  const rows = mat.length;

  for (let i = 0; i < rows; i++) {
    const row = mat[i];
    let count = 0;
    row.forEach(val => val === 1 && (count++));

    maxPQ.insert({ index: i, count });

    if (maxPQ.size() > k) {
      maxPQ.delMax();
    }
  }

  const kWeakestIndices: number[] = [];

  while (!maxPQ.isEmpty()) {
    const item = maxPQ.delMax();
    kWeakestIndices.unshift(item.index);
  }

  return kWeakestIndices;
}

/// }}


/// {{
/// Problem: 658. Find K Closest Elements
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/find-k-closest-elements/
/// Topics: -
/// Timestamp: `Tue, 16 Sep 2025 12:17:37 +0530`

function findClosestElements(arr: number[], k: number, x: number): number[] {
  const minPQ: MinPQ<number> = new MinPQ((a, b) => {
    const distA = Math.abs(a - x);
    const distB = Math.abs(b - x);
    const cmpDistAandB = cmpNumber(distA, distB);
    if (cmpDistAandB !== 0) {
      return cmpDistAandB;
    }
    return cmpNumber(a, b);
  });

  for (const num of arr) {
    minPQ.insert(num);

    if (minPQ.size() > k) {
      minPQ.delMin();
    }
  }

  const kClosest: number[] = [];

  while (!minPQ.isEmpty()) {
    const num = minPQ.delMin();
    kClosest.push(num);
  }

  return kClosest;
};

/// }}

