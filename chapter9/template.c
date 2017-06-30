#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************
 * Functions to be implemented are defined below.           *
 ************************************************************/

typedef struct node{
  int key;
  struct node *parent;
  struct node *left;
  struct node *right;
} node;

node nilNode = {0, NULL, NULL, NULL};
#define NIL (&nilNode)

node* createNode(node *parent, const int key);
void freeNode(node *n);
void freeTree(node *t);

// functions to be implemented
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

/*************************************************************
 * Functions to be implemented                               *
 *    insert and delete take pointer of pointer to root.     *
 *    Because these function may change root                 *
 *************************************************************/

/*
 * Insert a node to tree.
 * tree: pointer of pointer to root node
 * key: key to be inserted
 * parent: parent of *tree (for new node's parent)
 */
void insert(node **tree, const int key, node *parent) {
  // your code here
}

/*
 * Print a tree.
 * tree: pointer to root node
 */
void print(const node *tree) {
  // your code here
}

/*
 * Find if the tree has specified key.
 * tree: pointer to root node
 * key: key to be found
 */
int find(const node *tree, const int key) {
  // your code here
}

/*
 * Delete a node which has specified key.
 * tree: pointer of pointer to root node
 * key: key to be inserted
 */
void delete(node **tree, const int key) {
  // your code here
}