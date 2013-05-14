#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<queue>  
using namespace std;  
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 上0，右1，下2，左3  
int M,N,start_x, start_y,end_x,end_y, step;  
char map[30][30];  
bool  vis[30][30][4][5]; //前2维代表坐标，后2维代表方向和颜色的状态  
  
struct Node{  
    int x,y;  
    int color;  // 绿0，白1，黑2，红3，蓝4  
    int time;  
    int dir; // 当前指向的方向  
    friend bool operator < (const Node &a, const Node &b){ // 重载<构建最小堆  
        return a.time > b.time;   
    }  
};  
  
Node begin, q, t;  
priority_queue<Node >que;  
  
void bfs(){  
    while(!que.empty()) que.pop();  
    que.push(begin);  
    vis[begin.x][begin.y][begin.dir][begin.color] = true;  
  
    while(!que.empty()){  
        q = que.top();  
        que.pop();  
        printf("%d %d %d %d %d\n",q.x,q.y,q.dir,q.color,q.time);
        for(int i=0; i<4; ++i){  
            int dx = q.x+dir[i][0];  
            int dy = q.y+dir[i][1];  
              
            if(dx>=0 && dx<M && dy>=0 && dy<N && map[dx][dy]!='#'){  
                if(q.dir==i){  
                    t.time = q.time+1;  
                    t.dir=i;  
                    t.x=dx, t.y=dy;  
                    t.color = (q.color+1)%5;  
                }  
                else{  
                    if(abs(q.dir-i)==2)  
                        t.time = q.time+2;  
                    else   
                        t.time = q.time+1;  
                    t.dir = i;  
                    t.x=q.x, t.y=q.y;  
                    t.color = q.color;  
                }  
                if(!vis[t.x][t.y][i][t.color]){  
                    if(t.x==end_x && t.y==end_y && t.color==0){  
                        printf("minimum time = %d sec\n", t.time);  
                        return;  
                    }  
                    que.push(t);  
                    vis[t.x][t.y][i][t.color] = true;  
                }  
            }  
        }  
  
    }  
    printf("destination not reachable\n");  
}  
  
  
int main(){   
    int cas=1;  
    while(~scanf("%d %d%*c", &M, &N) && M && N){  
        
        bool isFind_S=false, isFind_T=false;   
  
        memset(vis, 0, sizeof(vis));  
  
        for(int i=0; i<M; ++i){  
            gets(map[i]);  
            if(!isFind_S || !isFind_T){  
                for(int k=0; k<strlen(map[i]); ++k){  
                    if(map[i][k]=='S'){  
                        start_x=i,start_y=k; isFind_S=true;   
                    }   
                    if(map[i][k]=='T'){  
                        end_x=i, end_y=k; isFind_T=true;  
                    }  
                }  
            }  
        }     
        begin.x=start_x, begin.y=start_y, begin.color=0, begin.time=0;  
        begin.dir=0;  
        if(cas!=1) printf("\n");  
        printf("Case #%d\n", cas++);  
        bfs();  
    }  
    return 0;  
}  