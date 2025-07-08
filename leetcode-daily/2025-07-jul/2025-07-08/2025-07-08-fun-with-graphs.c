// Title: Fun with graphs
// Date: 2025-07-07
// Created: Tue, 08 Jul 2025 12:16:06 +0530
// Tags: [graphs, daily-practice]

#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 990. Satisfiability of Equality Equations
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Topics: `array`, `string`, `union-find`, `graph`
/// Timestamp: `Tue, 08 Jul 2025 12:16:06 +0530`

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

  while (qu->entries[node] != node) {
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

  return rootA == rootB;
}


bool equationsPossible(char **equations, int equationsSize) {
  struct QuickUnion qu;
  int capacity = 'z' - 'a' + 1;
  QuickUnion_init(&qu, capacity);

  const char *nonEqualityEquations[equationsSize];
  int nonEqualityEquationsSize = 0;

  for (int i = 0; i < equationsSize; i++) {
    const char *equation = equations[i];
    const char equatilyOp = equation[1];

    if (equatilyOp == '=') {
      const int varA = equation[0] - 'a';
      const int varB = equation[3] - 'a';
      QuickUnion_connect(&qu, varA, varB);
    } else if (equatilyOp == '!') {
      nonEqualityEquations[nonEqualityEquationsSize++] = equation;
    }
  }

  for (int i = 0; i < nonEqualityEquationsSize; i++) {
    const char *equation = nonEqualityEquations[i];
    const char equatilyOp = equation[1];

    if (equatilyOp == '!') {
      const int varA = equation[0] - 'a';
      const int varB = equation[3] - 'a';
      bool areConnected = QuickUnion_connected(&qu, varA, varB);

      if (areConnected) {
        return false;
      }
    }
  }

  return true;
}

/// }}

