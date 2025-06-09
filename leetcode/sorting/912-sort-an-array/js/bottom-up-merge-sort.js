class BottomUpMerge {
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

    let iMin = low,
      iMax = mid;
    let jMin = mid + 1,
      jMax = high;

    for (let i = iMin, j = jMin, k = low; k <= high; k++) {
      if (i > iMax) {
        arr[k] = this.#aux[j++];
      } else if (j > jMax) {
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
   */
  static sort(arr) {
    /** @type {number} */
    const n = arr.length;
    this.#aux = Array(n).fill(0);

    for (let l = 1; l < n; l *= 2) {
      for (let offset = 0; offset + l < n; offset += 2 * l) {
        const low = offset;
        const mid = offset + l - 1;
        const high = Math.min(offset + 2 * l - 1, n - 1);
        this.#merge(arr, low, mid, high);
      }
    }
  }
}
