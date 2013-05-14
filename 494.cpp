#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main() {
	int count=0;
	char s[1000];
	
	while(fgets(s,sizeof(s),stdin) != NULL) {
		count = 0;
		for(int i=0;i<strlen(s);i++) {
			if(isalpha(s[i])) {
				while(isalpha(s[i++]))
					;
				count++;
				i -= 2;
			} else {
				while(!isalpha(s[i++]))
					;
				i -= 2;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}