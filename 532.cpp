// uva 532
// 3 dimensional search is just like 2 dimentional search, just add another two directions to search, that's it

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Vertex {
	int l,r,c;
	Vertex(int l, int r, int c):l(l),r(r),c(c) {}	
	Vertex():l(0),r(0),c(0) {}
};
char dungeon[31][31][31];
int v[31][31][31]; // this is the array that will only track whether visited but also the distance plus one fron the origin
int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

int bfs(int sl, int sr, int sc, int el, int er, int ec, int L, int R, int C) {
	queue<Vertex> Q;
	Vertex vertex(sl,sr,sc);
	v[sl][sr][sc] = 1;
	Q.push(vertex);
	while(!Q.empty()) {
		Vertex ve = Q.front();
		Q.pop();
		if(ve.l==el && ve.r==er && ve.c==ec)
			return v[ve.l][ve.r][ve.c] - 1;
		for(int k=0;k<6;k++) {
			int new_l = ve.l + dir[k][0];
			int new_r = ve.r + dir[k][1];
			int new_c = ve.c + dir[k][2];
			if(new_l>=0 && new_l<L && new_r>=0 && new_r<R && new_c>=0 && new_c<C && !v[new_l][new_r][new_c] && dungeon[new_l][new_r][new_c]!='#') {
				Vertex bv(new_l,new_r,new_c);
				v[new_l][new_r][new_c] = v[ve.l][ve.r][ve.c] + 1;
				Q.push(bv);
			}
		}
	}
	return 0;
}

int main() {
	int L,R,C,sl,sr,sc,el,er,ec,dis;
	char *sp,*ep;
	while(scanf("%d %d %d%*c",&L,&R,&C),L+R+C) {
		sp = ep = NULL;
		for(int l=0;l<L;l++) {
			for(int r=0;r<R;r++) {
				gets(dungeon[l][r]);
				if(!sp)
					sp = strchr(dungeon[l][r],'S');
				if(!ep)
					ep = strchr(dungeon[l][r],'E');
			}
			getchar();
		}
		int offset = sp - &dungeon[0][0][0]; 
		sl = offset / (31*31);
		sr = offset / 31 % 31;
		sc = offset % 31;

		offset = ep - &dungeon[0][0][0]; 
		el = offset / (31*31);
		er = offset / 31 % 31;
		ec = offset % 31;
		
		memset(v,0,sizeof(v));
		dis = bfs(sl,sr,sc,el,er,ec, L, R, C);
		if(dis)
			printf("Escaped in %d minute(s).\n",dis);
		else
			printf("Trapped!\n");
	}
	return 0;
}