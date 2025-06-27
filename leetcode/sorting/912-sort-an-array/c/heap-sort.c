#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 912. Sort an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/sort-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `Heap-(priority-queue)`, `merge-sort`, `bucket-sort`, `radix-sort`, `Counting-sort`
/// Timestamp: `Fri, 27 Jun 2025 18:20:22 +0530`

// Heap sort based solution

inline bool less(int *arr, int i, int j) {
  return arr[i] < arr[j];
}

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void MaxHeap_sinkDown(int *heap, int n, int p) {
  for (
    int c = 2 * p + 1;
    c < n;
    p = c, c = 2 * p + 1
  ) {
    if ((c + 1) < n && less(heap, c, c + 1)) {
      c++;
    }
    if (less(heap, p, c)) {
      swap(heap, p, c);
    } else {
      break;
    }
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int n, int *returnSize) {
  *returnSize = n;

  // Build the heap
  for (int k = (n - 1) / 2; k >= 0; k--) {
    MaxHeap_sinkDown(nums, n, k);
  }

  // Pull out the max
  for (int s = n; s > 0; ) {
    swap(nums, 0, --s);
    MaxHeap_sinkDown(nums, s, 0);
  }

  return nums;
}

/// }}
