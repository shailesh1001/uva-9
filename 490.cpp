#include<cstdio>
#include<cstring>
int main() {
	char a[200][200];
	int row=199;
	int maxrow_len = 0;
	while((fgets(a[row],sizeof(a[row]),stdin)) != NULL) {
		int len = strlen(a[row]);
		if(a[row][len-1]=='\n')
			len--; //get rid of \n as counted
		if(len>maxrow_len) {
			maxrow_len = len;
		}
		row--;
	}
	
	for (int j=0;j<maxrow_len;j++) {
		for (int i=row+1;i<=199;i++) {
			int len = strlen(a[i]);
			if(a[i][len-1]=='\n')
				len--;
			if(j<len) {
				putchar(a[i][j]);
			}
			else 
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}