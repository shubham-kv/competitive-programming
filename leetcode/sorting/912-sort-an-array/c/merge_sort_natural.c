#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 912. Sort an Array
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/sort-an-array/
/// Topics: `array`, `divide-and-conquer`, `sorting`, `Heap-(priority-queue)`,
/// `merge-sort`, `bucket-sort`, `radix-sort`, `Counting-sort`
/// Timestamp: `Sun, 13 Jul 2025 11:39:36 +0530`

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

void naturalMergesort(int *arr, int n) {
  int *aux = calloc(n, sizeof(int));

  for (int low = 0;;) {
    int i, mid;

    for (
      mid = low, i = mid;
      i + 1 < n && !LESS(arr, i + 1, i);
      mid++, i++
    ) { }

    if (!(mid + 1 < n)) {
      if (low == 0) {
        break;
      } else {
        low = 0;
        continue;
      }
    }

    int high = mid + 1;

    for (
      i = high;
      i + 1 < n && !LESS(arr, i + 1, i);
      high++, i++
    ) { }

    merge(arr, aux, low, mid, high);

    if (high + 1 < n) {
      low = high + 1;
    } else {
      low = 0;
    }
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int n, int *returnSize) {
  int *result = calloc(n, sizeof(int));
  memcpy(result, nums, n * sizeof(int));
  *returnSize = n;

  naturalMergesort(result, n);

  return result;
}

/// }}
