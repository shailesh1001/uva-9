// uva 621

#include<stdio.h>
#include<string.h>
int main() {
	int n;
	char s[1000];
	scanf("%d",&n);
	getchar();
	while(n--) {
		gets(s);
		if(strlen(s)==2 && s[0]=='7' && s[1]=='8') {
			puts("+");
			continue;
		}
		if(strlen(s)==1 && (s[0]=='1' && s[1]=='4')) {
			puts("+");
			continue;
		}
		if(strlen(s)>=2 && s[strlen(s)-1]=='5' && s[strlen(s)-2]=='3') {
			puts("-");
			continue;
		}
		if(strlen(s)>=2 && s[0]=='9' && s[strlen(s)-1]=='4') {
			puts("*");
			continue;
		}
		if(strlen(s)>=3 && s[0]=='1' && s[1]=='9' && s[2]=='0') {
			puts("?");
			continue;
		}
	}
	return 0;
}