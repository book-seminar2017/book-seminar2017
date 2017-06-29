#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  int key;
  struct node *parent;
  struct node *left;
  struct node *right;
} node;

node nilNode = {0, NULL, NULL, NULL};
#define NIL (&nilNode)

node* createNode(node *parent, const int key);
int isRoot(node *n);
void freeNode(node *n);
void freeTree(node *t);

void insert(node **tree, const int key, node *parent);
void print(const node *tree);
int find(const node *tree, const int key);
void delete(node **tree, const int key);

int main(void) {
  int m, i, t;
  char command[7];
  node *tree = NIL;

  scanf("%d", &m);
  for(i=0; i<m; i++) {
    scanf("%s", command);
    if(!strcmp(command, "insert")) {
      scanf("%d", &t);
      insert(&tree, t, NIL);
    } else if(!strcmp(command, "print")) {
      print(tree);
    } else if(!strcmp(command, "find")) {
      scanf("%d", &t);
      printf(find(tree, t) ? "yes\n" : "no\n");
    } else if(!strcmp(command, "delete")) {
      scanf("%d", &t);
      delete(&tree, t);
    } else {
      printf("Invalid command: %s\n", command);
    }
  }
  freeTree(tree);

  return 0;
}

// malloc and return address of new node which is initialized with key, parent and nil children
node* createNode(node *parent, const int key) {
  node t = {key, parent, NIL, NIL};
  node *p = (node*)malloc(sizeof(node));
  if(p == NULL) {
    fprintf(stderr, "Memory allocation failure\n");
    exit(1);
  }
  *p = t;
  return p;
}

// free a node
void freeNode(node *n) {
  free(n);
}

// free whole tree
void freeTree(node *t) {
  if(t == NIL) return;
  freeTree(t->left);
  freeTree(t->right);
  freeNode(t);
}

void insert(node **tree, const int key, node *parent) {
  if(*tree == NIL) {
    *tree = createNode(parent, key);
  } else {
    node **next = (*tree)->key > key ? &(*tree)->left : &(*tree)->right;
    insert(next, key, *tree);
  }
}

void printPreOrder(const node *t) {
  if(t == NIL) return;
  printf(" %d", t->key);
  printPreOrder(t->left);
  printPreOrder(t->right);
}

void printInOrder(const node *t) {
  if(t == NIL) return;
  printInOrder(t->left);
  printf(" %d", t->key);
  printInOrder(t->right);
}

void print(const node *tree) {
  printInOrder(tree);
  printf("\n");
  printPreOrder(tree);
  printf("\n");
}

node* findNode(const node *tree, const int key) {
  if(tree == NIL) {
    return NIL;
  } else if(tree->key == key) {
    return (node*)tree;
  } else if(tree->key > key) {
    return findNode(tree->left, key);
  } else {
    return findNode(tree->right, key);
  }
}

int find(const node *tree, const int key) {
  return findNode(tree, key) != NIL;
}

void updateParent(node *oldChild, node *newChild) {
  if(oldChild->parent->left == oldChild) {
    oldChild->parent->left = newChild;
  } else {
    oldChild->parent->right = newChild;
  }
}

node* minNode(node *tree) {
  while(tree->left != NIL) tree = tree->left;
  return tree;
}

void delete(node **tree, const int key) {
  node *hit = findNode(*tree, key);
  if(hit == NIL) return;
  if(hit->left == NIL || hit->right == NIL) {
    node *next = hit->left == NIL ? hit->right : hit->left;
    if(hit->parent == NIL) {
      *tree = next;
    } else {
      updateParent(hit, next);
    }
    next->parent = hit->parent;
    freeNode(hit);
  } else {
    node *minSub = minNode(hit->right);
    updateParent(minSub, NIL);
    hit->key = minSub->key;
    freeNode(minSub);
  }
}