// Title: Fun with graphs
// Date: 2025-07-05
// Created: Sat, 05 Jul 2025 13:59:31 +0530
// Tags: [graphs, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 684. Redundant Connection
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/redundant-connection/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Sat, 05 Jul 2025 14:01:02 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
};

void QuickUnion_init(struct QuickUnion *qu, int n);
void QuickUnion_clear(struct QuickUnion *qu);
int QuickUnion_findRoot(struct QuickUnion *qu, int node);
bool QuickUnion_connect(struct QuickUnion *qu, int nodeA, int nodeB);

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
}

int QuickUnion_findRoot(struct QuickUnion *qu, int node) {
  if (!(0 <= node && node <= qu->capacity - 1)) {
    return -1;
  }

  while(qu->entries[node] != node) {
    qu->entries[node] = qu->entries[qu->entries[node]];
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
    qu->sizes[rootB] = treeASize;
  } else {
    qu->entries[rootB] = rootA;
    qu->sizes[rootA] = treeBSize;
  }
  return true;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRedundantConnection(
    int **edges,
    int edgesSize,
    int *edgesColSize,
    int *returnSize) {

  struct QuickUnion qu;
  QuickUnion_init(&qu, edgesSize + 1);

  int *redundant = calloc(2, sizeof(int));
  *returnSize = 2;

  for (int i = 0; i < edgesSize; i++) {
    int *edge = edges[i];
    bool didConnect = QuickUnion_connect(&qu, edge[0], edge[1]);

    if (!didConnect) {
      redundant[0] = edge[0];
      redundant[1] = edge[1];
    }
  }

  QuickUnion_clear(&qu);

  return redundant;
}

/// }}

