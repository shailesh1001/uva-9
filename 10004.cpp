// uva 10004
// thought from http://www.ackratos.com/blog/?p=360

//uva 10004
// thought from http://www.ackratos.com/blog/?p=360

#include<cstdio>
#include<cstring>

int queue[1000];
int map[205][205];
int v[205]; // not only use as a visited matrix but also used for color
            // why it is not a two dimentional matrix? because we use adjacency matrix to represent graph in this problem
            // and each node is actually appear only in one dimension in map[][]
            // 此题的点不是以坐标的形式存储的  而是以编号的形式存储的

bool bfs(int n,int m) {
	int front,rear;
	front=rear=0;
	queue[rear++] = 0; //push first node into the queue
	v[0] = 1;   //color first node to 1
	while(front<rear) {
		int bn = queue[front++];
		for(int i=0;i<n;i++) {
			if(map[bn][i]) {
				if(!v[i]) {
					v[i] = v[bn]==1 ? 2 : 1;
					queue[rear++] = i;
				} else if(v[i]==v[bn]){
					return false; // non bicolorable
				}
			}
		}
	}
	return true;
}

int main() {
	int n,m; //number of nodes and edges
	while(scanf("%d",&n),n) {
		scanf("%d",&m);
		memset(v,0,sizeof(v));
		memset(map,0,sizeof(map));
		for(int i=0;i<m;i++) {
			int from,to;
			scanf("%d%d",&from,&to);
			map[from][to] = map[to][from] = 1;
		}
		if(bfs(n,m))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
	return 0;
}