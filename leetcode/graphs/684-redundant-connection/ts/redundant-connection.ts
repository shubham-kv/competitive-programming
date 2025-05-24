class WeightedQuickUnion {
  private entries: number[];
  private sizes: number[];

  constructor(size: number) {
    this.entries = [];
    
    for (let i = 0; i < size; i++) {
      this.entries.push(i);
    }

    this.sizes = Array(size).fill(1);
  }

  find(a: number): number {
    if (a > this.entries.length) {
      return -1;
    }

    while (this.entries[a] != a) {
      a = this.entries[a];
    }
    return a;
  }

  connect(a: number, b: number): boolean {
    const i = this.find(a);
    const j = this.find(b);

    if (i === -1 || j === -1) {
      return false;
    }

    if (i === j) {
      return false;
    }

    if (this.sizes[i] < this.sizes[j]) {
      this.entries[i] = j;
      this.sizes[j] += this.sizes[i];
    } else {
      this.entries[j] = i;
      this.sizes[i] += this.sizes[j];
    }

    return true;
  }
}

function findRedundantConnection(edges: number[][]): number[] {
  const flattened = edges.flat();
  const max = Math.max(...flattened);

  const qu = new WeightedQuickUnion(max);
  let redundantConnections: number[] = [];

  for (const edge of edges) {
    const didConnect = qu.connect(edge[0], edge[1]);

    if (!didConnect) {
      redundantConnections = [edge[0], edge[1]];
    }
  }

  return redundantConnections;
}
