// Title: Fun with graphs
// Date: 2025-07-09
// Created: Wed, 09 Jul 2025 19:33:50 +0530
// Tags: [graphs, daily-practice]

#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 1971. Find if Path Exists in Graph
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
/// Timestamp: `Wed, 09 Jul 2025 19:35:18 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
};

void QuickUnion_init(struct QuickUnion *qu, int capacity);
void QuickUnion_clear(struct QuickUnion *qu);
int QuickUnion_findRoot(struct QuickUnion *qu, int node);
void QuickUnion_connect(struct QuickUnion *qu, int nodeA, int nodeB);
bool QuickUnion_connected(struct QuickUnion *qu, int nodeA, int nodeB);

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
  if (!(0 <= node && node < qu->capacity)) {
    return -1;
  }

  while (node != qu->entries[node]) {
    qu->entries[node] = qu->entries[qu->entries[node]];
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

bool QuickUnion_connected(struct QuickUnion *qu, int nodeA, int nodeB) {
  int rootA = QuickUnion_findRoot(qu, nodeA);
  int rootB = QuickUnion_findRoot(qu, nodeB);

  if (!(rootA > -1 && rootB > -1)) {
    return false;
  }

  return (rootA == rootB);
}


bool validPath(
    int n,
    int **edges,
    int edgesSize,
    int *edgesColSize,
    int source,
    int destination)
{
  struct QuickUnion _qu, *qu = &_qu;
  QuickUnion_init(qu, n);

  for (int i = 0; i < edgesSize; i++) {
    QuickUnion_connect(qu, edges[i][0], edges[i][1]);
  }

  bool pathExists = QuickUnion_connected(qu, source, destination);
  QuickUnion_clear(qu);

  return pathExists;
}

/// }}
