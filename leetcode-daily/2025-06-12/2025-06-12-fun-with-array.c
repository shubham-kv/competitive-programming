#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

// Problem: 977. Squares of a Sorted Array {{
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/

int intComparator(const void *a, const void *b) {
  int numA = *(const int *)a;
  int numB = *(const int *)b;

  return (numA < numB) ? -1 : (numA > numB) ? 1
                                            : 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  int *squares = calloc(numsSize, sizeof(int));
  *returnSize = numsSize;

  for (int i = 0; i < numsSize; i++) {
    squares[i] = nums[i] * nums[i];
  }

  qsort(squares, numsSize, sizeof(int), intComparator);
  return squares;
}

// }}


// 1089. Duplicate Zeros {{
// https://leetcode.com/problems/duplicate-zeros/

void duplicateZeros(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] == 0) {
      for (int j = arrSize - 1; j > i; j--) {
        arr[j] = arr[j - 1];
      }
      ++i;
    }
  }
}

// }}

// 88. Merge Sorted Array {{
// https://leetcode.com/problems/merge-sorted-array

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int *nums1Aux = calloc(m, sizeof(int));

  // for (int i = 0; i < m; i++)
  //   nums1Aux[i] = nums1[i];
  memcpy(nums1Aux, nums1, m * sizeof(int));

  int iMin = 0, jMin = 0, iMax = m - 1, jMax = n - 1;

  for (int i = iMin, j = jMin, k = 0; k < m + n; k++) {
    if (i > iMax) {
      nums1[k] = nums2[j++];
    } else if (j > jMax) {
      nums1[k] = nums1Aux[i++];
    } else if (nums2[j] < nums1Aux[i]) {
      nums1[k] = nums2[j++];
    } else {
      nums1[k] = nums1Aux[i++];
    }
  }
}

// }}

// 27. Remove Element {{
// https://leetcode.com/problems/remove-element/

void removeElementAtNthIndex(int *nums, int numsSize, int n) {
  for (int j = n; (j + 1) < numsSize; j++) {
    nums[j] = nums[j + 1];
  }
}

int removeElement(int* nums, int numsSize, int val) {
  int countOfElementsNotEqualToVal = numsSize;

  for (int i = 0; i < countOfElementsNotEqualToVal; i++) {
    if (nums[i] == val) {
      removeElementAtNthIndex(nums, countOfElementsNotEqualToVal, i);
      i--;
      countOfElementsNotEqualToVal--;
    }
  }

  return countOfElementsNotEqualToVal;
}

// }}

// 26. Remove Duplicates from Sorted Array {{
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

void removeElementAtN(int *nums, int size, int n) {
  for (int i = n; (i + 1) < size; i++) {
    nums[i] = nums[i + 1];
  }
}

int removeDuplicates(int* nums, int numsSize) {
  int sizeOfNonDuplicates = numsSize;

  for (int i = 1; i < sizeOfNonDuplicates; i++) {
    if (nums[i] == nums[i - 1]) {
      removeElementAtN(nums, numsSize, i);
      i--;
      sizeOfNonDuplicates--;
    }
  }

  return sizeOfNonDuplicates;
}

// }}

/// 1346. Check If N and Its Double Exist {{
// https://leetcode.com/problems/check-if-n-and-its-double-exist/

bool checkIfExist(int* arr, int arrSize) {
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

/// 941. Valid Mountain Array {{
// https://leetcode.com/problems/valid-mountain-array/
// https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/

bool validMountainArray(int* arr, int arrSize) {
  int i;
  for (i = 1; i < arrSize && arr[i - 1] < arr[i]; i++) { }
  
  if (
    !(i < arrSize) ||       // There should be more elements
    !(i > 1) ||             // There should be at least one increasing sequence
    (arr[i - 1] == arr[i])  // There should be no duplicates
  ) {
    return false;
  }

  for(; i < arrSize && arr[i - 1] > arr[i]; i++) {}

  // There should not be a non decreasing sequence here
  if (!(i == arrSize)) {
    return false;
  }

  return true;
}

/// }}
