/// {{
/// Problem: 347. Top K Frequent Elements
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/top-k-frequent-elements/
/// Topics: `array`, `hash-table`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Sun, 14 Sep 2025 13:55:55 +0530`

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

