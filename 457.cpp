//uva 457 Linear Celluar Automata
#include<cstdio>
#include<cstring>

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	getchar();
	int DNA[10];
	char day[50][40];
	
	while(n) {
		for (int i=0;i<10;i++) {
			scanf("%d",&DNA[i]);
		}
		//getchar();
		//getchar();
		memset(day[0],' ',sizeof(day[0])); 
		day[0][19] = '.';


		for (int k=1;k<50;k++)  {
			for (int i=0;i<40;i++) {
				char left = i-1>=0 ? day[k-1][i-1] : 0;
				char right = i+1<40 ? day[k-1][i+1] : 0; 
				int today;
				switch(day[k-1][i]) {
					case ' ': today = 0; break;
					case '.': today = 1; break;
					case 'x': today = 2; break;
					case 'W': today = 3; break;
				}
				switch(left) {
					case ' ': left = 0; break;
					case '.': left = 1; break;
					case 'x': left = 2; break;
					case 'W': left = 3; break;
				}
				switch(right) {
					case ' ': right = 0; break;
					case '.': right = 1; break;
					case 'x': right = 2; break;
					case 'W': right = 3; break;
				}
				int sum = left + today + right;
				switch(DNA[sum]) {
					case 0:	day[k][i] = ' '; break;
					case 1: day[k][i] = '.'; break;
					case 2: day[k][i] = 'x'; break;
					case 3: day[k][i] = 'W'; break;
				}
			}
		}

		for (int i=0;i<50;i++) {
			for (int j=0;j<40;j++) 
				putchar(day[i][j]);
			putchar('\n');
		}
		if(n>1) 
			putchar('\n');
		n--;
	}

	return 0;
}