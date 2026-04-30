#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 74. Search a 2D Matrix
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-a-2d-matrix/
/// Topics: `array`, `binary-search`, `matrix`
/// Timestamp: `Thu, 30 Apr 2026 10:58:42 +0530`

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize,
                  int target) {
  const int rows = matrixSize, cols = *matrixColSize;
  const int n = rows * cols;

  int low = 0, high = n - 1;

  while (low <= high) {
    const int mid = (low + high) / 2;
    const int midI = mid / cols;
    const int midJ = mid % cols;

    if (target < matrix[midI][midJ]) {
      high = mid - 1;
    } else if (target > matrix[midI][midJ]) {
      low = mid + 1;
    } else {
      return true;
    }
  }

  return false;
}

/// }}
