#include<iostream>
#include<cstdlib>
using namespace std;

int cmp_int(const void* _a, const void* _b) {
	int *a = (int*)_a;
	int *b = (int*)_b;
	return *a - *b;
}


int search(int *s, int size, int q) {
	for(int i=0;i<size;i++) {
		if(s[i]==q) {
			return i;
		}
	}
	return -1;
}

int main(){
	int n,q,k=0;
	cin>>n>>q;
	while(n!=0&&q!=0) {
		k++;
		int *s = new int[n];
		int *qu = new int[q];
		for(int i=0;i<n;i++) {
			cin>>s[i];
		}
		for(int i=0;i<q;i++) {
			cin>>qu[i];
		}
		qsort(s,n,sizeof(int),cmp_int);
		int exist;
		cout<<"CASE# "<<k<<":"<<endl;
		for(int i=0;i<q;i++) {
			exist = search(s,n,qu[i]);
			if(exist==-1) {
				cout<<qu[i]<<" not found"<<endl;
			} else {
				cout<<qu[i]<<" found at "<<exist+1<<endl;
			}
		}
		delete [] s;
		delete [] qu;
		cin>>n>>q;
	}
}