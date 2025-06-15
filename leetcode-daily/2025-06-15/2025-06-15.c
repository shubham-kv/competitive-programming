// Date: 2025-06-15
// Created: Sun, 15 Jun 2025 11:31:08 +0530
// Tags: [arrays, daily-practice]

#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 283. Move Zeroes
/// Links: https://leetcode.com/problems/move-zeroes/

void moveZeroes(int *nums, int numsSize) {
  if (numsSize <= 1) {
    return;
  }

  int writeI = -1;

  for (int i = 0; i < numsSize; i++) {
    const int curValue = nums[i];

    if (curValue == 0) {
      if (writeI < 0) {
        writeI = i;
      }
    } else {
      if (writeI > -1 && writeI < i) {
        nums[i] = nums[writeI];
        nums[writeI++] = curValue;
      }
    }
  }
}

/// }}

/// {{
/// Problem: 905. Sort Array By Parity
/// Links: https://leetcode.com/problems/sort-array-by-parity/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
  int *result = calloc(numsSize, sizeof(int));
  memcpy(result, nums, numsSize * sizeof(int));
  *returnSize = numsSize;

  int firstOddI = -1;

  for (int i = 0; i < numsSize; i++) {
    const int cur = result[i];

    if (cur % 2 == 0) {
      if (firstOddI > -1 && firstOddI < i) {
        result[i] = result[firstOddI];
        result[firstOddI++] = cur;
      }
    } else {
      if (firstOddI < 0) {
        firstOddI = i;
      }
    }
  }

  return result;
}

/// }}

/// {{
/// Problem: 27. Remove Element
/// Links: https://leetcode.com/problems/remove-element/

int removeElement(int *nums, int numsSize, int val) {
  if (numsSize <= 0) {
    return 0;
  }

  int iMin = 0, iMax = numsSize - 1;
  int leftI, rightI;
  int count = 0;

  for (
      leftI = iMin, rightI = iMax;
      leftI < rightI;
      leftI++)
  {
    const int val1 = nums[leftI];
    const int val2 = nums[rightI];

    if (val1 == val) {
      if (val2 != val) {
        if (leftI < rightI) {
          nums[leftI] = val2;
          nums[rightI--] = val1;
        }
      }
      else {
        leftI--;
        rightI--;
      }
    }
  }

  return ;
}

/// }}
