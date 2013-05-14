#include<cstdio>

int main() {
	int n,a,b;
	scanf("%d",&n);
	while(n--) {
		scanf("%d %d",&a,&b);
		if(b-a<=1)
			printf("1\n");
		else if(b-a==2)
			printf("2\n");
		else if(b-a<=4)
			printf("3\n");
		else {
			int sum =0;
			int i=0;
			for(;sum<b-a;) {
				i++;
				sum += 2*i;
			}
			if(sum==b-a)
				printf("%d\n",2*i);
			else if(sum-(b-a)>=1 && sum-(b-a)<i)
				printf("%d\n",2*i);
			else 
				printf("%d\n",2*i-1);
		}
	}
	return 0;
}




//http://blog.163.com/blueshell@yeah/blog/static/169200818201071891936740/ 这个代码好理解一些

// 这个人的代码思路跟我差不多 而且结果测试了很多也差不多  但是她的能过我的过不了
/*
#include <stdio.h>
int main()
{
    int i,m,n,t,step,count;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&m,&n);
        step=1;
        count=0;
        while(1)
        {
            if(m>=n)
            {
                printf("%d\n",2*count);
                break;
            }
            else if(n-m<=step)
            {
                printf("%d\n",2*count+1);
                break;
            }
            else
            {
                m+=step;
                n-=step;
                step++;
                count++;
            }
        }
    }
    return 0;
}
*/