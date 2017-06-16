#include <stdio.h>
#define MAX_N 25
#define NIL -1
typedef struct Node { int parent, left, right;} Node;

void preorder(Node tree[MAX_N], int node){
	if(node==NIL){
		return;
	}
	printf(" %d",node);
	preorder(tree,tree[node].left);
	preorder(tree,tree[node].right);
}

void inorder(Node tree[MAX_N], int node){
	if(node==NIL){
		return;
	}
	inorder(tree,tree[node].left);
	printf(" %d",node);
	inorder(tree,tree[node].right);
}
void postorder(Node tree[MAX_N], int node){
	if(node==NIL){
		return;
	}
	postorder(tree,tree[node].left);
	postorder(tree,tree[node].right);
	printf(" %d",node);
}
int main(){
	int n,root_node;
	int node,left,right;
	int i;
	int depth_list[MAX_N],height_list[MAX_N];
	Node tree[MAX_N];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		tree[i].parent=NIL;
	}
	for(i=0;i<n;i++){
		scanf("%d %d %d",&node,&left,&right);
		tree[node].left=left;
		tree[node].right=right;
		if(left!=NIL){
			tree[left].parent=node;
		}
		if(right!=NIL){
			tree[right].parent=node;
		}
	}
	
	for(i=0;i<n;i++){
		if(tree[i].parent==NIL){
			root_node=i;
		}
	}
	printf("Preorder\n");
	preorder(tree,root_node);
	printf("\n");
	printf("Inorder\n");
	inorder(tree,root_node);
	printf("\n");
	printf("Postorder\n");
	postorder(tree,root_node);
	printf("\n");
	return 0;	
}
