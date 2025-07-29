/// {{
/// Problem: 74. Search a 2D Matrix
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/search-a-2d-matrix/
/// Topics: `array`, `binary-search`, `matrix`
/// Timestamp: `Wed, 30 Jul 2025 01:17:35 +0530`

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
function searchMatrix(matrix, target) {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const n = rows * cols;

  for (
    let low = 0, high = n - 1;
    low <= high;
  ) {
    const mid = Math.floor((low + high) / 2);
    const rowIndex = Math.floor(mid / cols);
    const colIndex = mid % cols;
    const midVal = matrix[rowIndex][colIndex];

    if (target < midVal) {
      high = mid - 1;
    } else if (target > midVal) {
      low = mid + 1;
    } else {
      return true;
    }
  }

  return false;
};

/// }}
