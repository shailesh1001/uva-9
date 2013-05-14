#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
const int maxn=1000;
// pre condition we have already set all the unused cell to be 0
void add(char *p1, char *p2) {
	char temp[maxn];
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	int i,c=0;
	int tmp;
	int len=0;
	for (i=0;i<len1 && i<len2;i++) {
		tmp = p1[i]-'0' + p2[i]-'0' + c;
		temp[len++] = tmp % 10 + '0';
		c = tmp/10;
	}
	for (;i<len1;i++) {
		tmp = p1[i]-'0' + c;
		temp[len++] = tmp % 10 + '0';
		c = tmp/10;
	}
	for (;i<len2;i++) {
		tmp = p2[i]-'0' + c;
		temp[len++] = tmp % 10 + '0';
		c = tmp/10;
	}
	if(c)
		temp[len++] = c+'0';
	temp[len] = '\0';
	strcpy(p1, temp);
}

void multi(char *p1, char *p2) {
	//result will be stored in *p1
	char temp_nine[10][maxn];//temp_nine[i] will store i*(*this) i倍的*this
	strcpy(temp_nine[0],"0");
	
	//special case for operand 0
	if(!strcmp(p1,"0") || !strcmp(p2,"0")) {
		strcpy(p1,"0");
		return ;
	}
	
		
	for(int i=1;i<=9;i++) {
		strcpy(temp_nine[i],temp_nine[i-1]);
		add(temp_nine[i],p1);
	}

	// this part is where this algorithm is fast, the number of iteration is only p2.len not the value of p2
	int len_p2 = strlen(p2);
	char bs[maxn]="";
	bs[0]='\0'; // equivalent to bs[maxn]=""
	char result[maxn]="0";
	char temp[maxn];
	for(int i=0;i<len_p2;i++) {
		strcpy(temp,bs);
		strcat(temp,temp_nine[p2[i]-'0']);
		add(result,temp);
		strcat(bs,"0");
	}
	strcpy(p1,result);
}



int manip(char *p, char *q) {
// remove the dot part of *q, and store it into *p and return the number of decimals
	int len = strlen(q);
	int dot_pos = 0, k=0,i;
	bool nonzero_start = false;
	//trim the leading zeros
	for (i=0;i<len;i++) 
		if(q[i]!=0 && q[i]!='.')
			break;
		if(q[i]=='.')
			dot_pos = i;

	for(;i<len;i++) {
		if(q[i]!='.') {
			p[k++] = q[i];
		}
		if(q[i]=='.')
			dot_pos = i;
	}
	p[k] = '\0';
	return len-dot_pos-1;
}

char num1[maxn],num2[3],num1_tmp[maxn],num1_tmp2[maxn];
int main() {
	char s[11];
	int deci;
	long long total_deci;
	long long diff;
	while(cin.getline(s,11)) {

		int kk=0;
		for(kk=0;kk<6;kk++)
			num1[kk] = s[kk];
		//trim trailing zeros
		for(kk=kk-1;kk>=0;kk--) {
			if(num1[kk]!='0')
				break;
		}
		num1[kk+1]='\0';

		if(s[7]!=' ') {
			num2[0] = s[7];
			num2[1] = s[8];
			num2[2] = '\0';
		} else {
			num2[0] = s[8];
			num2[1] = '\0';
		}

		deci = manip(num1_tmp,num1);
		total_deci =deci;
		int expo = atoi(num2);
		reverse(num1_tmp,num1_tmp+strlen(num1_tmp));
		strcpy(num1_tmp2,num1_tmp);
		for(int i=1;i<expo;i++) {
			multi(num1_tmp,num1_tmp2);
			total_deci = total_deci + deci;
		}
		int len = strlen(num1_tmp);
		reverse(num1_tmp,num1_tmp + len);
		diff = total_deci - len;
		if(diff>=0) {
			putchar('.');
			for(long long i=0;i<diff;i++)
				putchar('0');
			puts(num1_tmp);
		} else {
			long long i=0;
			for(i=0;i<-diff;i++)
				putchar(num1_tmp[i]);
			putchar('.');
			for(;i<len;i++)
				putchar(num1_tmp[i]);
			putchar('\n');
		}

	}

	return 0;
}