#include<cstdio>

struct case1 {
	int b,c;
};

typedef struct case1 TheCase;

int main()
{
	int a,b,c;
	TheCase cases[200];
	scanf("%d",&a);
	getchar();
	getchar();
	int total=0,count=0;
	for(int i=0;i<a;i++) {
		scanf("%d\n%d",&b,&c);
		total += c;
		cases[i].b = b;
		cases[i].c = c;
	}
	for (int i=0;i<a;i++) {
		for (int k=0;k<cases[i].c;k++) {
			for (int j=1;j<=cases[i].b;j++) {
				for(int u=1;u<=j;u++) {
					printf("%d",j);
				}
				printf("\n");
			}
			for (int j=cases[i].b-1;j>=1;j--) {
				for(int u=1;u<=j;u++) {
					printf("%d",j);
				}
				printf("\n");
			}
			count++;
			if(count<total)
				printf("\n");
		}	
	}
	return 0;
}