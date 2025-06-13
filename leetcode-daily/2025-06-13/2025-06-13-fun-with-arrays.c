// Date: 2025-06-13
// Title: Fun with Arrays
// Tags: [arrays, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 1346. Check If N and Its Double Exist
/// Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/
/// Link: https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/

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
/// Link: https://leetcode.com/problems/valid-mountain-array/
/// Link: https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/

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
/// Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
/// Link: https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/

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
/// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
/// Link: https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3258/

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
