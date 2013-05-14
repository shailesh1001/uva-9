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