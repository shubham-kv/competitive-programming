function search(nums: number[], target: number): number {
  let low = 0,
    high = nums.length - 1,
    mid = 0;

  while (low <= high) {
    mid = Math.floor(low + (high - low) / 2);

    if (target < nums[mid]) {
      high = mid - 1;
    } else if (target > nums[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}
