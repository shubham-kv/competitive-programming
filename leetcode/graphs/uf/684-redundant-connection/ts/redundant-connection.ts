class WeightedQuickUnion {
  private entries: number[];
  private sizes: number[];

  constructor(nOfVertices: number) {
    this.entries = [];
    for (let i = 0; i < nOfVertices; i++) {
      this.entries.push(i);
    }

    this.sizes = [];
    for (let i = 0; i < nOfVertices; i++) {
      this.sizes.push(1);
    }
  }

  findRootIndex(objIndex: number): number {
    if (objIndex < 0 || objIndex >= this.entries.length) {
      return -1;
    }

    while (objIndex != this.entries[objIndex]) {
      this.entries[objIndex] = this.entries[this.entries[objIndex]]; // path compression
      objIndex = this.entries[objIndex];
    }

    return objIndex;
  }

  union(objAIndex: number, objBIndex: number): boolean | null {
    const rootAIndex = this.findRootIndex(objAIndex);
    const rootBIndex = this.findRootIndex(objBIndex);

    if (rootAIndex === -1 || rootBIndex === -1) {
      return null;
    }

    if (rootAIndex === rootBIndex) {
      return false;
    }

    const treeASize = this.sizes[rootAIndex];
    const treeBSize = this.sizes[rootBIndex];

    if (treeASize < treeBSize) {
      this.entries[rootAIndex] = rootBIndex;
      this.sizes[rootBIndex] += treeASize;
    } else {
      this.entries[rootBIndex] = rootAIndex;
      this.sizes[rootAIndex] += treeBSize;
    }

    return true;
  }
}

function findRedundantConnection(edges: number[][]): number[] {
  // Calculate the number of vertices
  const nOfVertices = Math.max(...edges.flat()) + 1;
  const unionFind = new WeightedQuickUnion(nOfVertices);

  // CHeck for redundancy
  let redundantConnections: number[] = []

  for (const [vertexA, vertexB] of edges) {
    if (!unionFind.union(vertexA, vertexB)) {
      redundantConnections = [vertexA, vertexB];
    }
  }

  return redundantConnections;
}
