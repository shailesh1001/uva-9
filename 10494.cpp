#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


//<算法竞赛入门经典>P22 提示2-12
//This problem uses the problem that
//that if there are only +,-,* in an integer expression, then mod operation
//can be done after each operation arbitrarily. That being said, 1234 % 10 is equivalent to
//    ((((1*10+2) % 10) + 3 ) %10 + 4) %10
// or ((((1*10%10+2) % 10) + 3 ) %10 + 4) %10
// or .... (any cand of %10 injection)


char dividend[1000];
char result[1000];
int main() {
	long long divider,mod;
	char op;
	while(cin>>dividend>>op>>divider) {
		int len = strlen(dividend);
		if(op=='%') {
			mod=0;
			for(int i=0;i<len;i++) {
				mod = mod*10+dividend[i]-'0';
				mod = mod % divider;
			}
			printf("%lld\n",mod);
		} else {
			long long temp=0;
			int k=0;
			bool ok=false; // this sentinel help us solve the situation like 100000000 / 2.  In this case, temp will be < divider for most time, but we still need to record the zero
			for(int i=0;i<len;i++) {
				temp = temp*10 + dividend[i]-'0';
				if(temp>=divider) {
					result[k++] = temp/divider + '0';
					temp = temp%divider;
					ok = true;
				} else if(ok) {
					result[k++] = temp/divider + '0';
					temp = temp%divider;
				}
			}
			if(k==0) {
				//dividend is less than divider;
				strcpy(result,"0");
			} else {
				result[k] = '\0';
			}
			puts(result);
		}
	}
	return 0;
}