#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// {{
/// Problem: 506. Relative Ranks
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/relative-ranks/
/// Topics: `array`, `sorting`, `heap-(priority-queue)`
/// Timestamp: `Sat, 13 Sep 2025 13:11:37 +0530`

#define LESS(heap, p, c) (heap[p] < heap[c])

inline void swap(int *arr, int n, int i, int j) {
  if ((0 <= i && i < n) && (0 <= j && j < n)) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void sinkDown(int *heap, const int heapSize, int p) {
  for (
    int c = 2 * p + 1;
    c < heapSize;
    p = c, c = 2 * p + 1
  ) {
    if ((c + 1) < heapSize && heap[c] < heap[c + 1]) {
      c = c + 1;
    }
    if (LESS(heap, p, c)) {
      swap(heap, heapSize, p, c);
    } else {
      break;
    }
  }
}

void swimUp(int *heap, const int heapSize, int c) {
  for (
    int p = (c - 1) / 2;
    p >= 0;
    c = p, p = (c - 1) / 2
  ) {
    if (LESS(heap, p, c)) {
      swap(heap, heapSize, p, c);
    } else {
      break;
    }
  }
}

void insert(int *heap, int *heapSize, const int heapArrSize, int key) {
  if (!(*heapSize < heapArrSize)) {
    return;
  }
  heap[*heapSize] = key;
  *heapSize += 1;
  swimUp(heap, *heapSize, *heapSize - 1);
}

int delMax(int *heap, int *heapSize) {
  if (!(*heapSize > 0)) {
    return -1;
  }

  const int max = heap[0];

  heap[0] = heap[*heapSize - 1];
  *heapSize -= 1;
  sinkDown(heap, *heapSize, 0);

  return max;
}

int indexOf(int *arr, int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

const char *places[3] = {
  "Gold Medal",
  "Silver Medal",
  "Bronze Medal"
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findRelativeRanks(int *score, int scoreSize, int* returnSize) {
  int heap[scoreSize];
  int heapSize = 0;

  for (int i = 0; i < scoreSize; i++) {
    insert(heap, &heapSize, scoreSize, score[i]);
  }

  char **ranks = calloc(scoreSize, sizeof(*ranks));
  *returnSize = scoreSize;

  const int bufSize = 16;
  char buffer[bufSize];

  const int savedHeapSize = heapSize;

  for (int i = 1; i <= savedHeapSize; i++) {
    const int athleteScore = delMax(heap, &heapSize);
    const int athleteIndex = indexOf(score, scoreSize, athleteScore);

    if (!(athleteIndex > -1)) {
      continue;
    }
    char *rank;

    if (i <= 3) {
      rank = strdup(places[i - 1]);
    } else {
      snprintf(buffer, bufSize, "%d", i);

      const size_t len = strlen(buffer) + 1;
      rank = calloc(len, sizeof(*rank));
      snprintf(rank, len, "%d", i);
    }

    ranks[athleteIndex] = rank;
  }

  return ranks;
}

/// }}

