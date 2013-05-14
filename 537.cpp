#include<cstdio>
#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;


double convert(string digit, string unit);
void cal_print(int probnum, double u, double p, double i);
int main() {
	int n = 0;
	string a;
	scanf("%d",&n);
	getchar();

	int I;
	int U;
	int P;

	for (int k=0;k<n;k++) {
		getline(cin,a);

		double u=0,i=0,p=0;

		for(int ii=0;ii<a.size();ii++) {
			if(a.at(ii) == '=') {
				string datafield = "";
				int dotcount=0;
				for(int j=ii-1;j<a.size();j++) {
					if(ispunct(a[j]) && a[j]!='=' && a[j]!='.' || isspace(a[j]) || a[j]=='.' && dotcount>1)
						break;
					if(a[j]=='.')
						dotcount++;
					datafield += a.at(j);
				}
				
				char concept = datafield[0];
				string digit="";
				int digit_end_pos = 0;
				for(int j=2;j<datafield.size();j++) {
					if(isdigit(datafield[j])||datafield[j]=='.') 
						digit += datafield[j];
					else {
						digit_end_pos = j;
						break;
					}
				}
				string unit = datafield.substr(digit_end_pos,datafield.size()-digit_end_pos);

				switch(concept) {
					case 'U': u=convert(digit,unit); break;
					case 'P': p=convert(digit,unit); break;
					case 'I': i=convert(digit,unit); break;
				}
				
			}
		}
		cal_print(k+1,u,p,i);
	}
}

void cal_print(int probnum, double u, double p, double i) {
	if(u==0) {
		u = p/i;
		printf("Problem #%d\nU=%.2fV\n\n",probnum,u);
	} else if(p==0) {
		p = u*i;
		printf("Problem #%d\nP=%.2fW\n\n",probnum,p);
	} else {
		i = p/u;
		printf("Problem #%d\nI=%.2fA\n\n",probnum,i);
	}
	
}

double convert(string digit, string unit) {
	double value=0;
	double decimal=0;
	double factor =0 ;
	int i;
	for(i=0;i<digit.size() && isdigit(digit[i]);i++) {
		value = value*10 + digit[i]-'0';
	}
	
	int decimal_width = digit.size()-i-1;
	i++;//move past the dot
	if(i<digit.size()) {
		//it encoutered dot, and it is a float
		for(;i<digit.size();i++) {
			decimal = decimal*10+digit[i]-'0';
		}
	}
	decimal = decimal/pow(10,decimal_width*1.0);
	value += decimal;

	switch(unit[0]) {
		case 'm': factor = 0.001; break;
		case 'k': factor = 1000; break;
		case 'M': factor = 1000000; break;
		default: factor = 1.0;
	}
	return value * factor;
}