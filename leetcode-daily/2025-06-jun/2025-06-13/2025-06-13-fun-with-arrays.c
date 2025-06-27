// Date: 2025-06-13
// Title: Fun with Arrays
// Tags: [arrays, daily-practice]

#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

/// {{
/// Problem: 1346. Check If N and Its Double Exist
/// Links: https://leetcode.com/problems/check-if-n-and-its-double-exist/, https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/

bool checkIfExist(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    for (int j = 0; j < arrSize; j++) {
      if (i != j && arr[i] == 2 * arr[j]) {
        return true;
      }
    }
  }

  return false;
}

/// }}

/// {{
/// Problem: 941. Valid Mountain Array
/// Links: https://leetcode.com/problems/valid-mountain-array/, https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/

bool validMountainArray(int *arr, int arrSize) {
  int i;
  for (i = 1; i < arrSize && arr[i - 1] < arr[i]; i++) { }
  
  if (
    !(i > 1) ||           // At least one increasing sequence
    !(i < arrSize) ||     // There should be more elements
    arr[i - 1] == arr[i]  // No duplicates
  ) {
    return false;
  }

  for (; i < arrSize && arr[i - 1] > arr[i]; i++) { }

  // Array should end by now
  if (!(i >= arrSize)) {
    return false;
  }

  return true;
}

/// }}

/// {{
/// Problem: 1299. Replace Elements with Greatest Element on Right Side
/// Links: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/, https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *replaceElements(int *arr, int arrSize, int *returnSize) {
  int *result = calloc(arrSize, sizeof(int));
  *returnSize = arrSize;

  int greatest = -1;

  for (int i = arrSize - 1; i >= 0; i--) {
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
/// Links: https://leetcode.com/problems/remove-duplicates-from-sorted-array/, https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3258/

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 0) {
    return 0;
  }

  int uniqueI = 0;

  for (int i = 1; i < numsSize; i++) {
    if (nums[i - 1] != nums[i]) {
      nums[++uniqueI] = nums[i];
    }
  }

  return uniqueI + 1;
}

/// }}

/// {{
/// Problem: 283. Move Zeroes
/// Links: https://leetcode.com/problems/move-zeroes/, https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/

void moveZeroes(int *nums, int numsSize) {
  int firstZeroI = -1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      if (firstZeroI > -1 && firstZeroI < i) {
        const int temp = nums[i];
        nums[i] = nums[firstZeroI];
        nums[firstZeroI++] = temp;
      }
    } else {
      if (firstZeroI == -1) {
        firstZeroI = i;
      }
    }
  }
}

// Case 1:
// nums=[0,1,0,0,3,12], numsSize = 6

// loop starts
// i = 0, zerothI = 0
// i = 1, zerothI = 0
//    temp = 1
//    nums=[0,0,0,0,3,12]
//    nums=[1,0,0,0,3,12], zerothI=1

// i = 2, zerothI=1, nums[i]=0, nums=[1,0,0,0,3,12]
// i = 3, zerothI=1, nums[i]=0, nums=[1,0,0,0,3,12]
// i = 4, zerothI=1, nums[i]=3, nums=[1,0,0,0,3,12]
//    temp = 3
//    nums=[1,0,0,0,0,12]
//    nums=[1,3,0,0,0,12], zerothI=2

// i=5, zerothI=2, nums[i]=12, nums=[1,3,0,0,0,12]
//    temp=12
//    nums=[1,3,0,0,0,0]
//    nums=[1,3,12,0,0,0], zerothI=3

// i=6, zerothI=3, nums[i]=, nums=[1,3,12,0,0,0]
// loop ends

/// }}

/// {{
/// Problem: 905. Sort Array By Parity
/// Links: https://leetcode.com/problems/sort-array-by-parity/, https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
  int firstOddI = -1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] % 2 == 0) {
      if (firstOddI > -1 && firstOddI < i) {
        const int temp = nums[i];
        nums[i] = nums[firstOddI];
        nums[firstOddI++] = temp;
      }
    } else {
      if (firstOddI < 0) {
        firstOddI = i;
      }
    }
  }

  *returnSize = numsSize;
  return nums;
}

/// }}

/// {{
/// Problem: 27. Remove Element
/// Links: https://leetcode.com/problems/remove-element/, https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3575/

int removeElement(int* nums, int numsSize, int val) {
  if (numsSize <= 0) {
    return numsSize;
  }

  int leftmostValI = -1;
  int count = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      if (leftmostValI > -1 && leftmostValI < i) {
        const int itemNotEqualToVal = nums[i];
        nums[i] = nums[leftmostValI];
        nums[leftmostValI++] = itemNotEqualToVal;
      }
      count++;
    } else {
      if (leftmostValI < 0) {
        leftmostValI = i;
      }
    }
  }

  return leftmostValI < 0 ? count : leftmostValI;
}

// Case 1: nums=[0,1,2,2,3,0,4,2], val=2

// i=0, leftMostValI=-1, nums[i]=0, val=2
// i=1, leftMostValI=-1, nums[i]=1, val=2
// i=2, leftMostValI=-1, nums[i]=2, val=2
//    leftMostValI=2

// i=3, leftMostValI=2, nums[i]=2, val=2, nums=[0,1,2,2,3,0,4,2]
// i=4, leftMostValI=2, nums[i]=3, val=2, nums=[0,1,2,2,3,0,4,2]
//     itemNotEqualToVal=3
//     nums=[0,1,2,2,2,0,4,2]
//     nums=[0,1,3,2,2,0,4,2]

// i=5, leftMostValI=3, nums[i]=0, val=2, nums=[0,1,3,2,2,0,4,2]
//     nums=[0,1,3,0,2,2,4,2]
//     leftMostValI=4

// i=6, leftMostValI=4, nums[i]=4, val=2, nums=[0,1,3,0,2,2,4,2]
//     nums=[0,1,3,0,4,2,2,2]
//     leftMostValI=5

// i=7, leftMostValI=5, nums[i]=2, val=2, nums=[0,1,3,0,4,2,2,2]

/// }}
