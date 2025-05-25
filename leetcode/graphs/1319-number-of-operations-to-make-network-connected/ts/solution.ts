class WeightedQuickUnion {
  private entries: number[];
  private sizes: number[];

  constructor(size: number) {
    this.entries = [];

    for (let i = 0; i < size; i++) {
      // Initially the nodes are connected only to themselves
      this.entries.push(i);
    }

    this.sizes = Array(size).fill(1);
  }

  findRoot(nodeIndex: number): number {
    if (nodeIndex < 0 || nodeIndex >= this.entries.length) {
      return -1;
    }

    let parentIndex: number = nodeIndex;

    while (this.entries[parentIndex] != parentIndex) {
      parentIndex = this.entries[parentIndex];
    }

    return parentIndex;
  }

  connectNodes(nodeAIndex: number, nodeBIndex: number): boolean {
    const rootAIndex = this.findRoot(nodeAIndex);
    const rootBIndex = this.findRoot(nodeBIndex);

    // Possibly throw an error here
    if (rootAIndex === -1 || rootBIndex === -1) {
      return false;
    }

    if (rootAIndex === rootBIndex) {
      return false;
    }

    const rootAChildCount = this.sizes[rootAIndex];
    const rootBChildCount = this.sizes[rootBIndex];

    if (rootAChildCount < rootBChildCount) {
      this.entries[rootAIndex] = rootBIndex;
      this.sizes[rootBIndex] += this.sizes[rootAIndex];
    } else {
      this.entries[rootBIndex] = rootAIndex;
      this.sizes[rootAIndex] += this.sizes[rootBIndex];
    }

    return true;
  }
}

function makeConnected(n: number, connections: number[][]): number {
  const connectionsLength = connections.length;
  // Ex.1. n = 4, connectionsLength = 3

  if (connectionsLength < n - 1) {
    // It's not possible to connect all nodes without n - 1 edges
    return -1;
  }

  const unionFind = new WeightedQuickUnion(n);
  let count = 0;

  for (let i = 0; i < connectionsLength; i++) {
    const connection = connections[i];
    const didConnect = unionFind.connectNodes(connection[0], connection[1]);

    if (!didConnect) {
      ++count;
    }
  }

  return count;
}
