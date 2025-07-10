// Title: Fun with sorting
// Date: 2025-07-10
// Created: Thu, 10 Jul 2025 11:41:07 +0530
// Tags: [sorting, daily-practice]

#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 912. Sort an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/sort-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `Heap-(priority-queue)`,
/// `merge-sort`, `bucket-sort`, `radix-sort`, `Counting-sort`
/// Timestamp: `Thu, 10 Jul 2025 11:41:07 +0530`

#define LESS(arr, i, j) (arr[i] < arr[j])

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void sinkDown(int *arr, int n, int p) {
  for (int c = 2 * p + 1; c < n; p = c, c = 2 * p + 1) {
    if (c + 1 < n && LESS(arr, c, c + 1)) {
      c = c + 1;
    }

    if (LESS(arr, p, c)) {
      swap(arr, p, c);
    } else {
      break;
    }
  }
}

void heapSort(int *arr, int n) {
  for (int i = (n - 1) / 2; i >= 0; i--) {
    sinkDown(arr, n, i);
  }

  for (; n > 0;) {
    swap(arr, 0, --n);
    sinkDown(arr, n, 0);
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int numsSize, int *returnSize) {
  int *result = calloc(numsSize, sizeof(int));

  *returnSize = numsSize;
  memcpy(result, nums, numsSize * sizeof(int));

  heapSort(result, numsSize);

  return result;
}

/// }}
