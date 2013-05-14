#include<cstdio>

int main() {
	char c;
	while(scanf("%c",&c)!=EOF) {
		if(c==10) {
			putchar(c);
		} else {
			putchar(c-7);
		}
	}
	return 0;
}