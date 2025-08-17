#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 684. Redundant Connection
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/redundant-connection/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`
/// Timestamp: `Thu, 14 Aug 2025 19:23:31 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
};
typedef struct QuickUnion *QU;

void QuickUnion_Init(QU qu, int n);
void QuickUnion_Clear(QU qu);
 int QuickUnion_Find(QU qu, int p);
 int QuickUnion_Connect(QU qu, int p, int q, bool *outDidConnect);

void QuickUnion_Init(QU qu, int n) {
  qu->capacity = n;
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
  memset(qu, 0, sizeof(struct QuickUnion));
}

int QuickUnion_Find(QU qu, int p) {
  if (!(0 <= p && p < qu->capacity)) {
    return -1;
  }

  while (qu->entries[p] != p) {
    qu->entries[p] = qu->entries[qu->entries[p]];
    p = qu->entries[p];
  }
  return p;
}

int QuickUnion_Connect(QU qu, int p, int q, bool *outDidConnect) {
  int rootP = QuickUnion_Find(qu, p);
  int rootQ = QuickUnion_Find(qu, q);

  if (rootP == -1 || rootQ == -1) {
    return -1;
  }

  if (rootP == rootQ) {
    *outDidConnect = false;
    return 0;
  }

  int sizeP = qu->sizes[rootP];
  int sizeQ = qu->sizes[rootQ];

  if (sizeP < sizeQ) {
    qu->entries[rootP] = rootQ;
    qu->sizes[rootQ] += sizeP;
  } else {
    qu->entries[rootQ] = rootP;
    qu->sizes[rootP] += sizeQ;
  }
  *outDidConnect = true;
  return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize) {
  const int rows = edgesSize;
  const int cols = *edgesColSize;

  struct QuickUnion _qu, *qu = &_qu;
  QuickUnion_Init(qu, rows + 1);

  int *redundantEdge = NULL;
  *returnSize = *edgesColSize;

  for (int i = 0; i < rows; i++) {
    int *edge = edges[i];
    bool didConnect;

    if (QuickUnion_Connect(qu, edge[0], edge[1], &didConnect) == 0) {
      if (!didConnect) {
        redundantEdge = edge;
      }
    }
  }

  QuickUnion_Clear(qu), (qu = NULL);

  return redundantEdge;
}

/// }}

