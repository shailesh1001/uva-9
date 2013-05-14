#include<cstdio>
#include<cstring>
char line[140];
char stack[140];
char map[256];

int main() {
	map[')'] = '(';
	map[']'] = '[';
	int num;
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++) {
		int top=-1,j;
		gets(line);
		int flag=1;
		for(j=0;j<strlen(line)&&flag;j++) {
			if(line[j]=='(' || line[j]=='[')
				stack[++top] = line[j];
			else if(line[j]==')'||line[j]==']') {
				if(top<0 || stack[top--]!=map[line[j]]) {
					printf("No\n");
					flag=0;
					break;
				}
			}
		}
		if(flag==1 && top==-1)
			printf("Yes\n");
		else if(flag!=0)
			printf("No\n");
	}
	return 0;
}