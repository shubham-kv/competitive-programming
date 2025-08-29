// Title: Fun with Graphs
// Date: 2025-08-29
// Created: `Fri, 29 Aug 2025 16:57:17 +0530`
// Tags: [graphs, daily-practice]

#include <stdlib.h>
#include <stdbool.h>

/// {{
/// Problem: 785. Is Graph Bipartite?
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/is-graph-bipartite/
/// Topics: `depth-first-search`, `breadth-first-search`, `union-find`, `graph`  
/// Timestamp: `Fri, 29 Aug 2025 16:57:17 +0530`

struct GraphBipartite {
  bool *marked;
  bool *color;
  int vertices;
  bool isBipartite;
};
typedef struct GraphBipartite *Bipartite;

void Bipartite_Init(Bipartite bipartite, const int **graph,
                    const int graphSize, const int graphColSize);
void Bipartite_Clear(Bipartite *bipartite);
bool Bipartite_IsBipartite(Bipartite bipartite);

void _dfs(const int **graph, const int graphSize, const int graphColSize,
          Bipartite bipartite, const int v) {

  bipartite->marked[v] = true;

  const int *adjList = graph[v];
  for (int i = 0; i < graphColSize; i++) {
    const int w = adjList[i];

    if (!bipartite->marked[w]) {
      bipartite->color[w] = !bipartite->color[v];
      _dfs(graph, graphSize, graphColSize, bipartite, w);
    } else {
      if (bipartite->color[w] == bipartite->color[v]) {
        bipartite->isBipartite = false;
      }
    }
  }
}

void Bipartite_Init(Bipartite bipartite, const int **graph,
                    const int graphSize, const int graphColSize) {

  const int vertices = graphSize;
  bipartite->marked = calloc(vertices, sizeof(bool));
  bipartite->color = calloc(vertices, sizeof(bool));
  bipartite->isBipartite = true;

  for (int v = 0; v < vertices; v++) {
    if (!bipartite->marked[v]) {
      _dfs(graph, graphSize, graphColSize, bipartite, v);
    }
  }
}

void Bipartite_Clear(Bipartite *bipartite) {
  free((*bipartite)->marked), ((*bipartite)->marked = NULL);
  free((*bipartite)->color), ((*bipartite)->color = NULL);
}

bool Bipartite_IsBipartite(Bipartite bipartite) {
  return bipartite->isBipartite;
}

bool isBipartite(int **graph, int graphSize, int *graphColSize) {
  struct GraphBipartite _bipartite, *bipartite = &_bipartite;
  Bipartite_Init(bipartite, (const int **) graph, graphSize, *graphColSize);

  const bool isGraphBipartite = Bipartite_IsBipartite(bipartite);
  Bipartite_Clear(&bipartite);

  return isGraphBipartite;
}

/// }}

