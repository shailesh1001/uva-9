// uva 10387 billiard 
// http://blog.csdn.net/lingyunjinzhu/article/details/8110485
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
const double PI=4.0*atan(1.0);
int main()
{
    long long a,b,s,m,n;//用long long 防止中间过程溢出， 一开始没注意在这里WA一次
    while(cin>>a>>b>>s>>m>>n,(a||b||s||m||n))
    {
        double ang=atan((n*b*1.0)/(m*a*1.0))*180.0/PI;
        double v=sqrt((a*m)*(a*m)*1.0+(b*n)*(b*n)*1.0)/(double)s;
        printf("%.2lf %.2lf\n",ang,v);
    }
    return 0;
}