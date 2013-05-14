// uva 10054

// when using union-find set,no need to distinguish edge direction

#include<cstdio>
#include<cstring>
int parent[51];
int deg[51];
int appeared[51];
int edge[51][51]; // edge[1][2] stores how many edges between node 1 and node 2

void init() {
	for(int i=1;i<=50;i++)
		parent[i] = i;
}

int find(int x) {
	return x==parent[x] ? x : parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	int xp = find(x);
	int yp = find(y);
	parent[xp] = yp;
}

bool Euler() {
	int sum=0; // num of disjoint sets, 
	for(int i=1;i<=50 && appeared[i];i++) {
		if(i == find(i)) 
			sum++;
		if(deg[i]&1)
			return false; // not Euler
	}
	if(sum>1)
		return false; // not connected
	return true;
}

// this is acutally a dfs
// 当两个节点间边的数量大于1时  整个遍历的可以理解为多重图深度优先遍历
void showEuler(int u) {
	for(int v=1;v<=50;v++) {
		if(edge[u][v]) {
			edge[u][v]--;  
			edge[v][u]--;
			showEuler(v);
			printf("%d %d\n",v,u); // 这里为什么要 v u而不是 u v 因为整个算法是回溯的过程中知性这条打印语句的 所以在递归到最深几层返回的时候 如果按照u->v 输出那么会是什么情况
			// eg 假设 递归到   这种情况  s->u->v  最深层是 u->v 开始回溯，回溯的时候输出u v 再返回上一层输出 s u 
			// u v  (从左往右的顺序读取)
			// s u
			//  这顺序明显不对，所以就应该倒过来 第一次回溯的时候输出v u
			//然后再返回到上一层的时候输出u s 这样就对了   
			// v u 
			// u s
			// 《算法竞赛入门经典》p112提出的压栈的方式也行 压栈的话 程序最后的结果是   
			// s u  
			// u v
		}
	}
}

int main() {
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&m);
		int a,b;
		memset(appeared,0,sizeof(appeared));
		memset(edge,0,sizeof(edge));
		memset(deg,0,sizeof(deg));
		init();
		for(int j=0;j<m;j++) {
			scanf("%d %d",&a,&b);
			deg[a]++;
			deg[b]++;
			appeared[a] = appeared[b] = 1;
			edge[a][b]++;
			edge[b][a]++;
			uni(a,b);
		}

		if(i!=1)
			printf("\n");
		printf("Case #%d\n",i);

		if(Euler()) {
			int kk=1;
			for(;kk<=50 && !appeared[kk];kk++)
				;
			//now kk is the first one that we found appeared we can pass in showEuler any kk that satisfies the condition- appeared. here we simply pass the first one.
			showEuler(kk);
		} else {
			printf("some beads may be lost\n");
		}
	}
	return 0;
}