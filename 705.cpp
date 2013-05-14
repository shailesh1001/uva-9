// uva 705
// thourght http://blog.csdn.net/shuangde800/article/details/7726620
// self-coded
#include<cstdio>
#include<cstring>
#include<climits>

char str[100][100], map[300][300]; 
bool v[300][300];
int dir[8][2] ={{-1,0}, {1,0}, {0,-1},{0,1}, // {delta_i,delta_j} 这一行是上下左右方向走  
                 {-1,-1},{-1,1},{1,1},{1,-1}}; // 这一行是斜的方向走，从左上开始，顺时针
int w,h,last_i,last_j;

void expand(int row) {
	for(int i=0;i<strlen(str[row]);i++) {
		int expanded_row = row*2, expanded_col = i*2;
		if(str[row][i] == '\\') {
			map[expanded_row][expanded_col] = '\\';
			map[expanded_row+1][expanded_col+1] = '\\';
			map[expanded_row][expanded_col+1] = ' ';
			map[expanded_row+1][expanded_col] = ' ';
		} else if(str[row][i] == '/'){  
            map[expanded_row][expanded_col+1] = '/';  
            map[expanded_row+1][expanded_col] = '/';  
            map[expanded_row][expanded_col] = ' ';  
            map[expanded_row+1][expanded_col+1] = ' ';    
        }  
	}
}

// as long as there is an obstacle(full/half) in front of the direction, cannot go, return false
bool can_go(int i,int j, int dir) {
	switch(dir) {
		case 4: if(i-1>0 && map[i-1][j]=='/')
					return false;
				if(j-1>0 && map[i][j-1]=='/') 
					return false;
				return true;
				break;
		case 5:
				if(i-1>0 && map[i-1][j]=='\\')
					return false;
				if(j+1<2*w && map[i][j+1]=='\\')
					return false;
				return true;
				break;
		case 6:
				if(j+1<2*w && map[i][j+1]=='/')
					return false;
				if(i+1<2*h && map[i+1][j]=='/')
					return false;
				return true;
				break;
		case 7:
				if(j-1>0 && map[i][j-1]=='\\')
					return false;
				if(i+1<2*h && map[i+1][j]=='\\')
					return false;
				return true;
				break;
	}
}
void dfs(int i,int j,int& cnt) {
	if(i<0 || i>=2*h || j<0 || j>=2*w || map[i][j]!=' ' || v[i][j])
		return ;
	v[i][j] = true;
	cnt++;
	last_i = i;
	last_j = j;
	for(int k=0;k<8;k++) {
		int new_x = i + dir[k][0], new_y = j+dir[k][1];
		if(k<4) {
			dfs(new_x,new_y,cnt);
		} else if(can_go(i,j,k)){
			dfs(new_x,new_y,cnt);
		}
	}
}

int main() {
	int cas=1;
	while(~scanf("%d %d",&w,&h) && w && h) {
		getchar();
		memset(str,0,sizeof(str));
		memset(map,0,sizeof(map));
		memset(v,false,sizeof(v));
		for(int i=0;i<h;i++) {
			gets(str[i]);
			expand(i);
		}
		int maxNum = INT_MIN, cnt, circleNum=0;
		bool haveCircle = false;
		for(int i=0; i<2*h; ++i){
            for(int j=0; j<2*w; ++j){  
                if(map[i][j]==' ' && !v[i][j]) {
                    cnt = 0;
                    dfs(i,j,cnt);

	                // 判断是否是环的，首先要判断结束的那点是否和开始的相邻  
	  				bool flag = false;
	  				for(int k=0; k<8; ++k){  
	                    int dx=last_i+dir[k][0];  
	                    int dy=last_j+dir[k][1];  
	                    if(dx==i && dy==j){   
	                        flag=true; break;  
	                    }  
	                } 
	                // 相邻的还不够，数量至少是4才能形成环状  
	                if(flag && cnt>=4){  
	                    haveCircle = true;  
	                    ++circleNum;  
	                    if(cnt > maxNum)  
	                        maxNum = cnt;  
	                } 
            	}
            }  
        } 
       	printf("Maze #%d:\n",cas++);  
  
        if(haveCircle)
            printf("%d Cycles; the longest has length %d.\n\n", circleNum, maxNum);
        else
            printf("There are no cycles.\n\n");
	}
	return 0;
}