// uva 657
// thourght from http://blog.csdn.net/kjc19920531/article/details/8074428
// self coded
#include<cstdio>
#include<cstring>
#include<cstdlib>
char map[51][51];
int v[51][51];    //store the code of each outer connected component
bool v_X[51][51]; //store the visited flag of the inner connected component

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void dfs(int i, int j, int w, int h, int num) {
	if(i<0 || i>=h || j<0 || j>=w || v[i][j] || map[i][j]=='.') 
		return ;
	v[i][j] = num; // store num of this connected component, not only a ture value
	dfs(i-1,j,w,h,num); // up
	dfs(i+1,j,w,h,num); // down
	dfs(i,j-1,w,h,num); // left
	dfs(i,j+1,w,h,num); // right
}

void dfs_X(int i, int j, int w, int h) {
	if(i<0 || i>=h || j<0 || j>=w || v_X[i][j] || map[i][j]!='X')
		return ;
	v_X[i][j] = true;
	dfs_X(i-1,j,w,h); // up
	dfs_X(i+1,j,w,h); // down
	dfs_X(i,j-1,w,h); // left
	dfs_X(i,j+1,w,h); // right
}

int main() {
	int w,h,T=1,num,count[100];// assume there are no more than 100 dices
	while(scanf("%d%d",&w,&h),h&&w) {
		getchar();
		for(int i=0;i<h;i++)
			gets(map[i]);
		printf("Throw %d\n",T++);
	
		memset(v,0,sizeof(v));
		num = 0;
		for(int i=0;i<h;i++) 
			for(int j=0;j<w;j++)
				if(map[i][j]!='.' && !v[i][j]) 
					dfs(i,j,w,h,++num); //have to start from 1, because we cannot mark number as 0 because 0 means false
		memset(v_X,false,sizeof(v_X));
		memset(count,0,num*sizeof(int));
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++) 
				if(map[i][j]=='X' && !v_X[i][j]) {
					int num_X = v[i][j]; // connect component number
					dfs_X(i,j,w,h);
					count[num_X-1]++; //store from index 0 because we need to use qsort later, qsort can only soft from index 0
				}
		qsort(count,num,sizeof(int),cmp);
		for(int i=0;i<num;i++) {
			if(i==0)
				printf("%d",count[i]);
			else
				printf(" %d",count[i]);
		}
		printf("\n\n");
	}
	return 0;
}