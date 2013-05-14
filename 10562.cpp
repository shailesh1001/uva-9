// uva 10562
#include<cstdio>
#include<cstring>

char figure[220][220]; // the 2 dimentional array to store each professor's tree presentation

bool notin(char a) {
	return a!='-' && a!=' ' && a!= '#' && a!='|'&&a;
}

void dfs(int i,int j, int height) { 
// this height is not the height of the tree, but the height of the filled figure[][]
	putchar(figure[i][j]);
	if(i+1>=height || i+1<height && figure[i+1][j]!='|') // leaf node
		printf("()");
	else {
		putchar('('); // has to be out of for loop since leaf node won't have a pair of () around it
		int start=j,end=j; //start and end position of '-'
		while(start>=0 && figure[i+2][start]=='-')  
			start--;
		start++;
		while(end<strlen(figure[i+2]) && figure[i+2][end]=='-')
			end++;
		end--;
		for(int r=start;r<=end;r++) {
			if(notin(figure[i+3][r])){
				dfs(i+3,r,height);
			}
		}
		putchar(')');
	}
}

int main() {
	int ca,row;
	scanf("%d",&ca);
	getchar();
	while(ca--) {
		row = 0;
		memset(figure,0,sizeof(figure));
		while(gets(figure[row]) && figure[row][0] != '#')
			row++;
		if(row==0) {
			printf("()\n");
			continue;
		}
		for(int i=0;i<strlen(figure[0]);i++) // do recursion on the root line is enough, recursion will take care of the rest branches below
			if(notin(figure[0][i])) {
				putchar('(');
				dfs(0,i,row);
				putchar(')');
			}
		putchar('\n');
	}
	return 0;	
}