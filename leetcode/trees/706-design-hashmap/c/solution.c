#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/// {{
/// Problem: 706. Design HashMap
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/design-hashmap/
/// Topics: `array`, `hash-table`, `linked-list`, `design`, `hash-function`
/// Timestamp: `Wed, 16 Jul 2025 11:48:37 +0530`

struct Node {
  struct Node *left;
  struct Node *right;
  int key;
  int val;
};

typedef struct {
  struct Node *root;
} MyHashMap;

const size_t HASH_MAP_WIDTH = sizeof(MyHashMap);
const size_t NODE_WIDTH = sizeof(struct Node);

MyHashMap *myHashMapCreate();
void myHashMapFree(MyHashMap *hashMap);
void myHashMapPut(MyHashMap *hashMap, int key, int value);
int myHashMapGet(MyHashMap *hashMap, int key);
void myHashMapRemove(MyHashMap *hashMap, int key);

static struct Node *putRecursive(struct Node *node, int key, int val);
static int getRecursive(struct Node *node, int key);
static struct Node *deleteRecursive(struct Node *node, int key);

static struct Node *minRecursive(struct Node *node);
static struct Node *deleteMinRecursive(struct Node *node, bool shouldFree);


MyHashMap *myHashMapCreate() {
  return calloc(1, HASH_MAP_WIDTH);
}

void myHashMapFree(MyHashMap *hashMap) {
  while (hashMap->root != NULL) {
    myHashMapRemove(hashMap, hashMap->root->key);
  }
  memset(hashMap, 0, HASH_MAP_WIDTH);
  free(hashMap);
}


static struct Node *putRecursive(struct Node *node, int key, int val) {
  if (node == NULL) {
    node = calloc(1, NODE_WIDTH);
    node->key = key;
    node->val = val;
    return node;
  }

  if (key < node->key) {
    node->left = putRecursive(node->left, key, val);
  } else if (key > node->key) {
    node->right = putRecursive(node->right, key, val);
  } else {
    node->val = val;
  }

  return node;
}

void myHashMapPut(MyHashMap *hashMap, int key, int value) {
  hashMap->root = putRecursive(hashMap->root, key, value);
}


static int getRecursive(struct Node *node, int key) {
  if (node == NULL) {
    return -1;
  }

  if (key < node->key) {
    return getRecursive(node->left, key);
  } else if (key > node->key) {
    return getRecursive(node->right, key);
  } else {
    return node->val;
  }
}

int myHashMapGet(MyHashMap *hashMap, int key) {
  return getRecursive(hashMap->root, key);
}


static struct Node *deleteRecursive(struct Node *node, int key) {
  if (node == NULL) {
    return NULL;
  }

  if (key < node->key) {
    node->left = deleteRecursive(node->left, key);
  } else if (key > node->key) {
    node->right = deleteRecursive(node->right, key);
  } else {
    if (node->left == NULL) {
      struct Node *right = node->right;
      free(node);
      return right;
    }

    if (node->right == NULL) {
      struct Node *left = node->left;
      free(node);
      return left;
    }

    struct Node *successor = minRecursive(node->right);
    node->right = deleteMinRecursive(node->right, false);

    successor->left = node->left;
    successor->right = node->right;
    free(node);
    node = successor;
  }

  return node;
}

void myHashMapRemove(MyHashMap *hashMap, int key) {
  hashMap->root = deleteRecursive(hashMap->root, key);
}


static struct Node *minRecursive(struct Node *node) {
  if (node == NULL) { return NULL; }
  return (node->left) ? minRecursive(node->left) : node;
}

static struct Node *deleteMinRecursive(struct Node *node, bool shouldFree) {
  if (node == NULL) { return NULL; }

  if (node->left == NULL) {
    if (shouldFree) {
      free(node->left);
    }
    return node->right;
  }
  node->left = deleteMinRecursive(node->left, shouldFree);
  return node;
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 *
 * MyHashMap* hashMap = myHashMapCreate();
 * myHashMapPut(hashMap, key, value);
 * int param_2 = myHashMapGet(hashMap, key);
 * myHashMapRemove(hashMap, key);
 * myHashMapFree(hashMap);
*/

/// }}
