// Title: Fun with heaps
// Date: 2025-09-14
// Created: `Sun, 14 Sep 2025 13:55:55 +0530`
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

/// {{
/// Problem: 347. Top K Frequent Elements
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/top-k-frequent-elements/
/// Topics: `array`, `hash-table`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Sun, 14 Sep 2025 13:55:55 +0530`

type Item = { key: number; count: number };

function topKFrequent(nums: number[], k: number): number[] {
  const keyToCountMap: Map<number, number> = new Map();

  for (const key of nums) {
    if (keyToCountMap.has(key)) {
      const count = keyToCountMap.get(key);
      keyToCountMap.set(key, count + 1);
    } else {
      keyToCountMap.set(key, 1);
    }
  }

  const itemCmp: ComparatorFn<Item> = (a, b) => a.count < b.count ? -1 : a.count > b.count ? 1 : 0;
  const minPQ: MinPQ<Item> = new MinPQ(itemCmp);

  for (const [key, count] of keyToCountMap.entries()) {
    minPQ.insert({key, count});

    if (minPQ.size() > k) {
      minPQ.delMin();
    }
  }

  const kFrequent: number[] = [];

  while (!minPQ.isEmpty()) {
    const min = minPQ.delMin()!;
    kFrequent.push(min.key);
  }

  return kFrequent;
}

/// }}


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

    return this.#minPQ.getMin();
  }
}

/// }}


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
/// Problem: 378. Kth Smallest Element in a Sorted Matrix
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
/// Topics: `array`, `binary search`, `sorting`, `heap-(priority-queue)`, `matrix`
/// Timestamp: `Sun, 14 Sep 2025 20:35:51 +0530`

function kthSmallest(matrix: number[][], k: number): number {
  const maxPQ: MaxPQ<number> = new MaxPQ((a, b) => a < b ? -1 : a > b ? 1 : 0);

  for (const row of matrix) {
    for (const item of row) {
      maxPQ.insert(item);

      if (maxPQ.size() > k) {
        maxPQ.delMax();
      }
    }
  }

  return maxPQ.getMax()!;
}

//
// ## Notes
//
// This isn't an optimal solution for this problem, as it's using extra space
// proportional to `k` when it only needs to access the kth smallest.
//

/// }}

