// uva 712
// thought: http://blog.csdn.net/cgl1079743846/article/details/7713019
// self coded
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

int main() {
	int num,order[10],k,j;
	int N=1;
	char line[100], *pch,leafs[1000];
	while(scanf("%d",&num),num) {
		k=0;
		getchar();
		gets(line);
		gets(leafs);
		pch = strtok(line," ");
		while(pch) {
			order[k++] = atoi(pch+1);
			pch = strtok(NULL, " ");
		}
		scanf("%d",&j);
		getchar();
		printf("S-Tree #%d:\n",N);
		for(int i=0;i<j;i++) {
			gets(line);
			int val = 0;
			for(int y=0;y<k;y++) {
				val = val*2 + line[order[y]-1]-'0';
			}
			printf("%c",leafs[val]);
		}
		printf("\n\n");
		N++;
	}	
	return 0;
}