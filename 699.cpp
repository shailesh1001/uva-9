// uva 699
// thought from http://blog.csdn.net/cc_again/article/details/8562515
// self coded

#include<cstdio>
#include<cstring>
int ground[500]; // assume the root is at the center ground[250]
int left_most_pos,right_most_pos;

//
void buildtree(int cur, int pos_on_ground) {
	if(cur==-1)
		return;
	if(pos_on_ground<left_most_pos)
		left_most_pos = pos_on_ground;
	if(pos_on_ground>right_most_pos)
		right_most_pos = pos_on_ground;

	ground[pos_on_ground] += cur;
	scanf("%d", &cur);
	buildtree(cur, pos_on_ground-1);
	scanf("%d", &cur);
	buildtree(cur, pos_on_ground+1);
	return ;
}


int main() {
	int cur,N=1;
	while(scanf("%d",&cur)&&cur!=-1) {
		memset(ground,0,sizeof(ground));
		left_most_pos = 499;
		right_most_pos = 0;
		buildtree(cur,250);
		printf("Case %d:\n",N++);
		for(int i=left_most_pos;i<=right_most_pos;i++) {
			if(i==left_most_pos)
				printf("%d",ground[i]);
			else
				printf(" %d",ground[i]);
		}
		printf("\n\n");

	}
	return 0;
}