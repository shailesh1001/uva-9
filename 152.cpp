// uva 152

#include<cstdio>
#include<cmath>
#include<cstring>
int trees[6000][3];


int main() {
	int k=0,hist[10];
	memset(hist,0,sizeof(hist));
	while(scanf("%d %d %d",&trees[k][0],&trees[k][1],&trees[k][2]), (trees[k][0]!=0 || trees[k][1]!=0 || trees[k][2]!=0)) {
		k++;
	}
	for(int i=0;i<k;i++) {
		double min_dis = 2000;
		for(int j=0;j<k;j++) {
			if(i!=j) {
				double dis = sqrt((trees[i][0]-trees[j][0])*(trees[i][0]-trees[j][0])+(trees[i][1]-trees[j][1])*(trees[i][1]-trees[j][1])+(trees[i][2]-trees[j][2])*(trees[i][2]-trees[j][2]));
				if(dis<min_dis) 
					min_dis = dis;
			}
		}
		int flo = floor(min_dis);
		if(flo<10)
			hist[flo]++;
	}
	for(int i=0;i<10;i++) {
		printf("%4d",hist[i]);
	}
	putchar('\n');
	return 0;
}