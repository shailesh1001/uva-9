// uva 442
#include<cstdio>
#include<cstring>
struct Matrix{
	int m,n;
};

int main() {
	Matrix map[256],stack[1000];
	int num,top,ans;
	char line[1000];
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++) {
		char name;
		int m,n;
		scanf("%c %d %d",&name,&m,&n);
		getchar();
		map[name].m = m;
		map[name].n = n;
	}
	while(gets(line)) {
		ans=0;
		top = -1;
		int flag = 1;
		for(int i=0;i<strlen(line) && flag;i++) {
			if(line[i]>='A' && line[i]<='Z') {
				stack[++top] = map[line[i]];
			}
			else if(line[i]==')') {
				if(top>=1) { //has two matrices in stack
					Matrix matrix1 = stack[top--]; // right operand
					Matrix matrix2 = stack[top--]; // left operand
					if(matrix2.n!=matrix1.m) {
						flag = 0;
						break;
					}
					ans += matrix2.m * matrix2.n * matrix1.n;
					Matrix temp;
					temp.m = matrix2.m;
					temp.n = matrix1.n;
					stack[++top] = temp;
				}
			}
		}
		if(flag)
			printf("%d\n",ans);
		else
			printf("error\n");
	}
	return 0;
}