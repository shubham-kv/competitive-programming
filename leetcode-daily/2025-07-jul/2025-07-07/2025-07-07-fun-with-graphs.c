// Title: Fun with graphs
// Date: 2025-07-07
// Created: Mon, 07 Jul 2025 11:24:25 +0530
// Tags: [graphs, daily-practice]

#include <memory.h>
#include <stdlib.h>

/// {{
/// Problem: 695. Max Area of Island
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/max-area-of-island/
/// Topics: `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`
/// Timestamp: `Mon, 07 Jul 2025 11:24:25 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
};

void QuickUnion_init(struct QuickUnion *qu, int capacity);
void QuickUnion_clear(struct QuickUnion *qu);
int QuickUnion_findRoot(struct QuickUnion *qu, int node);
void QuickUnion_connect(struct QuickUnion *qu, int nodeA, int nodeB);
int QuickUnion_largestComponentSize(struct QuickUnion *qu);
void QuickUnion_unsetSize(struct QuickUnion *qu, int node);

void QuickUnion_init(struct QuickUnion *qu, int capacity) {
  qu->entries = calloc(capacity, sizeof(int));
  qu->sizes = calloc(capacity, sizeof(int));
  qu->capacity = capacity;

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
  if (!(0 <= node && node <= qu->capacity - 1)) {
    return -1;
  }

  while (node != qu->entries[node]) {
    node = qu->entries[node];
  }

  return node;
}

void QuickUnion_connect(struct QuickUnion *qu, int nodeA, int nodeB) {
  int rootA = QuickUnion_findRoot(qu, nodeA);
  int rootB = QuickUnion_findRoot(qu, nodeB);

  if (!(rootA > -1 && rootB > -1)) {
    return;
  }

  if (rootA == rootB) {
    return;
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
}

int QuickUnion_largestComponentSize(struct QuickUnion *qu) {
  int max = 0;

  for (int i = 0; i < qu->capacity; i++) {
    int componentSize = qu->sizes[i];

    if (componentSize > max) {
      max = componentSize;
    }
  }

  return max;
}

void QuickUnion_unsetSize(struct QuickUnion *qu, int node) {
  if (!(0 <= node && node <= qu->capacity - 1)) {
    return;
  }

  qu->sizes[node] = 0;
}


int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize) {
  struct QuickUnion qu;
  int rows = gridSize, cols = *gridColSize;
  QuickUnion_init(&qu, rows * cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int curLand = i * cols + j;

      if (grid[i][j] != 1) {
        QuickUnion_unsetSize(&qu, curLand);
        continue;
      }

      if (i - 1 >= 0 && grid[i - 1][j] == 1) {
        int topLand = (i - 1) * cols + j;
        QuickUnion_connect(&qu, curLand, topLand);
      }

      if (j + 1 < cols && grid[i][j + 1] == 1) {
        int rightLand = i * cols + (j + 1);
        QuickUnion_connect(&qu, curLand, rightLand);
      }

      if (i + 1 < rows && grid[i + 1][j] == 1) {
        int bottomLand = (i + 1) * cols + j;
        QuickUnion_connect(&qu, curLand, bottomLand);
      }

      if (j - 1 >= 0 && grid[i][j - 1] == 1) {
        int leftLand = i * cols + (j - 1);
        QuickUnion_connect(&qu, curLand, leftLand);
      }
    }
  }

  int max = QuickUnion_largestComponentSize(&qu);
  QuickUnion_clear(&qu);

  return max;
}

/// }}

