class WeightedQuickUnion {
  /** @type {number[]} */
  #entries;

  /** @type {number[]} */
  #sizes;

  /**
   * @param {number} nOfObjects
   */
  constructor(nOfObjects) {
    this.#entries = [];
    for (let i = 0; i < nOfObjects; i++) {
      this.#entries.push(i);
    }

    this.#sizes = [];
    for (let i = 0; i < nOfObjects; i++) {
      this.#sizes.push(1);
    }
  }

  /**
   * @param {number} objIndex
   */
  #findRoot(objIndex) {
    if (objIndex < 0 || objIndex >= this.#entries.length) {
      throw new Error(
        `findRoot(${objIndex}): Index '${objIndex}' is out of bounds`
      );
    }

    while (this.#entries[objIndex] != objIndex) {
      objIndex = this.#entries[objIndex];
    }

    return objIndex;
  }

  /**
   * @param {number} objAIndex
   * @param {number} objBIndex
   * @returns {boolean}
   */
  union(objAIndex, objBIndex) {
    const rootAIndex = this.#findRoot(objAIndex);
    const rootBIndex = this.#findRoot(objBIndex);

    if (rootAIndex === rootBIndex) {
      return false;
    }

    const treeASize = this.#sizes[rootAIndex];
    const treeBSize = this.#sizes[rootBIndex];

    if (treeASize < treeBSize) {
      this.#entries[rootAIndex] = rootBIndex;
      this.#sizes[rootBIndex] += treeASize;
    } else {
      this.#entries[rootBIndex] = rootAIndex;
      this.#sizes[rootAIndex] += treeBSize;
    }
    return false;
  }

  /**
   * @param {number} objIndex 
   */
  unsetTreeSize(objIndex) {
    if (objIndex < 0 || objIndex >= this.#sizes.length) {
      throw new Error(
        `unsetTreeSize(${objIndex}): Index '${objIndex}' is out of bounds`
      );
    }
    this.#sizes[objIndex] = 0;
  }

  getLargestTreeSize() {
    const sizesLength = this.#sizes.length;
    let max = 0;

    for (let i = 0; i < sizesLength; i++) {
      const treeSize = this.#sizes[i];

      if (treeSize > max) {
        max = treeSize;
      }
    }

    return max;
  }
}

/**
 * @param {number[][]} grid
 * @return {number}
 */
function maxAreaOfIsland(grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  const unionFind = new WeightedQuickUnion(rows * cols);

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (grid[i][j] === 1) {
        const curLandIndex = i * cols + j;

        if (i > 0 && grid[i - 1][j] === 1) {
          const topLandIndex = (i - 1) * cols + j;
          unionFind.union(curLandIndex, topLandIndex);
        }

        if (j > 0 && grid[i][j - 1] === 1) {
          const leftLandIndex = i * cols + (j - 1);
          unionFind.union(curLandIndex, leftLandIndex);
        }

        if (j + 1 < cols && grid[i][j + 1] === 1) {
          const rightLandIndex = i * cols + (j + 1);
          unionFind.union(curLandIndex, rightLandIndex);
        }

        if (i + 1 < rows && grid[i + 1][j] === 1) {
          const bottomLandIndex = (i + 1) * cols + j;
          unionFind.union(curLandIndex, bottomLandIndex);
        }
      } else {
        unionFind.unsetTreeSize(i * cols + j);
      }
    }
  }

  return unionFind.getLargestTreeSize();
}
