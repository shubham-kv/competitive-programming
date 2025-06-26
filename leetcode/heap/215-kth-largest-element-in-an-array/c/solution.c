#include <stdlib.h>

/// {{
/// Problem: 215. Kth Largest Element in an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `heap-(priority-queue)`, `quickselect`
/// Timestamp: `Thu, 26 Jun 2025 11:08:59 +0530`

// Heap Based solution
// 1. Build the heap
// 2. Remove the max k times & reheapify every time

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

/// }}
