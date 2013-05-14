#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int main(){
	char a[100];
	map<char,char> mymap;
	mymap['A'] = 'A';
	mymap['E'] = '3';
	mymap['H'] = 'H';
	mymap['I'] = 'I';
	mymap['J'] = 'L';
	mymap['L'] = 'J';
	mymap['M'] = 'M';
	mymap['O'] = 'O';
	mymap['S'] = '2';
	mymap['T'] = 'T';
	mymap['U'] = 'U';
	mymap['V'] = 'V';
	mymap['W'] = 'W';
	mymap['X'] = 'X';
	mymap['Y'] = 'Y';
	mymap['Z'] = '5';
	mymap['1'] = '1';
	mymap['2'] = 'S';
	mymap['3'] = 'E';
	mymap['5'] = 'Z';
	mymap['8'] = '8';


	while(EOF!=(scanf("%s",a))) {
		int ismirror = 1;
		int ispalindrome = 1;
		for(int i=0,j=strlen(a)-1;i<=j;i++,j--) {
			if (a[i] != a[j]) 
				ispalindrome = 0;
			if (a[i] != mymap[a[j]]) 
				ismirror = 0;
			if (!ismirror && !ispalindrome)
				break;
		}
		if(ismirror && ispalindrome) 
			printf("%s -- is a mirrored palindrome.\n\n",a);
		else if(ismirror) 
			printf("%s -- is a mirrored string.\n\n",a);
		else if(ispalindrome) 
			printf("%s -- is a regular palindrome.\n\n", a);
		else
			printf("%s -- is not a palindrome.\n\n",a );
		
	}
	return 0;
}