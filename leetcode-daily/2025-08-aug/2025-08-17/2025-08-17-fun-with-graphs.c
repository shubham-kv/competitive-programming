// Title: Fun with Graphs
// Date: 2025-08-17
// Created: `Sun, 17 Aug 2025 18:44:27 +0530`
// Tags: [graphs, daily-practice]

#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 1971. Find if Path Exists in Graph
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
/// Timestamp: `Sun, 17 Aug 2025 18:44:27 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
};
typedef struct QuickUnion *QU;

void QuickUnion_Init(QU qu, const int capacity);
void QuickUnion_Clear(QU qu);
 int QuickUnion_Find(QU qu, int p);
void QuickUnion_Union(QU qu, const int p, const int q);
bool QuickUnion_Connected(QU qu, const int p, const int q);

void QuickUnion_Init(QU qu, const int capacity) {
  qu->capacity = capacity;
  qu->entries = calloc(qu->capacity, sizeof(int));
  qu->sizes = calloc(qu->capacity, sizeof(int));

  for (int i = 0; i < qu->capacity; i++) {
    qu->entries[i] = i;
    qu->sizes[i] = 1;
  }
}

void QuickUnion_Clear(QU qu) {
  free(qu->entries), (qu->entries = NULL);
  free(qu->sizes), (qu->sizes = NULL);
  qu->capacity = 0;
}

int QuickUnion_Find(QU qu, int p) {
  while (qu->entries[p] != p) {
    qu->entries[p] = qu->entries[qu->entries[p]];
    p = qu->entries[p];
  }
  return p;
}

void QuickUnion_Union(QU qu, const int p, const int q) {
  const int rootP = QuickUnion_Find(qu, p);
  const int rootQ = QuickUnion_Find(qu, q);

  if (rootP == rootQ) {
    return;
  }

  const int sizeP = qu->sizes[rootP];
  const int sizeQ = qu->sizes[rootQ];

  if (sizeP < sizeQ) {
    qu->entries[rootP] = rootQ;
    qu->sizes[rootQ] += sizeP;
  } else {
    qu->entries[rootQ] = rootP;
    qu->sizes[rootP] += sizeQ;
  }
}

inline bool QuickUnion_Connected(QU qu, const int p, const int q) {
  return QuickUnion_Find(qu, p) == QuickUnion_Find(qu, q);
}


bool validPath(
    int n,
    int **edges,
    int edgesSize,
    int *edgesColSize,
    int source,
    int destination
) {
  struct QuickUnion _qu, *qu = &_qu;
  QuickUnion_Init(qu, n);

  for (int i = 0; i < edgesSize; i++) {
    const int *edge = edges[i];
    QuickUnion_Union(qu, edge[0], edge[1]);
  }

  const bool connected = QuickUnion_Connected(qu, source, destination);
  QuickUnion_Clear(qu), (qu = NULL);

  return connected;
}

/// }}

