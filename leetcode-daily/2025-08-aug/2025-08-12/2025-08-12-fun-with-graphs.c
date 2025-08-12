// Title: Fun with Graphs
// Date: 2025-08-12
// Created: `Tue, 12 Aug 2025 18:27:30 +0530`
// Tags: [graphs, daily-practice]

#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 547. Number of Provinces
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/number-of-provinces/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Tue, 12 Aug 2025 18:27:30 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
  int componentCount;
};
typedef struct QuickUnion *UF;

void QuickUnion_Init(UF uf, int n);
void QuickUnion_Clear(UF uf);
void QuickUnion_Union(UF uf, int p, int q);
 int QuickUnion_Find(UF uf, int p);
bool QuickUnion_Connected(UF uf, int p, int q);
 int QuickUnion_Count(UF uf);

void QuickUnion_Init(UF uf, int n) {
  uf->capacity = n;
  uf->entries = calloc(uf->capacity, sizeof(int));
  uf->sizes = calloc(uf->capacity, sizeof(int));
  uf->componentCount = n;

  for (int i = 0; i < uf->capacity; i++) {
    uf->entries[i] = i;
    uf->sizes[i] = 1;
  }
}

void QuickUnion_Clear(UF uf) {
  free(uf->entries), (uf->entries = NULL);
  free(uf->sizes), (uf->sizes = NULL);
  memset(uf, 0, sizeof(struct QuickUnion));
}

void QuickUnion_Union(UF uf, int p, int q) {
  int rootP = QuickUnion_Find(uf, p);
  int rootQ = QuickUnion_Find(uf, q);

  if (rootP == rootQ) {
    return;
  }

  int sizeP = uf->sizes[rootP];
  int sizeQ = uf->sizes[rootQ];

  if (sizeP < sizeQ) {
    uf->entries[rootP] = rootQ;
    uf->sizes[rootQ] += sizeP;
  } else {
    uf->entries[rootQ] = rootP;
    uf->sizes[rootP] += sizeQ;
  }
  uf->componentCount--;
}

int QuickUnion_Find(UF uf, int p) {
  while (uf->entries[p] != p) {
    uf->entries[p] = uf->entries[uf->entries[p]]; // path compression
    p = uf->entries[p];
  }
  return p;
}

inline bool QuickUnion_Connected(UF uf, int p, int q) {
  return QuickUnion_Find(uf, p) == QuickUnion_Find(uf, q);
}

inline int QuickUnion_Count(UF uf) {
  return uf->componentCount;
}


int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize) {
  const int rows = isConnectedSize;
  const int cols = *isConnectedColSize;

  struct QuickUnion _uf, *uf = &_uf;
  QuickUnion_Init(uf, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (isConnected[i][j] == 1) {
        QuickUnion_Union(uf, i, j);
      }
    }
  }

  int count = QuickUnion_Count(uf);
  QuickUnion_Clear(uf), (uf = NULL);

  return count;
}

/// }}

