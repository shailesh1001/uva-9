// uva 113

//k=p^(1/n)
//log k = (1/n)*log p
//k = exp(log p / n)

#include<cstdio>
#include<cmath>
double a,b;
int main(void){
	while(scanf("%lf %lf",&a,&b)!=EOF)
		printf("%.0lf\n",exp(log(b)/a)); //fractional part is 0 width
	return 0;
}