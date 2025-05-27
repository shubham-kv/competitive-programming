class WeightedQuickUnion {
  private entries: Record<string, string> = {};
  private sizes: Record<string, number> = {};

  add(object: string) {
    const entryKeys = Object.keys(this.entries);
    const sizeKeys = Object.keys(this.sizes);

    if (!entryKeys.includes(object) && !sizeKeys.includes(object)) {
      this.entries[object] = object;
      this.sizes[object] = 1;
    }
  }

  find(object: string): string | null {
    if (!object) {
      return null;
    }

    while (object && object != this.entries[object]) {
      object = this.entries[object];
    }

    return object;
  }

  union(objectA: string, objectB: string): boolean | null {
    const rootA = this.find(objectA);
    const rootB = this.find(objectB);

    if (rootA === null || rootB === null) {
      return null;
    }

    if (rootA === rootB) {
      return false;
    }

    const rootASize = this.sizes[rootA];
    const rootBSize = this.sizes[rootB];

    if (rootASize < rootBSize) {
      this.entries[rootA] = rootB;
      this.sizes[rootB] += rootASize;
    } else if (rootBSize <= rootASize) {
      this.entries[rootB] = rootA;
      this.sizes[rootA] += rootBSize;
    } else {
      return null;
    }

    return true;
  }

  connected(objectA: string, objectB: string): boolean | null {
    const rootA = this.find(objectA);
    const rootB = this.find(objectB);

    if (rootA === null || rootB === null) {
      return null;
    }

    return rootA === rootB;
  }
}

function equationsPossible(equations: string[]): boolean {
  const equationsLength = equations.length;
  const unionFind = new WeightedQuickUnion();

  // Arrange all '==' equations before '!='
  equations.sort((a, b) => {
    if (a.substring(1, 3) === "==") {
      return -1;
    } else if (b.substring(1, 3) === "==") {
      return 1;
    } else {
      return 0;
    }
  });

  for (let i = 0; i < equationsLength; i++) {
    const equation = equations[i];

    if (equation.length !== 4) {
      // Invalid length
      return false;
    }

    const var1 = equation[0];
    const operator = equation.substring(1, 3);
    const var2 = equation[3];

    unionFind.add(var1);
    unionFind.add(var2);

    switch (operator) {
      case "==": {
        unionFind.union(var1, var2);
        break;
      }
      case "!=": {
        if (unionFind.connected(var1, var2)) {
          return false;
        }
        break;
      }
      default: {
        // Invalid Op
        return false;
      }
    }
  }

  return true;
}
