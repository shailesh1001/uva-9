#include<stdio.h>

int main() {
  long long a,b,c;
  while((scanf("%lld%lld",&a,&b))!=EOF) {
    c = b>a?b-a:a-b;
    printf("%lld\n",c);
  }
  return 0;
}
