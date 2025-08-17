#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Sat, 16 Aug 2025 20:52:04 +0530`

struct QuickUnion {
  int *entries;
  int *sizes;
  int capacity;
};
typedef struct QuickUnion *QU;

void QuickUnion_Init(QU qu, int capacity);
void QuickUnion_Clear(QU qu);
 int QuickUnion_Find(QU qu, int p);
void QuickUnion_Union(QU qu, int p, int q);
bool QuickUnion_Connected(QU qu, int p, int q);

void QuickUnion_Init(QU qu, int capacity) {
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

void QuickUnion_Union(QU qu, int p, int q) {
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

inline bool QuickUnion_Connected(QU qu, int p, int q) {
  return QuickUnion_Find(qu, p) == QuickUnion_Find(qu, q);
}


bool equationsPossible(char **equations, int equationsSize) {
  const int capacity = 'z' - 'a' + 1;

  struct QuickUnion _qu, *qu = &_qu;
  QuickUnion_Init(qu, capacity);

  const char *nonEquals[equationsSize];
  int nonEqualsSize = 0;

  for (int i = 0; i < equationsSize; i++) {
    const char *equation = equations[i];

    if (equation[1] == '=') {
      const int p = equation[0] - 'a';
      const int q = equation[3] - 'a';
      QuickUnion_Union(qu, p, q);
    } else if (equation[1] == '!') {
      nonEquals[nonEqualsSize++] = equation;
    }
  }

  for (int i = 0; i < nonEqualsSize; i++) {
    const char *equation = nonEquals[i];

    if (equation[1] == '!') {
      const int p = equation[0] - 'a';
      const int q = equation[3] - 'a';

      if (QuickUnion_Connected(qu, p, q)) {
        QuickUnion_Clear(qu), (qu = NULL);
        return false;
      }
    }
  }

  QuickUnion_Clear(qu), (qu = NULL);
  return true;
}

/// }}

