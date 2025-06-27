#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 215. Kth Largest Element in an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Fri, 27 Jun 2025 19:17:21 +0530`

// Heap Based solution
// 1. Build the heap
// 2. Remove the max k times & reheapify every time

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

bool less(int *arr, int i, int j) {
  return arr[i] < arr[j];
}

void sinkDown(int *heap, int n, int p) {
  for (
    int c = 2 * p + 1;
    c < n;
    p = c, c = 2 * p + 1
  ) {
    if ((c + 1) < n && less(heap, c, c+1)) {
      c = c + 1;
    }
    if (less(heap, p, c)) {
      swap(heap, p, c);
    } else {
      break;
    }
  }
}

int findKthLargest(int *nums, int n, int k) {
  for (int k = (n - 1) / 2; k >= 0; k--) {
    sinkDown(nums, n, k);
  }

  for (int i = 0, s = n; i < k; i++) {
    swap(nums, 0, --s);
    sinkDown(nums, s, 0);
  }

  return nums[n - k];
}

/// }}
