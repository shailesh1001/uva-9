#include<cstdio>
#include<cstring>
// thought borrowed from :
//http://blog.csdn.net/shiqi_614/article/details/7035558?reload

// 6 cases when when one face is at the top
int dir[7][7] = {{0,0,0,0,0,0,0},{0,1,2,3,4,5,6},{0,2,6,3,4,1,5},{0,3,6,5,2,1,4},{0,4,6,2,5,1,3},{0,5,6,4,3,1,2},{0,6,2,4,3,5,1}};

int main() {
	char cube[20];
	while((scanf("%s",cube+1))!=EOF) {
		char ttt = cube[7];
		char left[8];
		cube[7] = '\0';
		strcpy(left+1,cube+1);
		cube[7] = ttt;
		int found = 0;
		
		char temp[8];
		memset(temp,'\0',sizeof(temp));
		for(int i=1;i<=6;i++) {
			if(found==1) break;
			for(int j=1;j<=6;j++) //这一步相当于 按照上前左右后下的顺序在temp上涂上对应的颜色的 这就相当于在按照dir在旋转正方体
				temp[j]=left[dir[i][j]]; 
				//revolve for times to enum
			for(int k=0;k<4;k++) {
				char tmp = temp[2];
				temp[2] = temp[3];
				temp[3] = temp[5];
				temp[5] = temp[4];
				temp[4] = tmp;
				if(!strcmp(temp+1,cube+7)) {
					found = 1;
					break;
				}
			}
		}

		if(found)
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}
	return 0;
}