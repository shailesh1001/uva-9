#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#define ONLINE_JUDGE
using namespace std;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
#else
#define fin cin
#endif
const int maxn=205;
int vis[maxn];
int graph[maxn][maxn];
int n;	//记录结点总数
int m;	//记录边的数量
vector<int>que;	//广度优先搜索遍历队列
bool
	bfs(){
	while(!que.empty())
	{
		int tempnode=que.front();
		que.erase(que.begin());
		for(int i=0;i<n;i++)
		{
			if(graph[tempnode][i]==1)	//如果之间有边的话
			{
				if(vis[i]==0)	//如果该结点还没被上色，那么把它上色
				{
					vis[i]=((vis[tempnode]==1)?2:1);
					que.push_back(i);
				}
				else
				{
					if(vis[i]==vis[tempnode])
						return false;
					//否则，不入队了，避免造成不必要的循环
				}
			}
		}
	}
	return true;
}
int
main()
{
	while(fin>>n&&n)
	{
		memset(vis,0,sizeof(vis));
		memset(graph,0,sizeof(graph));
		que.clear();
		fin>>m;
		for(int i=0;i<m;i++)
		{
			int start,end;
			fin>>start>>end;
			graph[start][end]=1;
			graph[end][start]=1;
		}
		que.push_back(0);
		vis[0]=1;		//vis=1时表示上了第一种颜色
		if(bfs()==false)	//广度优先搜索遍历
			cout<<"NOT BICOLORABLE."<<endl;
		else
			cout<<"BICOLORABLE."<<endl;
	}
	return 0;
}