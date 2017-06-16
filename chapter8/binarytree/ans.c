#include <stdio.h>
#define MAX_N 25
#define NIL -1
typedef struct Node { int parent, left, right;} Node;

void setDepth(Node tree[MAX_N],int depth_list[MAX_N],int node,int depth){
	if(node==NIL){
		return; 
	}
	depth_list[node]=depth;
	setDepth(tree,depth_list,tree[node].left,depth+1);
	setDepth(tree,depth_list,tree[node].right,depth+1);
}

int setHeight(Node tree[MAX_N],int height_list[MAX_N],int node){
	int h_left,h_right;
	if(node==NIL){
		return -1;
	}
	h_left=setHeight(tree,height_list,tree[node].left)+1;
	h_right=setHeight(tree,height_list,tree[node].right)+1;
	if(h_left>h_right){
		height_list[node]=h_left;
	}else{
		height_list[node]=h_right;
	}
	return height_list[node];
}

int getSibling(Node tree[MAX_N],int node){
	if(tree[node].parent==NIL){
		return NIL;
	}
	Node parentNode = tree[tree[node].parent];
	if(parentNode.left != node && parentNode.left != NIL){
		return parentNode.left;
	}
	if(parentNode.right != node && parentNode.right != NIL){
		return parentNode.right;
	}
	return NIL;
}

int getDegree(Node tree[MAX_N],int node){
	int deg=0;
	if(tree[node].left!=NIL){
		deg++;
	}
	if(tree[node].right!=NIL){
		deg++;
	}
	return deg;
}
void print(Node tree[MAX_N],int depth_list[MAX_N], int height_list[MAX_N],int node){
	printf("node %d: ",node);
	printf("parent = %d, ",tree[node].parent);
	printf("sibling = %d, ",getSibling(tree,node));
	printf("degree = %d, ",getDegree(tree,node));
	printf("depth = %d, ",depth_list[node]);
	printf("height = %d, ",height_list[node]);
	
	if(tree[node].parent==NIL){
		printf("root\n");
	}else if(tree[node].left == NIL && tree[node].right == NIL ){
		printf("leaf\n");
	}else{
		printf("internal node\n");
	}
	
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
	setDepth(tree,depth_list,root_node,0);
	setHeight(tree,height_list,root_node);
	
	for(i=0;i<n;i++){
		print(tree,depth_list,height_list,i);
	}
	return 0;	
}
