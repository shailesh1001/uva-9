#include<stdio.h>
#include<string.h>

int prev[25];
int next[25];
int N, pos1, pos2,m,n;

// 删除节点
void remove(int n){
    next[prev[n]] = next[n];
    prev[next[n]] = prev[n];
}

void init(){
    memset(prev,0,sizeof(prev));
    memset(next,0,sizeof(next));
    for(int i=1; i<=N;i++){
        prev[i]=i-1;
        next[i]=i+1;
    }
    prev[1]=N;
    next[N]=1;
    pos1=1;
    pos2=N;
}

void solve(){
    while(1){
        if(prev[pos2]==pos2 || next[pos1]==pos1 ){
            printf("%3d\n",pos1);
            break;
        }
        // 第一个人进行移动
        int stepNum=1;
        while(stepNum++<m)
            pos1 = next[pos1];
        // 第二个人进行移动
        stepNum=1;
        while(stepNum++<n)
            pos2 = prev[pos2];

        //如果两个人移动到相同的地方
        if(pos1==pos2){
            printf("%3d,",pos1);
            // 找出两个人的新位置
            int newPos1=next[pos1],newPos2=prev[pos2];
            // 如果第一个人的新位置是第二个人要删除的位置，那么要再跳过那个位置
            if(newPos1==pos2) newPos1=next[newPos1];
            // 如果第二个人的新位置是第一个人要删除的位置，那么也要再跳过那个位置
            if(newPos2==pos1) newPos2=prev[newPos2];
            
            // 把该节点删掉
            remove(pos1);
            
            pos1=newPos1;
            pos2=newPos2;
        }
        else {
            int newPos1=next[pos1],newPos2=prev[pos2];
        
            // 如果第一个人的新位置是第二个人要删除的位置，那么要再跳过那个位置
            if(newPos1==pos2 ) newPos1=next[newPos1];     
            // 如果第二个人的新位置是第一个人要删除的位置，那么也要再跳过那个位置
            if(newPos2==pos1) newPos2=prev[newPos2];
            
            // 特别情况：当最后只剩下两个结点，且两个人都选中不同的编号时，则两个都要删掉
            // 这时候，其中一个人的新位置一定还是它自己原来要删除的位置
            // 因为另一个要被另一个人删除
            if(newPos1==pos1)  { printf("%3d%3d\n",pos1,pos2);break; }
            if(newPos2==pos2) { printf("%3d%3d\n",pos1,pos2);break; }
               
            
            printf("%3d%3d,",pos1,pos2);

            remove(pos1);
            remove(pos2);
            
            pos1=newPos1;
            pos2=newPos2;
        }
    }     
}
int main()
{
    
    while(scanf("%d %d %d",&N,&m,&n))
    {
        if(N==0 && m==0 && n==0) return 0;
        init();
        solve();      
    }
    return 0;
}      

 