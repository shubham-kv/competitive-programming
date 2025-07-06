#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

/// {{
/// Problem: 547. Number of Provinces
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/number-of-provinces/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Sun, 06 Jul 2025 17:21:06 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capcity;
  int nOfComponents;
};

void QuickUnion_init(struct QuickUnion *qu, int capacity);
void QuickUnion_clear(struct QuickUnion *qu);
int QuickUnion_findRoot(struct QuickUnion *qu, int node);
bool QuickUnion_connect(struct QuickUnion *qu, int nodeA, int nodeB);

#define QUICK_UNION_NOF_COMPONENTS(qu) (((struct QuickUnion *)qu)->nOfComponents)

void QuickUnion_init(struct QuickUnion *qu, int capacity) {
  qu->entries = calloc(capacity, sizeof(int));
  qu->sizes = calloc(capacity, sizeof(int));
  qu->capcity = capacity;
  qu->nOfComponents = capacity;

  for (int i = 0; i < capacity; i++) {
    qu->entries[i] = i;
    qu->sizes[i] = 1;
  }
}

void QuickUnion_clear(struct QuickUnion *qu) {
  free(qu->entries);
  free(qu->sizes);
  memset(qu, 0, sizeof(struct QuickUnion));
}

int QuickUnion_findRoot(struct QuickUnion *qu, int node) {
  if (!(0 <= node && node <= qu->capcity - 1)) {
    return -1;
  }

  while (node != qu->entries[node]) {
    qu->entries[node] = qu->entries[qu->entries[node]]; // path compression
    node = qu->entries[node];
  }

  return node;
}

bool QuickUnion_connect(struct QuickUnion *qu, int nodeA, int nodeB) {
  int rootA = QuickUnion_findRoot(qu, nodeA);
  int rootB = QuickUnion_findRoot(qu, nodeB);

  if (!(rootA > -1 && rootB > -1)) {
    return false;
  }

  if (rootA == rootB) {
    return false;
  }

  int treeASize = qu->sizes[rootA];
  int treeBSize = qu->sizes[rootB];

  if (treeASize < treeBSize) {
    qu->entries[rootA] = rootB;
    qu->sizes[rootB] += treeASize;
  } else {
    qu->entries[rootB] = rootA;
    qu->sizes[rootA] += treeBSize;
  }
  qu->nOfComponents -= 1;
  return true;
}

int findCircleNum(
    int** isConnected,
    int isConnectedSize,
    int* isConnectedColSize) {

  struct QuickUnion qu;
  QuickUnion_init(&qu, isConnectedSize);

  for (int i = 0; i < isConnectedSize; i++) {
    for (int j = 0; j < *isConnectedColSize; j++) {
      int entry = isConnected[i][j];

      if (entry == 1) {
        QuickUnion_connect(&qu, i, j);
      }
    }
  }

  int nOfProvinces = QUICK_UNION_NOF_COMPONENTS(&qu);
  QuickUnion_clear(&qu);

  return nOfProvinces;
}

/// }}

