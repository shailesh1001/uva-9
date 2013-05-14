// uva 299
// bubble sort

#include<cstdio>


// return how many swaps
// in this problem no duplicate numbers in *p
int bubble_sort(int* p, int size) {
	int n=0;
	for(int i=0;i<size-1;i++) {
		for(int j=0;j<size-i-1;j++) {
			if(p[j]>p[j+1]) {
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				n++;
			}
		}
	}
	return n;
}


int main() {
	int s[60],n,l;
	scanf("%d",&n);
	getchar();
	for(int k=0;k<n;k++) {
		scanf("%d",&l);
		getchar();
		for(int i=0;i<l;i++) {
			scanf("%d",&s[i]);
		}
		getchar();
		printf("Optimal train swapping takes %d swaps.\n",bubble_sort(s,l));
	}	
	return 0;	
}