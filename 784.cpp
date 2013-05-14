//uva 784
#include<cstdio>
#include<cstring>
char map[31][81];
char seperator[81];
bool v[31][81];

void dfs(int i,int j,char wall) {
	if(map[i][j]==wall || v[i][j])
		return ;
	v[i][j] = true;
	map[i][j] = '#';
	dfs(i-1,j-1,wall);
	dfs(i-1,j,wall);
	dfs(i-1,j+1,wall);
	dfs(i,j-1,wall);
	dfs(i,j+1,wall);
	dfs(i+1,j-1,wall);
	dfs(i+1,j,wall);
	dfs(i+1,j+1,wall);
}

int main() {
	int c,k,x,y; // x is height, y is width direction
	char *p,wall;
	scanf("%d",&c);
	getchar();
	for(int i=0;i<c;i++){
		k=0;
		p=NULL;
		
		while(gets(map[k]),map[k][0]!='_') {
			if(!p)
				p=strchr(map[k],'*');
			k++;
		}
		wall = map[0][0]; //assume that top left corner is wall because there is no outdoor door
		x = (p-map[0]+1)/81; // height direction
		y = (p-map[0])%81;   // width direction
		memset(v,false,sizeof(v));
		dfs(x,y,wall);
		for(int j=0;j<=k;j++)
			puts(map[j]);
	}
	return 0;
}