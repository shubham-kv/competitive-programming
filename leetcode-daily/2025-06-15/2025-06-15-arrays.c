// Title: Arrays
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
  int leftI = iMin, rightI = iMax;
  int count = 0;

  while (leftI <= rightI) {
    const int valFromLeft = nums[leftI];
    const int valFromRight = nums[rightI];

    if (leftI < rightI) {
      if (valFromLeft == val) {
        if (valFromLeft == valFromRight) {
          rightI--;
        } else {
          nums[leftI++] = valFromRight;
          nums[rightI--] = valFromLeft;
          count++;
        }
      } else {
        leftI++;
        count++;
      }
    } else {
      if (valFromLeft != val) {
        count++;
      }
      leftI++;
    }
  }

  return count;
}

// Case 1: nums=[3,2,2,3], val=3
// -----------------------------

// [Initial]
//   iMin = 0, iMax = 3
//  leftI = 0
// rightI = 3
//  count = 0

// [Running]

// [ret count=2]

// [loop entry check 4]
// (leftI <= rightI), (2 <= 1) false, exit

// [loop entry check 3]
// (leftI <= rightI), (1 <= 1) true, enter

// [Iteration 3]
//  leftI = 2      V
//   nums =   [2 2 3 3]
// rightI = 1    ^
//  count = 2

// [loop entry check 2]
// (leftI <= rightI), (0 <= 2) true, enter

// [Iteration 2]
//  leftI = 1    V
//   nums =   [2 2 3 3]
// rightI = 1    ^
//  count = 1

// [loop entry check 1]
// (leftI <= rightI), (0 <= 3) true, enter

// [Iteration 1]
//  leftI = 0  V
//   nums =   [3 2 2 3]
// rightI = 2      ^
//  count = 0


// Case 2: nums=[2] val=3
// ----------------------

// [Initial]
//   iMin = 0, iMax = 0
//  leftI = 0
// rightI = 0
//  count = 0

// [Running]
// Return count=1

// [Iteration _] while (leftI <= rightI), false as 1 !<= 0, exit

//  leftI = 1    V
//   nums =   [2]
// rightI = 0  ^
//  count = 1

// [Iteration 1] while (leftI <= rightI), true, enter

//  leftI = 1    V
//   nums =   [2]
// rightI = 0  ^
//  count = 1

/// }}

/// {{
/// Problem: 1051. Height Checker
/// Links: https://leetcode.com/problems/height-checker/

int compareInts(const void *a, const void *b) {
  const int num1 = *(const int *)a;
  const int num2 = *(const int *)b;

  return (num1 < num2) ? -1 : (num1 > num2) ? 1
                                            : 0;
}

int heightChecker(int *heights, int heightsSize) {
  if (heightsSize <= 1) {
    return 0;
  }

  int *expected = calloc(heightsSize, sizeof(int));
  memcpy(expected, heights, heightsSize * sizeof(int));
  qsort(expected, heightsSize, sizeof(int), compareInts);

  int count = 0;

  for (int i = 0; i < heightsSize; i++) {
    if (heights[i] != expected[i]) {
      count++;
    }
  }

  return count;
}

/// }}

/// {{
/// Problem: 414. Third Maximum Number
/// Links: https://leetcode.com/problems/third-maximum-number/

int INTS_DECREASING(const void *ptrA, const void *ptrB) {
  const int a = *(const int *)ptrA;
  const int b = *(const int *)ptrB;

  return (a > b) ? -1 : (a < b) ? 1
                                : 0;
}

int thirdMax(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), INTS_DECREASING);

  int max = nums[0];

  if (numsSize >= 3) {
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
      int cur = nums[i];

      if (cur < max && cur != max) {
        if (count < 3) {
          max = cur;
          count++;
        }
        else {
          return max;
        }
      }
    }
  }

  return max;
}

// 2^4
// In 4 bits total 16 values can be represented from 0 to 15

/// }}
