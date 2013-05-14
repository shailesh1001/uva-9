//uva 548
#include<cstdio>
#include<climits>
#define N 100000
int global_sum = INT_MAX;
int global_leaf = -1;
typedef struct Node* PTR; 
struct Node{
	int val;
	PTR left,right;
	Node(int v):val(v) {left = right = NULL;} 
};

// no need in this program
void in_traverse(PTR root) {
	if(!root) return;
	in_traverse(root->left);
	printf("%d ",root->val);
	in_traverse(root->right);
}

//return the root of the tree built from in-order and post-order traversal, precondition: all values are distinct
PTR buildtree_postin(int post[], int in[], int in_start, int post_start, int size, int current_sum) {
	int i,num;
	if(size==0)
		return NULL;
	PTR root = new Node(post[post_start+size-1]);
	current_sum += root->val; // this line is for calculating path sum
	if(size==1) {   // if we reached the leaf we need to compare the path sum with the global value
		if(current_sum<global_sum) { // this line is for calculating path sum
			global_sum = current_sum;
			global_leaf = root->val;
		}
		return root;
	}
	for(i=in_start,num=0;in[i]!=post[post_start+size-1];i++,num++)
		;
	root->left = buildtree_postin(post,in,in_start,post_start,num,current_sum);          // left child starts from 0 in both in[] and post[], size is num
	root->right = buildtree_postin(post,in,in_start+num+1,post_start+num,size-num-1,current_sum);  // right child starts from i+1 in in[], starts from i in post[], size is size-num-1;
	return root;
}

int main() {
	
	char ch;
	int post[N],in[N];
	PTR r;
	while(~scanf("%d%c",in,&ch)) {
		int n;
		for(n=1;ch!='\n';n++)
			scanf("%d%c",in+n,&ch);
		for(int i=0;i<n;i++)
			scanf("%d",post+i);
		global_sum = INT_MAX;
		global_leaf = -1;
		r=buildtree_postin(post,in,0,0,n,0);
		printf("%d\n",global_leaf);
	}
	
	return 0;
}