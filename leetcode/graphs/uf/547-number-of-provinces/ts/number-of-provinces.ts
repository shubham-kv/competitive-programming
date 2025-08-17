class WeightedQuickUnion {
  private entries: number[];
  private sizes: number[];
  private componentsCount: number;

  constructor(size: number) {
    this.entries = [];

    for (let i = 0; i < size; i++) {
      this.entries.push(i);
    }

    this.sizes = Array(size).fill(1);
    this.componentsCount = size;
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

    this.componentsCount--;

    return true;
  }

  get count() {
    return this.componentsCount;
  }
}

function findCircleNum(isConnected: number[][]): number {
  const rows = isConnected.length;
  const cols = isConnected[0].length;
  const quickUnion = new WeightedQuickUnion(cols);

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (i != j && isConnected[i][j] === 1) {
        quickUnion.connect(i, j);
      }
    }
  }

  return quickUnion.count;
}
