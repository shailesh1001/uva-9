#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstdio>  
#include <cctype>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <stack>  
#include <list>  
#include <algorithm>  
using namespace std;  
  
const int MAXN = 1000;  
int n , m , sum;  
string str[10] , mstr[MAXN];//str用来存储操作的步骤  
char num[MAXN];//存储叶子节点的值  
  
//输入函数  
void input(){  
    for(int i = 0 ;i < n ; i++)  
        cin>>str[i];  
    cin>>num;  
}  
//处理函  
void solve(int k){  
    cin>>m;  
    int temp;  
    for(int i = 0 ; i < m ; i++)  
        cin>>mstr[i];  
    printf("S-Tree #%d:\n" , k);  
    for(int i = 0 ; i < m ; i++){  
         temp = 0;  
         for(int j = 0 ; j < n ; j++)  
             temp += (mstr[i][j] - 48) * pow((double)2 , (double)n - j -1);  
         printf("%c" , num[temp]);  
    }  
    cout<<endl<<endl;  
}  
//主函数  
int main(){  
    int i = 1;  
    while(scanf("%d" , &n) && n){  
        sum = pow(2.0 , (double)n);  
        input();  
        solve(i);  
        i++;  
    }  
    return 0;  
}  