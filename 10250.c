// uva 10250
// http://blog.csdn.net/frankiller/article/details/7725401
#include<stdio.h>
int main()
{double x1,y1,x2,y2,x3,y3,x4,y4,cx,cy;
 while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
 {if(x1==x2 && y1==y2)
  printf("Impossible.\n");
  else
    {cx=(x1+x2)/2;cy=(y1+y2)/2;        
     x1-=cx;x2-=cx;y1-=cy;y2-=cy;    
     x3=-y1;y3=x1;x4=-x3;y4=-y3;        
     printf("%lf %lf %lf %lf\n",x3+cx,y3+cy,x4+cx,y4+cy);
    }
 }
 return 0;
} 