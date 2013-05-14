#include<cstdio>
#include<cstring>
int main() {
	int n;
	int total,count;
	int min = 25;
	char s[30];
	scanf("%d",&n);
	while(n != 0) {
		getchar();
		int num = n;
		min = 25;
		total = 0;
		int j=0;
		while(j++<n) {
			fgets(s,sizeof(s),stdin);
			count = 0;
			for (int i=0;i<strlen(s);i++) {
				if(s[i]==' ') {
					count++;
					total++;
				}
			}
			if(count<min) {
				min = count;
			}
		}
		scanf("%d",&n);
		getchar();
		printf("%d\n",total-num*min);
	}
	return 0;
}