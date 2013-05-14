#include<cstdio>

int main() {
  int a,b,c,d,e;
  while((scanf("%d",&a))!=EOF){
  	while(a--) {
    	scanf("%d",&b);
    	int sum=0;
    	while(b--) {
      		scanf("%d%d%d",&c,&d,&e);
      		sum += c*e;
    	}
    	printf("%d\n",sum);
  	}
  }
  return 0;
}

