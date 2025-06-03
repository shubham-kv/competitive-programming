class WeightedQuickUnion {
  /** @type {number[]} */
  #entry;

  /** @type {number[]} */
  #treeSize;

  /** @type {number} */
  #countOfComponents;

  /**
   * @param {number} numberOfObjects
   */
  constructor(numberOfObjects) {
    this.#entry = [];
    for (let i = 0; i < numberOfObjects; i++) {
      this.#entry.push(i);
    }

    this.#treeSize = [];
    for (let i = 0; i < numberOfObjects; i++) {
      this.#treeSize.push(i);
    }

    this.#countOfComponents = numberOfObjects;
  }

  /**
   * @param {number} objectIndex
   */
  #findRoot(objectIndex) {
    if (objectIndex < 0 || objectIndex >= this.#entry.length) {
      throw new Error(
        `findRoot(): Object index '${objectIndex}' out of bounds`
      );
    }

    while (objectIndex !== this.#entry[objectIndex]) {
      objectIndex = this.#entry[objectIndex];
    }

    return objectIndex;
  }

  /**
   * @param {number} objectAIndex
   * @param {number} objectBIndex
   * @returns {boolean}
   */
  union(objectAIndex, objectBIndex) {
    const rootAIndex = this.#findRoot(objectAIndex);
    const rootBIndex = this.#findRoot(objectBIndex);

    // Objects are already connected
    if (rootAIndex === rootBIndex) {
      return false;
    }

    // Link the smaller tree to the larger tree
    const treeASize = this.#treeSize[rootAIndex];
    const treeBSize = this.#treeSize[rootBIndex];

    if (treeASize < treeBSize) {
      this.#entry[rootAIndex] = rootBIndex;
      this.#treeSize[rootBIndex] += treeASize;
    } else {
      this.#entry[rootBIndex] = rootAIndex;
      this.#treeSize[rootAIndex] += treeBSize;
    }
    --this.#countOfComponents;

    return true;
  }

  decrementCountOfComponents() {
    --this.#countOfComponents;
  }

  get countOfComponents() {
    return this.#countOfComponents;
  }
}

/**
 * @param {string[][]} grid
 * @return {number}
 */
function numIslands(grid) {
  const numberOfRows = grid.length;
  const numberOfCols = grid[0].length;
  const numberOfObjects = numberOfRows * numberOfCols;

  const unionFind = new WeightedQuickUnion(numberOfObjects);

  for (let i = 0; i < numberOfRows; i++) {
    for (let j = 0; j < numberOfCols; j++) {
      const item = grid[i][j];

      if (item === "1") {
        const curLandFlattenedIndex = numberOfCols * i + j;

        // there could be a adjacent land at the top
        if (i > 0 && grid[i - 1][j] === "1") {
          const topFlattenedIndex = numberOfCols * (i - 1) + j;
          unionFind.union(curLandFlattenedIndex, topFlattenedIndex);
        }

        // there could be a adjacent land at the left
        if (j > 0 && grid[i][j - 1] === "1") {
          const leftFlattenedIndex = numberOfCols * i + (j - 1);
          unionFind.union(curLandFlattenedIndex, leftFlattenedIndex);
        }

        // there could be a adjacent land at the right
        if (j + 1 < numberOfCols && grid[i][j + 1] === "1") {
          const rightFlattenedIndex = numberOfCols * i + (j + 1);
          unionFind.union(curLandFlattenedIndex, rightFlattenedIndex);
        }

        // there could be a adjacent land below
        if (i + 1 < numberOfRows && grid[i + 1][j] === "1") {
          const bottomFlattenedIndex = numberOfCols * (i + 1) + j;
          unionFind.union(curLandFlattenedIndex, bottomFlattenedIndex);
        }
      } else if (item === "0") {
        unionFind.decrementCountOfComponents();
      } else {
        break;
      }
    }
  }

  return unionFind.countOfComponents;
}

console.log(
  numIslands([
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "0"],
  ])
);
