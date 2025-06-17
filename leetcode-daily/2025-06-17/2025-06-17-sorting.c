// Title: Fun with sorting
// Date: 2025-06-17
// Created: Tue, 17 Jun 2025 19:06:56 +0530
// Tags: [sorting, arrays, daily-practice]

#include <stdlib.h>
#include <time.h>

/// {{
/// Problem: 215. Kth Largest Element in an Array
/// Links: https://leetcode.com/problems/kth-largest-element-in-an-array/

void shuffle(int *array, size_t n) {
  if (n <= 1) {
    return;
  }

  size_t i;

  for (i = 0; i < n - 1; i++) {
    size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
    int t = array[j];
    array[j] = array[i];
    array[i] = t;
  }
}

int partition(int *nums, int low, int high) {
  int p = low, i = low, j = high + 1;

  for(;;) {
    while (nums[++i] < nums[p] && i < high) { }

    while (nums[p] < nums[--j] && j > low) { }

    if (i >= j) {
      break;
    }

    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }

  int t = nums[j];
  nums[j] = nums[p];
  nums[p] = t;

  return j;
}

int findKthLargest(int* nums, int numsSize, int k) {
  srand(time(NULL));
  shuffle(nums, numsSize);

  int low = 0, high = numsSize - 1;

  while (low < high) {
    int p = partition(nums, low, high);

    if (p < k) {
      low = p + 1;
    } else if (p > k) {
      high = p - 1;
    } else {
      return nums[k];
    }
  }

  return nums[k];
}

/// }}
