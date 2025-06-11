/**
 * @param {number[]} nums
 */
function Solution(nums) {
  this.originalArr = [...nums];
}

/**
 * @return {number[]}
 */
Solution.prototype.reset = function () {
  return [...this.originalArr];
};

/**
 * @return {number[]}
 */
Solution.prototype.shuffle = function () {
	const arr = [...this.originalArr];
	const nOfItems = arr.length;

	for (let i = 0; i < nOfItems; i++) {
		const randomIndex = Math.floor(i + Math.random() * (nOfItems - i));
		const randomItem = arr[randomIndex];
		arr[randomIndex] = arr[i];
		arr[i] = randomItem;
	}

	return arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
