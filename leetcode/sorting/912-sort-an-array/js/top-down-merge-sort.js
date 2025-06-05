class TopDownMergeSort {
  /** @type {number[]} */
  static #aux;

  /**
   * @param {number[]} arr
   * @param {number} low
   * @param {number} mid
   * @param {number} high
   */
  static #merge(arr, low, mid, high) {
    for (let k = low; k <= high; k++) {
      this.#aux[k] = arr[k];
    }

    let i = low;
    let j = mid + 1;

    for (let k = low; k <= high; k++) {
      if (i > mid) {
        arr[k] = this.#aux[j++];
      } else if (j > high) {
        arr[k] = this.#aux[i++];
      } else if (this.#aux[j] < this.#aux[i]) {
        arr[k] = this.#aux[j++];
      } else {
        arr[k] = this.#aux[i++];
      }
    }
  }

  /**
   * @param {number[]} arr
   * @param {number} low
   * @param {number} high
   */
  static #sortRecursive(arr, low, high) {
    if (low >= high) {
      return;
    }

    /** @type {number} */
    const mid = low + Math.trunc((high - low) / 2);

    this.#sortRecursive(arr, low, mid);
    this.#sortRecursive(arr, mid + 1, high);
    this.#merge(arr, low, mid, high);
  }

  /**
   * @param {number[]} arr
   */
  static sort(arr) {
    const n = arr.length;
    this.#aux = Array(n).fill(0);

    this.#sortRecursive(arr, 0, n - 1);
  }
}

/**
 * @param {number[]} nums
 * @return {number[]}
 */
function sortArray(nums) {
  TopDownMergeSort.sort(nums);
  return nums;
}
