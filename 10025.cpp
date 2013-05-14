// uva 10025

// 这道题首先k 的正负是不用考虑的 因为如果输入的是一个负数，那么只要它的绝对值能用左边的式子表达，那把左边反个符号也可能能表达这个负数
// 然后 我们就先从1+2+3+....+n来开始找如果能找到1+2+3+...+n 的前n项的和正好是k那么结果就是n （为什么要一直加 因为全加还达不到k的话肯定还要加 不能减）
// 然后如果我们在循环的过程中发现 前n项的和第一次大于k了此刻 我们知道这前n项当中必须做出一些减法才能达到k  假设需要做减法的是 i ,j, q.  那么 1+2+3+.-i... -j... -q.+n
// 就相当于 1+2+3+i...+j...+q+...+n - 2i-2j-2q  == k                所以k与前n项的和的差必须是偶数才行 所以我们一旦第一找到差为偶数那么 就找到结果了


#include<cstdio>

long long a[100000];

int main() {
	a[0]=0;
	for(int i=1;i<=99999;i++) {
		a[i]=i+a[i-1];
		if(a[i]>1000000000)
			break;
	}
	long long k,n;
	scanf("%lld",&n);
	getchar();
	while(n--) {
		scanf("%lld",&k);
		getchar();
		if(k<0) 
			k=-k;
		for(long long N=1;;N++) {
			if(k==a[N]) {
				printf("%lld\n",N);
				break;
			} else if(a[N]>k && (a[N]-k)%2==0) {
				printf("%lld\n",N);
				break;
			}
		}
		if(n)
			printf("\n");
	}
	return 0;
}