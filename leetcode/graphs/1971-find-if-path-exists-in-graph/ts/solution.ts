class WeightedQuickUnion {
  #entries: number[]
  #sizes: number[]

  constructor(numberOfVertices: number) {
    this.#entries = [];
    for (let i = 0; i < numberOfVertices; i++) {
      this.#entries.push(i);
    }

    this.#sizes = [];
    for (let i = 0; i < numberOfVertices; i++) {
      this.#sizes.push(1);
    }
  }

  findRoot(objIndex: number): number {
    if (objIndex < 0 || objIndex >= this.#entries.length) {
      return -1;
    }

    while (objIndex != this.#entries[objIndex]) {
      objIndex = this.#entries[objIndex];
    }

    return objIndex;
  }

  union(objAIndex: number, objBIndex: number): boolean {
    const rootAIndex = this.findRoot(objAIndex);
    const rootBIndex = this.findRoot(objBIndex);

    if (rootAIndex === -1 || rootBIndex === -1) {
      return false;
    }

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

    return true;
  }

  connected(objAIndex: number, objBIndex: number): boolean | null {
    const rootAIndex = this.findRoot(objAIndex);
    const rootBIndex = this.findRoot(objBIndex);

    if (rootAIndex === -1 || rootBIndex === -1) {
      return null;
    }

    return (rootAIndex === rootBIndex);
  }
}

function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
  const edgesLength = edges.length;
  const unionFind = new WeightedQuickUnion(n);

  for (let i = 0; i < edgesLength; i++) {
    const edge = edges[i];
    unionFind.union(edge[0], edge[1]);
  }

  return !!unionFind.connected(source, destination);
};
