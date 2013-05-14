// uva 375   acos, pi, inscribed circles and isosceles triangle
// http://hi.baidu.com/tomtongjiantao/item/8a4c54d584a33c2138f6f75f
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi = acos(-1.0);
int main()
{
   double b,h,r,c,k,l,p;
   int t;
   cin>>t;
   while(t--)
   {
      cin>>b>>h;
      l = sqrt(b*b/4+h*h);
      k = b/(b+2*l);
      p = h;
      r = p*k;
      while(r >= 0.000001)
      {
         p = p-2*r;
         r = p*k;
      }
      c = pi*(h-r/k);
      printf("%13.6lf\n",c);
      if(t)putchar('\n');
   }
   return 0;
}