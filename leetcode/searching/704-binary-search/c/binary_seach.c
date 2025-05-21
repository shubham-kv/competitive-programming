int search(int* nums, int numsSize, int target) {
  // 0 based indices
  int low, high, mid;

  // Initializations
  low = 0, high = numsSize - 1;
  mid = low + (high - low) / 2;

  // Loop until target is found or low is >= high
  while (target != nums[mid]) {
    if (target < nums[mid]) {
      high = mid - 1;
      mid = low + (high - low) / 2;
    } else if (target > nums[mid]) {
      low = mid + 1;
      mid = low + (high - low) / 2;
    }

    if (low > high) {
      return -1;
    }
  }

  return mid;
}
