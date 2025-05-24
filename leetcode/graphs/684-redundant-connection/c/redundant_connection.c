#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct WeightedQuickUnion
{
  uint32_t capacity;
  int *entries;
  int *sizes;
};

void quInit(struct WeightedQuickUnion *qu, uint32_t size);
void quClear(struct WeightedQuickUnion *qu);
int quFind(struct WeightedQuickUnion *qu, int p);
bool quConnect(struct WeightedQuickUnion *qu, int p, int q);

void quInit(struct WeightedQuickUnion *qu, uint32_t capacity)
{
  qu->entries = calloc(capacity, sizeof(int));
  qu->sizes = calloc(capacity, sizeof(int));
  qu->capacity = capacity;

  for (int i = 0; i < capacity; i++)
    qu->entries[i] = i;

  for (int i = 0; i < capacity; i++)
    qu->sizes[i] = 1;
}

void quClear(struct WeightedQuickUnion *qu)
{
  free(qu->entries);
  free(qu->sizes);
}

int quFind(struct WeightedQuickUnion *qu, int p)
{
  if (p >= qu->capacity)
    return -1;

  while (qu->entries[p] != p)
    p = qu->entries[p];

  return p;
}

bool quConnect(struct WeightedQuickUnion *qu, int p, int q)
{
  int rootA = quFind(qu, p);
  int rootB = quFind(qu, q);

  if (rootA == -1 || rootB == -1)
    return false;

  if (rootA == rootB)
    return false;

  int treeASize = qu->sizes[rootA];
  int treeBSize = qu->sizes[rootB];

  if (treeASize < treeBSize)
  {
    qu->entries[rootA] = rootB;
    qu->sizes[rootB] += treeASize;
  }
  else
  {
    qu->entries[rootB] = rootA;
    qu->sizes[rootA] += treeBSize;
  }

  return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
  int max = 0;

  for (int i = 0; i < edgesSize; i++) {
    for(int j = 0; j < *edgesColSize; j++) {
      if (edges[i][j] > max)
        max = edges[i][j];
    }
  }

  struct WeightedQuickUnion qu;
  quInit(&qu, max + 1);

  int *redundant = calloc(*edgesColSize, sizeof(int));

  for (int i = 0; i < edgesSize; i++) {
    int p = edges[i][0];
    int q = edges[i][1];
    bool didConnect = quConnect(&qu, p, q);

    if (!didConnect) {
      redundant[0] = p;
      redundant[1] = q;
      *returnSize = 2;
    }
  }

  quClear(&qu);

  return redundant;
}
