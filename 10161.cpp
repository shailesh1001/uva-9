//uva 10161 网上贴来的代码， 具体思路就是 这是路径的大致形状 一个以左下角为中心的 左右摇摆的路线 以四十五度对角线为中线
// 所以 是有规律可循的   先照出两端的 端点 然后再用这个位置减去左边的断点 判断位移 会发现满足一定的奇偶规律
//http://hi.baidu.com/tomtongjiantao/item/fd28f6914f464df828164759
//http://blog.csdn.net/lingyunjinzhu/article/details/8110454
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 35;
int main()
{
   int n,k,a,b,x,y;
   while(scanf("%d",&n) && n)
   {
      a = 1;
      for(k = 1; k*k < n; k++);
      a = (k-1)*(k-1);
      b = n-a;
      if(k&1)
      {
         if(b <= k)
         {
            x = k;
            y = b;
         }
         else
         {
            y = k;
            x = 2*k-b;
         }
      }
      else
      {
         if(b <= k)
         {
            y = k;
            x = b;
         }
         else
         {
            x = k;
            y = 2*k-b;
         }
      }
      printf("%d %d\n",x,y);
   }
   return 0;
}