#include<cstdio>

int main(){
	long long a, b;
	int num =1;
	scanf(" %lld %lld",&a,&b);
	long long originala = a;
	while(a>=0 && b>=0) {
		int term = 0;
		while(a<=b && a!=1) {
			term++;
			//printf("%lld,%d\n",a,term);
			if(a%2==0) {
				a /= 2;
			} else {
				a = a*3+1;
			}
		}
		if(a==1)
			term++;
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",num,originala,b,term);
		num++;
		scanf(" %lld %lld",&a,&b);
		originala = a;
	}
	return 0;
}