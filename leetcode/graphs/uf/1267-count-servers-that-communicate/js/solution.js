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
   * @param {number} objA
   * @param {number} objB
   * @returns {boolean}
   */
  union(objA, objB) {
    const rootA = this.#findRoot(objA);
    const rootB = this.#findRoot(objB);

    if (rootA === rootB) {
      return false;
    }

    const treeASize = this.#sizes[rootA];
    const treeBSize = this.#sizes[rootB];

    if (treeASize < treeBSize) {
      this.#entries[rootA] = rootB;
      this.#sizes[rootB] += treeASize;
    } else {
      this.#entries[rootB] = rootA;
      this.#sizes[rootA] += treeBSize;
    }
    return true;
  }

  /**
   * @returns {number[][]}
   */
  disjointSubsets() {
    /** @type {Record<number, number[]>} */
    const subsets = {};
    const nOfEntries = this.#entries.length;

    for (let i = 0; i < nOfEntries; i++) {
      const root = this.#findRoot(i);

      if (!(root in subsets)) {
        subsets[root] = [i];
      } else {
        subsets[root] = [...subsets[root], i];
      }
    }

    return Object.values(subsets);
  }

  /**
   * @returns {number}
   */
  countOfConnectedComponents() {
    const subsets = this.disjointSubsets();
    const nOfSubsets = subsets.length;

    /** @type {number} */
    let count = 0;

    for (let i = 0; i < nOfSubsets; i++) {
      if (subsets[i].length > 1) {
        count += subsets[i].length;
      }
    }

    return count;
  }
}

/**
 * @param {number[][]} grid
 * @return {number}
 */
function countServers(grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  const unionFind = new WeightedQuickUnion(rows * cols);
  console.log(JSON.stringify(unionFind.disjointSubsets()));

  for (let i = 0; i < rows; i++) {
    /** @type {number[]} */
    const serversToConnect = [];

    for (let j = 0; j < cols; j++) {
      if (grid[i][j] === 1) {
        serversToConnect.push(i * cols + j);
      }
    }

    // Connect the servers
    const nOfServers = serversToConnect.length;

    for (let k = 0; k + 1 < nOfServers; k++) {
      unionFind.union(serversToConnect[k], serversToConnect[k + 1]);
      console.log(`union(${serversToConnect[k]}, ${serversToConnect[k + 1]})`);
      console.log(JSON.stringify(unionFind.disjointSubsets()));
    }
  }

  for (let j = 0; j < cols; j++) {
    /** @type {number[]} */
    const serversToConnect = [];

    for (let i = 0; i < rows; i++) {
      if (grid[i][j] === 1) {
        serversToConnect.push(i * cols + j);
      }
    }

    // Connect the servers
    const nOfServers = serversToConnect.length;

    for (let k = 0; k + 1 < nOfServers; k++) {
      unionFind.union(serversToConnect[k], serversToConnect[k + 1]);
      console.log(`union(${serversToConnect[k]}, ${serversToConnect[k + 1]})`);
      console.log(JSON.stringify(unionFind.disjointSubsets()));
    }
  }

  return unionFind.countOfConnectedComponents();
}

console.log(
  countServers([
    [1, 0],
    [0, 1],
  ]) + '\n'
);
console.log(
  countServers([
    [1, 0],
    [1, 1],
  ]) + '\n'
);

console.log(
  countServers([
    [1, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1],
  ]) + '\n'
);

console.log(
  countServers([
    [0, 0, 0, 0],
    [1, 1, 1, 1],
    [0, 0, 0, 1],
    [0, 0, 1, 1],
    [0, 0, 0, 1],
  ]) + '\n'
);
