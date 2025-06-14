// Title: Fun with Arrays
// Date: 2025-06-13
// Created: Sat, 14 Jun 2025 11:12:18 +0530
// Tags: [arrays, daily-practice]

#include <stdlib.h>

/// {{
/// Problem: 1299. Replace Elements with Greatest Element on Right Side
/// Links: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *replaceElements(int *arr, int arrSize, int *returnSize) {
  int *result = calloc(arrSize, sizeof(int));
  *returnSize = arrSize;

  for (int greatest = -1, i = arrSize - 1; i >= 0; i--) {
    result[i] = greatest;

    if (arr[i] > greatest) {
      greatest = arr[i];
    }
  }

  return result;
}

/// }}

/// {{
/// Problem: 26. Remove Duplicates from Sorted Array
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(int *nums, int numsSize) {
  if (numsSize <= 1) {
    return numsSize;
  }

  int writeI = 0;

  for (int readI = 1; readI < numsSize; readI++) {
    if (nums[readI - 1] != nums[readI]) {
      nums[++writeI] = nums[readI];
    }
  }

  return writeI + 1;
}

// Case 1: nums=[1,1,2]

// [Initial]
//  writeI = 0  V
//    nums =  [ 3 3 3 6 6 8 ]
// indices =    0 1 2 3 4 5
//   readI = 1    ^

// [Running]

//   [Last Increment of for loop]
//    writeI = 2      V
//      nums =  [ 3 6 8 6 6 8 ]
//   indices =    0 1 2 3 4 5
//     readI = 6              ^

//   [Iteration 3]
//    writeI = 2      V
//      nums =  [ 3 6 8 6 6 8 ]
//   indices =    0 1 2 3 4 5
//     readI = 5            ^

//   [Iteration 3]
//    writeI = 1    V
//      nums =  [ 3 6 3 6 6 8 ]
//   indices =    0 1 2 3 4 5
//     readI = 4          ^

//   [Iteration 2]
//    writeI = 1    V
//      nums =  [ 3 6 3 6 6 8 ]
//   indices =    0 1 2 3 4 5
//     readI = 3        ^

//   [Iteration 2]
//    writeI = 0  V
//      nums =  [ 3 3 3 6 6 8 ]
//   indices =    0 1 2 3 4 5
//     readI = 2      ^

//   [Iteration 1]
//    writeI = 0  V
//      nums =  [ 3 3 3 6 6 8 ]
//   indices =    0 1 2 3 4 5
//     readI = 1    ^

/// }}

/// {{
/// Problem: 283. Move Zeroes
/// Links: https://leetcode.com/problems/move-zeroes/

void moveZeroes(int *nums, int numsSize) {
  if (numsSize <= 1) {
    return;
  }

  // Index of running first zero
  int writeI = -1;

  for (int i = 0; i < numsSize; i++) {
    const int curNum = nums[i];

    if (curNum == 0) {
      if (writeI < 0) {
        writeI = i;
      }
    } else {
      if (writeI > -1 && writeI < i) {
        nums[i] = nums[writeI];
        nums[writeI++] = curNum;
      }
    }
  }
}

// Case: nums = [0,1,0,3,12]

// [INITIAL]
//   nums = [ 0 1 0 3 12 ]
// writeI = -1

// [RUNNING] for i from 1 to 4

//   [Iteration -]: i = 5 !< 5; exits
//    writeI = 3          V
//      nums =   [ 1 3 12 0 0 ]
//   indices =     0 1  2 3 4
//         i = 5            ^

//   [Iteration 5]: i = 4 < 5; enters
//    writeI = 3          V
//      nums =   [ 1 3 12 0 0 ]
//   indices =     0 1  2 3 4
//         i = 4            ^

//   [Iteration 4]
//    writeI = 2       V
//      nums =   [ 1 3 0 0 12 ]
//   indices =     0 1 2 3  4
//         i = 3         ^

//   [Iteration 3]
//    writeI = 1     V
//      nums =   [ 1 0 0 3 12 ]
//   indices =     0 1 2 3  4
//         i = 2       ^

//   [Iteration 2]
//    writeI = 1     V
//      nums =   [ 1 0 0 3 12 ]
//   indices =     0 1 2 3  4
//         i = 1     ^

//   [Iteration 1]
//    writeI = 0    V
//      nums =    [ 0 1 0 3 12 ]
//   indices =      0 1 2 3  4
//         i =  0   ^

/// }}
