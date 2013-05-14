//uva 133
// pay special attention when N is 1(only one node is in the circle)
#include<cstdio>

typedef struct Node* PTR;
struct Node {
	int val;
	PTR left,right;
};

int main() {
	int N,k,m;
	while(scanf("%d%d%d",&N,&k,&m),N+k+m) {
		int size=N;
		PTR head=NULL,p=NULL,pre=NULL;
		for(int i=0;i<N;i++) {
			if(!head) {
				head = new Node;
				head->val = i+1;
				head->left = head->right = head;
				pre = head;
			} else {
				p = new Node;
				p->val = i+1;
				pre->left = p;
				p->right = pre;
				p->left = NULL;
				pre = p;
			}
		}
		if(p) {
			p->left=head;
			head->right=p;
		}
		int j=size;
		PTR kstart = head,mstart=head->right;
		PTR kp,mp;
		while(j > 0) {
			kp=kstart;
			mp=mstart;
			for(int i=2;i<=k;i++) {
				kp = kp->left;
			}
			for(int i=2;i<=m;i++) {
				mp = mp->right;
			}
			
			kp->left->right = kp->right;
			kp->right->left = kp->left;
			j--;
			printf("%3d",kp->val);
			
			if(kp==mp) {
				if(j==0)
					printf("\n");
				else
					printf(",");
				kstart=kp->left;
				mstart=mp->right;
				delete kp;
			}
			else {
				mp->left->right = mp->right;
				mp->right->left = mp->left;
				j--;
				printf("%3d",mp->val);
				if(j==0)
					printf("\n");
				else
					printf(",");
				if(kp->left==mp) 
					kstart=mp->left;
				else
					kstart=kp->left;
				if(mp->right==kp)
					mstart= kp->right;
				else
					mstart=mp->right;
				delete kp;
				delete mp;
			}
		}
	}
	return 0;
}