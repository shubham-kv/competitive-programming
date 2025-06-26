// Title: Fun with heaps
// Date: 2025-06-26
// Created: Thu, 26 Jun 2025 11:07:05 +0530
// Tags: [heap, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 215. Kth Largest Element in an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Thu, 26 Jun 2025 11:08:59 +0530`

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void swimUp(int *arr, int n, int k) {
  for (
    int p = (k - 1) / 2;
    p > 0 && (arr[p] < arr[k]);
    k = p, p = (k - 1) / 2
  ) {
    swap(arr, p, k);
  }
}

void sinkDown(int *arr, int n, int k) {
  for (
    int j = 2 * k + 1;
    j < n;
    k = j, j = 2 * k + 1
  ) {
    if (j + 1 < n && arr[j] < arr[j + 1]) {
      j = j + 1;
    }

    if (arr[k] < arr[j]) {
      swap(arr, k, j);
    } else {
      break;
    }
  }
}

int findKthLargest(int *nums, int n, int k) {
  for (int i = (n - 1) / 2; i >= 0; i--) {
    sinkDown(nums, n, i);
  }

  for (int i = 0, s = n; i < k; i++) {
    swap(nums, 0, --s);
    sinkDown(nums, s, 0);
  }

  return nums[n - k];
}

// }}


/// {{
/// Problem: 703. Kth Largest Element in a Stream
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/kth-largest-element-in-a-stream
/// Topics: `tree`, `design`, `binary-search-tree`, `heap-(priority-queue)`, `binary-tree`, `data-stream`
/// Timestamp: `Thu, 26 Jun 2025 12:01:57 +0530`

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

bool less(int *arr, int i, int j) {
  return (arr[i] < arr[j]);
}

void MinPQ_swimUp(int *arr, int n, int k) {
  for (
    int p = (k - 1) / 2;
    p > 0 && less(arr, k, p);
    k = p, p = (k - 1) / 2
  ) {
    swap(arr, p, k);
  }
}

void MinPQ_sinkDown(int *arr, int n, int k) {
  for (
    int j = 2 * k + 1;
    j < n;
    k = j, j = 2 * k + 1
  ) {
    if (j + 1 < n && less(arr, j + 1, j)) {
      j++;
    }

    if (less(arr, j, k)) {
      swap(arr, k, j);
    } else {
      break;
    }
  }
}

void MinPQ_insert(int *heap, int *heapSize, int val) {
  int n = *heapSize++;
  heap[n - 1] = val;
  MinPQ_swimUp(heap, n, n - 1);
}

int MinPQ_delMin(int *heap, int *heapSize) {
  int n = *heapSize;
  int min = heap[0];
  swap(heap, 0, --n);
  MinPQ_sinkDown(heap, n, 0);
  *heapSize = n;
  return min;
}

typedef struct {
  int *heap;
  int capacity;
  int heapSize;
  int k;
} KthLargest;

KthLargest *kthLargestCreate(int k, int *nums, int numsSize) {
  KthLargest *kthLargest = calloc(1, sizeof(KthLargest));
  kthLargest->heap = nums;
  kthLargest->capacity = numsSize;
  kthLargest->heapSize = numsSize;
  kthLargest->k = k;

  // Heap construction
  int n = numsSize;
  for (int k = (n - 1) / 2; k >= 0; k--) {
    MinPQ_sinkDown(nums, n, k);
  }

  return kthLargest;
}

int kthLargestAdd(KthLargest *kthLargest, int val) {
  kthLargest->heap[0] = val;
  MinPQ_sinkDown(kthLargest->heap, kthLargest->heapSize, 0);

  int n = kthLargest->capacity;
  int k = kthLargest->k;
  int aux[n];
  int times = n - k + 1;

  for (int i = 0; i < times; i++) {
    aux[i] = MinPQ_delMin(kthLargest->heap, &kthLargest->heapSize);
  }

  for (int i = 0; i < times; i++) {
    MinPQ_insert(kthLargest->heap, &kthLargest->heapSize, aux[i]);
  }

  return aux[n - k];
}

void kthLargestFree(KthLargest *obj) {
  free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

/// }}
