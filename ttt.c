#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int i=1;
    double b=34.56;
    char s[100];
    sprintf(s,"%d",i);
    puts(s);
    sprintf(s,"%f",b);
    puts(s);
    strcpy(s,"000000010");
    sscanf(s,"%d",&i);
    printf("%d\n",i);
    strcpy(s,"0.00003");
    sscanf(s,"%lf",&b);
    printf("%f\n",b);

}