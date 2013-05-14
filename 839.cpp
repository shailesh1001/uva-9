// uva 839
// self thought self coded
#include<cstdio>

struct Node{
	int wl,dl,wr,dr,wtotal;
	Node *left;
	Node *right;
	Node(int wl,int dl,int wr,int dr):wl(wl),dl(dl),wr(wr),dr(dr) {left=right=NULL; wtotal = wl+wr;}
};

Node* buildtree(int& balanced) {
	int i,wl,dl,wr,dr;
	scanf("%d %d %d %d",&wl,&dl,&wr,&dr);
	Node *p = new Node(wl,dl,wr,dr);
	
	if(!wl) {
		p->left = buildtree(balanced);
		wl = p->left->wtotal;
		p->wtotal += wl;
	}
	if(!wr) {
		p->right = buildtree(balanced);
		wr = p->right->wtotal;
		p->wtotal += wr;
	}
	if(wl*dl != wr*dr) {
		balanced = 0;
	}
	return p;
}


int main() {
	int num,balanced=1;
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++) {
		getchar();
		balanced = 1;
		buildtree(balanced);
		if(i!=0)
			printf("\n");
		if(balanced)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}