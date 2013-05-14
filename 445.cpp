#include<cstdio>
#include<cstring>
#include<cctype>
int main() {
	char a[200];
	int num=0;
	int xxx = 0;
	while((fgets(a,sizeof(a),stdin))!=NULL) {
		if(a[strlen(a)-1]=='\n') 
			a[strlen(a)-1] = '\0';
		if(strlen(a)!=0) {
			for (int i=0;i<strlen(a);) {
				num = 0;
				if(isdigit(a[i])) {
					while(isdigit(a[i])) { 
						num += a[i]-'0';
						i++;
					}
				} 
				if(!isdigit(a[i]) && a[i]!='b' && a[i]!='!') {
					for (int j=0;j<num;j++) 
						putchar(a[i]);
				} else if(a[i]=='b') {
					for (int j=0;j<num;j++) 
						putchar(' ');
				} else if(a[i]=='!') {
					if (num==0)
						putchar('\n');
					else 
						for (int j=0;j<num;j++) 
							putchar('\n');
				}
				i++;			
			}
			putchar('\n');
		} else {
			putchar('\n');
		}
	}
	return 0;
}