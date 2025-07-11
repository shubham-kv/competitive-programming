// Title: Fun with sorting
// Date: 2025-07-11
// Created: Fri, 11 Jul 2025 11:32:29 +0530
// Tags: [sorting, daily-practice]

#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 912. Sort an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/sort-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `Heap-(priority-queue)`,
/// `merge-sort`, `bucket-sort`, `radix-sort`, `Counting-sort`
/// Timestamp: `Fri, 11 Jul 2025 11:32:29 +0530`

#define LESS(arr, i, j) (arr[i] < arr[j])

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

void mergeSortRecursive(int *arr, int *aux, int low, int high) {
  if (!(low < high)) {
    return;
  }

  const int mid = (low + high) / 2;
  mergeSortRecursive(arr, aux, low, mid);
  mergeSortRecursive(arr, aux, mid+1, high);

  if (LESS(arr, mid + 1, mid)) {
    merge(arr, aux, low, mid, high);
  }
}

void mergeSort(int *arr, int n) {
  int *aux = calloc(n, sizeof(int));
  mergeSortRecursive(arr, aux, 0, n - 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int numsSize, int *returnSize) {
  int *result = calloc(numsSize, sizeof(int));
  memcpy(result, nums, numsSize * sizeof(int));
  *returnSize = numsSize;

  mergeSort(result, numsSize);

  return result;
}

/// }}
