// Date: 2025-06-13
// Created: Sat, 14 Jun 2025 11:12:18 +0530
// Tags: [arrays, sorting, daily-practice]

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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

  int writeI = -1;

  for (int i = 0; i < numsSize; i++) {
    const int curValue = result[i];

    if (curValue % 2 == 0) {
      if (writeI > -1 && writeI < i) {
        result[i] = result[writeI];
        result[writeI++] = curValue;
      }
    } else {
      if (writeI < 0) {
        writeI = i;
      }
    }
  }

  return result;
}

/// }}

/// {{
/// Problem: 1051. Height Checker
/// Links: https://leetcode.com/problems/height-checker/

int heightChecker(int *heights, int heightsSize) {
  int *expected = calloc(heightsSize, sizeof(int));
  memcpy(expected, heights, heightsSize * sizeof(int));

}

/// }}

/// {{
/// Problem: 148. Sort List
/// Links: https://leetcode.com/problems/sort-list/

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *linkedListMerge(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *merged = calloc(1, sizeof(struct ListNode));
  merged->next = NULL;

  struct ListNode *cur1 = list1, *cur2 = list2, *cur3 = merged;

  for(;;) {
    if (cur1 == NULL) {
      cur3->next = cur2;
      break;
    }
    else if (cur2 == NULL) {
      cur3->next = cur1;
      break;
    }
    else if (cur2->val < cur1->val) {
      cur3->next = cur2;
      cur2 = cur2->next;
      cur3 = cur3->next;
    }
    else {
      cur3->next = cur1;
      cur1 = cur1->next;
      cur3 = cur3->next;
    }
  }

  return merged->next;
}

struct ListNode *sortList(struct ListNode *head) {
  struct ListNode *prev, *list1;

  for (prev = NULL, list1 = head; ;) {
    struct ListNode *cur;

    // 1. Find the left sub-array
    // Loop until a node is out of order or it's next is null
    for (
      cur = list1;
      cur != NULL && cur->next != NULL && cur->val <= cur->next->val;
      cur = cur->next
    ) { }

    // Check if something's left
    if (cur == NULL || cur->next == NULL) {
      if (list1 == head) {
        // Nothing left to sort
        break;
      } else {
        prev = NULL;
        list1 = head;
        continue;
      }
    }

    // 2. Find the right sub-array
    struct ListNode *list2 = cur->next;

    // Break the list here at current node
    cur->next = NULL;

    // Loop until a node is out of order or it's next is null
    for (
      cur = list2;
      cur != NULL && cur->next != NULL && cur->val <= cur->next->val;
      cur = cur->next
    ) { }

    struct ListNode *next = NULL;

    if (cur != NULL && cur->next != NULL) {
      next = cur->next;
      cur->next = NULL;
    }

    // 3. Merge the two sub-arrays
    struct ListNode *merged = linkedListMerge(list1, list2);

    // Link the returned merged list with previous node
    if (list1 == head) {
      head = merged;
    } else {
      prev->next = merged;
    }

    // Iterate to the last node of the returned list
    for (
      cur = merged;
      cur != NULL && cur->next != NULL;
      cur = cur->next
    ) {}

    // Link the returned merged list with the next node
    prev = cur;
    list1 = next;
    prev->next = list1;
  }

  return head;
}

/// }}
