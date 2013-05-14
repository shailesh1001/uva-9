#include <stdio.h>
#include <string.h>
#define N 55
#define MAX 1010
int g[N][N],vis[N];
int d[N];
int n;


void euler(int u)
{
    int v;
    for(v=1; v<=50; v++) 
        if(g[u][v])
        {
            g[u][v]--;
            g[v][u]--;
            euler(v);
            printf("%d %d\n",v,u);
            //一定要逆序输出
        }
}
int main()
{
    int t,T;
    int i,j;
    int u,v;
    int count,max,start;
    scanf("%d",&T);
    for(t=1 ;t<=T; t++)
    {
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(i=1 ;i<=n; i++)
        {
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
            g[u][v]++;
            g[v][u]++;
        }
        printf("Case #%d\n",t);

        //图是连通的，要判断所有点的度是否有为偶数    
        max=0; start=0;
        for(i=1 ;i<=50; i++)
            if( d[i]%2 )
                break;
        if(i<=50)
            printf("some beads may be lost\n");
        else  //图连通而且所有点的度都为偶数，则是一个欧拉回路，输出路径
            for(i=1; i<=50; i++)
                euler(i);

        if(t!=T) printf("\n");
    }
    return 0;
}