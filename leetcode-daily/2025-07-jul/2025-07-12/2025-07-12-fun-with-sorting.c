// Title: Fun with sorting
// Date: 2025-07-12
// Created: Sat, 12 Jul 2025 19:48:04 +0530
// Tags: [sorting, daily-practice]

#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 912. Sort an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/sort-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `Heap-(priority-queue)`,
/// `merge-sort`, `bucket-sort`, `radix-sort`, `Counting-sort`
/// Timestamp: `Sat, 12 Jul 2025 19:48:04 +0530`

#define LESS(arr, i, j) (arr[i] < arr[j])
#define MIN(a, b) (a < b ? a : b)

void merge(int *arr, int *aux, int low, int mid, int high) {
  memcpy(&aux[low], &arr[low], (high - low + 1) * sizeof(int));
  const int iMin = low, iMax = mid, jMin = mid + 1, jMax = high;

  for (int i = iMin, j = jMin, k = iMin; k <= jMax; k++) {
    if (i > iMax) {
      arr[k] = aux[j++];
    } else if (j > jMax) {
      arr[k] = aux[i++];
    } else if (LESS(aux, j, i)) {
      arr[k] = aux[j++];
    } else {
      arr[k] = aux[i++];
    }
  }
}

void bottomUpMergeSort(int *arr, int n) {
  int *aux = calloc(n, sizeof(int));

  for (int l = 1; l < n; l *= 2) {
    for (int low = 0; low + l < n; low += 2 * l) {
      const int mid = low + l - 1;
      const int high = MIN(n - 1, low + 2 * l - 1);

      if (LESS(arr, mid + 1, mid)) {
        merge(arr, aux, low, mid, high);
      }
    }
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int numsSize, int *returnSize) {
  int *result = calloc(numsSize, sizeof(int));
  memcpy(result, nums, numsSize * sizeof(int));
  *returnSize = numsSize;

  bottomUpMergeSort(result, numsSize);

  return result;
}

/// }}
