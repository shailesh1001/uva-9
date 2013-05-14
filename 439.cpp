// uva 439
#include<cstdio>
#include<cstring>
int dir[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
struct Vertex{
	int i,j,r; //r is the distance from the origin vertex plus one
	Vertex(int a,int b,int c):i(a),j(b),r(c){}
	Vertex():i(0),j(0),r(0){}
};
int v[8][8],front,rear;
Vertex queue[1000];
int bfs(int si,int sj,int ei, int ej) {
	Vertex vert(si,sj,1);
	queue[rear++]=vert;
	int r;
	while(front!=rear) {
		Vertex vx = queue[front++];
		v[vx.i][vx.j] = vx.r;
		r = vx.r + 1;
		if(vx.i==ei && vx.j==ej)
			return vx.r-1; // because we stored one more length, we need to substract it before returning
		for(int k=0;k<8;k++) {
			int new_i = vx.i+dir[k][0];
			int new_j = vx.j+dir[k][1];
			if(new_i>=0 && new_i<8 && new_j >=0 && new_j < 8 && !v[new_i][new_j]) {
				Vertex bv(new_i,new_j,r);
				queue[rear++] = bv;
			}
		}
	}
}

int main() {
	char start[3],end[3];
	int si,sj,ei,ej,dis;
	while(~scanf("%s %s",start,end)) {
		memset(v,0,sizeof(v));
		front = rear = 0; // empty the queue
		si = 7-(start[1]-'1');
		sj = start[0]-'a';
		ei = 7-(end[1]-'1');
		ej = end[0]-'a';
		dis = bfs(si,sj,ei,ej);
		printf("To get from %s to %s takes %d knight moves.\n",start,end,dis);
	}
	return 0;
}