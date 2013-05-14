// uva 10047
// use 0,1,2,3 to stand for north, east, south, west; because we are talking about minimum time we should use bfs
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
struct Node{
	int i,j,d; //d is the direction when entering this node
	int c,t; //color and time
	Node(int i,int j,int d,int c, int t):i(i),j(j),d(d),c(c),t(t) {}
	Node():i(0),j(0),d(0),c(0),t(0) {}
	friend bool operator < (const Node &a, const Node &b){ // 重载<构建最小堆  
        return a.t > b.t;   // 时间作为 priority queue 的heuristic
    } 
};

bool v[30][30][4][5]; //first two dimensions are coordination, last two dimensions are dir and color respectively
char map[30][30];
int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; //north, east, south, west

int bfs(int i,int j,int ei,int ej, int M, int N) {
	Node node(i,j,0,0,0); // start node faces north
	priority_queue<Node> que;
	que.push(node);
	while(!que.empty()) {
		Node nd = que.top();   
		que.pop();
		//printf("%d %d %d %d %d\n",nd.i,nd.j,nd.d,nd.c,nd.t);
		v[nd.i][nd.j][nd.d][nd.c] = true;
		if(nd.i==ei && nd.j==ej && nd.c==0) 
			return nd.t;

		for(int k=0;k<4;k++) {
			int next_i = nd.i;
			int next_j = nd.j;
			int next_d = k;
			int next_c = nd.c;
			int next_t = nd.t + 1;
			if(k==nd.d) {  // same direction, change color change position
				next_c = (nd.c+1)%5;
				next_i = nd.i + direction[k][0];
				next_j = nd.j + direction[k][1];
			}
			
			if(abs(nd.d-k)==2)
				next_t++;
			if(next_i<0 || next_j<0 || next_i>=M || next_j>=N || v[next_i][next_j][next_d][next_c] || map[next_i][next_j]=='#')
				continue;
			
			Node next(next_i,next_j,next_d,next_c,next_t);
			que.push(next);
		}
	}
	return 0;
}

int main() {
	int M,N,si,ei,sj,ej;
	char *ps,*pe;
	int t;
	int ca=1;
	while(scanf("%d %d%*c",&M,&N), M+N) {
		ps = pe = NULL;
		for(int i=0;i<M;i++) {
			gets(map[i]);
			if(!ps) {
				ps = strchr(map[i],'S');
			}
			if(!pe) {
				pe = strchr(map[i],'T');
			}
		}
		si = (ps-&map[0][0]) / 30;
		sj = (ps-&map[0][0]) % 30;
		ei = (pe-&map[0][0]) / 30;
		ej = (pe-&map[0][0]) % 30;
		memset(v,false,sizeof(v));
		t = bfs(si,sj,ei,ej,M,N);
		if(ca!=1)
			printf("\n");
		printf("Case #%d\n",ca++);
		if(!t)
			printf("destination not reachable\n");
		else 
			printf("minimum time = %d sec\n",t);
	}
	return 0;
}